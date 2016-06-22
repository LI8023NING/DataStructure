#include <iostream>  
#include <stack>  
using namespace std; 


/*两个栈实现队列*/
template<class T>   
class Queue
{
public:
	Queue()
	{}
	~Queue()
	{}
public:
	void Push(T A);
	int Pop();
private:
	stack<T> stack1;
	stack<T> stack2;
};

//入队
template<class T> 
void Queue<T>::Push(T A)
{
	stack1.push(A);
}

//出栈
template<class T> 
int Queue<T>::Pop()
{
	int node = 0;
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			int num = stack1.top();
			stack2.push(num);
			stack1.pop();
		}
	}
	node = stack2.top();
	stack2.pop();
	return node;
}


void Test()
{
	Queue<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Push(6);
	s1.Push(7);
	for(int i = 0; i < 7; i++)
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