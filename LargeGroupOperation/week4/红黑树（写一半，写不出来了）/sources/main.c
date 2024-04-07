#include "redandblack.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

NodePtr Tree;

int main(void)
{
	int Choice, Value;
	char ch;
	bool State = 0;

	while (1)
	{
		system("cls");

		printf("��ӭ���������ϵͳ��\n");
		printf("������ѡ��\n");
		printf("1.��ʼ��һ�ú����\n");
		printf("2.����ڵ�\n");
		printf("3.ɾ���ڵ�\n");
		printf("4.�����ú����\n");
		printf("5.���ٺ����\n");
		printf("6.�˳�ϵͳ\n");

		while (scanf_s("%d", &Choice) != 1)
		{
			getchar();
			printf("���������Ҫ���ѡ�\n");
		}
		getchar();

		switch (Choice)
		{
			case 1:
			{
				system("cls");

				if (State == 0)
				{
					RAB_Init(&Tree);
					State = 1;
					printf("�������ʼ����ɣ�\n");

					printf("������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("������Ѿ����ڣ�\n");
					printf("������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
			}
			break;

			case 2:
			{
				system("cls");

				if (State == 1)
				{
					printf("����������������е��������ݣ�\n");

					while (1)
					{
						if (scanf_s("%d", &Value) != 1)
						{
							getchar();
							printf("���������Ҫ����������ݣ�\n");
							continue;
						}

						if (RAB_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("�������Ѵ��ڣ������������µ����ݣ�\n");
							continue;
						}
					}
					getchar();

					RAB_Insert(&Tree, Value);
					printf("���ݲ�����ɣ�\n");

					printf("������#�������˵�\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("��������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ���������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ���������\n");
					}
				}
			}
			break;

			case 3:
			{
				system("cls");

				if (State == 1)
				{
					if (Tree == NULL)
					{
						printf("��ǰ��Ϊ�գ��޷�����ɾ��������\n");
						printf("������#�������˵���\n");
						while ((ch = getchar()) != '#')
						{
							getchar();
							printf("������#�������˵���\n");
						}
					}
					else
					{
						printf("����������ɾ�������е��������ݣ�\n");

						while (1)
						{
							if (scanf_s("%d", &Value) != 1)
							{
								getchar();
								printf("���������Ҫ����������ݣ�\n");
								continue;
							}

							if (RAB_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("�����ݲ����ڣ�����������һ�����ڵ����ݣ�\n");
								continue;
							}
						}
						getchar();

						//RAB_Delete(&Tree, Value);
						printf("����ɾ����ɣ�\n");

						printf("������#�������˵���\n");
						while ((ch = getchar()) != '#')
						{
							getchar();
							printf("������#�������˵���\n");
						}
					}
				}
				else
				{
					printf("��������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ���������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ���������\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ǰ�����ǰ��������£�\n");
					RAB_preorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("��ǰ���������������£�\n");
					RAB_inorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("��ǰ���������������£�\n");
					RAB_postorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("��ǰ���������������£�\n");
					RAB_levelOrder(Tree, RAB_printnode);
					putchar('\n');

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("��������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ���������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ���������\n");
					}
				}
			}
			break;

			case 5:
			{
				system("cls");

				if (State == 1)
				{
					//RAB_Destory(&Tree);
					State = 0;
					printf("���ٺ�����ɹ���\n");

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("��������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ���������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ���������\n");
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
					printf("�������ٴ��ڵĺ�������ͷſռ䣡\n");

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