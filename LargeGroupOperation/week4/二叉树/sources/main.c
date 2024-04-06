#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

NodePtr Tree;

int main(void)
{
	int Choice, Value;
	char ch;
	bool State=0;

	while (1)
	{
		system("cls");

		printf("��ӭ����������ϵͳ��\n");
		printf("������ѡ��\n");
		printf("1.��ʼ��һ�ö�����\n");
		printf("2.����ڵ�\n");
		printf("3.ɾ���ڵ�\n");
		printf("4.ǰ������ö�����\n");
		printf("5.��������ö�����\n");
		printf("6.��������ö�����\n");
		printf("7.��������ö�����\n");
		printf("8.���ٶ�����\n");
		printf("9.�˳�ϵͳ\n");

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
					BST_init(&Tree);
					State = 1;
					printf("��������ʼ����ɣ�\n");

					printf("������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("�������Ѿ����ڣ�\n");
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

						if (BST_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("�������Ѵ��ڣ������������µ����ݣ�\n");
							continue;
						}
					}
					getchar();

					BST_insert(&Tree, Value);
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
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
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

							if (BST_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("�����ݲ����ڣ�����������һ�����ڵ����ݣ�\n");
								continue;
							}
						}
						getchar();

						BST_delete(&Tree, Value);
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
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ѡ��1.ǰ������ݹ��   2.ǰ������ǵݹ�\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("���������Ҫ���ѡ�\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("���������Ҫ���ѡ�\n");
							continue;
						}
					}
					getchar();

					printf("��ǰ��ǰ��������£�\n");

					if (Choice == 1)
						BST_preorderR(Tree, BST_printnode);
					else
						BST_preorderI(Tree, BST_printnode);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}				
			}
			break;

			case 5:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ѡ��1.��������ݹ��   2.��������ǵݹ�\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("���������Ҫ���ѡ�\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("���������Ҫ���ѡ�\n");
							continue;
						}
					}
					getchar();

					printf("��ǰ������������£�\n");

					if (Choice == 1)
						BST_inorderR(Tree, BST_printnode);
					else
						BST_inorderI(Tree, BST_printnode);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}
			}
			break;

			case 6:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ѡ��1.���������ݹ��   2.���������ǵݹ�\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("���������Ҫ���ѡ�\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("���������Ҫ���ѡ�\n");
							continue;
						}
					}
					getchar();

					printf("��ǰ�������������£�\n");

					if (Choice == 1)
						BST_postorderR(Tree, BST_printnode);
					else
						BST_postorderI(Tree, BST_printnode);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}
			}
			break;

			case 7:
			{
				system("cls");

				if (State == 1)
				{
					printf("��ǰ������������£�\n");

					BST_levelOrder(Tree, BST_printnode);

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}
			}
			break;

			case 8:
			{
				system("cls");

				if (State == 1)
				{
					BST_destory(Tree);
					State = 0;
					printf("���ٶ������ɹ���\n");

					printf("\n������#�������˵���\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵���\n");
					}
				}
				else
				{
					printf("���������ϵܣ�\n");

					printf("������#�������˵����ȳ�ʼ��һ����������\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("������#�������˵����ȳ�ʼ��һ����������\n");
					}
				}
			}
			break;

			case 9:
			{
				system("cls");

				if(State==0)
					return 0;
				else
				{
					printf("�������ٴ��ڵĶ��������ͷſռ䣡\n");

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
