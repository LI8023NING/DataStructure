#pragma once
//
//建立大堆，
void AdjustUp(int *a, int index,int size)
{
	int child = index * 2 + 1;
	while (child < size)
	{
		if ((child + 1) < size && a[child] < a[child + 1])
		{
			++child;
		}

		if (a[child] > a[(child - 1) / 2])
		{
			swap(a[child], a[index]);
			index = child;
			child = index * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int *a,int size)
{
	assert(a);
	//建大堆
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustUp(a,i,size);
	}

	//排序
	for (int i = 0; i < size; ++i)  //++i是因为控制后边的  保证每次最后一个数个堆顶数交换
	{
		swap(a[0], a[size-1-i]);
		AdjustUp(a, 0,size-1-i);
	}
}