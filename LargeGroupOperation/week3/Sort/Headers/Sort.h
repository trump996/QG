#ifndef  SORT_H
#define SORT_H

void InsertSort(long long int* a, long int n);
void MergeArray(long long int* a, long int begin, long int mid, long int end, long long int* temp);
void MergeSort(long long int* a, long int begin, long int end, long long int* temp);
void QuickSort_Recursion(long long int* a, long int begin, long int end);
void QuickSort(long long int* a, long int size);
void Partition(long long int* a, long int begin, long int end);
void CountSort(long long int* a, long int size);
void RadixCountSort(long long int* a, long int size);
void ColorSort(long long int* a, long int size);
long long int FindYourNum(long long int* a, long int start, long int end, int k);

#endif // ! SORT_H
