#pragma once

// �޸� Ǯ�� �Ǵ� ����� ���� �Ҵ���
// ����� ���� �Ҵ��ڳ� Ǯ���� ū �޸� ����� �̸� �Ҵ��ϰ� ���������� �����Ͽ� ���� Ŀ�� ȣ���� ���ϰ�,
// ��ü ũ�⺰ ������ ���� ����ȭ�� ���δ�.

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

// Stomp Allocator�� Use-After-Free�� ���� �޸� ������ �� ã�Ƴ��� �ٽ����� ������ �����ϱ�?
// Stomp Allocator�� VirtualAlloc/VirtualFree�� �̿���
// �޸� �������� OS�� ��� ��ȯ�ϰų� ��ȣ�Ͽ� Use-After-Free ���� �߸��� ���� �� ��� ũ���ø� �߻����� ������ ã�� ����.
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