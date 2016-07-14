#pragma once

#include"BitMap.h"
#include"HashFun.h"

template<class T>
struct __HashFun1          //5种哈希函数对应的仿函数
{
	size_t operator()(const T& key)
	{
		return BKDRHash<T>(key.c_str());
	}
};

template<class T>
struct __HashFun2
{
	size_t operator()(const T& key)
	{
		return SDBMHash<T>(key.c_str());
	}
};

template<class T>
struct __HashFun3
{
	size_t operator()(const T& key)
	{
		return RSHash<T>(key.c_str());
	}
};

template<class T>
struct __HashFun4
{
	size_t operator()(const T& key)
	{
		return APHash<T>(key.c_str());
	}
};

template<class T>
struct __HashFun5
{
	size_t operator()(const T& key)
	{
		return JSHash<T>(key.c_str());
	}
};


template<class K = string,
class HashFun1 = __HashFun1<K>,
class HashFun2 = __HashFun2<K>,
class HashFun3 = __HashFun3<K>,
class HashFun4 = __HashFun4<K>,
class HashFun5 = __HashFun5<K>>
class Bloom_Filter
{
public:
	Bloom_Filter(size_t size)
		:_capacity(size)
	{
		_bitmap._array.resize((size >> 5) + 1);
	}

	void _Set(const K& key)
	{
		_bitmap.Set(HashFun1()(key) % _capacity);
		_bitmap.Set(HashFun2()(key) % _capacity);
		_bitmap.Set(HashFun3()(key) % _capacity);
		_bitmap.Set(HashFun4()(key) % _capacity);
		_bitmap.Set(HashFun5()(key) % _capacity);
	}

	bool _IsIn(const K& key)
	{
		if (!_bitmap.Test(HashFun1()(key) % _capacity))
			return false;
		if (!_bitmap.Test(HashFun1()(key) % _capacity))
			return false;
		if (!_bitmap.Test(HashFun1()(key) % _capacity))
			return false;
		if (!_bitmap.Test(HashFun1()(key) % _capacity))
			return false;
		if (!_bitmap.Test(HashFun1()(key) % _capacity))
			return false;
		return true;
	}
private:
	BitMap _bitmap;
	size_t _capacity;
};
