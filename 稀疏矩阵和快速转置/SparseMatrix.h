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

	//ϵ�������һ��ת��
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

private:
	//Trituple* _array;	// ѹ���洢
	//size_t _size;		// ϡ��������Ч���ݵĸ���

	vector<Trituple<T>> _array;   //Vector��װ������Ԫ��
	size_t _rowSize;              //�д�С
	size_t _colSize;              //�д�С
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

	SparseMatrix<int> sm2 = sm1.Transpose();
	sm2.Display();
}