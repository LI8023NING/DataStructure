/*
*设有两个队列A和B，栈的push操作，直接push到A的队尾就行了。
*栈的pop操作时，将A中的队列依次取出放到B中，取到最后一个时，
*最后一个不要放到B中，直接删掉，再将B中的值依次放回A中。
*栈的top操作时，将A中的队列依次取出放到B中，取到最后一个时，
*将最后一个值记录下来，再将最后一个值放到B中，再将B中的值依次放回到A中
*/

#include<iostream>  
#include <queue>  
using namespace std; 

template<class T>
class Mystack
{
public:
	Mystack()
	{}
	~Mystack()
	{}
public:
	void Push(T value);
	T Top();
	T Pop();
private:
	queue<T> Queue1;
	queue<T> Queue2;
};

//入栈
template<class T>
void Mystack<T>::Push(T a)
{
	Queue1.push(a);
}

//栈顶
template<class T>
T Mystack<T>::Top()
{
	return Queue1.back();//???????????这里是否可以
}

//出栈
template<class T>
T Mystack<T>::Pop()
{
	int node = 0;
	while(Queue1.back() != Queue1.front())
	{
		int num = Queue1.front();
		Queue2.push(num);
		Queue1.pop();
	}
	node = Queue1.back();
	Queue1.pop();

	while(!Queue2.empty())
	{
		int num = Queue2.front();
		Queue1.push(num);
		Queue2.pop();
	}
	return node;
}
void Test()
{
	Mystack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
    cout<<s1.Top()<<endl;
	for(int i = 0; i < 5; i++)
	{
		cout<<s1.Pop()<<"->";
	}
	cout<<"NULL"<<endl;
}

int main()
{
	Test();
	return 0;
}