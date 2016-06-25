#pragma once
#include<vector>

//�Գƾ����ѹ���洢
template<class T>
class  SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t n)
		:_array(new T[n*(n+1)/2])     //n*(n+1)/2  �Գƾ�������������Ԫ�ع�ʽ
		, _n(n)
	{
		size_t index = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				//if (i >= j)  //������
				//{
				//	_array[index++] = a[i*n+j];
				//}

				if (j >= i)    //������
				{
					_array[index++] = a[i*n+j];
				}
				else
				{
					continue;
				}
			}
		}
	}

	int fun(int num)
	{
		int res = 0;
		for (int i = 1; i <= num; i++)
		{
			res = res + i;
		}

		return res;
	}

	void Display()
	{
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				/*if (i >= j)
					cout << _array[i*(i + 1) / 2 + j] << " ";
					else
					cout << _array[j*(j + 1) / 2 + i] << " ";*/

				if (j >= i)
					cout << _array[i*_n+j-fun(i)] << " ";
				else
					cout << _array[j*_n+i-fun(j)] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	~SymmetricMatrix()
	{
		if (_array)
		{
			delete[] _array;
		}
	}

private:
	T* _array;  //�Գƾ����һά���ݴ���
	size_t _n;   //�Գƾ���������

};

void Test()
{
	int a[5][5] =
	{
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 },
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 },
	};

	SymmetricMatrix<int> sy((int*)a, 5);
	sy.Display();
}