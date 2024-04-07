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

		printf("欢迎来到红黑树系统！\n");
		printf("您可以选择：\n");
		printf("1.初始化一棵红黑树\n");
		printf("2.插入节点\n");
		printf("3.删除节点\n");
		printf("4.遍历该红黑树\n");
		printf("5.销毁红黑树\n");
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
					RAB_Init(&Tree);
					State = 1;
					printf("红黑树初始化完成！\n");

					printf("请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("红黑树已经存在！\n");
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

						if (RAB_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("该数据已存在！请重新输入新的数据！\n");
							continue;
						}
					}
					getchar();

					RAB_Insert(&Tree, Value);
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
					printf("红黑树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个红黑树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个红黑树先\n");
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

							if (RAB_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("该数据不存在！请重新输入一个存在的数据！\n");
								continue;
							}
						}
						getchar();

						//RAB_Delete(&Tree, Value);
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
					printf("红黑树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个红黑树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个红黑树先\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("当前红黑树前序遍历如下：\n");
					RAB_preorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("当前红黑树中序遍历如下：\n");
					RAB_inorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("当前红黑树后序遍历如下：\n");
					RAB_postorderR(Tree, RAB_printnode);
					putchar('\n');
					printf("当前红黑树层序遍历如下：\n");
					RAB_levelOrder(Tree, RAB_printnode);
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
					printf("红黑树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个红黑树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个红黑树先\n");
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
					printf("销毁红黑树成功！\n");

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("红黑树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个红黑树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个红黑树先\n");
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
					printf("请先销毁存在的红黑树，释放空间！\n");

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