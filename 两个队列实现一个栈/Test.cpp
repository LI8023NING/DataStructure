/*
*������������A��B��ջ��push������ֱ��push��A�Ķ�β�����ˡ�
*ջ��pop����ʱ����A�еĶ�������ȡ���ŵ�B�У�ȡ�����һ��ʱ��
*���һ����Ҫ�ŵ�B�У�ֱ��ɾ�����ٽ�B�е�ֵ���ηŻ�A�С�
*ջ��top����ʱ����A�еĶ�������ȡ���ŵ�B�У�ȡ�����һ��ʱ��
*�����һ��ֵ��¼�������ٽ����һ��ֵ�ŵ�B�У��ٽ�B�е�ֵ���ηŻص�A��
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

//��ջ
template<class T>
void Mystack<T>::Push(T a)
{
	Queue1.push(a);
}

//ջ��
template<class T>
T Mystack<T>::Top()
{
	return Queue1.back();//???????????�����Ƿ����
}

//��ջ
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