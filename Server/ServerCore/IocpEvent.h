#pragma once

// Overlapped �𵨿��� �񵿱� I/O �ϷḦ �����޴� �� ���� �ֿ� ���
// -> �̺�Ʈ ��ü �ñ׳θ��� �ݹ� �Լ� ȣ��
// Overlapped �𵨿��� �񵿱� �۾� �Ϸ� ������ �̺�Ʈ ��ü�� ���� ��ȭ�� �����ϰų�,
// �̸� ����ص� �ݹ� �Լ�(Completion Routine)�� ȣ��Ǵ� ������� �̷����

// Overlapped ��(�ݹ� ���) ��� ��, �ü���� �Ϸ� �ݹ� �Լ��� ȣ���ϱ� ���� ������� � ����
// -> Alertable Wait ����
// �ݹ� �Լ��� ȣ��Ƿ��� �ش� �����尡 Alertable Wait ���·� �����ؾ� �Ѵ�.
// �ü���� �� ������ �����忡�Ը� APC Queue�� ���� �ݹ� ������ ���

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