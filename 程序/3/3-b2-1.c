/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, a1, a2, a3, a4, a5;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &a);

	a5 = a % 10;
	a4 = (a / 10) % 10;
	a3 = (a / 100) % 10;
	a2 = (a / 1000) % 10;
	a1 = a / 10000;

	printf("��λ : %d\n", a1);
	printf("ǧλ : %d\n", a2);
	printf("��λ : %d\n", a3);
	printf("ʮλ : %d\n", a4);
	printf("��λ : %d\n", a5);

	return 0;
}