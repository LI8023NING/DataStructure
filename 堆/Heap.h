#pragma once
#include"AllHeadFile.h"

template<class T>
class Heap
{
public:
	//构造
	Heap();

	//建堆
	Heap(const T* a,size_t size);

	//堆排序
	void HeapSort(const T* a,int index,size_t size);
	
	//建堆副
	void _Heap(const T* a,size_t size);

	//虚向下调整 实向上走
	void AdjustDown(int index);

	//插入时，向上调整
	void AdjustUp();
	
	//插入
	void Push(int x);//尾插的话 存在向上调整
	
	//删除
	void Pop();
	
	//取堆顶元素
	int Top();

	//打印
	void Print();

private:
	vector<T> MinHeap;//这是一个数组类对象
};

template<class T>
Heap<T>::Heap()
	{}

template<class T>
Heap<T>::Heap(const T* a,size_t size)
{
	_Heap(a,size);
}

template<class T>
void Heap<T>::_Heap(const T *a, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		MinHeap.push_back(a[i]);
	}
	
	//第一个非叶子结点开始
	for(int i = (MinHeap.size()-2)/2; i >= 0; i--)
	{
		AdjustDown(i);
	}
}

template<class T>
void Heap<T>::AdjustDown(int index)
{
	int child = 2*index+1;
	while(child < MinHeap.size())
	{
		if(child+1 <MinHeap.size() && MinHeap[child] > MinHeap[child+1])
		{
			child++;
		}

		if(MinHeap[child] < MinHeap[(child-1)/2])
		{
			swap(MinHeap[child],MinHeap[(child-1)/2]);
			index = child; //交换后的是不是打乱了顺序  继续
			child = 2*index+1;//等效循环外的第一个条件
		}
		else
		{
			break;	
		}
	}
}

template<class T>
void Heap<T>::AdjustUp()
{
	int index = MinHeap.size()-1;
	while(index)
	{
		if(MinHeap[index] < MinHeap[(index-1)/2])
		{
			swap(MinHeap[index],MinHeap[(index-1)/2]);
			index = (index - 1) / 2;
		}
		else
		{
			break;
		}
	    
	}
}

template<class T>
void Heap<T>::Push(int x)
{
	MinHeap.push_back(x);
	AdjustUp();
}

template<class T>
void Heap<T>::Pop()
{
	int LastNum = MinHeap.size() - 1;
	swap(MinHeap[0],MinHeap[LastNum]);
	MinHeap.pop_back();
	
	AdjustDown(0);
}

template<class T>
int Heap<T>::Top()
{
	return MinHeap[0];
}

template<class T>
void Heap<T>::Print()
{
	for(int i = 0; i < MinHeap.size();i++)
	{
		cout<<MinHeap[i]<<" ";
	}
	cout<<endl;
}

