#pragma once

// C++���� ���� ������(shared_ptr)�� ����(lambda)�� �Բ� ����Ͽ� �۾��� ĸ��ȭ�� ��
// �߻��� �� �ִ� �ֿ� �޸� ���� ������ �̸� �ذ��ϱ� ���� �Ϲ����� ���
// -> ��ȯ ������ ���� �޸� ����, �ذ�å: ���� ������(weak_ptr) ���
// ��ü�� �ڽ��� ����Ű�� shared_ptr�� ���ٸ� ���� ĸó�ϰ�,
// ���ٰ� ��ü ������ ��� �Լ��� ȣ���� �� ��ȯ ������ �߻��� �� �ִ�.
// �� ��� shared_ptr�� ���� ī��Ʈ�� 0�� ���� �ʾ� �޸� ������ �߻��ϸ�,
// �̸� �ذ��ϱ� ���� weak_ptr�� ����� ���� ī��Ʈ ���� ���� ��ü�� ����

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

// MMO �������� ĳ������ ��ų ��ٿ� ���ᳪ ������ Ư�� �ൿó��, ��Ȯ�� '���� �ð� ��� ��' ����Ǿ�� �ϴ� �۾��� �����ϱ� ���� �ý���
// -> �� Ÿ�̸� (Job Timer)
// �۷ι� ť(Global Queue)�� �� ť(Lock Queue)�� '����' �۾��� �񵿱������� �����ϰų� �й��ϴ� �� ���
// ��Ŷ �ڵ鷯(Packet Handler)�� ��Ʈ��ũ �����͸� ó��
// �� Ÿ�̸Ӵ� �̷��� Ư�� ������ ����� �۾��� �����ϰ� �����ϴ� �ý�������, �������� �ֱ����̰ų� ������ ó���� �ʼ���

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

