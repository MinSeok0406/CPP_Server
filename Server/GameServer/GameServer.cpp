#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ClientPacketHandler.h"
#include <tchar.h>
#include "Protocol.pb.h"
#include "Job.h"
#include "Room.h"
#include "DBConnectionPool.h"
#include "DBBind.h"
#include "XmlParser.h"
#include "DBSynchronizer.h"
#include "GenProcedures.h"

// 수동 직렬화 방식과 비교할 때, Google Protocol Buffers를 사용하는 중요한 장점
// -> 간단한 정의 파일로부터 직렬화/역직렬화 코드를 자동으로 생성
// 프로토콜 버퍼는 .proto 파일로 구조만 정의하면 필요한 코드를 자동으로 생성
// 수작업 대비 생산성과 편리성이 크게 향상

// 보안 원칙에 따르면, 서버가 클라이언트로부터 받은 패킷 데이터(예: 크기 검사)를 검증하는 것이 왜 중요
// -> 클라이언트에서 직접 받은 데이터는 절대 신뢰해서는 안 되기 때문
// 클라이언트에서 온 데이터는 위변조 가능성이 항상 존재하므로,
// 서버에서는 패킷 사이즈나 내용 등을 검증하여 신뢰할 수 없는 데이터를 걸러내야 한다.

enum
{
    WORKER_TICK = 64
};

void DoWorkerJob(ServerServiceRef& service)
{
    while (true)
    {
        LEndTickCount = ::GetTickCount64() + WORKER_TICK;

        // 네트워크 입출력 처리 -> 인게임 로직까지 (패킷 핸들러에 의해)
        service->GetIocpCore()->Dispatch(10);

        // 예약된 일감 처리
        // 워커 쓰레드들이 메인 로직으로 가서 일감을 처리하는 방식
        // 다 끝났으면 다시 워커 쓰레드 본인들의 일을 하러 감
        ThreadManager::DistributeReserveJobs();

        // 글로벌 큐
        ThreadManager::DoGlobalQueueWork();
    }
}

int main()
{
    ASSERT_CRASH(GDBConnectionPool->Connect(1, L"Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=ServerDB;Trusted_Connection=Yes;"));

    DBConnection* dbConn = GDBConnectionPool->Pop();
    DBSynchronizer dbSync(*dbConn);
    dbSync.Synchronize(L"GameDB.xml");

    {
        WCHAR name[] = L"Minseok";
        SP::InsertGold insertGold(*dbConn);
        insertGold.In_Gold(100);
        insertGold.In_Name(name);
        insertGold.In_CreateDate(TIMESTAMP_STRUCT{ 2024, 11, 17 });
        insertGold.Execute();
    }

    {
        SP::GetGold getGold(*dbConn);
        getGold.In_Gold(100);

        int32 id = 0;
        int32 gold = 0;
        WCHAR name[100];
        TIMESTAMP_STRUCT date;

        getGold.Out_Id(OUT id);
        getGold.Out_Gold(OUT gold);
        getGold.Out_Name(OUT name);
        getGold.Out_CreateDate(OUT date);

        getGold.Execute();

        while (getGold.Fetch())
        {
            GConsoleLogger->WriteStdOut(Color::BLUE,
                L"ID[%d] Gold[%d] Name[%s]\n", id, gold, name);
        }
    }
    
    ClientPacketHandler::Init();

    ServerServiceRef service = MakeShared<ServerService>(
        NetAddress(L"127.0.0.1", 7777),
        MakeShared<IocpCore>(),
        MakeShared<GameSession>,    // TODO : SessionManager 등
        100);

    ASSERT_CRASH(service->Start());

    for (int32 i = 0; i < 5; i++)
    {
        GThreadManager->Launch([&service]()
            {
                while (true)
                {
                    DoWorkerJob(service);
                }
            });
    }

    // Main Thread
    //DoWorkerJob(service);

    while (true)
    {
        Protocol::S_CHAT pkt;
        pkt.set_msg("Hello World(Server -> Client)");
        auto sendBuffer = ClientPacketHandler::MakeSendBuffer(pkt);

        GSessionManager.Broadcast(sendBuffer);
        this_thread::sleep_for(1s);
    }

    GThreadManager->Join();
}