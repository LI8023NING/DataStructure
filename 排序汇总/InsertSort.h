#pragma once

//void InsertSort(int *a,int size)
//{
//	assert(a);
//	int i, j, tmp;
//	for (i = 0; i < size-1; ++i)
//	{
//		tmp = a[i + 1];
//		for (j = i; j >= 0; --j)
//		{
//			if (a[j] > tmp)
//			{
//				a[j+1] = a[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[j+1] = tmp;//草 原来时上边的J最后又减了一个
//	}
//}
//
//
////很可笑的一个问题
//void InsertSort(int *a,int size)
//{
//	assert(a);
//	int i, j, tmp;
//	for (i = 0; i < size-1; ++i)
//	{
//		tmp = a[i + 1];
//		for (j = i; j >= -1; --j)
//		{
//			if (a[j] > tmp)  //[j] j尽然成负数了
//			{
//				a[j+1] = a[j];
//			}
//			else
//			{
//				a[j + 1] = tmp;
//				break;
//			}
//			
//		}
//	}
//}
//
////下面就是对的
//void InsertSort(int a[], int len)
//{
//	int i, j, temp;
//	for (i = 1; i<len; i++)
//	{
//		if (a[i]<a[i - 1])
//		{
//			temp = a[i];
//			for (j = i - 1; a[j]>temp; j--)
//				a[j + 1] = a[j];
//			a[j + 1] = temp;
//		}
//	}
//}

void InsertSort(int *a, int size)
{
	assert(a);
	for (int i = 1; i < size; ++i)
	{
		int index = i;
		int tmp = a[index];
		int end = index - 1;
		while (end >= 0 && tmp < a[end])
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp; //这里end加一是因为上边多减得一个
	}
}