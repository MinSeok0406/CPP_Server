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
						/* 외부에서 사용 */
	void				Send(SendBufferRef sendBuffer);		// 데이터 송신 요청을 처리하는 메소드
	bool				Connect();
	void				Disconnect(const WCHAR* cause);		// 소켓 연결을 해제하는 메소드

	shared_ptr<Service> GetService() { return _service.lock(); }
	void				SetService(shared_ptr<Service> service) { _service = service; }

public:
						/* 정보 관련 */
	void				SetNetAddress(NetAddress address) { _netAddress = address; }
	NetAddress			GetAddress() { return _netAddress; }
	SOCKET				GetSocket() { return _socket; }
	bool				IsConnected() { return _connected; }
	SessionRef			GetSessionRef() { return static_pointer_cast<Session>(shared_from_this()); }

private:
						/* 인터페이스 구현 */
	virtual HANDLE		GetHandle() override;
	virtual void		Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;

private:
						/* 전송 관련 */

	// Register는 낚시대를 던지는 행위
	bool				RegisterConnect();
	bool				RegisterDisconnect();
	void				RegisterRecv();			// 수신 대기를 등록하는 메소드
	void				RegisterSend();			// 송신 데이터가 있을 경우 소켓에 비동기로 송신을 등록하는 메소드

	// Process는 낚시대를 다시 올리는 행위
	void				ProcessConnect();
	void				ProcessDisconnect();
	void				ProcessRecv(int32 numOfBytes);
	void				ProcessSend(int32 numOfBytes);

	void				HandleError(int32 errorCode);

protected:
						/* 컨텐츠 코드에서 재정의 */
	virtual void		OnConnected() { }									// 연결되었을 때 호출되는 메소드
	virtual int32		OnRecv(BYTE* buffer, int32 len) { return len; }		// 데이터 수신 시 호출되는 메소드
	virtual void		OnSend(int32 len) { }								// 데이터 송신 완료 시 호출되는 메소드
	virtual void		OnDisconnected() { }								// 연결 해제 시 호출되는 메소드

private:
	weak_ptr<Service>	_service;
	SOCKET				_socket = INVALID_SOCKET;	// 네트워크 통신에 사용되는 소켓
	NetAddress			_netAddress = {};
	Atomic<bool>		_connected = false;

private:
	USE_LOCK;

							/* 수신 관련 */
	RecvBuffer				_recvBuffer;

							/* 송신 관련 */
	Queue<SendBufferRef>	_sendQueue;
	Atomic<bool>			_sendRegistered = false;

private:
						/* IocpEvent 재사용 */
	ConnectEvent		_connectEvent;
	DisconnectEvent		_disconnectEvent;
	RecvEvent			_recvEvent;
	SendEvent			_sendEvent;
};


// `PacketSession` 구조에서 애플리케이션 레벨의 패킷 헤더(예: 크기 + ID)를 사용하는 주된 기능
// -> 데이터 스트림 내에서 논리적인 패킷의 시작과 끝 경계를 식별하고 그 내용을 파악하기 위해서
// TCP가 데이터 스트림을 조각내어 전송하므로, 수신된 바이트의 연속에서 개별 메시지(패킷)를 구분하기 위한 기준이 필요
// 패킷 헤더의 크기 정보는 패킷의 전체 길이를 알려주고,
// ID는 해당 패킷이 어떤 종류의 데이터(예: 로그인 요청, 이동 정보)를 담고 있는지 식별하여 올바른 핸들링이 가능
// 이는 단편화 문제를 해결하고 애플리케이션 레벨의 통신 프로토콜을 구축하는 핵심

//-----------------
//	 PacketSession
//-----------------

struct PacketHeader
{
	uint16 size;
	uint16 id;	// 프로토콜ID
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