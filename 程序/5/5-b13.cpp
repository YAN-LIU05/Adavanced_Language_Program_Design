/* 2352018 ��06 ���� */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define ROW 10
#define COL 26

void print(int field[ROW][26])
{
    int i, j;
    for (i = 0; i < ROW; ++i)
    {
        for (j = 0; j < COL; ++j)
        {
            switch (field[i][j]) 
            {
                case 0:
                    cout << "0";
                    break;
                case -1:
                    cout << "*";
                    break;
                default:
                    cout << field[i][j];
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
}

void count(int field[ROW][COL])
{
    int i, j, r, c;
    int row, col;
    for (i = 0; i < ROW; ++i)
    {
        for (j = 0; j < COL; ++j)
        {
            if (field[i][j] == 0) { // ����λ��
                int count = 0;
                for (r = -1; r <= 1; ++r)
                {
                    for (c = -1; c <= 1; ++c)
                    {
                        row = i + r;
                        col = j + c;
                        if (row >= 0 && row < ROW && col >= 0 && col < COL && (r != 0 || c != 0))
                        {
                            if (field[row][col] == -1)
                            {
                                count++;
                            }
                        }
                    }
                }
                field[i][j] = count; // �洢��Χ������
            }
        }
    }
}

int main() 
{
    int field[ROW][COL] = { 0 }; // ��������
    int Count = 0; // �׵�����

    // ʹ�õ�ǰʱ����Ϊ��������ʼ�������������
    srand((unsigned int)(time(0)));

    // �������50����
    while (Count < 50) 
    {
        int row = rand() % ROW;
        int col = rand() % COL;
        if (field[row][col] == 0) // ȷ��λ�û�û����
        { 
            field[row][col] = -1; // ʹ��-1��ʾ��
            Count++;
        }
    }

    // ����ÿ������λ����Χ������
    count(field);

    // ��ӡ����
    print(field);

    return 0;
}