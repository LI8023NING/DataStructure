#ifndef _BIT_MAP_H
#define _BIT_MAP_H

#include<iostream>
#include<vector>
using namespace std;

/*
*一个数据32位，40亿个整数，每个整数需用一位表示，40亿位就完事
*/

class BitMap
{
public:
	BitMap()
		:_size(0)
	{}

	BitMap(size_t size)
		:_size(0)
	{
		_array.resize((size>>5)+1);  //多少个数据，一个数据占32位，加一是至少一个数据
	}

	bool Set(size_t num)
	{
		size_t index = num >> 5;     //计算在哪个数据上
		size_t n = num % 32;

		if (_array[index] & (1 << (31 - n)))   //移位问题
		{
			cout << "有数据" << endl;
			return false;
		}
		else
		{
			size_t a = 1 << (31 - n);
			_array[index] |= a;
			++_size;
			return true;
		}
	}

	bool ReSet(size_t num)   //删除一个数 之后重置
	{
		size_t index = num >> 5;
		size_t n = num % 32;

		if (_array[index] & (1 << (31 - n)))   //数存在 删除
		{
			_array[index] &= (~(1 << (31 - n)));
			--_size;
			return true;
		}
		else
		{
			return false;  //不存在这个数
		}
	}

private:
	vector<size_t> _array; //数组
	size_t _size;          //位图中数据个数
};

#endif


void Test()
{
	BitMap bm(65);

	for (int i = 0; i < 32; ++i)
	{
		bm.Set(i);
	}

	bm.ReSet(0);
}