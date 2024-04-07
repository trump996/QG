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

		printf("欢迎来到AVL树系统！\n");
		printf("您可以选择：\n");
		printf("1.初始化一棵AVL树\n");
		printf("2.插入节点\n");
		printf("3.删除节点\n");
		printf("4.遍历该AVL树\n");
		printf("5.销毁AVL树\n");
		printf("6.退出系统\n");

		while (scanf_s("%d", &Choice) != 1)
		{
			getchar();
			printf("请输入符合要求的选项！\n");
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
					printf("AVL初始化完成！\n");

					printf("请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("AVL树已经存在！\n");
					printf("请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
			}
			break;

			case 2:
			{
				system("cls");

				if (State == 1)
				{
					printf("请输入您想插入树中的整形数据：\n");

					while (1)
					{
						if (scanf_s("%d", &Value) != 1)
						{
							getchar();
							printf("请输入符合要求的整形数据！\n");
							continue;
						}

						if (AVL_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("该数据已存在！请重新输入新的数据！\n");
							continue;
						}
					}
					getchar();

					AVL_Insert(&Tree, Value);
					printf("数据插入完成！\n");

					printf("请输入#返回主菜单\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("AVL树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个AVL树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个AVL树先\n");
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
						printf("当前树为空，无法进行删除操作！\n");
						printf("请输入#返回主菜单！\n");
						while ((ch = getchar()) != '#')
						{
							getchar();
							printf("请输入#返回主菜单！\n");
						}
					}
					else
					{
						printf("请输入您想删除的树中的整形数据：\n");

						while (1)
						{
							if (scanf_s("%d", &Value) != 1)
							{
								getchar();
								printf("请输入符合要求的整形数据！\n");
								continue;
							}

							if (AVL_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("该数据不存在！请重新输入一个存在的数据！\n");
								continue;
							}
						}
						getchar();

						AVL_Delete(&Tree, Value);
						printf("数据删除完成！\n");

						printf("请输入#返回主菜单！\n");
						while ((ch = getchar()) != '#')
						{
							getchar();
							printf("请输入#返回主菜单！\n");
						}
					}
				}
				else
				{
					printf("AVL树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个AVL树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个AVL树先\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("当前树前序遍历如下：\n");
					AVL_preorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("当前树中序遍历如下：\n");
					AVL_inorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("当前树后序遍历如下：\n");
					AVL_postorderR(Tree, AVL_printnode);
					putchar('\n');
					printf("当前树层序遍历如下：\n");
					AVL_levelOrder(Tree, AVL_printnode);
					putchar('\n');

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("AVL树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个AVL树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个AVL树先\n");
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
					printf("销毁AVL树成功！\n");

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("AVL树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个AVL树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个AVL树先\n");
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
					printf("请先销毁存在的AVL树，释放空间！\n");

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