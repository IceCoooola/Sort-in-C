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

void testQuickSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	QuickSort(arr1, sz);
	PrintArray(arr1, sz);
}
void testQuickSortNonR()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	QuickSortNonR(arr1,sz);
	PrintArray(arr1, sz);
}

void testMergeSort()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47};
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	MergeSort(arr1,sz);
	PrintArray(arr1, sz);
}


void testMergeSortNonR()
{
	int arr1[] = { 5,456,2,3,476,23,-345,0, 24,12,45,8,4,7,9,-6,47 };
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	MergeSortNonR(arr1, sz);
	PrintArray(arr1, sz);
}

void testCountSort()
{
	int arr1[] = { 5,0,1,5,4,2,2,2,1,3,2,0};
	int sz = sizeof(arr1) / sizeof(int);
	PrintArray(arr1, sz);
	CountSort(arr1, sz);
	PrintArray(arr1, sz);
}


int main()
{
	printf("testInsertSort :\n");
	testInsertSort();
	printf("testShellSort :\n");
	testShellSort();
	printf("testSelectSort :\n");
	testSelectSort();
	printf("testBubbleSort :\n");
	testBubbleSort();
	printf("testHeapSort :\n");
	testHeapSort();
	printf("testQuickSort :\n");
	testQuickSort();
	printf("testQuickSortNonR :\n");
	testQuickSortNonR();
	printf("testMergeSort :\n");
	testMergeSort();
	printf("testMergeSortNonR :\n");
	testMergeSortNonR();
	printf("testCountSort :\n");
	testCountSort();
	return 0;
}
