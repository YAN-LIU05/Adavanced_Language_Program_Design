/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char src, char tmp, char dst);
void init(int n, int arr[]);

// ȫ�ֱ�������
int A[10], B[10], C[10]; // Բ�̱������
int topA = 0, topB = 0, topC = 0; // ջ��ָ��
int Count = 0; // �ƶ�����������

char capital(char x)
{
    if (x == 'a' || x == 'A')
        x = 'A';
    if (x == 'B' || x == 'b')
        x = 'B';
    if (x == 'c' || x == 'C')
        x = 'C';
    return x;
}

void printTower(int tower[], char label) {
    printf("%c:", label);
    for (int i = 0; i < 10; ++i) {
        if (tower[i] == 0) {
            printf("  "); // �����ո��ʾû����
        }
        else {
            printf("%2d", tower[i]);
        }
    }
    printf(" ");
}
void print()
{
    printTower(A, 'A');
    printTower(B, 'B');
    printTower(C, 'C');
}

void moveA(char dst)
{
    int a;
    a = A[--topA];   // ��Դ�������Ƴ�һ��Բ��
    A[topA] = 0;
    if (dst == 'B')
    {
        B[topB++] = a;    // ��Բ���ƶ���Ŀ������
    }
    if (dst == 'C')
    {
        C[topC++] = a;
    }
}
void moveB(char dst)
{
    int b;
    b = B[--topB];
    B[topB] = 0;
    if (dst == 'A')
    {
        A[topA++] = b;
    }
    if (dst == 'C')
    {
        C[topC++] = b;
    }
}
void moveC(char dst)
{
    int c;
    c = C[--topC];
    C[topC] = 0;
    if (dst == 'A')
    {
        A[topA++] = c;
    }
    if (dst == 'B')
    {
        B[topB++] = c;
    }
}
void move(char src, char dst)
{
    if (src == 'A')
        moveA(dst);
    if (src == 'B')
        moveB(dst);
    if (src == 'C')
        moveC(dst);
}

int main()
{
    int n, ret, ret1, ret2, i;
    char src, dst, tmp = 0;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-10):\n");
        ret = scanf("%d", &n);
        if (ret == 1 && n >= 1 && n <= 10)
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
        ret1 = scanf("%c", &src);
        src = capital(src);
        if (ret1 == 1 && (src >= 'A' && src <= 'C'))
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
        ret2 = scanf("%c", &dst);
        dst = capital(dst);
        if (dst == src)
        {
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
            while (getchar() != '\n');
        }
        else if (ret2 == 1 && (dst >= 'A' && dst <= 'C'))
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
        }
    }
    src = capital(src);
    dst = capital(dst);
    if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
        tmp = 'A';
    if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
        tmp = 'B';
    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
        tmp = 'C';   //ȷ��������

    //��ʼ��Բ��
    if (src == 'A')
    {
        init(n, A);
        topA = n;
    }
    if (src == 'B')
    {
        init(n, B);
        topB = n;
    }
    if (src == 'C')
    {
        init(n, C);
        topC = n;
    }

    // ��ӡ��ʼ״̬
    printf("��ʼ:");
    printf("                ");
    printf("A:");
    for (i = 0; i < 10; i++)
    {
        if (A[i] != 0)
        {
            printf("%2d", A[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf(" ");
    printf("B:");
    for (i = 0; i < 10; i++)
    {
        if (B[i] != 0)
        {
            printf("%2d", B[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf(" ");
    printf("C:");
    for (i = 0; i < 10; i++)
    {
        if (C[i] != 0)
        {
            printf("%2d", C[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf("\n");

    // �ݹ����
    hanoi(n, src, tmp, dst);
    return 0;
}
// ��ʼ��Բ��
void init(int n, int arr[]) 
{
        for (int i = 0; i < n; i++) 
        {
            arr[i] = n - i ;
        }
}

// ��ŵ������
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) 
    {
        Count++; // �����ƶ�����
        printf("��%4d��(%2d):%c-->%c   ", Count, n, src, dst);   // ��ӡ�ƶ�����
        move(src, dst);
        // ��ӡԲ��
        print();
        printf("\n");
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        Count++;

        printf("��%4d��(%2d):%c-->%c   ", Count, n, src, dst);
        move(src, dst);
        // ��ӡԲ��
        print();
        printf("\n");
        hanoi(n - 1, tmp, src, dst);
    }
}