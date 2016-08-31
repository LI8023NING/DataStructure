#pragma once

//�����м��Ǹ�λ�� һ�߶������� һ�߶�С����
int Partition(int *a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right - 1;

	while (begin < end)
	{

		//key���Լ�ѡ
		while (a[begin] < key && begin < end) //Ҳ����˵ key��ߵĶ���keyС �ұߵĶ���key��
		{
			++begin;
		}

		while (a[end] > key && end > begin)//�����ұ�
		{
			--end;
		}

		//�����ϱ��κ�һ��ѭ����������������Ϊ�������� �����ж�
		if (begin < end)
		{
			swap(a[begin],a[end]);
		}
	}

	//if (a[begin] > key)
	//{
	//	swap(a[begin],a[right]);
	//	return begin;
	//}

	//else
	//{
	//	return right;
	//}


	if (a[begin] < key)
	{
		return right;
	}

	else
	{
		swap(a[begin],a[right]);
		return begin;
	}
}

//int getPartition(int *a, int beg, int end)
//{
//	if (beg <= end)
//	{
//		int part = beg;
//		for (int i = beg + 1; i <= end; ++i)
//		{
//			if (a[i] <= a[beg])
//			{
//				swap(a[part + 1], a[i]);
//				++part;
//			}
//		}
//		swap(a[beg], a[part]);
//		return part;
//	}
//}


void QuickSortOne(int *a,int left,int right)
{
	assert(a);
	if (left <= right)
	{
		int tmp = Partition(a, left, right); //��������
		QuickSortOne(a,left,tmp-1);
		QuickSortOne(a,tmp+1,right);
	}
}



/// <summary>
/// �̶���׼Ԫ��Ĭ�������һ����Ϊ��׼Ԫ�����ҷ��飬���ػ�׼Ԫ���±�
/// </summary>
//int Partition(int *a, int low, int high)
//{
//	int first = low;
//	int last = high;
//	int key = a[low];                             //ȡ��һ��Ԫ����Ϊ��׼Ԫ
//	while (first < last)
//	{
//		while (first < last && a[last] >= key)
//			last--;
//		a[first] = a[last];
//		while (first < last && a[first] <= key)
//			first++;
//		a[last] = a[first];
//	}
//	a[first] = key;                               //��׼Ԫ����
//	return first;
//}
//
//
//
////����һ//�̶���׼Ԫ ������Ŀ�������
//
//void Quicksort(int *a, int low, int high)
//{
//	if (low >= high) return;                        //�ݹ����
//	int partition = Partition(a, low, high);      //�� >= x ��Ԫ�ؽ������ұ����򣬽� <= x ��Ԫ�ؽ������������
//	Quicksort(a, low, partition - 1);
//	Quicksort(a, partition + 1, high);
//}


//
////������ //�����׼Ԫ
//
///// <summary>
///// 2.0 �����׼Ԫ
///// </summary>
//public static void QsortRandom(int[] a, int low, int high)
//{
//	if (low >= high) return;                        //�ݹ����
//	PartitionRandom(a, low, high);                //�����׼Ԫ
//	int partition = Partition(a, low, high);      //�� >= x ��Ԫ�ؽ������ұ����򣬽� <= x ��Ԫ�ؽ������������
//	QsortRandom(a, low, partition - 1);
//	QsortRandom(a, partition + 1, high);
//}
//
///// <summary>
///// �����׼Ԫ����ȷ���õĻ�׼Ԫ���һ�����������޷���ֵ
///// </summary>        
//public static void PartitionRandom(int[] a, int low, int high)
//{
//	Random rd = new Random();
//	int randomIndex = rd.Next() % (high - low) + low;//ȡ����������±�
//	Swap(a, randomIndex, low);                     //���һ��������
//}
//
//
////������ //����ȡ��
//
///// <summary>
///// 3.0 ����ȡ��
///// </summary>
//public static void QsortMedianOfThree(int[] a, int low, int high)
//{
//	if (low >= high) return;                        //�ݹ����
//	PartitionMedianOfThree(a, low, high);         //����ȡ��
//	int partition = Partition(a, low, high);      //�� >= x ��Ԫ�ؽ������ұ����򣬽� <= x ��Ԫ�ؽ������������
//	QsortMedianOfThree(a, low, partition - 1);
//	QsortMedianOfThree(a, partition + 1, high);
//}
//
///// <summary>
///// ����ȡ��ȷ����׼Ԫ����ȷ���õĻ�׼Ԫ���һ�����������޷���ֵ
///// </summary>        
//public static void PartitionMedianOfThree(int[] a, int low, int high)
//{
//	int mid = low + (high + -low) / 2;
//	if (a[mid] > a[high])
//	{
//		Swap(a, mid, high);
//	}
//	if (a[low] > a[high])
//	{
//		Swap(a, low, high);
//	}
//	if (a[mid] > a[low])
//	{
//		Swap(a, mid, low);
//	}                                                //���м��С�������һ��������
//}
//


