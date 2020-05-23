#include<iostream>
#include"head.h"


Heap CreateHeap(int Maxlayer)
{
	//创建容积为2^Maxlayer-1的最大堆(Maxlayer >= 1)
	int Maxsize = (int)pow(2, Maxlayer);
	Heap h = (Heap)malloc(sizeof(struct HNode));
	h->Data = new int[Maxsize]();
	h->Capacity = Maxsize-1;
	h->Size = 0;
	h->Data[0] = MAX;//哨兵，意义？

	return h;
}

bool IsFullHeap(Heap H)
{
	return (H->Capacity == H->Size);
}

bool IsEmptyHeap(Heap H)
{
	return (H->Size == 0);
}


MaxHeap InsertMaxHeap(Heap H, int X)
{
	//如果H为空，直接插入
	if (IsEmptyHeap(H)) {
		H->Data[1] = X;
		H->Size++;
	}
	else if (IsFullHeap(H))
	{
		cout << "The MaxHeap is full!" << endl;
	}
	else {
		int emp;
		int i = H->Size + 1;
		H->Data[i] = X;
		H->Size++;
		while (H->Data[i] > H->Data[i / 2] && i/2 >= 1) {
				//若叶节点的值大于根节点，交换两值
				emp = H->Data[i];
				H->Data[i] = H->Data[i / 2];
				i = i / 2;
				H->Data[i] = emp;
		}
			
	}
	return H;
}

void Pr_Heap(Heap H)
{
	for (int i = 1; i <= H->Size; i++) {
		cout << H->Data[i]<<"\t";
	}
}

MinHeap InsertMinHeap(Heap H, int X)
{
	//如果H为空，直接插入
	if (IsEmptyHeap(H)) {
		H->Data[1] = X;
		H->Size++;
	}
	else if (IsFullHeap(H))
	{
		cout << "The MaxHeap is full!" << endl;
	}
	else {
		int emp;
		int i = H->Size + 1;
		H->Data[i] = X;
		H->Size++;
		while (H->Data[i] < H->Data[i / 2] && i / 2 >= 1) {
			//若叶节点的值小于根节点，交换两值
			emp = H->Data[i];
			H->Data[i] = H->Data[i / 2];
			i = i / 2;
			H->Data[i] = emp;
		}

	}
	return H;
}

int Maxab(int a, int b)
{
	return a > b ? a: b;
}

int DeleteMaxHeap(MaxHeap H)
{
	int cmp;
	int i = 1;
	int ret;

	ret = H->Data[1];
	H->Data[i] = H->Data[H->Size];
	H->Data[H->Size] = 0;
	H->Size--;

	while (H->Data[i*2]!=0)
	{
		//在i,i*2,i*2+1三个数的Data之间比较大小
		cmp = Maxab(H->Data[i * 2], H->Data[i * 2 + 1]);
		if (cmp == H->Data[i * 2]) {
			cmp = Maxab(cmp, H->Data[i]);
			if (cmp!=H->Data[i]) {
				cmp = H->Data[i];
				H->Data[i] = H->Data[i * 2];
				H->Data[i * 2] = cmp;
				i = i * 2;
			}
		}
		else {
			cmp = Maxab(cmp, H->Data[i]);
			if (cmp != H->Data[i]) {
				cmp = H->Data[i];
				H->Data[i] = H->Data[i * 2 + 1];
				H->Data[i * 2 + 1] = cmp;
				i = i * 2 + 1;
			}
		}

	}

	return ret;
}

MaxHeap WriteToMaxHeap(int Maxlayer, int a[], int lentha)
{
	MaxHeap h = CreateHeap(Maxlayer);
	int i = 0;

	for (i = 0;i < lentha;i++) {
		InsertMaxHeap(h, a[i]);
	}

	return h;
}