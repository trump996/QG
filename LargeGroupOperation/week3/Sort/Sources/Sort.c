#include "Sort.h"
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void InsertSort(long long int* a, long int n)
{
	for (long int i = 1; i < n; i++)
	{
		int j;
		long long int Temp = a[i];

		for ( j = i-1; a[j] > Temp && j>=0 ; j--)
			a[j + 1] = a[j];	

		a[j + 1] = Temp;
	}

	return;
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(long long int* a, long int begin, long int mid, long int end, long long int* temp)
{
	long int i = begin, j = mid+1;
	long int x = begin;

	while (i<=mid&&j<=end)
	{
		if (a[i] <= a[j])
			temp[x++] = a[i++];
		else
			temp[x++] = a[j++];
	}

	while (i <= mid)
		temp[x++] = a[i++];

	while (j <= end)
		temp[x++] = a[j++];

	for (long int y = begin; y <= end; y++)
		a[y] = temp[y];
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(long long int* a, long int begin, long int end, long long int* temp)
{
	if (begin<end)
	{
		long int mid = (begin + end)/2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid+1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
	return;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(long long int* a,long int begin, long int end)
{
	if (begin > end)
		return;

	long int i = begin, j = end;
	long long int p = a[begin];

	while (i<j)
	{
		while (i < j && a[j] >= p)
			j--;
		if (i < j)
			a[i++] = a[j];

		while (i < j && a[i] < p)
			i++;
		if (i < j)
			a[j--] = a[i];
	}

	a[i] = p;

	QuickSort_Recursion(a, begin, i-1);
	QuickSort_Recursion(a, i+1, end);

	return;
}

long int Part(long long int* a, long int begin, long int end)
{
	long int i = begin, j = end;
	long long int p = a[begin];

	while (i < j)
	{
		while (i < j && a[j] >= p)
			j--;
		if (i < j)
			a[i++] = a[j];

		while (i < j && a[i] < p)
			i++;
		if (i < j)
			a[j--] = a[i];
	}

	a[i] = p;
	return i;
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(long long int* a, long int size)
{
	long int* Stack = (long int*)malloc(size * sizeof(long int));
	long int top = -1;

	if (Stack == NULL)
		return;

	Stack[++top] = 0;
	Stack[++top] = size - 1;

	while (top>=0)
	{
		long int end = Stack[top--];
		long int begin = Stack[top--];

		long int part = Part(a, begin, end);

		if (part - begin > 1)
		{
			Stack[++top] = begin;
			Stack[++top] = part - 1;
		}

		if (end-part>1)
		{
			Stack[++top] = part + 1;
			Stack[++top] = end;
		}
	}

	free(Stack);
	return;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void Partition(long long int* a, long int begin, long int end)
{
	long long int temp;
	long int i = begin, j = end;

	while (i < j && j >= 0)
	{
		for (; a[j] >= a[begin] && i < j && j >= 0; j--);
		for (; a[i] <= a[begin] && i < j && j >= 0; i++);

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	temp = a[i];
	a[i] = a[begin];
	a[begin] = temp;

	if (i > begin && i < end)
	{
		Partition(a, begin, i - 1);
		Partition(a, i + 1, end);
	}

	return;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(long long int* a, long int size)
{
	long long int max = a[0];
	for (long int i = 0; i < size; i++)
		if (a[i] > max)
			max = a[i];

	long long int* temp = (long long int*)malloc(max*sizeof(long long int));
	long int x = 0;

	if (temp == NULL)
		return;

	for (long long int i = 0; i < max; i++)
		temp[i] = 0;

	for (long int i = 0; i < size; i++)
		temp[a[i]-1]++;

	for (long long int i = 0; i < max; i++)
	{
		while (temp[i])
		{
			a[x++] = i+1;
			temp[i]--;
		}
	}

	free(temp);
	return;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(long long int* a, long int size)
{
	long long int* temp = (long long int*)malloc(size * sizeof(long long int));
	if (temp == NULL)
		return;

	long long int max = a[0];
	for (long int i = 0; i < size; i++)
		if (a[i] > max)
			max = a[i];

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		int count[10] = { 0 };

		for (long int i = 0; i < size; i++)
			count[(a[i] / exp) % 10]++;//count��������Ϊ�����ֵĴ���

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];//����count��������λ��Ӧ�ó��ֵ�λ��

		for (long int i = size-1; i >=0 ; i--)
		{
			temp[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}

		for (long int i = 0; i < size; i++)
			a[i] = temp[i];
	}

	free(temp);
	return;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(long long int* a, long int size)
{
	long int p1=0, p2=size-1;

	for (long int p = 0; p1 <= p2 && p<=p2 && p>=p1;)
	{
		if (a[p] == 0)
		{
			long long int temp = a[p];
			a[p] = a[p1];
			a[p1] = temp;

			p1++;
			p++;
		}
		else if (a[p] == 2)
		{
			long long int temp = a[p];
			a[p] = a[p2];
			a[p2] = temp;

			p2--;
		}
		else
			p++;
	}

	return;
}

/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
 */
long long int FindYourNum(long long int* a, long int start, long int end, int k)
{
	if (start <= end)
	{
		long int num = Part(a, start, end);

		if (num == k)
			return a[k - 1];
		else if (num < k)
			return FindYourNum(a, num + 1, end, k);
		else
			return FindYourNum(a, start, num - 1, k);
	}
	else
		return -1;
}