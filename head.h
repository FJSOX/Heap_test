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

MaxHeap CreateHeap(int Maxlayer);//MaxlayerΪ������
bool IsFullHeap(Heap H);
bool IsEmptyHeap(Heap H);
MaxHeap InsertMaxHeap(Heap H, int X);//����������Ϊ����
void Pr_Heap(Heap H);
MinHeap InsertMinHeap(Heap H, int X);
int Maxab(int a, int b);
int DeleteMaxHeap(MaxHeap H);
MaxHeap WriteToMaxHeap(int Maxlayer, int a[], int lentha);//lenthaΪ����a[]�ĳ���

#endif