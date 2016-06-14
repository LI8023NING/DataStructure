#include"AllHeadFile.h"
#include"Heap.h"

void Test()
{
	int a[11] = {10,20,15,21,14,16,18,25,34,94,55};
	Heap<int> s1(a,11);
	cout<<"小堆："<<endl;
	s1.Print();
	cout<<"插入数据："<<endl;
	s1.Push(1);
	s1.Print();
	cout<<"删除头："<<endl;
	s1.Pop();
	s1.Print();
	cout<<"堆顶数据："<<endl;
	cout<<s1.Top()<<endl;
}

int main()
{
	Test();
	return 0;
}