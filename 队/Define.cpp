#include"Queue.h"
//#include"HeadFile.h"

template<class T>
Node<T>::Node(const T& data)
	:data(data)
	,next(NULL)
{}

template<class T>
Node<T>::Node(const Node& s)
	:data(s.data)
	,next(s.next)
{}

template<class T>
Node<T>::~Node()
	{}


template<class T,template<class> class Node>
Queue<T,Node>::Queue()
	:_head(NULL)
	,_tial(NULL)
	,_size(0)
{}

template<class T,template<class> class Node>
Queue<T,Node>::Queue(const Queue& Q)
	:_head(Q._head)
	,_tial(Q._tial)
	,_size(Q._size)
{
	Copy(Q);
}

//template<class T,template<class> class Node>
//Queue& Queue<T,Node>::operator = (const Queue& Q)
//{
//
//}

template<class T,template<class> class Node>
Queue<T,Node>::~Queue()
{}

template<class T,template<class> class Node>
void Queue<T,Node>::Pop()
{
	assert(_head);
	if(_head == _tial)
	{
		delete _head;
		_head = _tial = NULL;
		return;
	}
	else
	{
		Node<T>* tmp = _head;
		_head = _head->next;
		delete tmp;
	}

}

template<class T,template<class> class Node>
void Queue<T,Node>::Push(const T& data)
{
	if(_head == NULL)
	{
		_tial = _head = new Node<T>(data);
	}
	else
	{
		_tial->next = new Node<T>(data);
		_tial = _tial->next;
	}
}

template<class T,template<class> class Node>
bool Queue<T,Node>::Empty()
{
	if(_head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T,template<class> class Node>
T& Queue<T,Node>::Front()
{
	return _head->data;	
}

template<class T,template<class> class Node>
T& Queue<T,Node>::Back()
{
	return _tial->data;
}

template<class T,template<class> class Node>
int Queue<T,Node>::Size()
{
	return 0;
}
