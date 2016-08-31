#include<iostream>
using namespace std;
#include<assert.h>

#include"HeapSort.h"
#include"InsertSort.h"
#include"ShellSort.h"
#include"BubblSort.h"
#include"QuickSort.h"
#include"MergerSort.h"
#include"CountSort.h"
#include"BucketSort.h"

void Print(int *a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Test1()
{
	int a[10] = { 2, 7, 1, 9, 5, 8, 3, 4, 6, 0 };
	HeapSort(a, 10);
	cout << "¶ÑÅÅÐò£º"<<endl;
	Print(a, 10);
}

void Test2()
{
	int b[11] = { 9, 7, 1, 2, 5, 8, 3, 4, 6, 0};
	InsertSort(b,10);
	cout << "Ö±½Ó²åÈëÅÅÐò£º"<<endl;
	Print(b, 10);
}

void Test3()
{
	int b[10] = { 9, 7, 1, 2, 5, 8, 3, 4, 6, 0 };
	cout << "Ï£¶ûÅÅÐò£º" << endl;
	ShellSort(b, 10);
	Print(b,10);
}

void Test4()
{
	int b[10] = { 0, 7, 1, 2, 5, 8, 3, 4, 6, 9 };
	cout << "Ã°ÅÝÅÅÐò£º" << endl;
	BubblSort(b,10);
	Print(b,10);
}

void SchemeOne()
{
	int b[10] = { 0, 7, 1, 2, 9, 8, 3, 4, 6, 5 };
	QuickSortOne(b,0,9);
	cout << "¿ìËÙÅÅÐò£º" << endl;
	Print(b,10);
}



void QuickSortTest()
{
	//·½°¸Ò»
	SchemeOne();
	//SchemeTwo();
	//SchemeThree();

}

void Test5()
{
	int b[10] = { 7, 9, 8, 2, 0, 1, 3, 4, 6, 5 };
	cout << "¹é²¢ÅÅÐò£º" << endl;
	MergeSort(b,10);
	Print(b,10);
}

void Test6()
{
	int a[10] = { 7, 9, 5, 2, 8, 0, 3, 4, 6, 1 };
	CountSort(a,10);
	cout << "¼ÆÊýÅÅÐò£º" << endl;
	Print(a,10);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//QuickSortTest();
	Test5();
	//Test6();
	//Test7();
	return 0;
}