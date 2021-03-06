#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	//多趟排序
	//这里尽量用for循环，因为while循环稍微慢一点，预判条件与实际不符的话不准就会慢
	for (int i = 0; i < n - 1; i++)
	{
		//把i+1的位置掏出来当作比较的对象
		int end = i;
		int temp = a[end + 1];
		//依次向前比
		while (end >= 0)
		{
			//如果比end位置小，end往后挪，继续向前比
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			//直到不比end小，就找到了自己应该在的位置
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	assert(a);
	//先对gap区间的数预排序，然后再减少gap的大小，最后直到gap为1（不能为0）也就是插入排序。
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //这里要加1因为有可能变成0。gap不能除以2因为会死循环（2/2 +1 = 1， 1/2 +1 = 1）
		//多趟循环
		for (int i = 0; i < n - gap; i++)
		{
			//每一趟循环
			int end = i;
			//temp等于end加上gap区间
			int temp = a[i + gap];
			while (end >= 0)
			{
				//如果比temp大就把大的丢到后面
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int largeIndex, smallIndex, left = 0, right = n - 1;
	//多趟循环
	while (right > left)
	{
		smallIndex = largeIndex = left;
		//每一趟循环
		//遍历找出最大和最小的数
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[smallIndex])
			{
				smallIndex = i;
			}
			if (a[i] > a[largeIndex])
			{
				largeIndex = i;
			}
		}
		//找出来后把小的和最左边交换，大的和最右边交换
		Swap(&a[left], &a[smallIndex]);
		//如果最大的在最左边，但是最左边的值已经被换走了
		//那就把被换走的位置赋给最大的index然后再交换
		if (largeIndex == left)
		{
			largeIndex = smallIndex;
		}
		Swap(&a[right], &a[largeIndex]);
		left++;
		right--;
	}
}
//建大堆
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//选出最大的孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		//如果父亲比孩子小，就换下去，把大孩子换上来
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		//如果父亲小于孩子，就不用调整了
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	//先建堆
	//最后一个父亲的节点是最后一个孩子的节点-1/2
	for (int i = (n - 1 - 1) >> 1; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//建好堆后把最大的和最后一个位置交换，然后--需要排序的，向下调整
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int findMid(int a, int b, int c)
{
	int large = a;
	int small = a;
	if(b > large)
	{
		large = b;
	}
	if (c > large)
	{
		large = c;
	}
	if (b < small)
	{
		small = b;
	}
	if (c < small)
	{
		small = c;
	}
	return a + b + c - large - small;
}

//hoare分治法
int PartSort1(int* a, int left, int right)
{
	int midIndex = findMid(left, (left + right )/2, right);
	Swap(&a[midIndex], &a[left]);
	int key = a[left];
	//选最左边的值当作key
	int begin = left;
	//记录最左边的位置
	while (left < right)
	{
		//右指针去找小于key的
		while (right > left && a[right] >= key)
		{
			right--;
		}
		//左指针去找大于key的
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//交换
		Swap(&a[left], &a[right]);
	}
	//最后把key和当前位置交换
	Swap(&a[left], &a[begin]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = findMid(left, (left + right) / 2, right);
	Swap(&a[midIndex], &a[left]);
	//把最左边的位置当作坑
	int key = a[left];
	while (right > left)
	{
		while (right > left && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		while(left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int midIndex = findMid(left, (left + right) / 2, right);
	Swap(&a[midIndex], &a[left]);
	int key = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		// cur找小，把小的往前翻，大的往后翻
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[left]);
	return prev;
}

void _QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = PartSort3(a, left, right);
	_QuickSort(a, left, key - 1);
	_QuickSort(a, key + 1, right);
}

//快排
void QuickSort(int* a, int n)
{
	_QuickSort(a, 0, n - 1);
}

void _QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	InitStack(&st);

	PushStack(&st, right);
	PushStack(&st, left);
	
	while (!IsEmptyStack(&st))
	{
		int begin = TopStack(&st);
		PopStack(&st);
		int end = TopStack(&st);
		PopStack(&st);
		int key = PartSort1(a, begin, end);
		if (key-1 > begin)
		{
			PushStack(&st, key - 1);
			PushStack(&st, begin);
		}
		if (key+1 < end)
		{

			PushStack(&st, end);
			PushStack(&st, key + 1);
		}	
	}

}

void QuickSortNonR(int* a, int n)
{
	_QuickSortNonR(a, 0, n - 1);
}

void Merge(int* a, int* temp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	for (j; j <= end2; j++)
	{
		a[j] = temp[j];
	}
}

void _MergeSort(int* a, int left, int right, int* temp)
{

	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//[left , mid]  [mid+1, right]
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);
	//左右两段子区间归并，并且拷贝回去
	int begin1 = left, end1 = mid, begin2 = mid + 1, end2 = right;
	Merge(a, temp, begin1, end1, begin2, end2);
}

//归并排序
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, temp);
	//[0, mid]  [mid+1, n-1]
	free(temp);
}

//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		exit(-1);
	}
	//设多个小区间，开始间隔为1
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2*gap)
		{
			//
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + gap + gap - 1;
			if (end1 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			Merge(a, temp, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}
	free(temp);
}

//计数排序
void CountSort(int* a, int n)
{
	int large = a[0], small = a[0];
	//遍历找出最小的和最大的值
	for (int i = 1; i < n; i++)
	{
		if (a[i] > large)
		{
			large = a[i];
		}
		if (a[i] < small)
		{
			small = a[i];
		}
	}
	int sz = large - small + 1;
	int* count = (int*)malloc(sizeof(int) * (sz));
	if (count == NULL)
	{
		exit(-1);
	}
	memset(count, 0, sizeof(int) * (sz));
	for (int i = 0; i < n; i++)
	{
		count[a[i] - small]++;
	}
	int j = 0;
	for (int i = 0; i < sz; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + small;
		}
	}
	free(count);
}
