#include<iostream>
#include"head.h"

int main()
{
	cout << "Hi, Master!" << endl;
	int a[] = { 1,3,6,7,2,9,8,4 };
	MaxHeap h = WriteToMaxHeap(4, a, sizeof(a)/sizeof(a[0]));

	Pr_Heap(h);
	cout << "Program is over!" << endl;
	return 0;
}
