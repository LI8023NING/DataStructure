#pragma once

void BubblSort(int *a,int size)
{
	assert(a);
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j+1],a[j]);
			}
		}
	}
}