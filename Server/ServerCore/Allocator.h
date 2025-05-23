#pragma once

// 메모리 풀링 또는 사용자 정의 할당자
// 사용자 정의 할당자나 풀링은 큰 메모리 블록을 미리 할당하고 내부적으로 관리하여 잦은 커널 호출을 피하고,
// 객체 크기별 관리를 통해 파편화를 줄인다.

//--------------------
//	BaseAllocator
//--------------------

class BaseAllocator
{
public:
	static void*	Alloc(int32 size);
	static void		Release(void* ptr);
};

//--------------------
//	StompAllocator
//--------------------

// Stomp Allocator가 Use-After-Free와 같은 메모리 오류를 잘 찾아내는 핵심적인 이유는 무엇일까?
// Stomp Allocator는 VirtualAlloc/VirtualFree를 이용해
// 메모리 페이지를 OS에 즉시 반환하거나 보호하여 Use-After-Free 같은 잘못된 접근 시 즉시 크래시를 발생시켜 오류를 찾기 쉽다.
class StompAllocator
{
	enum { PAGE_SIZE = 0x1000 };

public:
	static void*	Alloc(int32 size);
	static void		Release(void* ptr);
};

//--------------------
//	PoolAllocator
//--------------------

class PoolAllocator
{
public:
	static void*	Alloc(int32 size);
	static void		Release(void* ptr);
};

//--------------------
//	 STL Allocator
//--------------------

template<typename T>
class StlAllocator
{
public:
	using value_type = T;

	StlAllocator() { }

	template<typename Other>
	StlAllocator(const StlAllocator<Other>&) { }

	T* allocate(size_t count)
	{
		const int32 size = static_cast<int32>(count * sizeof(T));
		return static_cast<T*>(PoolAllocator::Alloc(size));
	}

	void deallocate(T* ptr, size_t count)
	{
		PoolAllocator::Release(ptr);
	}
};