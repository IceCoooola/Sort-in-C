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
		if(child +1 < n && a[child+1] > a[child])
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
	for (int i = (n - 1 - 1) >> 1; i>=0 ;i--)
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
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//快排
void QuickSort(int* a, int n);

