#pragma once
#include <functional>

/*--------------
*	Job
--------------*/

// 태스크별로 별도의 클래스를 정의했던 1세대 방식과 비교했을 때, `std::function`과 람다를 활용하는 2세대 잡 처리 방식의 주요 개선점
// -> 새로운 태스크를 추가할 때 별도의 클래스 생성을 줄여 코드 관리가 용이
// 1세대 방식은 작업 종류마다 EnterTask, LeaveTask 등 별도 클래스가 필요
// 2세대 방식은 `std::function`과 람다를 사용하여 함수와 인자를 캡슐화함
// 클래스 생성 없이 더 유연하게 작업을 정의하고 추가할 수 있게 한다.

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

