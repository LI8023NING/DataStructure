#include"BinaryTreeThreading.h"

void Test()
{
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> t1(a, 10);
	t1.InOrderThreading();
	t1.InOderThd();

	BinaryTreeThd<int> t2(a, 10);
	t2.PrevOrderThreading();
	t2.PrevOrderThd();

	int a1[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTreeThd<int> t3(a1, 15);
	t3.PrevOrderThreading();
	t3.PrevOrderThd();

	//BinaryTreeThd<int> t3(a, 10);
	//t3.PostOrderThreading();
}

int main()
{
	Test();
	return 0;
}