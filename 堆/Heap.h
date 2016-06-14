#pragma once
#include"AllHeadFile.h"

template<class T>
class Heap
{
public:
	//����
	Heap();

	//����
	Heap(const T* a,size_t size);

	//������
	void HeapSort(const T* a,int index,size_t size);
	
	//���Ѹ�
	void _Heap(const T* a,size_t size);

	//�����µ��� ʵ������
	void AdjustDown(int index);

	//����ʱ�����ϵ���
	void AdjustUp();
	
	//����
	void Push(int x);//β��Ļ� �������ϵ���
	
	//ɾ��
	void Pop();
	
	//ȡ�Ѷ�Ԫ��
	int Top();

	//��ӡ
	void Print();

private:
	vector<T> MinHeap;//����һ�����������
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
	
	//��һ����Ҷ�ӽ�㿪ʼ
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
			index = child; //��������ǲ��Ǵ�����˳��  ����
			child = 2*index+1;//��Чѭ����ĵ�һ������
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

