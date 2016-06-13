#include<iostream>
#include<string.h>
#include<assert.h>
#include<windows.h>
using namespace std;

//#define _DE_BUG_
//#define _DE_BUG

#pragma warning(disable:4018)
#pragma warning(disable:4996)

#include"StructOfHuffaMan.h"
#include"MinHeap.h"
#include"FileCompress.h"

//文件压缩
void TestCompress()
{
	int time1 = GetTickCount();
	FileCompress fc;
	fc.Compress("lining.dat");
	int time2 = GetTickCount();
#ifndef _DE_BUG_
#define _DE_BUG_
	cout << "文件压缩...........完成" << endl;
#endif

	cout << "压缩耗时：" << time2 - time1 << endl;
}

//文件解压缩
void TestUnCompress()
{
	int time3 = GetTickCount();
	FileCompress fc;
	fc.UnCompress("lining.dat");
	int time4 = GetTickCount();

#ifndef _DE_BUG
#define _DE_BUG
	cout << "文件解压...........完成" << endl;
#endif

	cout << "解压耗时：" << time4 - time3 << endl;
}


int main()
{
	//文件压缩
	TestCompress();

	//文件解压缩
	TestUnCompress();
	return 0;
}



