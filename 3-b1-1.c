/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double r, h, C, S1, S2, V1, V2;
	const double pi = 3.14159;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &r, &h);

	C = pi * r * 2;
	S1 = pi * r * r;
	S2 = pi * 4 * r * r;
	V1 = (4 * pi * r * r * r) / 3;
	V2 = S1 * h;

	printf("Բ�ܳ�     : %.2lf\n", C);
	printf("Բ���     : %.2lf\n", S1);
	printf("Բ������ : %.2lf\n", S2);
	printf("Բ�����   : %.2lf\n", V1);
	printf("Բ�����   : %.2lf\n", V2);

	return 0;
}