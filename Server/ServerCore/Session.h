#pragma once
#include "IocpCore.h"
#include "IocpEvent.h"
#include "NetAddress.h"
#include "RecvBuffer.h"

class Service;

//--------------
//	 Session
//--------------

class Session : public IocpObject
{
	friend class Listener;
	friend class IocpCore;
	friend class Service;

	enum 
	{
		BUFFER_SIZE = 0x10000,	// 64KB
	};

public:
	Session();
	virtual ~Session();

public:
						/* �ܺο��� ��� */
	void				Send(SendBufferRef sendBuffer);		// ������ �۽� ��û�� ó���ϴ� �޼ҵ�
	bool				Connect();
	void				Disconnect(const WCHAR* cause);		// ���� ������ �����ϴ� �޼ҵ�

	shared_ptr<Service> GetService() { return _service.lock(); }
	void				SetService(shared_ptr<Service> service) { _service = service; }

public:
						/* ���� ���� */
	void				SetNetAddress(NetAddress address) { _netAddress = address; }
	NetAddress			GetAddress() { return _netAddress; }
	SOCKET				GetSocket() { return _socket; }
	bool				IsConnected() { return _connected; }
	SessionRef			GetSessionRef() { return static_pointer_cast<Session>(shared_from_this()); }

private:
						/* �������̽� ���� */
	virtual HANDLE		GetHandle() override;
	virtual void		Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;

private:
						/* ���� ���� */

	// Register�� ���ô븦 ������ ����
	bool				RegisterConnect();
	bool				RegisterDisconnect();
	void				RegisterRecv();			// ���� ��⸦ ����ϴ� �޼ҵ�
	void				RegisterSend();			// �۽� �����Ͱ� ���� ��� ���Ͽ� �񵿱�� �۽��� ����ϴ� �޼ҵ�

	// Process�� ���ô븦 �ٽ� �ø��� ����
	void				ProcessConnect();
	void				ProcessDisconnect();
	void				ProcessRecv(int32 numOfBytes);
	void				ProcessSend(int32 numOfBytes);

	void				HandleError(int32 errorCode);

protected:
						/* ������ �ڵ忡�� ������ */
	virtual void		OnConnected() { }									// ����Ǿ��� �� ȣ��Ǵ� �޼ҵ�
	virtual int32		OnRecv(BYTE* buffer, int32 len) { return len; }		// ������ ���� �� ȣ��Ǵ� �޼ҵ�
	virtual void		OnSend(int32 len) { }								// ������ �۽� �Ϸ� �� ȣ��Ǵ� �޼ҵ�
	virtual void		OnDisconnected() { }								// ���� ���� �� ȣ��Ǵ� �޼ҵ�

private:
	weak_ptr<Service>	_service;
	SOCKET				_socket = INVALID_SOCKET;	// ��Ʈ��ũ ��ſ� ���Ǵ� ����
	NetAddress			_netAddress = {};
	Atomic<bool>		_connected = false;

private:
	USE_LOCK;

							/* ���� ���� */
	RecvBuffer				_recvBuffer;

							/* �۽� ���� */
	Queue<SendBufferRef>	_sendQueue;
	Atomic<bool>			_sendRegistered = false;

private:
						/* IocpEvent ���� */
	ConnectEvent		_connectEvent;
	DisconnectEvent		_disconnectEvent;
	RecvEvent			_recvEvent;
	SendEvent			_sendEvent;
};


// `PacketSession` �������� ���ø����̼� ������ ��Ŷ ���(��: ũ�� + ID)�� ����ϴ� �ֵ� ���
// -> ������ ��Ʈ�� ������ ������ ��Ŷ�� ���۰� �� ��踦 �ĺ��ϰ� �� ������ �ľ��ϱ� ���ؼ�
// TCP�� ������ ��Ʈ���� �������� �����ϹǷ�, ���ŵ� ����Ʈ�� ���ӿ��� ���� �޽���(��Ŷ)�� �����ϱ� ���� ������ �ʿ�
// ��Ŷ ����� ũ�� ������ ��Ŷ�� ��ü ���̸� �˷��ְ�,
// ID�� �ش� ��Ŷ�� � ������ ������(��: �α��� ��û, �̵� ����)�� ��� �ִ��� �ĺ��Ͽ� �ùٸ� �ڵ鸵�� ����
// �̴� ����ȭ ������ �ذ��ϰ� ���ø����̼� ������ ��� ���������� �����ϴ� �ٽ�

//-----------------
//	 PacketSession
//-----------------

struct PacketHeader
{
	uint16 size;
	uint16 id;	// ��������ID
};

class PacketSession : public Session
{
public:
	PacketSession();
	virtual ~PacketSession();

	PacketSessionRef	GetPacketSessionRef() { return static_pointer_cast<PacketSession>(shared_from_this()); }

protected:
	virtual int32		OnRecv(BYTE* buffer, int32 len) sealed;
	virtual void		OnRecvPacket(BYTE* buffer, int32 len) abstract;
};