<div align="center">

# 🎮 GameServer — IOCP 기반 C++ MMO 채팅 서버

고성능 Windows 네트워크 I/O 모델(**IOCP**)과 **Google Protocol Buffers**,  
**SQL Server(ODBC)**를 결합하여 **대규모 동시 접속 채팅/메시징**을 안정적으로 처리하는 C++ 게임 서버입니다.

<p>
  <img alt="C++17" src="https://img.shields.io/badge/C%2B%2B-17-blue">
  <img alt="Platform" src="https://img.shields.io/badge/Platform-Windows-informational">
  <img alt="Networking" src="https://img.shields.io/badge/Networking-IOCP-brightgreen">
  <img alt="Protocol" src="https://img.shields.io/badge/Protocol-Protocol%20Buffers-orange">
  <img alt="Database" src="https://img.shields.io/badge/DB-SQL%20Server%20(ODBC)-lightgrey">
</p>

**작성자**: 장민석

</div>

---

## 📖 목차
1. [프로젝트 개요](#프로젝트-개요)
2. [시스템 전체 구조](#시스템-전체-구조)
3. [⚙️ 네트워킹 & 스레드 모델](#️-네트워킹--스레드-모델)
4. [💬 패킷 프로토콜](#-패킷-프로토콜)
5. [🧍 게임 도메인 (세션/룸/플레이어)](#-게임-도메인-세션룸플레이어)
6. [🗄️ 데이터베이스 계층](#️-데이터베이스-계층)
7. [🧰 개발 자동화 도구](#-개발-자동화-도구)
8. [🧱 빌드 & 실행](#-빌드--실행)
9. [🛠️ 안정성/성능 설계 포인트](#️-안정성성능-설계-포인트)
10. [📚 출처](#-출처)

---

## 🧩 프로젝트 개요

**개발 목적**  
- 고성능 Windows 네트워크 I/O 모델(IOCP)과 Google Protocol Buffers를 결합하여  
  **수천 명의 동시 클라이언트**를 대상으로 안정적인 메시징/채팅을 처리하는 게임 서버입니다.  
- 데이터 계층은 **SQL Server(ODBC)** 를 사용하며,  
  **XML 기반 DSL → DB 스키마/프로시저 자동 동기화**와  
  **코드 생성 도구(패킷/프로시저)** 를 갖춘 것이 특징입니다.

**주요 기능**
- 🧠 **IOCP 네트워킹** — AcceptEx 기반 접속 처리, 다중 워커 스레드 디스패치, 세션 단위 패킷 처리  
- 🧩 **ProtoBuf 패킷 프로토콜** — `.proto`에서 자동 생성된 타입 안전 패킷 파이프라인 및 핸들러 테이블  
- 🗄️ **DB 자동화(ODBC + XML DSL)** — `DBSynchronizer`가 `GameDB.xml`을 해석해  
  스키마 및 프로시저 자동 동기화, `GenProcedures.h`로 안전한 SP 래퍼 제공  
- 🧵 **멀티스레드 잡 시스템** — 전역 큐, `Job/JobQueue/JobTimer`, `DeadLockProfiler` 등 코어 유틸 포함  
- 🧰 **개발 자동화 툴** — 패킷/프로시저 코드 제너레이터(Python) 제공

---

## 🏗️ 시스템 전체 구조

**아키텍처 구성**
- **ServerService / Listener / Session** : 서비스 생명주기, AcceptEx 기반 연결 수립, 세션별 송·수신 담당  
- **IocpCore / Dispatch Loop** : 워커 스레드가 `IocpCore::Dispatch()`를 반복 수행하며 I/O 완료 통지 처리  
- **Packet 파이프라인** : `ClientPacketHandler`의 핸들러 테이블이 패킷 ID → 타입 처리 함수 매핑  
- **게임 도메인** : `GameSession/Manager`, `Room`, `Player`로 세션/룸/브로드캐스트 로직 구성  
- **DB 레이어** : `DBConnectionPool`, `DBBind`, `DBSynchronizer` 등으로 연결 풀·바인딩·스키마 동기화 수행

---

## ⚙️ 네트워킹 & 스레드 모델

**워커 루프 동작**
- `IocpCore->Dispatch(10)`으로 I/O 완료 처리  
- `ThreadManager::DistributeReserveJobs()`로 예약 잡 분배  
- `ThreadManager::DoGlobalQueueWork()`로 전역 큐 작업 수행  

스레드는 `ThreadManager->Launch()`로 다수 생성되며,  
메인 스레드는 주기적으로 서버 → 클라이언트 채팅 패킷을 브로드캐스트합니다.

---

## 💬 패킷 프로토콜

**패킷 ID 예시**

| 이름 | ID | 설명 |
|------|----|------|
| `C_LOGIN` | 1000 | 클라이언트 로그인 요청 |
| `S_LOGIN` | 1001 | 서버 로그인 응답 |
| `C_ENTER_GAME` | 1002 | 게임 입장 요청 |
| `S_ENTER_GAME` | 1003 | 게임 입장 응답 |
| `C_CHAT` | 1004 | 채팅 요청 |
| `S_CHAT` | 1005 | 채팅 브로드캐스트 |

> `ClientPacketHandler::Init()`에서 패킷 ID → 핸들러 람다를 등록합니다.  
> 템플릿 `HandlePacket<T>`를 통해 ProtoBuf 역직렬화 후 타입 안전 핸들러 호출을 수행합니다.

---

## 🧍 게임 도메인 (세션/룸/플레이어)

- **GameSession** : 접속/해제/수신 이벤트 오버라이드.  
  해제 시 `Room::Leave()` 호출 등 리소스 정리 로직 포함  
- **GameSessionManager** : 세션 등록/해제, 전체 브로드캐스트 기능 제공  
- **Room** : `Enter()`, `Leave()`, `Broadcast()` 로 룸 단위 메시지 전파 처리  
- **Player** : `playerId`, `name`, `ownerSession` 등 주요 속성 보유

---

## 🗄️ 데이터베이스 계층

- **연결** : `ODBC Driver 17 for SQL Server`  
  예제 → `Server=(localdb)\MSSQLLocalDB; Database=ServerDB`
- 서버 부팅 시 풀 연결 후,  
  `DBSynchronizer.Synchronize(L"GameDB.xml")` 실행으로 **스키마 최신화**
- **SP 래퍼 코드 생성** :  
  `SP::InsertGold`, `SP::GetGold` 등 **타입 안전 호출** 가능
- **구성요소** :  
  `DBConnection/Pool`, `DBBind`, `DBModel`, `DBSynchronizer`, `XmlParser(RapidXML)`

---

## 🧰 개발 자동화 도구

- **PacketGenerator (Python)**  
  `.proto` 및 템플릿 기반으로 핸들러/보일러플레이트 코드 자동 생성  
- **ProcedureGenerator (Python)**  
  `GameDB.xml` 기반으로 `GenProcedures.h` 등 SP 래퍼 자동 재생성  
  *(각 폴더에 `MakeExe.bat`, 템플릿, 빌드 스크립트 포함)*

---

## 🧱 빌드 & 실행

### 요구사항
- Windows 10/11 + Visual Studio 2019/2022  
- C++17 이상  
- SQL Server(LocalDB 또는 인스턴스)  
- ODBC Driver 17 for SQL Server  
- Google Protobuf 헤더/런타임 포함

### 빌드 절차
1. 저장소 클론 후  
   `Server/GameServer.vcxproj` 또는 `Server/DummyClient/DummyClient.vcxproj` 열기  
2. 프로젝트 속성에서 `Common/`, `Libraries/Include/` 경로 추가  
3. x64 `Release` 또는 `Debug`로 빌드

### 데이터베이스 설정
- `GameServer.cpp`의 연결 문자열을 환경에 맞게 변경  
- 첫 실행 시 `DBSynchronizer.Synchronize(L"GameDB.xml")` 호출로  
  스키마 및 프로시저 자동 동기화 수행

---

## 🛠️ 안정성/성능 설계 포인트

- ⚡ IOCP + 멀티워커로 고성능 비동기 I/O 처리  
- 🔁 전역 큐 / 잡 시스템으로 게임 로직의 안전한 스레드 간 전파 및 예약 실행  
- 🧩 `DeadLockProfiler`, `ConsoleLog` 등 코어 유틸을 통한 디버깅 용이성 확보  
- 🧠 모듈화된 설계로 유지보수성과 확장성 강화  

---

## 📚 출처
**Inflearn** — [Rookiss | C++과 언리얼로 만드는 MMORPG 게임 개발 시리즈]  
**Part 4: 게임 서버**

🔗 https://www.inflearn.com/course/%EC%96%B8%EB%A6%AC%EC%96%BC-3d-mmorpg-4
