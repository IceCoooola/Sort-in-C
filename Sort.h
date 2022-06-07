#pragma once
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"stack.h"
//打印array
void PrintArray(int* a, int n);

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

//快排
void QuickSort(int* a, int n);

//快排没有递归
void QuickSortNonR(int* a, int n);

//归并排序
void MergeSort(int* a, int n);
 
//归并排序非递归
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);
