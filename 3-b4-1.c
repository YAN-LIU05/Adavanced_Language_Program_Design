/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h> 

int main()
{
	const double pi = 3.14159;
	int a, b, t;
	float S;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &t);

	S = (float)(a * b * sin(t * pi / 180)) / 2;
	printf("���������Ϊ : %.3f\n", S);

	return 0;
}