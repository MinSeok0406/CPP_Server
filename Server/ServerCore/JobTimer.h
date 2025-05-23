#pragma once

// C++에서 공유 포인터(shared_ptr)와 람다(lambda)를 함께 사용하여 작업을 캡슐화할 때
// 발생할 수 있는 주요 메모리 관리 문제와 이를 해결하기 위한 일반적인 방법
// -> 순환 참조로 인한 메모리 누수, 해결책: 약한 포인터(weak_ptr) 사용
// 객체가 자신을 가리키는 shared_ptr을 람다를 통해 캡처하고,
// 람다가 객체 내부의 멤버 함수를 호출할 때 순환 참조가 발생할 수 있다.
// 이 경우 shared_ptr의 참조 카운트가 0이 되지 않아 메모리 누수가 발생하며,
// 이를 해결하기 위해 weak_ptr을 사용해 참조 카운트 증가 없이 객체를 관찰

struct JobData
{
	JobData(weak_ptr<JobQueue> owner, JobRef job) : owner(owner), job(job)
	{

	}

	weak_ptr<JobQueue>	owner;
	JobRef				job;
};

struct TimerItem
{
	bool operator<(const TimerItem& other) const
	{
		return executeTick > other.executeTick;
	}

	uint64 executeTick = 0;
	JobData* jobData = nullptr;
};


/*-----------------
*	JobTimer
------------------*/

// MMO 서버에서 캐릭터의 스킬 쿨다운 종료나 몬스터의 특정 행동처럼, 정확히 '일정 시간 경과 후' 실행되어야 하는 작업을 관리하기 위한 시스템
// -> 잡 타이머 (Job Timer)
// 글로벌 큐(Global Queue)나 락 큐(Lock Queue)는 '지금' 작업을 비동기적으로 실행하거나 분배하는 데 사용
// 패킷 핸들러(Packet Handler)는 네트워크 데이터를 처리
// 잡 타이머는 미래의 특정 시점에 실행될 작업을 예약하고 관리하는 시스템으로, 서버에서 주기적이거나 지연된 처리에 필수적

class JobTimer
{
public:
	void			Reserve(uint64 tickAfter, weak_ptr<JobQueue> owner, JobRef job);
	void			Distribute(uint64 now);
	void			Clear();


private:
	USE_LOCK;
	PriorityQueue<TimerItem>	_items;
	Atomic<bool>				_distributing = false;
};

