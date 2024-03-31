#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"
#include "fileandtest.h"

int main(void)
{
	int Choice;
	long int Value;
	long long int loop=0;

	while (true)
	{
		system("cls");
		printf("欢迎来到排序测试平台：\n");
		printf("请选择你的测试方式：\n");
		printf("1.大数据量测试\n");
		printf("2.大量小数据测试\n");
		printf("3.退出系统\n");

		if (scanf_s("%d", &Choice) == 1)
		{
			switch (Choice)
			{
				case 1:
				{
					system("cls");
					printf("请选择你的测试层次，您可以选择：\n");
					printf("10000、50000或者200000\n");

					while (scanf_s("%ld", &Value) != 1 || (Value != 10000 && Value != 50000 && Value != 200000))
						printf("请输入符合要求的层次！\n");

					Test(Value,1);
					printf("\n请输入'#'返回主界面！\n");

					getchar();
					while (getchar() != '#')
					{
						printf("请输入'#'返回主界面！\n");
						getchar();
					}
				}
				break;

				case 2:
				{
					system("cls");
					printf("请输入您的数据量，不大于100：\n");

					while(scanf_s("%ld", &Value) != 1 || Value < 0 || Value > 100)
						printf("请输入符合要求的数据量\n");

					printf("请在输入您想测试的轮数,大于1000 ：\n");
					printf("温馨提示：当loop达到十万级别后，计时会很久，请耐性等待!\n");

					while (scanf_s("%lld", &loop) != 1 || loop < 1000)
						printf("请输入符合要求的轮数：\n");

					Test(Value, loop);

					printf("\n请输入'#'返回主界面！\n");
					getchar();
					while (getchar() != '#')
					{
						printf("请输入'#'返回主界面！\n");
						getchar();
					}
				}
				break;

				case 3:
					return 0;
				break;

				default:
					printf("请输入符合要求的选项！\n");
					break;
			}
		}
		else
			printf("请输入符合要求的选项！\n");
	}
}