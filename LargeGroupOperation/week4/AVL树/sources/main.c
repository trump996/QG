#include "AVL.h"
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

		printf("��ӭ����AVL��ϵͳ��\n");
		printf("������ѡ��\n");
		printf("1.��ʼ��һ��AVL��\n");
		printf("2.����ڵ�\n");
		printf("3.ɾ���ڵ�\n");
		printf("4.������AVL��\n");
		printf("5.����AVL��\n");
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
					AVL_Init(&Tree);
					State = 1;
					printf("AVL��ʼ����ɣ�\n");

					printf("������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("AVL���Ѿ����ڣ�\n");
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

						if (AVL_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("�������Ѵ��ڣ������������µ����ݣ�\n");
							continue;
						}
					}
					getchar();

					AVL_Insert(&Tree, Value);
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
					printf("AVL�����ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
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

							if (AVL_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("�����ݲ����ڣ�����������һ�����ڵ����ݣ�\n");
								continue;
							}
						}
						getchar();

						AVL_Delete(&Tree, Value);
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
					printf("AVL�����ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ǰ��ǰ��������£�\n");
					AVL_preorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("��ǰ������������£�\n");
					AVL_inorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("��ǰ������������£�\n");
					AVL_postorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("��ǰ������������£�\n");
					AVL_levelOrder(Tree, AVL_printnode);
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
					printf("AVL�����ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					}
				}
			}
			break;

			case 5:
			{
				system("cls");

				if (State == 1)
				{
					AVL_Destory(&Tree);
					State = 0;
					printf("����AVL���ɹ���\n");

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("AVL�����ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ��AVL����\n");
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
					printf("�������ٴ��ڵ�AVL�����ͷſռ䣡\n");

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