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

	//稀疏矩阵的一般转置
	SparseMatrix<T> Transpose()
	{
		SparseMatrix<T> sm;
		sm._colSize = _rowSize;
		sm._rowSize = _colSize;
		sm._invalid = _invalid;

		// O(colSize*有效数据的个数)
		for (size_t i = 0; i < _colSize; ++i)
		{
			size_t index = 0;
			while (index < _array.size())
			{
				if (_array[index]._col == i)
				{
					Trituple<T> t;
					t._row = _array[index]._col;
					t._col = _array[index]._row;
					t._value = _array[index]._value;
					sm._array.push_back(t);
				}

				++index;
			}
		}

		return sm;
	}

	// O(有效数据个数+colsize)
	//稀疏矩阵快速转置
	SparseMatrix<T> FastTranspose()
	{
		SparseMatrix<T> sm;
		sm._colSize = _rowSize;   //装置后的列是前面的行
		sm._rowSize = _colSize;   //装置后的行是前面的列
		sm._invalid = _invalid;

		int* rowCounts = new int[_colSize];  //用来统计转置后矩阵每行有效数据个数，也就是
		                                     //转置前没列的有效数据个数，大小当然是列数
		int* rowStart = new int[_colSize];   //转置后的矩阵每行在压缩矩阵中的存储起始位置

		memset(rowCounts, 0, sizeof(int)*_colSize);
		memset(rowStart, 0, sizeof(int)*_colSize);   //初始化

		//统计行数据个数
		size_t index = 0;
		while (index < _array.size())
		{
			rowCounts[_array[index]._col]++;  //按转之前的列号统计，就是转置后的每行的数据个数
			++index;
		}

		//行开始位置
		rowStart[0] = 0;
		for (int i = 1; i < _colSize; ++i)
		{
			rowStart[i] = rowStart[i - 1] + rowCounts[i - 1];
		}

		// 借助rowStart定位转置后压缩存储的位置
		index = 0;
		sm._array.resize(_array.size());
		while (index < _array.size())
		{
			size_t begin = rowStart[_array[index]._col];
			Trituple<T> t;
			t._col = _array[index]._row;
			t._row = _array[index]._col;
			t._value = _array[index]._value;

			sm._array[begin] = t;

			++rowStart[_array[index]._col];
			++index;
		}

		delete[] rowCounts;
		delete[] rowStart;

		return sm;
	}


private:
	//Trituple* _array;	// 压缩存储
	//size_t _size;		// 稀疏矩阵的有效数据的个数

	vector<Trituple<T>> _array;   //Vector中装的是三元组
	size_t _rowSize;              //行大小
	size_t _colSize;              //列大小
	T _invalid;	                  //矩阵中非法元素
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

	SparseMatrix<int> sm2 = sm1.FastTranspose();
	sm2.Display();
}