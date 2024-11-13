/* 2352018 ��06 ���� */
/* 2351440 ���Ӱ� 2353801 ������ 2351767 �ž��� 2352036 �״� 2351134 ������ 2351883 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROW 10
#define COL 26

int main() 
{
    char field[ROW][COL];
    int Count = 0;
    int i, j;
    int x, y;

    // ��ȡ����
    for (i = 0; i < ROW; i++) 
    {
        for (j = 0; j < COL; j++)
        {
            // ÿ�ζ�ȡһ���ַ�
            scanf(" %c", &field[i][j]); // ʹ�� %c ��ȡ�ַ��������Կհ��ַ�
            if (field[i][j] == '*') 
            {
                Count++; // ͳ���Ǻ�����
            }
        }
    }

    // ����׵ĸ����Ƿ�Ϊ50
    if (Count != 50) 
    {
        printf("����1\n");
        return 1;
    }

    // ���ÿ������λ����Χ������
    for (i = 0; i < ROW; i++) 
    {
        for (j = 0; j < COL; j++) 
        {
            if (field[i][j] >= '0' && field[i][j] <= '8') 
            {
                int count = 0;
                // �����Χ������
                for (x = -1; x <= 1; x++) 
                {
                    for (y = -1; y <= 1; y++) 
                    {
                        int i1 = i + x;
                        int j1 = j + y;
                        if (i1 >= 0 && i1 < ROW && j1 >= 0 && j1 < COL && field[i1][j1] == '*') 
                        {
                            count++;
                        }
                    }
                }
                // �Ƚϼ����������ʵ�ʵ�����
                if (field[i][j] != count + '0') 
                {
                    printf("����2\n");
                    return 1;
                }
            }
        }
    }

    // ������м�鶼ͨ��
    printf("��ȷ\n");
    return 0;
}