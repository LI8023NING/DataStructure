#include"AllHeadFile.h"
#include"Heap.h"

void Test()
{
	int a[11] = {10,20,15,21,14,16,18,25,34,94,55};
	Heap<int> s1(a,11);
	cout<<"С�ѣ�"<<endl;
	s1.Print();
	cout<<"�������ݣ�"<<endl;
	s1.Push(1);
	s1.Print();
	cout<<"ɾ��ͷ��"<<endl;
	s1.Pop();
	s1.Print();
	cout<<"�Ѷ����ݣ�"<<endl;
	cout<<s1.Top()<<endl;
}

int main()
{
	Test();
	return 0;
}