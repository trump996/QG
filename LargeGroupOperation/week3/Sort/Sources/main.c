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
		printf("��ӭ�����������ƽ̨��\n");
		printf("��ѡ����Ĳ��Է�ʽ��\n");
		printf("1.������������\n");
		printf("2.����С���ݲ���\n");
		printf("3.�˳�ϵͳ\n");

		if (scanf_s("%d", &Choice) == 1)
		{
			switch (Choice)
			{
				case 1:
				{
					system("cls");
					printf("��ѡ����Ĳ��Բ�Σ�������ѡ��\n");
					printf("10000��50000����200000\n");

					while (scanf_s("%ld", &Value) != 1 || (Value != 10000 && Value != 50000 && Value != 200000))
						printf("���������Ҫ��Ĳ�Σ�\n");

					Test(Value,1);
					printf("\n������'#'���������棡\n");

					getchar();
					while (getchar() != '#')
					{
						printf("������'#'���������棡\n");
						getchar();
					}
				}
				break;

				case 2:
				{
					system("cls");
					printf("������������������������100��\n");

					while(scanf_s("%ld", &Value) != 1 || Value < 0 || Value > 100)
						printf("���������Ҫ���������\n");

					printf("��������������Ե�����,����1000 ��\n");
					printf("��ܰ��ʾ����loop�ﵽʮ�򼶱�󣬼�ʱ��ܾã������Եȴ�!\n");

					while (scanf_s("%lld", &loop) != 1 || loop < 1000)
						printf("���������Ҫ���������\n");

					Test(Value, loop);

					printf("\n������'#'���������棡\n");
					getchar();
					while (getchar() != '#')
					{
						printf("������'#'���������棡\n");
						getchar();
					}
				}
				break;

				case 3:
					return 0;
				break;

				default:
					printf("���������Ҫ���ѡ�\n");
					break;
			}
		}
		else
			printf("���������Ҫ���ѡ�\n");
	}
}