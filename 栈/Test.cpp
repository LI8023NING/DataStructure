#include"Stack.h"

template<class T>
Stack<T>::Stack()
		:_array(new T[SIZE])
		,_size(0)
		,_capacity(SIZE)	
	{}

template<class T>
Stack<T>::~Stack()
	{
		if(_array)
		{
			delete _array;
		}
	}

//��ǳ��������
template<class T>
Stack<T>::Stack(const Stack<T>& d)
	:_size(d._size)
	,_capacity(d._capacity)
	{
		_deep_copy(d);
	}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& d)
	{
		if(this != &d)
		{
			_size = d._size;
			_capacity = d._capacity;
			_deep_copy(d);
		}
		return *this;
	}

template<class T>
void Stack<T>::_deep_copy(const Stack<T>& p)
{
	_array = new T[p._capacity];
	for (int i = 0; i < _size; i++)
	{
		_array[i] = p._array[i];
	}
}

template<class T>
void Stack<T>::Push(const T& x) //��ջ
	{
		_CheckCapacity();
		_array[_size] = x;
		_size++;
	}

template<class T>
void Stack<T>::_CheckCapacity()
{
	if(_size+1 > _capacity)
	{
		_capacity  = _capacity*2 + 3;
		T* tmp = new T[_capacity];
		for(int i = 0; i < _size; i++)
		{
			tmp[i] = _array[i];
		}
		delete[] _array;
		_array = tmp;
	}
	else
	{
		return;
	}
}


template<class T>
void Stack<T>::Pop()            //��ջ
	{
		if(_size >= 0)
		{
			_size--;
			cout<<_array[_size]<<endl;
		}
		else
	{
		cout<<"kong"<<endl;
	}
}
template<class T>
bool Stack<T>::Empty()         //��ջ
	{
		if(_size == 0)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}

template<class T>
size_t Stack<T>::Size()        //��С
	{
		return _size;
	}

template<class T>
T& Stack<T>::Top()           //ȡջ��Ԫ��
	{
		return _array[_size];
	}

void Test()
{
	Stack<int> s1;
	Stack<int> s2(s1);
	Stack<int> s3;
	s2 = s3;
	for(int i = 0; i < 100;i++)
	{
		s3.Push(i);
	}
	cout<<"ջ��С"<<s3.Size()<<endl;
	for(int i = 0; i < 100;i++)
	{
		s3.Pop();
	}
	cout<<"�ж�ջ��"<<s3.Empty()<<endl;
	


}

int main()
{
	Test();
	return 0;
}