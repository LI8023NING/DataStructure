#ifndef _BIT_MAP_H
#define _BIT_MAP_H

#include<iostream>
#include<vector>
using namespace std;

/*
*һ������32λ��40�ڸ�������ÿ����������һλ��ʾ��40��λ������
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
		_array.resize((size>>5)+1);  //���ٸ����ݣ�һ������ռ32λ����һ������һ������
	}

	bool Set(size_t num)
	{
		size_t index = num >> 5;     //�������ĸ�������
		size_t n = num % 32;

		if (_array[index] & (1 << (31 - n)))   //��λ����
		{
			cout << "������" << endl;
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

	bool ReSet(size_t num)   //ɾ��һ���� ֮������
	{
		size_t index = num >> 5;
		size_t n = num % 32;

		if (_array[index] & (1 << (31 - n)))   //������ ɾ��
		{
			_array[index] &= (~(1 << (31 - n)));
			--_size;
			return true;
		}
		else
		{
			return false;  //�����������
		}
	}

private:
	vector<size_t> _array; //����
	size_t _size;          //λͼ�����ݸ���
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