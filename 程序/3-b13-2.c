/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 

int main()
{
	int n, y, x, x0;   //�ꡢ�¡�����
	int r;

	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		r = scanf("%d %d", &n, &y);

		if (r == 2 && (n >= 2000 && n <= 2030) && (y >= 1 && y <= 12)) {
			break;
		}
		else if (r == 2) {
			printf("����Ƿ�������������\n");
		}
		else {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
		}
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", n, y);
		r = scanf("%d", &x);
		if (r == 1 && (x >= 0 && x <= 6)) {
			break;
		}
		else if (r == 1) {
			printf("����Ƿ�������������\n");
		}
		else {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
		}

	}
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", n, y);

	int i;
	for (i = 0; i < 7; i++) {
		switch (i)
		{
			case(0):
				printf("������  ");
				break;
			case(1):
				printf("����һ  ");
				break;
			case(2):
				printf("���ڶ�  ");
				break;
			case(3):
				printf("������  ");
				break;
			case(4):
				printf("������  ");
				break;
			case(5):
				printf("������  ");
				break;
			case(6):
				printf("������");
				break;

		}
	}
	printf("\n");
	x0 = x;
	int p;

	if ((n % 4 != 0) || (n % 100 == 0) && (n % 400 != 0))
	{
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 32; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 31) {
					printf("    ");
				}
			}
			printf("\n");
		}
		else if (y == 2)
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 29; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 28) {
					printf("    ");
				}
			}
			printf("\n");
		}
		else
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 31; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 30) {
					printf("    ");
				}
			}
			printf("\n");
		}
	}
	else
	{
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 32; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 31) {
					printf("    ");
				}
			}
			printf("\n");
		}
		else if (y == 2)
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 30; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 29) {
					printf("    ");
				}
			}
			printf("\n");
		}
		else
		{
			p = 1;
			while (p < (2 * x + 1) * 4) {
				printf(" ");
				p++;
			}
			for (i = 1; i < 31; i++)
			{
				if (i == 1) {
					printf("%d", i);
				}
				else if (x0 == 0) {
					printf("%4d", i);
				}
				else {
					printf("%8d", i);
				}

				x0++;

				if (x0 == 7) {
					printf("    \n");
					x0 = 0;
				}
				else if (i == 30) {
					printf("    ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}