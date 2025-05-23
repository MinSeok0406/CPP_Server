#pragma once


/*----------------
	RecvBuffer
----------------*/

// TCP의 특성인 데이터 단편화(Fragmentation)가 수신된 데이터 처리 과정에 일으키는 근본적인 문제
// -> 논리적인 하나의 완전한 패킷이 여러 개의 조각으로 나뉘어 도착할 수 있다.
// TCP는 데이터 스트림을 보장하지만, 전송 효율성을 위해 애플리케이션에서 보낸
// 하나의 논리적 메시지(패킷)가 물리적으로 여러 개의 작은 조각으로 나뉘어 전송될 수 있다.
// 수신 측에서는 이 조각들을 모아 완전한 패킷으로 재구성해야만 의미 있는 처리를 할 수 있으며,
// `ReceiveBuffer` 같은 클래스가 이 역할을 돕는다.

class RecvBuffer
{
	enum { BUFFER_COUNT = 10 };

public:
	RecvBuffer(int32 bufferSize);
	~RecvBuffer();

	void			Clean();
	bool			OnRead(int32 numOfBytes);
	bool			OnWrite(int32 numOfBytes);

	BYTE*			ReadPos() { return &_buffer[_readPos]; }
	BYTE*			WritePos() { return &_buffer[_writePos]; }
	int32			DataSize() { return _writePos - _readPos; }
	int32			FreeSize() { return _capacity - _writePos; }

private:
	int32			_capacity = 0;
	int32			_bufferSize = 0;
	int32			_readPos = 0;
	int32			_writePos = 0;
	Vector<BYTE>	_buffer;

};

