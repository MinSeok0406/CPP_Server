#pragma once

// IOCP(Completion Port) 모델이 대규모 동시 접속 서버에 적합한 주요 이점
// -> 낮은 스레드 부하로 높은 확장성 제공
// IOCP는 완료된 비동기 I/O 작업들을 중앙 큐에서 관리하며, 소수의 워커 스레드가 이 큐의 작업을 효율적으로 처리
// 스레드 컨텍스트 스위칭 부하를 줄여 높은 확장성을 제공

//--------------
//	 IocpObject
//--------------

class IocpObject : public enable_shared_from_this<IocpObject>
{
public:
	virtual HANDLE GetHandle() abstract;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) abstract;
};

//--------------
//	 IocpCore
//--------------

// 네트워크 라이브러리 설계에서 `IocpCore` 클래스의 주된 역할
// -> 비동기 I/O 작업 완료를 효율적으로 알리고 스레드에 분배
// `IocpCore`는 운영체제의 I/O 완료 포트 핸들을 관리하며,
// 비동기 I/O 작업이 완료될 때 이를 감지하고 대기 중인 워커 스레드에게 완료 알림을 전달하는 핵심 역할을 한다.
// 이를 통해 효율적인 비동기 작업 처리가 가능


// IOCP를 사용하는 비동기 소켓 작업 시 스마트 포인터를 이용한 레퍼런스 카운팅이 중요한 이유
// -> 비동기 작업이 완료되기 전에 관련 객체가 파괴되지 않도록 생명주기를 관리하기 위해서
// 비동기 I/O 작업은 함수 호출 직후 즉시 완료되지 않고 대기 상태에 있다가 나중에 완료
// 이때 작업에 필요한 객체(예: 세션, 이벤트 객체)가 미리 파괴되면 문제가 발생하므로, 레퍼런스 카운팅으로 객체가 비동기 작업 완료 시점까지 유지
// 이는 비동기 프로그래밍에서 메모리 안정성을 보장하는 핵심 기법

class IocpCore
{
public:
	IocpCore();
	~IocpCore();

	HANDLE		GetHandle() { return _iocpHandle; }

	bool		Register(IocpObjectRef iocpObject);
	bool		Dispatch(uint32 timeoutMs = INFINITE);

private:
	HANDLE		_iocpHandle;
};
