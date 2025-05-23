#pragma once

// Overlapped 모델에서 비동기 I/O 완료를 통지받는 두 가지 주요 방법
// -> 이벤트 객체 시그널링과 콜백 함수 호출
// Overlapped 모델에서 비동기 작업 완료 통지는 이벤트 객체의 상태 변화를 감지하거나,
// 미리 등록해둔 콜백 함수(Completion Routine)가 호출되는 방식으로 이루어짐

// Overlapped 모델(콜백 기반) 사용 시, 운영체제가 완료 콜백 함수를 호출하기 위해 스레드는 어떤 상태
// -> Alertable Wait 상태
// 콜백 함수가 호출되려면 해당 스레드가 Alertable Wait 상태로 진입해야 한다.
// 운영체제는 이 상태의 스레드에게만 APC Queue에 쌓인 콜백 실행을 허용

class Session;

enum class EventType : uint8
{
	Connect,
	Disconnect,
	Accept,
	Recv,
	Send
};

//--------------
//	 IocpEvent
//--------------

class IocpEvent : public OVERLAPPED
{
public:
	IocpEvent(EventType type);

	void			Init();

public:
	EventType		eventType;
	IocpObjectRef	owner;
};

//------------------
//	 ConnectEvent
//------------------

class ConnectEvent : public IocpEvent
{
public:
	ConnectEvent() : IocpEvent(EventType::Connect) { }
};

//--------------------
//	 DisconnectEvent
//--------------------

class DisconnectEvent : public IocpEvent
{
public:
	DisconnectEvent() : IocpEvent(EventType::Disconnect) { }
};

//------------------
//	 AcceptEvent
//------------------
class AcceptEvent : public IocpEvent
{
public:
	AcceptEvent() : IocpEvent(EventType::Accept) { }

public:
	SessionRef session = nullptr;
};



//------------------
//	 RecvEvent
//------------------
class RecvEvent : public IocpEvent
{
public:
	RecvEvent() : IocpEvent(EventType::Recv) { }
};



//------------------
//	 SendEvent
//------------------
class SendEvent : public IocpEvent
{
public:
	SendEvent() : IocpEvent(EventType::Send) { }

	Vector<SendBufferRef> sendBuffers;
};