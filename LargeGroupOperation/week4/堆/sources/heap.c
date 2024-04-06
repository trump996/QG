#include "heap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(int* a, int* b)
{
	if (a == NULL || b == NULL)
		return;

	int temp = *a;
	*a = *b;
	*b = temp;
}

//向下调整算法
void AdjustDown(int* arr, int root, int n)
{
	if (arr == NULL)
		return;

	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;

		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

//向上调整算法
void AdjustUp(int* arr, int New)
{
	int child = New;
	int parent = (child - 1) / 2;

	while (child>0)
	{
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void Heap_Create(HEAP* h,int* arr,int n)//建堆
{
	if (h == NULL || arr == NULL)
		return;

	h->data = (int*)malloc(n * sizeof(int));
	if (h->data == NULL)
		return;
	h->size = n;

	memcpy(h->data, arr, n*sizeof(int));

	for (int i = (n - 1) / 2; i >= 0; i--)
		AdjustDown(h->data, i, n);
}

void Heap_Insert(HEAP* h,int da)//插入
{
	if (h == NULL)
		return;

	int* temp = (int*)realloc(h->data, (h->size + 1) * sizeof(int));
	if (temp == NULL)
		return;

	h->data = temp;
	h->data[h->size++] = da;

	AdjustUp(h->data, h->size - 1);
}

void Heap_Destory(HEAP* h)//堆的销毁
{
	if (h == NULL)
		return;

	free(h->data);
	h->size = 0;

	return;
}

void Heap_DeTop(HEAP* h)//删除堆顶
{
	if (h == NULL)
		return;

	if (h->size > 0)
		return;

	swap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	AdjustDown(h->data, 0, h->size);
}

void Heap_Sort(int* arr,int n)
{
	if (arr == NULL)
		return;

	for (int i = n - 2; i >= 0; i--)
		AdjustDown(arr, i, n);

	while (n > 0)
	{
		swap(&arr[0], &arr[n - 1]);
		n--;
		AdjustDown(arr,0,n);
	}

	return;
}

void Heap_Display(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);
}