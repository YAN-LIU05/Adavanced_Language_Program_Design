/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  

int main() {
    int ret, x, c;

    while (1) {
        printf("������x��ֵ[0-100] : ");
        ret = scanf("%d", &x);
        if (ret == 1) {
            if (x >= 0 && x <= 100) {
                break;
            }
            else {
                printf("�����д�[ret=%d x=%d],����������\n", ret, x);   // ������ֵ������Χ����ӡ������Ϣ������ѭ��  
            }
        }
        else {
            printf("�����д�[ret=%d x=%d],����������\n", ret, x); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
            while ((c = getchar()) != '\n');   // ������뻺������ֱ���������з� 
        }
    }

    printf("ret=%d x=%d\n", ret, x);

    return 0;
}