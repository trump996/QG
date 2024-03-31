#include "fileandtest.h"
#include "Sort.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CreatDataToFile(long int num,long long int loop)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, "data.txt", "w");

	if (err != 0)
		exit(1);

	fseek(fp, 0, SEEK_SET);

	for (long long int j = 0; j < loop; j++)
	{
		fputc('#', fp);
		unsigned int next = 1;
		for (long int i = 0; i < num; i++)
		{
			srand(next);
			long long int data = rand();
			fprintf(fp, "%lld\t", data);
			next = next * 1103515245 + 12345;
		}
	}
	fputc(EOF, fp);

	fclose(fp);
	fp = NULL;
}

void ReadDataToArray(long int num, long long int** data)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, "data.txt", "r");

	if (err != 0)
		exit(1);

	fseek(fp, 0, SEEK_SET);

	long long int j = 0;
	char ch;
	while ((ch=fgetc(fp))!=EOF)
	{
		for (long int i = 0; i < num; i++)
		{
			fscanf_s(fp, "%lld", &data[j][i]);
			fgetc(fp);
		}
		j++;
	}

	fclose(fp);
	fp = NULL;

	return;
}

void Test_InsertSort(long int size, long long loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size,data);

	start = clock();
	for (long long int i = 0; i<loop;i++)
		InsertSort(data[i], size);
	end = clock();

	printf("�����������ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test_MergeSort(long int size,long long int loop)
{
	time_t start,end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	long long int** temp = (long long int**)malloc(loop * sizeof(long long int*));
	if (temp == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		temp[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for(long long int i=0;i<loop;i++)
		MergeSort(data[i], 0, size - 1, temp[i]);
	end = clock();

	printf("�鲢�������ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	free(temp);
	return;
}

void Test_QuickSort_Recursion(long int size,long long int loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for(long long int i=0;i<loop;i++)
		QuickSort_Recursion(data[i], 0, size - 1);
	end = clock();

	printf("�������򣨵ݹ�棩����ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test_QuickSort(long int size,long long int loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for (long long int i = 0; i < loop; i++)
		QuickSort(data[i], size);
	end = clock();

	printf("�����������ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test_Partition(long int size,long long int loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for (long long int i = 0; i < loop; i++)
		Partition(data[i], 0, size - 1);
	end = clock();
	printf("�������������ţ�����ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test_CountSort(long int size,long long int loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for (long long int i = 0; i < loop; i++)
		CountSort(data[i], size);
	end = clock();
	printf("�����������ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test_RadixCountSort(long int size,long long int loop)
{
	time_t start, end;

	long long int** data = (long long int**)malloc(loop * sizeof(long long int*));
	if (data == NULL)
		return;
	for (long long int i = 0; i < loop; i++)
		data[i] = (long long int*)malloc(size * sizeof(long long int));

	ReadDataToArray(size, data);

	start = clock();
	for (long long int i = 0; i < loop; i++)
		RadixCountSort(data[i], size);
	end = clock();
	printf("���������������ʱΪ:%f��\n", ((double)(end - start)) / CLK_TCK);

	free(data);
	return;
}

void Test(long int size,long long loop)
{
	CreatDataToFile(size,loop);

	system("cls");
	printf("��Ϊ��������ɲ�������\n");
	printf("���Խ�����ڻ��ٸ���ս�������Եȣ�\n\n");
	if (loop >= 10000)
		printf("������ã������ĵȴ�\n\n");

	Test_InsertSort(size,loop);
	Test_MergeSort(size,loop);
	Test_QuickSort_Recursion(size,loop);
	Test_QuickSort(size,loop);
	Test_Partition(size,loop);
	Test_CountSort(size,loop);
	Test_RadixCountSort(size,loop);
	
	return;
}