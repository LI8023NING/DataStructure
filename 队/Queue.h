//声明
#ifndef _QUEUE_
#define _QUEUE_

#include"HeadFile.h"

template<class T>
class Node
{
public:
	Node(const T& data);  //构造函数
	Node(const Node& N); //拷贝构造
	~Node();            //析构
public:
	T data;
	Node<T> *next;
};

template<class T,template<class> class Node>
class Queue
{
public:
	Queue();
	Queue(const Queue& Q);
	Queue& operator = (const Queue& Q);
	~Queue();
public:
	void Pop();
	void Push(const T& data);
	bool Empty();
	T& Front();
	T& Back();
	int Size();
protected:
	Node<T> *_head;
	Node<T> *_tial;
	size_t _size;
};


#endif