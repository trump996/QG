#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

int main(void)
{
	HEAP heap;
	int Choice, Value;
	int* array;
	char ch;
	bool State = 0;

	while (1)
	{
		system("cls");

		printf("欢迎来到堆系统！\n");
		printf("您可以选择：\n");
		printf("1.建堆\n");
		printf("2.堆插入\n");
		printf("3.删除堆顶\n");
		printf("4.堆排序\n");
		printf("5.销毁堆\n");
		printf("6.退出系统\n");

		while (scanf_s("%d", &Choice) != 1)
		{
			getchar();
			printf("请输入符合要求的选项！\n");
		}
		getchar();

		switch (Choice)
		{
			case 1://建堆
			{
				system("cls");

				if (State == 0)
				{
					printf("请先输入您想创建的堆的大小：\n");
					while (scanf_s("%d", &Value) != 1)
					{
						getchar();
						printf("请输入符合要求的整形！\n");
					}
					getchar();

					array = (int*)malloc(Value * sizeof(int));
					printf("接下来请依次写入这些数据：\n");
					for (int i = 0; i < Value; i++)
					{
						while (scanf_s("%d", &array[i]) != 1)
						{
							getchar();
							printf("请输入符合要求的选项！\n");
						}
						getchar();
					}

					Heap_Create(&heap, array, Value);
					free(array);
					State = 1;
					printf("堆建立完成！\n");

					printf("当前堆如下所示：\n");
					Heap_Display(heap.data, heap.size);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("堆已经存在！\n");
					printf("请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
			}
			break;

			case 2://插入
			{
				system("cls");

				if (State == 1)
				{
					printf("请输入您想插入堆中的整形数据：\n");

					while (scanf_s("%d", &Value) != 1)
					{
						getchar();
						printf("请输入符合要求的选项！\n");
					}
					getchar();

					Heap_Insert(&heap, Value);
					printf("数据插入完成！\n");

					printf("当前堆如下所示：\n");
					Heap_Display(heap.data, heap.size);

					printf("\n请输入#返回主菜单\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("堆呢老弟！\n");

					printf("请输入#返回主菜单，先创建一个堆先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先创建一个堆先\n");
					}
				}
			}
			break;

			case 3://删除堆顶
			{
				system("cls");

				if (State == 1)
				{
					Heap_DeTop(&heap);
					printf("删除堆顶完成！\n");

					printf("当前堆如下所示：\n");
					Heap_Display(heap.data, heap.size);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("堆呢老弟！\n");

					printf("请输入#返回主菜单，先创建一个堆先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先创建一个堆先\n");
					}
				}
			}
			break;

			case 4://堆排序
			{
				system("cls");

				if (State == 1)
				{
					Heap_Sort(heap.data, heap.size);
					printf("堆排序完毕！\n");

					printf("当前堆如下所示：\n");
					Heap_Display(heap.data, heap.size);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("堆呢老弟！\n");

					printf("请输入#返回主菜单，先创建一个堆先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先创建一个堆先\n");
					}
				}
			}
			break;

			case 5://销毁堆
			{
				system("cls");

				if (State == 1)
				{
					Heap_Destory(&heap);
					State = 0;
					printf("堆销毁完毕！\n");

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("堆呢老弟！\n");

					printf("请输入#返回主菜单，先创建一个堆先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先创建一个堆先\n");
					}
				}
			}
			break;

			case 6:
			{
				system("cls");

				if (State == 0)
					return 0;
				else
				{
					printf("请先销毁存在的堆，释放空间！\n");

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
			}
			break;

			default:
			{
				system("cls");
				printf("请输入符合要求的选项！\n");

				printf("请输入#返回主菜单\n");
				while ((ch = getchar()) != '#');
			}
			break;
		}
	}
}