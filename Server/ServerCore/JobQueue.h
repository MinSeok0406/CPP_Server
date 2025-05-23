#pragma once
#include "Job.h"
#include "LockQueue.h"
#include "JobTimer.h"

// 동기는 요청과 완료가 거의 동시에 이루어지거나 완료를 기다리는 반면,
// 비동기는 요청 후 즉시 반환되며 작업 완료는 나중에 이벤트나 콜백으로 통지받는다.

/*-----------------
*	JobQueue
------------------*/

// 작업(요청)을 객체 형태로 캡슐화하여 처리하는 잡 큐 시스템의 기반이 되는 디자인 패턴은 무엇
// -> 커맨드 패턴
// 커맨드 패턴은 요청 자체를 객체로 캡슐화하여,
// 요청을 보내는 객체와 받는 객체를 분리하고 요청을 큐에 저장하거나 로깅하는 등 다양한 방식으로 다룰 수 있게 한다.
// 잡 큐는 이 패턴을 활용한 예시


// MMO 서버 환경에서 동시 접속자 증가에 따른 성능 문제를 해결하기 위해 단순 락킹 대신 잡 큐를 사용하는 주된 이유는 무엇
// -> 여러 스레드가 공유 자원에 효율적으로 접근하고 병목 현상을 줄이기 위해서
// 잡 큐는 여러 스레드가 요청(작업)을 순차적으로 처리하도록 하여,
// 공유 자원에 대한 직접적인 잦은 락킹 경쟁을 줄여 성능 병목을 완화하는 데 도움을 준다.
// 확장성 높은 서버의 핵심 개념 중 하나

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

