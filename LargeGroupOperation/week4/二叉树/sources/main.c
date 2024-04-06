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

		printf("欢迎来到二叉树系统！\n");
		printf("您可以选择：\n");
		printf("1.初始化一棵二叉树\n");
		printf("2.插入节点\n");
		printf("3.删除节点\n");
		printf("4.前序遍历该二叉树\n");
		printf("5.中序遍历该二叉树\n");
		printf("6.后序遍历该二叉树\n");
		printf("7.层序遍历该二叉树\n");
		printf("8.销毁二叉树\n");
		printf("9.退出系统\n");

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
					BST_init(&Tree);
					State = 1;
					printf("二叉树初始化完成！\n");

					printf("请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树已经存在！\n");
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

						if (BST_search(Tree, Value) == NULL)
							break;
						else
						{
							printf("该数据已存在！请重新输入新的数据！\n");
							continue;
						}
					}
					getchar();

					BST_insert(&Tree, Value);
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
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
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

							if (BST_search(Tree, Value) != NULL)
								break;
							else
							{
								printf("该数据不存在！请重新输入一个存在的数据！\n");
								continue;
							}
						}
						getchar();

						BST_delete(&Tree, Value);
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
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					}
				}
			}
			break;

			case 4:
			{
				system("cls");

				if (State == 1)
				{
					printf("请选择：1.前序遍历递归版   2.前序遍历非递归\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("请输入符合要求的选项！\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("请输入符合要求的选项！\n");
							continue;
						}
					}
					getchar();

					printf("当前树前序遍历如下：\n");

					if (Choice == 1)
						BST_preorderR(Tree, BST_printnode);
					else
						BST_preorderI(Tree, BST_printnode);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					}
				}				
			}
			break;

			case 5:
			{
				system("cls");

				if (State == 1)
				{
					printf("请选择：1.中序遍历递归版   2.中序遍历非递归\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("请输入符合要求的选项！\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("请输入符合要求的选项！\n");
							continue;
						}
					}
					getchar();

					printf("当前树中序遍历如下：\n");

					if (Choice == 1)
						BST_inorderR(Tree, BST_printnode);
					else
						BST_inorderI(Tree, BST_printnode);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					}
				}
			}
			break;

			case 6:
			{
				system("cls");

				if (State == 1)
				{
					printf("请选择：1.后续遍历递归版   2.后续遍历非递归\n");

					while (1)
					{
						if (scanf_s("%d", &Choice) != 1)
						{
							getchar();
							printf("请输入符合要求的选项！\n");
							continue;
						}

						if (Choice == 1 || Choice == 2)
							break;
						else
						{
							printf("请输入符合要求的选项！\n");
							continue;
						}
					}
					getchar();

					printf("当前树后续遍历如下：\n");

					if (Choice == 1)
						BST_postorderR(Tree, BST_printnode);
					else
						BST_postorderI(Tree, BST_printnode);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					}
				}
			}
			break;

			case 7:
			{
				system("cls");

				if (State == 1)
				{
					printf("当前树层序遍历如下：\n");

					BST_levelOrder(Tree, BST_printnode);

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
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
					printf("销毁二叉树成功！\n");

					printf("\n请输入#返回主菜单！\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单！\n");
					}
				}
				else
				{
					printf("二叉树呢老弟！\n");

					printf("请输入#返回主菜单，先初始化一个二叉树先\n");
					while ((ch = getchar()) != '#')
					{
						getchar();
						printf("请输入#返回主菜单，先初始化一个二叉树先\n");
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
					printf("请先销毁存在的二叉树，释放空间！\n");

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
