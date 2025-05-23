#pragma once
#include "Job.h"
#include "LockQueue.h"
#include "JobTimer.h"

// ����� ��û�� �Ϸᰡ ���� ���ÿ� �̷�����ų� �ϷḦ ��ٸ��� �ݸ�,
// �񵿱�� ��û �� ��� ��ȯ�Ǹ� �۾� �Ϸ�� ���߿� �̺�Ʈ�� �ݹ����� �����޴´�.

/*-----------------
*	JobQueue
------------------*/

// �۾�(��û)�� ��ü ���·� ĸ��ȭ�Ͽ� ó���ϴ� �� ť �ý����� ����� �Ǵ� ������ ������ ����
// -> Ŀ�ǵ� ����
// Ŀ�ǵ� ������ ��û ��ü�� ��ü�� ĸ��ȭ�Ͽ�,
// ��û�� ������ ��ü�� �޴� ��ü�� �и��ϰ� ��û�� ť�� �����ϰų� �α��ϴ� �� �پ��� ������� �ٷ� �� �ְ� �Ѵ�.
// �� ť�� �� ������ Ȱ���� ����


// MMO ���� ȯ�濡�� ���� ������ ������ ���� ���� ������ �ذ��ϱ� ���� �ܼ� ��ŷ ��� �� ť�� ����ϴ� �ֵ� ������ ����
// -> ���� �����尡 ���� �ڿ��� ȿ�������� �����ϰ� ���� ������ ���̱� ���ؼ�
// �� ť�� ���� �����尡 ��û(�۾�)�� ���������� ó���ϵ��� �Ͽ�,
// ���� �ڿ��� ���� �������� ���� ��ŷ ������ �ٿ� ���� ������ ��ȭ�ϴ� �� ������ �ش�.
// Ȯ�强 ���� ������ �ٽ� ���� �� �ϳ�

class JobQueue : public enable_shared_from_this<JobQueue>
{
public:
	void DoAsync(CallbackType&& callback)
	{
		Push(ObjectPool<Job>::MakeShared(std::move(callback)));
	}

	template<typename T, typename Ret, typename... Args>
	void DoAsync(Ret(T::* memFunc)(Args...), Args... args)
	{
		shared_ptr<T> owner = static_pointer_cast<T>(shared_from_this());
		Push(ObjectPool<Job>::MakeShared(owner, memFunc, std::forward<Args>(args)...));
	}

	void DoTimer(uint64 tickAfter, CallbackType&& callback)
	{
		JobRef job = ObjectPool<Job>::MakeShared(std::move(callback));
		GJobTimer->Reserve(tickAfter, shared_from_this(), job);
	}

	template<typename T, typename Ret, typename... Args>
	void DoTimer(uint64 tickAfter, Ret(T::* memFunc)(Args...), Args... args)
	{
		shared_ptr<T> owner = static_pointer_cast<T>(shared_from_this());
		JobRef job = ObjectPool<Job>::MakeShared(owner, memFunc, std::forward<Args>(args)...);
		GJobTimer->Reserve(tickAfter, shared_from_this(), job);
	}

	void			ClearJobs() { _jobs.Clear(); }

public:
	void			Push(JobRef job, bool pushOnly = false);
	void			Execute();

protected:
	LockQueue<JobRef>	_jobs;
	Atomic<int32>		_jobCount = 0;
};

