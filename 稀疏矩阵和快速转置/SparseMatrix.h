//ϡ����� ��Ԫ��������
#pragma once
#include<vector>
template<class T>

//�ṹ��
struct Trituple
{
	int _row; //�к�
	int _col; //�к�
	T _value; //ֵ
};

template<class T>
//ϡ�����
class SparseMatrix
{
public:	
	SparseMatrix()
		:_colSize(0) //����
		,_rowSize(0) //����
	{}

	SparseMatrix(T* a, size_t m, size_t n, const T& invalid)
		:_rowSize(m) //m��
		,_colSize(n) //n��
		,_invalid(invalid)
	{
		for (size_t i = 0; i < m; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (a[i*n+j] != invalid)  //invalid  ����Ͳ�����  �������Ԫ��
				{
					Trituple<T> t;
					t._row = i;
					t._col = j;
					t._value = a[i*n+j];

					_array.push_back(t);  //push��vector��
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

	//ϡ������һ��ת��
	SparseMatrix<T> Transpose()
	{
		SparseMatrix<T> sm;
		sm._colSize = _rowSize;
		sm._rowSize = _colSize;
		sm._invalid = _invalid;

		// O(colSize*��Ч���ݵĸ���)
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

	// O(��Ч���ݸ���+colsize)
	//ϡ��������ת��
	SparseMatrix<T> FastTranspose()
	{
		SparseMatrix<T> sm;
		sm._colSize = _rowSize;   //װ�ú������ǰ�����
		sm._rowSize = _colSize;   //װ�ú������ǰ�����
		sm._invalid = _invalid;

		int* rowCounts = new int[_colSize];  //����ͳ��ת�ú����ÿ����Ч���ݸ�����Ҳ����
		                                     //ת��ǰû�е���Ч���ݸ�������С��Ȼ������
		int* rowStart = new int[_colSize];   //ת�ú�ľ���ÿ����ѹ�������еĴ洢��ʼλ��

		memset(rowCounts, 0, sizeof(int)*_colSize);
		memset(rowStart, 0, sizeof(int)*_colSize);   //��ʼ��

		//ͳ�������ݸ���
		size_t index = 0;
		while (index < _array.size())
		{
			rowCounts[_array[index]._col]++;  //��ת֮ǰ���к�ͳ�ƣ�����ת�ú��ÿ�е����ݸ���
			++index;
		}

		//�п�ʼλ��
		rowStart[0] = 0;
		for (int i = 1; i < _colSize; ++i)
		{
			rowStart[i] = rowStart[i - 1] + rowCounts[i - 1];
		}

		// ����rowStart��λת�ú�ѹ���洢��λ��
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
	//Trituple* _array;	// ѹ���洢
	//size_t _size;		// ϡ��������Ч���ݵĸ���

	vector<Trituple<T>> _array;   //Vector��װ������Ԫ��
	size_t _rowSize;              //�д�С
	size_t _colSize;              //�д�С
	T _invalid;	                  //�����зǷ�Ԫ��
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