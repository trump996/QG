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

		printf("��ӭ������ϵͳ��\n");
		printf("������ѡ��\n");
		printf("1.����\n");
		printf("2.�Ѳ���\n");
		printf("3.ɾ���Ѷ�\n");
		printf("4.������\n");
		printf("5.���ٶ�\n");
		printf("6.�˳�ϵͳ\n");

		while (scanf_s("%d", &Choice) != 1)
		{
			getchar();
			printf("���������Ҫ���ѡ�\n");
		}
		getchar();

		switch (Choice)
		{
			case 1://����
			{
				system("cls");

				if (State == 0)
				{
					printf("�����������봴���ĶѵĴ�С��\n");
					while (scanf_s("%d", &Value) != 1)
					{
						getchar();
						printf("���������Ҫ������Σ�\n");
					}
					getchar();

					array = (int*)malloc(Value * sizeof(int));
					printf("������������д����Щ���ݣ�\n");
					for (int i = 0; i < Value; i++)
					{
						while (scanf_s("%d", &array[i]) != 1)
						{
							getchar();
							printf("���������Ҫ���ѡ�\n");
						}
						getchar();
					}

					Heap_Create(&heap, array, Value);
					free(array);
					State = 1;
					printf("�ѽ�����ɣ�\n");

					printf("��ǰ��������ʾ��\n");
					Heap_Display(heap.data, heap.size);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���Ѿ����ڣ�\n");
					printf("������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
			}
			break;

			case 2://����
			{
				system("cls");

				if (State == 1)
				{
					printf("���������������е��������ݣ�\n");

					while (scanf_s("%d", &Value) != 1)
					{
						getchar();
						printf("���������Ҫ���ѡ�\n");
					}
					getchar();

					Heap_Insert(&heap, Value);
					printf("���ݲ�����ɣ�\n");

					printf("��ǰ��������ʾ��\n");
					Heap_Display(heap.data, heap.size);

					printf("\n������#�������˵�\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("�����ϵܣ�\n");

					printf("������#�������˵����ȴ���һ������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȴ���һ������\n");
					}
				}
			}
			break;

			case 3://ɾ���Ѷ�
			{
				system("cls");

				if (State == 1)
				{
					Heap_DeTop(&heap);
					printf("ɾ���Ѷ���ɣ�\n");

					printf("��ǰ��������ʾ��\n");
					Heap_Display(heap.data, heap.size);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("�����ϵܣ�\n");

					printf("������#�������˵����ȴ���һ������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȴ���һ������\n");
					}
				}
			}
			break;

			case 4://������
			{
				system("cls");

				if (State == 1)
				{
					Heap_Sort(heap.data, heap.size);
					printf("��������ϣ�\n");

					printf("��ǰ��������ʾ��\n");
					Heap_Display(heap.data, heap.size);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("�����ϵܣ�\n");

					printf("������#�������˵����ȴ���һ������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȴ���һ������\n");
					}
				}
			}
			break;

			case 5://���ٶ�
			{
				system("cls");

				if (State == 1)
				{
					Heap_Destory(&heap);
					State = 0;
					printf("��������ϣ�\n");

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("�����ϵܣ�\n");

					printf("������#�������˵����ȴ���һ������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȴ���һ������\n");
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
					printf("�������ٴ��ڵĶѣ��ͷſռ䣡\n");

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
			}
			break;

			default:
			{
				system("cls");
				printf("���������Ҫ���ѡ�\n");

				printf("������#�������˵�\n");
				while ((ch = getchar()) != '#');
			}
			break;
		}
	}
}