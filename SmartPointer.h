#pragma once
class Object
{
public:
	int a, b;
};
class ProSmartPointer;
class counter
{

	friend class ProSmartPointer;
public:
	counter()
	{
		cnt = 0;
		ptr = nullptr;
	}
	counter(Object* p)
	{
		cnt = 1;
		ptr = p;
	}
	~counter()
	{
		delete ptr;
	}
private:
	int cnt;
	Object* ptr;
};
class LowSmartPointer
{
public:
	LowSmartPointer(Object* p)
	{
		ptr = p;
	}
	~LowSmartPointer()
	{
		delete ptr;
	}
private:
	Object* ptr;
};
class ProSmartPointer
{
public:
	ProSmartPointer(Object* p)
	{
		ptr_counter = new counter(p);
	}
	ProSmartPointer(const ProSmartPointer& other)
	{
		ptr_counter = other.ptr_counter;
		++ptr_counter->cnt;
	}
	ProSmartPointer& operator=(const ProSmartPointer& other)
	{
		++other.ptr_counter->cnt;
		--ptr_counter->cnt;
		if (ptr_counter->cnt == 0)
		{
			delete ptr_counter;
		}
		ptr_counter = other.ptr_counter;
	}
	~ProSmartPointer()
	{
		--ptr_counter->cnt;
		if (ptr_counter->cnt == 0)
		{
			delete ptr_counter;
		}
	}
private:
	counter* ptr_counter;
};


