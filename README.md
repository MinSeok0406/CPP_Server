# GameServer: IOCP 기반 C++ MMO 채팅 서버

> **작성자**: 장민석

---

## 1. 개요

**개발 목적**  
- 수천 명의 클라이언트를 처리할 수 있는 고성능 비동기 C++ 채팅 서버 구축

**주요 기능**  
- IOCP 기반 네트워크 처리  
- Google Protocol Buffers 기반 채팅  
- DB 연동 및 스키마 자동 동기화  
- Python 자동화 도구  

**사용 기술 요약**

| 분류       | 항목                        |
|------------|-----------------------------|
| 언어       | C++, Python                 |
| 프로토콜   | TCP, Protocol Buffers       |
| 데이터베이스 | SQL Server (ODBC)          |
| 동기화 도구 | RapidXML + XML 기반 DSL     |
| 라이브러리 | WinSock2, STL, ODBC         |
