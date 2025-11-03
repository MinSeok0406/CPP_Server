# GameServer: IOCP 기반 C++ MMO 채팅 서버

> **작성자**: 장민석

---

**개발 목적**  
- 고성능 Windows 네트워크 I/O 모델(IOCP)과 Google Protocol Buffers를 결합하여, 수천 명의 동시 클라이언트를 대상으로 안정적인 메시징/채팅을 처리하는 게임 서버입니다. 데이터 계층은 SQL Server(ODBC) 를 사용하며, XML 기반 DSL → DB 스키마/프로시저 자동 동기화와 코드 생성 도구(패킷/프로시저)를 갖춘 것이 특징

**주요 기능**  
- IOCP(Completion Port) 네트워킹: AcceptEx 기반 접속 처리, 다중 워커 스레드 디스패치, 세션 단위 패킷 처리
- ProtoBuf 패킷 프로토콜: .proto에서 자동 생성된 타입 안정 패킷 파이프라인과 핸들러 테이블
- DB 자동화(ODBC + XML DSL): DBSynchronizer가 GameDB.xml을 해석해 스키마/프로시저를 자동 동기화하고, GenProcedures.h로 안전한 SP 래퍼를 제공
- 멀티스레드 잡 시스템: 전역 큐, Job/JobQueue/JobTimer, DeadLockProfiler 등 코어 유틸리티를 포함
- 개발 자동화 툴: 패킷/프로시저 코드 제너레이터(Python) 제공

**아키텍처 개요** 
- ServerService / Listener / Session: 서비스 생명주기, AcceptEx 기반 연결 수립, 세션별 송수신 담당
- IocpCore/Dispatch Loop: 워커 쓰레드가 IocpCore::Dispatch()를 반복 수행하여 I/O 완료 통지를 처리
- Packet 파이프라인: ClientPacketHandler의 핸들러 테이블이 패킷 ID → 타입 처리 함수를 매핑
- 게임 도메인: GameSession/Manager, Room, Player로 세션/룸/브로드캐스트 로직 구성
- DB 레이어: DBConnectionPool, DBBind, DBSynchronizer 등으로 연결 풀·바인딩·스키마 동기화 수행

**네트워킹 & 스레드 모델** 
- 워커 루프: IocpCore->Dispatch(10)으로 I/O 완료 처리 → 예약 잡 분배 → 전역 큐 작업 수행.
스레드는 ThreadManager->Launch()로 다수 생성되며, 메인은 주기적으로 서버 → 클라이언트 채팅 패킷을 브로드캐스트

service->GetIocpCore()->Dispatch(10);
ThreadManager::DistributeReserveJobs();
ThreadManager::DoGlobalQueueWork();
...
Protocol::S_CHAT pkt;
auto sendBuffer = ClientPacketHandler::MakeSendBuffer(pkt);
GSessionManager.Broadcast(sendBuffer);

**패킷 프로토콜** 
- 패킷 ID (예시): C_LOGIN(1000), S_LOGIN(1001), C_ENTER_GAME(1002), S_ENTER_GAME(1003), C_CHAT(1004), S_CHAT(1005)
→ ClientPacketHandler::Init()에서 ID → 핸들러 람다를 등록

**게임 도메인 (세션/룸/플레이어)** 
- GameSession: 접속/해제/수신 이벤트 오버라이드. 해제 시 Room::Leave 호출 등 정리 로직 포함
- GameSessionManager: 세션 등록/해제, 전체 브로드캐스트 제공
- Room: Enter/Leave/Broadcast로 룸 단위 메시지 전파
- Player: playerId, name, ownerSession 등 보유

**데이터베이스 계층** 
- 연결: ODBC Driver 17 for SQL Server / LocalDB Server=(localdb)\MSSQLLocalDB; Database=ServerDB 예제
서버 부팅 시 풀 연결 → DBSynchronizer.Synchronize(L"GameDB.xml")로 스키마 최신화
- 코드 생성 SP 래퍼: SP::InsertGold, SP::GetGold 등 타입 안전 호출 예제가 포함되어 있음
- 구성요소: DBConnection/Pool, DBBind, DBModel, DBSynchronizer, XmlParser(RapidXML)

**개발 자동화 도구** 
- PacketGenerator (Python): .proto/템플릿을 바탕으로 핸들러/보일러플레이트를 생성
- ProcedureGenerator (Python): GameDB.xml 기반으로 GenProcedures.h 등 SP 래퍼를 재생성.
(각 폴더에 MakeExe.bat/프로젝트 파일과 템플릿 포함)

**빌드 & 실행**
- 요구사항
    Windows 10/11 + Visual Studio 2019/2022, C++17 이상
    SQL Server(LocalDB 또는 인스턴스) + ODBC Driver 17 for SQL Server
    Google Protobuf 런타임 소스/헤더 포함
- 빌드
    저장소 클론 후 Server/GameServer.vcxproj, Server/DummyClient/DummyClient.vcxproj를 Visual Studio에서 열어 빌드
    필요 시 프로젝트 Include/Additional Library 경로에 Common/Libraries/Include를 등록
- DB 준비
    GameServer.cpp의 연결 문자열을 환경에 맞게 갱신
    첫 실행 시 DBSynchronizer.Synchronize(L"GameDB.xml")가 스키마/프로시저를 자동 동기화

**안정성/성능 설계 포인트**
- IOCP + 멀티워커로 고성능 비동기 I/O 처리
- 전역 큐/잡 시스템으로 게임 로직 스레드 전파/예약 실행
- DeadLockProfiler/ConsoleLog 등 코어 유틸 탑재로 디버깅 용이성 확보

## 출처 : Inflearn [Rookiss][C++과 언리얼로 만드는 MMORPG 게임 개발 시리즈] Part4: 게임 서버
