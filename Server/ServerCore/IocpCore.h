#pragma once

// IOCP(Completion Port) ���� ��Ը� ���� ���� ������ ������ �ֿ� ����
// -> ���� ������ ���Ϸ� ���� Ȯ�强 ����
// IOCP�� �Ϸ�� �񵿱� I/O �۾����� �߾� ť���� �����ϸ�, �Ҽ��� ��Ŀ �����尡 �� ť�� �۾��� ȿ�������� ó��
// ������ ���ؽ�Ʈ ����Ī ���ϸ� �ٿ� ���� Ȯ�强�� ����

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

// ��Ʈ��ũ ���̺귯�� ���迡�� `IocpCore` Ŭ������ �ֵ� ����
// -> �񵿱� I/O �۾� �ϷḦ ȿ�������� �˸��� �����忡 �й�
// `IocpCore`�� �ü���� I/O �Ϸ� ��Ʈ �ڵ��� �����ϸ�,
// �񵿱� I/O �۾��� �Ϸ�� �� �̸� �����ϰ� ��� ���� ��Ŀ �����忡�� �Ϸ� �˸��� �����ϴ� �ٽ� ������ �Ѵ�.
// �̸� ���� ȿ������ �񵿱� �۾� ó���� ����


// IOCP�� ����ϴ� �񵿱� ���� �۾� �� ����Ʈ �����͸� �̿��� ���۷��� ī������ �߿��� ����
// -> �񵿱� �۾��� �Ϸ�Ǳ� ���� ���� ��ü�� �ı����� �ʵ��� �����ֱ⸦ �����ϱ� ���ؼ�
// �񵿱� I/O �۾��� �Լ� ȣ�� ���� ��� �Ϸ���� �ʰ� ��� ���¿� �ִٰ� ���߿� �Ϸ�
// �̶� �۾��� �ʿ��� ��ü(��: ����, �̺�Ʈ ��ü)�� �̸� �ı��Ǹ� ������ �߻��ϹǷ�, ���۷��� ī�������� ��ü�� �񵿱� �۾� �Ϸ� �������� ����
// �̴� �񵿱� ���α׷��ֿ��� �޸� �������� �����ϴ� �ٽ� ���

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
