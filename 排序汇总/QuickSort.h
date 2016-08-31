#pragma once

//计算中间那个位置 一边都大于他 一边都小于他
int Partition(int *a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right - 1;

	while (begin < end)
	{

		//key是自己选
		while (a[begin] < key && begin < end) //也就是说 key左边的都比key小 右边的都比key大
		{
			++begin;
		}

		while (a[end] > key && end > begin)//处理右边
		{
			--end;
		}

		//但凡上边任何一个循环跳出来，都是因为遇到条件 下面判断
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
		int tmp = Partition(a, left, right); //单趟排序
		QuickSortOne(a,left,tmp-1);
		QuickSortOne(a,tmp+1,right);
	}
}



/// <summary>
/// 固定基准元，默认数组第一个数为基准元，左右分组，返回基准元的下标
/// </summary>
//int Partition(int *a, int low, int high)
//{
//	int first = low;
//	int last = high;
//	int key = a[low];                             //取第一个元素作为基准元
//	while (first < last)
//	{
//		while (first < last && a[last] >= key)
//			last--;
//		a[first] = a[last];
//		while (first < last && a[first] <= key)
//			first++;
//		a[last] = a[first];
//	}
//	a[first] = key;                               //基准元居中
//	return first;
//}
//
//
//
////方法一//固定基准元 最基础的快速排序
//
//void Quicksort(int *a, int low, int high)
//{
//	if (low >= high) return;                        //递归出口
//	int partition = Partition(a, low, high);      //将 >= x 的元素交换到右边区域，将 <= x 的元素交换到左边区域
//	Quicksort(a, low, partition - 1);
//	Quicksort(a, partition + 1, high);
//}


//
////方法二 //随机基准元
//
///// <summary>
///// 2.0 随机基准元
///// </summary>
//public static void QsortRandom(int[] a, int low, int high)
//{
//	if (low >= high) return;                        //递归出口
//	PartitionRandom(a, low, high);                //随机基准元
//	int partition = Partition(a, low, high);      //将 >= x 的元素交换到右边区域，将 <= x 的元素交换到左边区域
//	QsortRandom(a, low, partition - 1);
//	QsortRandom(a, partition + 1, high);
//}
//
///// <summary>
///// 随机基准元，将确定好的基准元与第一个数交换，无返回值
///// </summary>        
//public static void PartitionRandom(int[] a, int low, int high)
//{
//	Random rd = new Random();
//	int randomIndex = rd.Next() % (high - low) + low;//取数组中随机下标
//	Swap(a, randomIndex, low);                     //与第一个数交换
//}
//
//
////方法三 //三数取中
//
///// <summary>
///// 3.0 三数取中
///// </summary>
//public static void QsortMedianOfThree(int[] a, int low, int high)
//{
//	if (low >= high) return;                        //递归出口
//	PartitionMedianOfThree(a, low, high);         //三数取中
//	int partition = Partition(a, low, high);      //将 >= x 的元素交换到右边区域，将 <= x 的元素交换到左边区域
//	QsortMedianOfThree(a, low, partition - 1);
//	QsortMedianOfThree(a, partition + 1, high);
//}
//
///// <summary>
///// 三数取中确定基准元，将确定好的基准元与第一个数交换，无返回值
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
//	}                                                //将中间大小的数与第一个数交换
//}
//


