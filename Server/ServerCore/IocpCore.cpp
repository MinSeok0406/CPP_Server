#include "pch.h"
#include "IocpCore.h"
#include "IocpEvent.h"

//--------------
//	 IocpCore
//--------------

// �ϳ��� �Ŵ��� ť�� ���ϰ� ���� ��� ��ü���� ��� ���´�.
// �� ���ϵ��� �������� �� �� �ϰ����� �޾Ƽ� ���� �ϴ� ��������� ��Ŀ �������� �θ���.

IocpCore::IocpCore()
{
	// CreateIoCompletionPort�� �Ŵ��� ť�� ���� �� ����Ѵ�.
	_iocpHandle = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
	ASSERT_CRASH(_iocpHandle != INVALID_HANDLE_VALUE);
}

IocpCore::~IocpCore()
{
	::CloseHandle(_iocpHandle);
}

bool IocpCore::Register(IocpObjectRef iocpObject)
{
	// ����� ������ �ִ´�.
	return ::CreateIoCompletionPort(iocpObject->GetHandle(), _iocpHandle, 0, 0);
}

bool IocpCore::Dispatch(uint32 timeoutMs)
{
	DWORD numOfBytes = 0;
	ULONG_PTR key = 0;
	IocpEvent* iocpEvent = nullptr;

	// GetQueuedCompletionStatus�� ������ ����Ǹ� ��Ŀ �����忡�� �ϰ��� ����ġ �Ѵ�.
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
			// TODO : �α� ���
			IocpObjectRef iocpObject = iocpEvent->owner;
			iocpObject->Dispatch(iocpEvent, numOfBytes);
			break;
		}
	}

	return true;
}
