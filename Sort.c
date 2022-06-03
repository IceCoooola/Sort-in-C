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


// ��������
void InsertSort(int* a, int n)
{
	assert(a);
	//��������
	//���ﾡ����forѭ������Ϊwhileѭ����΢��һ�㣬Ԥ��������ʵ�ʲ����Ļ���׼�ͻ���
	for (int i = 0; i < n - 1; i++)
	{
		//��i+1��λ���ͳ��������ȽϵĶ���
		int end = i;
		int temp = a[end + 1];
		//������ǰ��
		while (end >= 0)
		{
			//�����endλ��С��end����Ų��������ǰ��
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			//ֱ������endС�����ҵ����Լ�Ӧ���ڵ�λ��
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	assert(a);
	//�ȶ�gap�������Ԥ����Ȼ���ټ���gap�Ĵ�С�����ֱ��gapΪ1������Ϊ0��Ҳ���ǲ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //����Ҫ��1��Ϊ�п��ܱ��0��gap���ܳ���2��Ϊ����ѭ����2/2 +1 = 1�� 1/2 +1 = 1��
		//����ѭ��
		for (int i = 0; i < n - gap; i++)
		{
			//ÿһ��ѭ��
			int end = i;
			//temp����end����gap����
			int temp = a[i + gap];
			while (end >= 0)
			{
				//�����temp��ͰѴ�Ķ�������
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

//ѡ������
void SelectSort(int* a, int n)
{
	int largeIndex, smallIndex, left = 0, right = n - 1;
	//����ѭ��
	while (right > left)
	{
		smallIndex = largeIndex = left;
		//ÿһ��ѭ��
		//�����ҳ�������С����
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
		//�ҳ������С�ĺ�����߽�������ĺ����ұ߽���
		Swap(&a[left], &a[smallIndex]);
		//�������������ߣ���������ߵ�ֵ�Ѿ���������
		//�ǾͰѱ����ߵ�λ�ø�������indexȻ���ٽ���
		if (largeIndex == left)
		{
			largeIndex = smallIndex;
		}
		Swap(&a[right], &a[largeIndex]);
		left++;
		right--;
	}
}
//�����
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//ѡ�����ĺ���
		if(child +1 < n && a[child+1] > a[child])
		{
			child++;
		}
		//������ױȺ���С���ͻ���ȥ���Ѵ��ӻ�����
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		//�������С�ں��ӣ��Ͳ��õ�����
		else
		{
			break;
		}
	}
}
//������
void HeapSort(int* a, int n)
{
	//�Ƚ���
	//���һ�����׵Ľڵ������һ�����ӵĽڵ�-1/2
	for (int i = (n - 1 - 1) >> 1; i>=0 ;i--)
	{
		AdjustDwon(a, n, i);
	}
	//���öѺ�����ĺ����һ��λ�ý�����Ȼ��--��Ҫ����ģ����µ���
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// ð������
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

//����
void QuickSort(int* a, int n);

