/* 2352018 ��06 ���� */
#include <iostream>  
using namespace std;

bool check(int sudoku[9][9]) 
{
    int row[9][10] = { 0 }; // ���ڼ����
    int col[9][10] = { 0 }; // ���ڼ����
    int box[3][3][10] = { 0 }; // ���ڼ��3x3����

    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++)
        {
            int num = sudoku[i][j];
            if (num > 0 && num <= 9) 
            {
                // �����
                if (row[i][num]) 
                    return false;
                row[i][num] = 1;
                // �����
                if (col[j][num]) 
                    return false;
                col[j][num] = 1;
                // ���3x3����
                int box_row = i / 3;
                int box_col = j / 3;
                if (box[box_row][box_col][num]) 
                    return false;
                box[box_row][box_col][num] = 1;
            }
            else if (num != 0) 
                // ������ֲ���0�Ҳ���1-9֮�䣬˵��������Ч
                return false;
        }
    }
    return true;
}

int main() 
{
    int i = 0, j = 0;
    int sudoku[9][9];
    cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

    while (1) {
        cin >> sudoku[i][j];
        if (cin.good() && sudoku[i][j] >= 1 && sudoku[i][j] <= 9) 
        {
            j++;
            if (j == 9) 
            {
                i++;
                j = 0;
            }
            if (i == 9) 
            {
                break;
            }
        }
        else if (cin.good()) 
        {
            cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
        }
        else 
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
        }
    }
    if (check(sudoku)) 
    {
        cout << "�������Ľ�" << endl;
    }
    else
    {
        cout << "���������Ľ�" << endl;
    }

    return 0;
}