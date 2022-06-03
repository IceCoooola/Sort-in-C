#include"Sort.h"

void testShellSort()
{

	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	ShellSort(arr1, sz);
	PrintArray(arr1, sz);
}

void testInsertSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	InsertSort(arr1, sz);
	PrintArray(arr1, sz);
}

void testSelectSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	SelectSort(arr1, sz);
	PrintArray(arr1, sz);
}

void testBubbleSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	BubbleSort(arr1, sz);
	PrintArray(arr1, sz);
}

void testHeapSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	HeapSort(arr1, sz);
	PrintArray(arr1, sz);
}


int main()
{
	testInsertSort();
	testShellSort();
	testSelectSort();
	testBubbleSort(); 
	testHeapSort();
	return 0;
}