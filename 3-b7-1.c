/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double s;
	int a, b, c, d, e, p, q, x, y, z, sum, t;

    printf("����������ֵ��\n");
    scanf("%lf", &s);

    if (s >= 0.01 && s < 100) {
        sum = (int)(s * 100);

        a = sum / 5000; // 50Ԫ  
        b = (sum - 5000 * a) / 2000;// 20Ԫ  
        c = (sum - 5000 * a - 2000 * b) / 1000;// 10Ԫ  
        d = (sum - 5000 * a - 2000 * b - c * 1000) / 500;// 5Ԫ
        e = (sum - 5000 * a - 2000 * b - c * 1000 - 500 * d) / 100;// 1Ԫ
        p = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100) / 50);// 5��
        q = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p) / 10);// 1��
        x = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q) / 5);// 5��
        y = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q - x * 5) / 2);// 2��
        z = sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q - 5 * x - 2 * y;// 1��

        t = a + b + c + d + e + p + q + x + y + z;
        printf("��%d�����㣬�������£�\n", t);

        switch (a) {
            case 0:
                break;
            default:
                printf("50Ԫ : %d��\n", a);
                break;
        }
        switch (b) {
            case 0:
                break;
            default:
                printf("20Ԫ : %d��\n", b);
                break;
        }
        switch (c) {
            case 0:
                break;
            default:
                printf("10Ԫ : %d��\n", c);
                break;
        }
        switch (d) {
            case 0:
                break;
            default:
                printf("5Ԫ  : %d��\n", d);
                break;
        }
        switch (e) {
            case 0:
                break;
            default:
                printf("1Ԫ  : %d��\n", e);
                break;
        }
        switch (p) {
            case 0:
                break;
            default:
                printf("5��  : %d��\n", p);
                break;
        }
        switch (q) {
            case 0:
                break;
            default:
                printf("1��  : %d��\n", q);
                break;
        }
        switch (x) {
            case 0:
                break;
            default:
                printf("5��  : %d��\n", x);
                break;
        }
        switch (y) {
            case 0:
                break;
            default:
                printf("2��  : %d��\n", y);
                break;
        }
        switch (z) {
            case 0:
                break;
            default:
                printf("1��  : %d��\n", z);
                break;
        }
    }
    else {
        printf("�����������������");
    }

	return 0;
}