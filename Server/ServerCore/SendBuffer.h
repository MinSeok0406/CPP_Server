#pragma once

// SendBuffer` 풀링(Pooling) 기법(SendBufferChunk, SendBufferManager, TLS 활용)을 구현하는 주된 목적
// -> SendBuffer 생성 및 메모리 할당 비용을 최적화하고 스레드 경쟁을 줄이기 위해서
// 데이터를 전송할 때마다 `SendBuffer`를 새로 생성하고 메모리를 할당하는 것은 성능 비용이 발생
// 풀링 기법은 미리 큰 메모리 덩어리를 확보하고 필요할 때마다 그 일부를 재사용함으로써 동적 할당 부하를 줄인다.
// TLS 활용은 스레드별로 버퍼를 관리하여 락 경쟁을 최소화하는 데 기여

class SendBufferChunk;

/*----------------
	SendBuffer
----------------*/

class SendBuffer
{
public:
	SendBuffer(SendBufferChunkRef owner, BYTE* buffer, uint32 allocSize);
	~SendBuffer();

	BYTE*		Buffer() { return _buffer; }
	uint32		AllocSize() { return _allocSize; }
	uint32		WriteSize() { return _writeSize; }
	void		Close(uint32 writeSize);

private:
	BYTE*				_buffer;
	uint32				_allocSize = 0;
	uint32				_writeSize = 0;
	SendBufferChunkRef	_owner;
};

/*--------------------
	SendBufferChunk
---------------------*/

class SendBufferChunk : public enable_shared_from_this<SendBufferChunk>
{
	enum 
	{
		SEND_BUFFER_CHUNK_SIZE = 6000
	};

public:
	SendBufferChunk();
	~SendBufferChunk();

	void			Reset();
	SendBufferRef	Open(uint32 allocSize);
	void			Close(uint32 writeSize);

	bool			IsOpen() { return _open; }
	BYTE*			Buffer() { return &_buffer[_usedSize]; }
	uint32			FreeSize() { return static_cast<uint32>(_buffer.size()) - _usedSize; }

private:
	Array<BYTE, SEND_BUFFER_CHUNK_SIZE>		_buffer = {};
	bool									_open = false;
	uint32									_usedSize = 0;
};


/*--------------------
	SendBufferManager
---------------------*/

class SendBufferManager
{
public:
	SendBufferRef		Open(uint32 size);

private:
	SendBufferChunkRef	Pop();
	void				Push(SendBufferChunkRef buffer);

	static void			PushGlobal(SendBufferChunk* buffer);

private:
	USE_LOCK;
	Vector<SendBufferChunkRef> _sendBufferChunks;
};