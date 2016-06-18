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
	//��ǳ��������
	Stack(const Stack<T>& d);
	Stack<T>& operator=(const Stack<T>& d);
public:
	void Push(const T& x); //��ջ
	bool Empty();         //��ջ
	size_t Size();        //��С
	void Pop();           
	T& Top();             //ȡջ��Ԫ��
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

