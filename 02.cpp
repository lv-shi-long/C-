
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <ctime>
#include <stdlib.h>
#include "SmartPointer.h"
#include <assert.h>
using namespace std;
int cnt[50];
//实现一个LRUCache 代码
class LRUCache {
public:
	LRUCache(int capacity) {
		has.reserve(capacity * 2);
		this->capacity = capacity;
	}

	int get(int key) {
		if (has.find(key) == has.end())
			return -1;
		else
		{
			int v = has[key]->second;
			cache.erase(has[key]);
			cache.push_front({ key, v });
			has[key] = cache.begin();
			return v;
		}
	}

	void put(int key, int value) {
		if (has.find(key) != has.end())
			cache.erase(has[key]);
		else if (cache.size() >= capacity)
		{
			cache.pop_back();
			has.erase(cache.back().first);
		}
		cache.push_front({ key, value });
		has[key] = cache.begin();
	}
private:
	int capacity;
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> has;
};
//随机选择算法
void knth1(int a[], int n, int m)
{
	//在n个整数中随机选取m个  数字。
	for (int i = 0; i < n; i++)
	{
		if (rand() % (n - i) < m)
		{
			cnt[a[i]]++;
			m--;
		}
	}
}
 //实现memcpy函数
void mymemcpy1(void* dst, const void* src, int num)
{
	assert(dst != NULL && src != NULL);
	char* pdst = (char *)dst;
	const char* psrc = (char*)src;
	if (pdst > psrc && pdst < psrc + num)
	{
		for (int i = num - 1; i != -1; i--)
		{
			pdst[i] = psrc[i];
		}
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			pdst[i] = psrc[i];
		}
	}
}
//mencpy函数改进优化
void mymemcpy2(void* dst, const void* src, size_t num)
{
	assert(dst != NULL && src != NULL);
	int* pintdst = (int*)dst;
	const int* pintsrc = (int*)src;
	int dword = num / 4;
	int slice = num % 4;
	while (dword--)
	{
		*pintdst++ = *pintsrc++;
	}
	char* pchardst = (char *)pintdst;
	const char *pcharsrc = (char*)pintsrc;
	while (slice--)
	{
		*pchardst++ = *pcharsrc++;
	}
}
//测试智能指针
void process(ProSmartPointer p)
{
	int a;
}
class A
{
public:

	A()
	{
		mi = 10;
		cout << "A()" << endl;

	}
	~A()
	{
		cout << "~A()" << endl;
	}
	int mi;
	virtual void print1()
	{
		cout << "A::print1" << endl;
	}
};

class B :public A
{
public:

	B()
	{
		mi = 10;
		cout << "B()" << endl;

	}
	~B()
	{
		cout << "~A()" << endl;
	}
	int mi;
	virtual void print1()
	{
		cout << "B::print1" << endl;
	}
};

int main()
{
	

	return 0;
}



