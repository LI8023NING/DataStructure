#pragma once

//合并两个分组的
void MergeSection(int *a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int index = 0;
	while (begin1 <= end1 && begin2 <= end2)   //两个子集合并
	{
		if (a[begin1] <= a[begin2])      //把小的放在index = 0的位置 以此类推
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	//还少几种情况，如下

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
}

//归并排序
void _MergeSort(int *a, int *tmp, int left,int right)
{
	assert(a);

	if (left >= right)
	{
		return;
	}
	
	int mid = left + (right - left) / 2;

 	_MergeSort(a, tmp,left,mid);
	_MergeSort(a, tmp, mid+1,right );

	MergeSection(a,tmp,left,mid,mid+1,right);
	 

	for (int i = 0; i < (right - left + 1); ++i)
	{
		a[left+i] = tmp[i];
	}
}

void MergeSort(int *a, int size)
{
	int *tmp = new int[size];  //相当于第三方数组 用来合并
	memset(tmp,0,sizeof(int)*size);
	_MergeSort(a, tmp, 0, size - 1);
	delete[] tmp;
}