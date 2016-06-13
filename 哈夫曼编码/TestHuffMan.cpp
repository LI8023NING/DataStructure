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

//�ļ�ѹ��
void TestCompress()
{
	int time1 = GetTickCount();
	FileCompress fc;
	fc.Compress("lining.dat");
	int time2 = GetTickCount();
#ifndef _DE_BUG_
#define _DE_BUG_
	cout << "�ļ�ѹ��...........���" << endl;
#endif

	cout << "ѹ����ʱ��" << time2 - time1 << endl;
}

//�ļ���ѹ��
void TestUnCompress()
{
	int time3 = GetTickCount();
	FileCompress fc;
	fc.UnCompress("lining.dat");
	int time4 = GetTickCount();

#ifndef _DE_BUG
#define _DE_BUG
	cout << "�ļ���ѹ...........���" << endl;
#endif

	cout << "��ѹ��ʱ��" << time4 - time3 << endl;
}


int main()
{
	//�ļ�ѹ��
	TestCompress();

	//�ļ���ѹ��
	TestUnCompress();
	return 0;
}



