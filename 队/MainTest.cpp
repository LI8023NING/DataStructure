#include"Queue.h"
#include"Define.cpp"  //ʲô�ⲿ�޷����������� ���� û��ӳ��ͷ�ļ�

void Test1()
{
	Queue<int,Node> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	while(!s1.Empty())
	{
		cout<<s1.Front()<<"->";
		s1.Pop();
	}
	cout<<"NULL"<<endl;
}
int main()
{	
	Test1();
	return 0;
}