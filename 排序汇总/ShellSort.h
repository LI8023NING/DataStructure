  #pragma once


void ShellSort(int *a, int size)
{
	assert(a);
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		//һ�¶��ǲ�������Ĺ���
        int index = gap;
		int i = gap;
		while (index < size)
		{
			int tmp = a[index];
			int end = index - gap;
			while (end >= 0 && tmp < a[end])
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
			index += 1;
		}
	}
}