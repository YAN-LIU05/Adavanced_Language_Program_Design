/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int num;

    if (n == 1)
    {
        ++num;
        printf("%5d:%3d# %c-->%c\n", num, n, src, dst);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        ++num;
        printf("%5d:%3d# %c-->%c\n", num, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int storey;
    int ret;
    char src, dst, tmp;
    tmp = 0;

    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret = scanf("%d", &storey);
        if (ret == 1 && storey >= 1 && storey <= 16)
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
        }
    }
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &src);
        if (src == 'a' || src == 'A')
            src = 'A';
        if (src == 'B' || src == 'b')
            src = 'B';
        if (src == 'c' || src == 'C')
            src = 'C';
        if (ret == 1 && (src >= 'A' && src <= 'C'))
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
        }
    }
    while (1)
    {
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &dst);
        if (dst == 'a' || dst == 'A')
            dst = 'A';
        if (dst == 'b' || dst == 'B')
            dst = 'B';
        if (dst == 'c' || dst == 'C')
            dst = 'C';
        if (dst == src)
        {
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
            while (getchar() != '\n');
        }
        else if (ret == 1 && (dst >= 'A' && dst <= 'C'))
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
        }
    }

    if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C') || (src == 'c' || src == 'C') && (dst == 'b' || dst == 'B'))
        tmp = 'A';
    if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C') || (src == 'c' || src == 'C') && (dst == 'a' || dst == 'A'))
        tmp = 'B';
    if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B') || (src == 'b' || src == 'B') && (dst == 'a' || dst == 'A'))
        tmp = 'C';

    printf("�ƶ�����Ϊ:\n");
    hanoi(storey, src, tmp, dst);
    return 0;
}