#pragma once
#include <functional>

/*--------------
*	Job
--------------*/

// �½�ũ���� ������ Ŭ������ �����ߴ� 1���� ��İ� ������ ��, `std::function`�� ���ٸ� Ȱ���ϴ� 2���� �� ó�� ����� �ֿ� ������
// -> ���ο� �½�ũ�� �߰��� �� ������ Ŭ���� ������ �ٿ� �ڵ� ������ ����
// 1���� ����� �۾� �������� EnterTask, LeaveTask �� ���� Ŭ������ �ʿ�
// 2���� ����� `std::function`�� ���ٸ� ����Ͽ� �Լ��� ���ڸ� ĸ��ȭ��
// Ŭ���� ���� ���� �� �����ϰ� �۾��� �����ϰ� �߰��� �� �ְ� �Ѵ�.

using CallbackType = std::function<void()>;

class Job
{
public:
	Job(CallbackType&& callback) : _callback(std::move(callback))
	{

	}

	template<typename T, typename Ret, typename... Args>
	Job(shared_ptr<T> owner, Ret(T::* memFunc)(Args...), Args&&... args)
	{
		_callback = [owner, memFunc, args...]()
		{
			(owner.get()->*memFunc)(args...);
		};
	}

	void Execute()
	{
		_callback();
	}

private:
	CallbackType _callback;
};

