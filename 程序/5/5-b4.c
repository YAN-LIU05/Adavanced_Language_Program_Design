/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
  
int main()
{
    int scores[1000];
    int count[101] = { 0 };
    int x = 0;
    int score;

    printf("������ɼ������1000������������������\n");

    while (x < 1000 && scanf("%d", &score) && score >= 0)
    {
        scores[x++] = score;
        if (score <= 100)
        {
            count[score]++;
        }
    }
    if (x == 0)
    {
        printf("����Ч����\n");
        return 0;
    }
    printf("���������Ϊ:\n");
    for (int i = 0; i < x; ++i)
    {
        printf("%d ", scores[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    printf("�����������Ķ�Ӧ��ϵΪ:\n");
    for (int i = 100; i >= 0; --i)
    {
        if (count[i] > 0)
        {
            printf("%d %d\n", i, count[i]);
        }
    }
    printf("\n");

    return 0;
}