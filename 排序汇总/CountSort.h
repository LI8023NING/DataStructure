#pragma once

//在范围中排序
void CountSortBetMaxAndMin(int *a, int min, int max,int size)
{
	int gap = max - min + 1;
	int *temparray = new int[gap];
	memset(temparray,0,sizeof(int)*(gap+1));

	for (int count = 0; count < size; ++count)
	{
		temparray[a[count]]++;
	}


	//temparray是一个
	int index = 0;
	for (int i = min; i < size; ++i)
	{
		while (temparray[i] != 0)
		{
			a[index++] = i;
			temparray[i]--;
		}
	}
}


//计数排序
void CountSort(int *a,int size)
{
	//找一个范围 即就是数组的元素的最大和最小值
	int max = a[0];  //最大
	int min = a[0];  //最小

	for (int i = 1; i < size; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		else if (a[i] < min)
		{
			min = a[i];
		}
	}

	//在这个范围中计数排序
	CountSortBetMaxAndMin(a, min, max,size);
}