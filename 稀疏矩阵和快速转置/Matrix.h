#pragma once
#include<vector>

//对称矩阵的压缩存储
template<class T>
class  SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t n)
		:_array(new T[n*(n+1)/2])     //n*(n+1)/2  对称矩阵的上三角最多元素公式
		, _n(n)
	{
		size_t index = 0;
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (i >= j)  //上三角
				{
					_array[index++] = a[i*n+j];
				}
				else
				{
					break;
				}
			}
		}
	}

	void Display()
	{
		for (size_t i = 0; i < _n; ++i)
		{
			for (size_t j = 0; j < _n; ++j)
			{
				if (i >= j)
					cout << _array[i*(i + 1) / 2 + j] << " ";
				else
					cout << _array[j*(j + 1) / 2 + i] << " ";
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
	T* _array;  //对称矩阵的一维数据存在
	size_t _n;   //对称矩阵行列数

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

	SymmetricMatrix<int> sy((int*)a,5);
	sy.Display();

}