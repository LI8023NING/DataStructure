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
}