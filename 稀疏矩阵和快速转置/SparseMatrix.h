//稀疏矩阵 三元组解决问题
#pragma once
#include<vector>
template<class T>

//结构体
struct Trituple
{
	int _row; //行号
	int _col; //列号
	T _value; //值
};

template<class T>
//稀疏矩阵
class SparseMatrix
{
public:	
	SparseMatrix()
		:_colSize(0) //行数
		,_rowSize(0) //列数
	{}

	SparseMatrix(T* a, size_t m, size_t n, const T& invalid)
		:_rowSize(m) //m行
		,_colSize(n) //n列
		,_invalid(invalid)
	{
		for (size_t i = 0; i < m; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (a[i*n+j] != invalid)  //invalid  是零就不保存  保存非零元素
				{
					Trituple<T> t;
					t._row = i;
					t._col = j;
					t._value = a[i*n+j];

					_array.push_back(t);  //push到vector中
				}
			}
		}
	}

	void Display()
	{
		size_t index = 0;
		for (size_t i = 0; i < _rowSize; ++i)
		{
			for (size_t j = 0; j < _colSize; ++j)
			{
				if (index < _array.size()
					&& _array[index]._row == i 
					&& _array[index]._col == j)
				{
					cout<<_array[index++]._value<<" ";
				}
				else
				{
					cout<<_invalid<<" ";
				}
			}

			cout<<endl;
		}

		cout<<endl;
	}

private:
	//Trituple* _array;	// 压缩存储
	//size_t _size;		// 稀疏矩阵的有效数据的个数

	vector<Trituple<T>> _array;   //Vector中装的是三元组
	size_t _rowSize;              //行大小
	size_t _colSize;              //列大小
	T _invalid;	                  //
};

void Test2()
{
	int a[6][5] =
	{
		{1,0,3,0,5},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{2,0,4,0,6},	
		{0,0,0,0,0},
		{0,0,0,0,0},
	};

	SparseMatrix<int> sm1((int*)a, 6, 5, 0);
	sm1.Display();
}