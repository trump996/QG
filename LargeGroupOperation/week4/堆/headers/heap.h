#ifndef HEAP_H
#define HEAP_H

typedef struct heap
{
	int* data;
	int size;
}HEAP;

void Heap_Create(HEAP* h, int* arr, int n);
void Heap_Insert(HEAP* h, int da);
void Heap_Destory(HEAP* h);
void Heap_DeTop(HEAP* h);
void Heap_Sort(int* arr, int n);
void Heap_Display(int* arr, int n);

#endif // !HEAP_H

