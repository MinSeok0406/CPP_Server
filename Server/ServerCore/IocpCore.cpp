#include "pch.h"
#include "IocpCore.h"
#include "IocpEvent.h"

//--------------
//	 IocpCore
//--------------

// 하나의 거대한 큐에 소켓과 관찰 대상 객체들을 담아 놓는다.
// 그 소켓들을 배출했을 때 그 일감들을 받아서 일을 하는 쓰레드들을 워커 쓰레드라고 부른다.

IocpCore::IocpCore()
{
	// CreateIoCompletionPort는 거대한 큐를 만들 때 사용한다.
	_iocpHandle = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
	ASSERT_CRASH(_iocpHandle != INVALID_HANDLE_VALUE);
}

IocpCore::~IocpCore()
{
	::CloseHandle(_iocpHandle);
}

bool IocpCore::Register(IocpObjectRef iocpObject)
{
	// 등록할 대상들을 넣는다.
	return ::CreateIoCompletionPort(iocpObject->GetHandle(), _iocpHandle, 0, 0);
}

bool IocpCore::Dispatch(uint32 timeoutMs)
{
	DWORD numOfBytes = 0;
	ULONG_PTR key = 0;
	IocpEvent* iocpEvent = nullptr;

	// GetQueuedCompletionStatus가 무사히 통과되면 워커 쓰레드에게 일감을 디스패치 한다.
	if (::GetQueuedCompletionStatus(_iocpHandle, OUT &numOfBytes, OUT &key, OUT reinterpret_cast<LPOVERLAPPED*>(&iocpEvent), timeoutMs))
	{
		IocpObjectRef iocpObject = iocpEvent->owner;
		iocpObject->Dispatch(iocpEvent, numOfBytes);
	}
	else
	{
		int32 errCode = ::WSAGetLastError();
		switch (errCode)
		{
		case WAIT_TIMEOUT:
			return false;
		default:
			// TODO : 로그 찍기
			IocpObjectRef iocpObject = iocpEvent->owner;
			iocpObject->Dispatch(iocpEvent, numOfBytes);
			break;
		}
	}

	return true;
}
