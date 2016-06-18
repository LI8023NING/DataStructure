#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

const int SIZE = 2;
template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	//深浅拷贝问题
	Stack(const Stack<T>& d);
	Stack<T>& operator=(const Stack<T>& d);
public:
	void Push(const T& x); //入栈
	bool Empty();         //空栈
	size_t Size();        //大小
	void Pop();           
	T& Top();             //取栈顶元素
	void Display();
private:
	void _CheckCapacity();
	void _deep_copy(const Stack& p);
private:
	int _size;
	int _capacity;
	T* _array;
};

#endif

