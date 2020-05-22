#pragma once
#ifndef _HEAD_H_
#define _HEAD_H_

#define MAX 1000;

using namespace std;

typedef struct HNode* Heap;
struct HNode
{
	int* Data;
	int Size;
	int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

MaxHeap CreateHeap(int Maxlayer);//Maxlayer为最大层数
bool IsFullHeap(Heap H);
bool IsEmptyHeap(Heap H);
MaxHeap InsertMaxHeap(Heap H, int X);//不能用零作为数据
void Pr_Heap(Heap H);
MinHeap InsertMinHeap(Heap H, int X);
int Maxab(int a, int b);
int DeleteMaxHeap(MaxHeap H);
MaxHeap WriteToMaxHeap(int Maxlayer, int a[], int lentha);//lentha为数组a[]的长度

#endif