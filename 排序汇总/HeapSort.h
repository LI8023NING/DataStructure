#pragma once
//
//������ѣ�
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
	//�����
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustUp(a,i,size);
	}

	//����
	for (int i = 0; i < size; ++i)  //++i����Ϊ���ƺ�ߵ�  ��֤ÿ�����һ�������Ѷ�������
	{
		swap(a[0], a[size-1-i]);
		AdjustUp(a, 0,size-1-i);
	}
}