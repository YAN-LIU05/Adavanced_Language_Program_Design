/* 2352018 ��06 ���� */
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "magic_ball.h"

using namespace std;

/***************************************************************************
  �������ƣ�ball_base_all
  ��    �ܣ�base�Ļ��ܺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int ball_base_all(int choice)
{
    int rows, cols;
    int x, y;
    int X = 0, Y = 0;   //���λ��
    int ret, maction;
    int keycode1, keycode2;
    int loop = 1;
    char hang;
    int lie;
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };   //��������

    // ������֤
    while (1)
    {
        cout << "����������(5-9)��" << endl;
        cin >> rows;

        if (rows >= MIN_ROWS && rows <= MAX_ROWS)
            break;
        else if (!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
    while (1)
    {
        cout << "����������(5-9)��" << endl;
        cin >> cols;

        if (cols >= MIN_COLS && cols <= MAX_COLS)
            break;
        else if (!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    int array[MAX_ROWS][MAX_COLS];   //�������Ϊ�����
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            array[i][j] = (rand() % 9) + 1;
    }
    print_origin(rows, cols, array);
    if (choice > 0 && choice <= 3)
        cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
    if (choice == 4)
        cout << "���س�����ʾͼ��...";
    cct_getxy(x, y);

    char ch = _getch();
    while (1)
    {
        if (ch == '\r')
            break;
        ch = _getch();
    }
    // ��ӡ��ʼ����ͱ�ʶ��������
    if (base_check1(array, rows, cols))
    {
        switch (choice)
        {
            case 1:
                print_mark(rows, cols, array);
                break;
            case 2:
            case 3:
                base_remove(array, rows, cols, choice);
                break;
            case 4:
            case 6:
                cct_cls();
                int a, b, c, d;
                cct_getconsoleborder(a, b, c, d);
                cct_setcolor();
                cct_cls();
                d = cols + 5;
                c = rows * 2 + 4;
                cct_setconsoleborder(c + 25, d + 5);
                cct_gotoxy(0, 0);
                cct_setfontsize("������", 28);
                cout << "��Ļ��" << d + 1 << "��" << 40 << "��";
                draw_border(rows, cols, 0, choice);
                if (choice == 4)
                {
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            draw_ball(i, j, array[i][j], 0);
                            Sleep(TIME);
                        }
                    }
                }
                if (choice == 6)
                {

                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            x = 2 * j + 2;
                            y = i + 2;
                            cct_gotoxy(x, y);
                            cct_setcolor(array[i][j], COLOR_BLACK);
                            if (base_check0(array, i, j, rows, cols))
                                cout << "��";
                            else
                                cout << "��";
                            cct_gotoxy(x, y + 1);
                        }
                    }
                }
                cct_setcolor();
                set_botton(0, 0);
                break;
            case 5:
            case 7:
            case 8:
                cct_cls();
                cct_getconsoleborder(a, b, c, d);
                cct_setcolor();
                cct_cls();
                d = 2 * cols + 5;
                c = rows * 4 + 4;
                cct_setconsoleborder(c + 25, d + 4);
                cct_gotoxy(0, 0);
                cct_setfontsize("������", 28);
                cout << "��Ļ��" << d << "��" << 40 << "��";
                if (choice == 8)
                {
                    cout << "(��ǰ������0 �Ҽ��˳�)";
                }
                draw_border(rows, cols, 1, choice);
                if (choice == 5)
                {
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            draw_ball(i, j, array[i][j], 1);
                            Sleep(TIME);
                        }
                    }
                }
                if (choice == 7 || choice == 8)
                {

                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            x = 4 * j + 2;
                            y = 2 * i + 2;
                            cct_gotoxy(x, y);
                            cct_setcolor(array[i][j], COLOR_BLACK);
                            if (base_check0(array, i, j, rows, cols))
                                cout << "��";
                            else
                                cout << "��";
                            cct_gotoxy(x, y + 1);
                        }

                    }
                    int array0[MAX_ROWS][MAX_COLS];
                    for (int i = 0; i < rows; ++i) {
                        for (int j = 0; j < cols; ++j) {
                            array0[i][j] = array[i][j];
                        }
                    }

                   
                    if (choice == 8)
                    {
                        while (1)
                        {
                            draw_fall(array, rows, cols, choice, array0, 0);
                            for (int i = 0; i < rows; ++i)
                            {
                                for (int j = 0; j < cols; ++j)
                                    array[i][j] = array0[i][j];
                            }
                            for (int i = 0; i < rows; ++i)
                            {
                                for (int j = 0; j < cols; ++j)
                                {
                                    // ��鲢��ǿ�������
                                    if (base_check2(array, directions, i, j, rows, cols))
                                    {
                                        draw_ball(i, j, array[i][j], 2);
                                    }

                                }
                            }
                            if (base_check1(array, rows, cols))
                                continue;
                            else
                                break;

                        }
                    }
                }
                if (choice == 8)
                {
                    int x8, y8;
                    x8 = 0;
                    y8 = 2 * rows + 2;
                    cct_enable_mouse();
                    cct_setcursor(CURSOR_INVISIBLE);
                    while (loop)
                    {
                        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

                        cout << "[��ǰ���] ";

                        if (ret == CCT_MOUSE_EVENT)
                        {
                            if (X <= 4 * cols && Y <= 2 * rows + 1)
                            {
                                hang = 'A' + Y / 2 - 1;
                                lie = int(X / 4) + 1;
                                if ((X % 4 == 2 || X % 4 == 3) && Y % 2 == 0 && Y > 0)
                                {
                                    cout << hang << "��" << lie << "��";

                                    switch (maction)
                                    {
                                        case MOUSE_LEFT_BUTTON_CLICK:
                                            if (base_check2(array, directions, Y / 2 - 1, lie - 1, rows, cols))
                                            {
                                                cct_gotoxy(x8, y8);
                                                cout << "��ǰѡ��" << hang << "��" << lie << "��";
                                                Sleep(TIME * 20);

                                                loop = 0;
                                            }
                                            else
                                            {
                                                cct_gotoxy(x8, y8);
                                                cout << "����ѡ��" << hang << "��" << lie << "��";
                                            }
                                            break;
                                        case MOUSE_RIGHT_BUTTON_CLICK:
                                            loop = 0;
                                            cct_gotoxy(x8, y8);
                                            break;
                                    }
                                }

                                else
                                {
                                    cout << "λ�÷Ƿ�";
                                }
                                cout << "        ";
                                cct_gotoxy(x8, y8);

                            }
                            else
                            {
                                cout << "λ�÷Ƿ�";
                                cout << "        ";
                                cct_gotoxy(x8, y8);
                            }
                        }
                    }
                }
                cct_setcolor();
                set_botton(0, 0);
                break;
              case 9:
                draw_nine(array, rows, cols, choice);
                set_botton(0, 0);
                break;
        }
        if (choice != 7 && choice != 8 && choice != 9)
            cout << endl;
    }

    else
    {
        switch (choice)
        {
            case 1:
            case 2:
                cct_gotoxy(x, y);
                cout << "��ʼ�޿��������С���޷����ԣ����ٴ�����";
                break;
            case 3:
                cct_gotoxy(x, y);
                cout << "��ʼ�޿�������" << endl;
                print_tips(rows, cols, array);
                break;
            case 4:
            case 6:
                cct_cls();
                int a, b, c, d;
                cct_getconsoleborder(a, b, c, d);
                cct_setcolor();
                cct_cls();

                d = cols + 5;
                c = rows * 2 + 4;
                cct_setconsoleborder(c + 25, d + 5);
                cct_gotoxy(0, 0);
                cct_setfontsize("������", 28);
                cout << "��Ļ��" << d + 1 << "��" << 40 << "��";
                draw_border(rows, cols, 0, choice);

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        draw_ball(i, j, array[i][j], 0);
                        if (choice == 4)
                            Sleep(TIME);
                    }
                }

                cct_setcolor();
                set_botton(0, 0);
                break;
            case 5:
            case 7:
            case 8:
                cct_cls();
                cct_getconsoleborder(a, b, c, d);
                cct_setcolor();
                cct_cls();

                d = 2 * cols + 5;
                c = rows * 4 + 4;
                cct_setconsoleborder(c + 25, d + 4);

                cct_gotoxy(0, 0);
                cct_setfontsize("������", 28);
                cout << "��Ļ��" << d << "��" << 40 << "��";
                if (choice == 7)
                {
                    cout << "(δ�ҵ���ʼ��������)";
                }

                if (choice == 8)
                {
                    cout << "(��ǰ������0 �Ҽ��˳�)";
                }


                draw_border(rows, cols, 1, choice);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        draw_ball(i, j, array[i][j], 1);
                        if (choice == 5)
                            Sleep(TIME);
                    }
                }
                if (choice == 7 || choice == 8)
                {
                    int x0, y0;
                    cout << endl;
                    cct_getxy(x0, y0);
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
                    if (choice == 7)
                    {
                        cout << "���س�����ʾ������ʾ...";

                        char ch3 = _getch();
                        while (1)
                        {
                            if (ch3 == '\r')
                                break;
                            ch3 = _getch();
                        }
                    }



                    for (int i = 0; i < rows; ++i)
                    {
                        for (int j = 0; j < cols; ++j)
                        {
                            // ��鲢��ǿ�������
                            if (base_check2(array, directions, i, j, rows, cols))
                            {
                                draw_ball(i, j, array[i][j], 2);
                            }

                        }
                    }
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
                    cct_gotoxy(x0, y0);
                }

                if (choice == 8)
                {
                    int x8, y8;
                    cct_enable_mouse();
                    cct_setcursor(CURSOR_INVISIBLE);
                    while (loop)
                    {
                        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
                        cct_getxy(x8, y8);
                        cct_gotoxy(x8, y8);
                        cout << "[��ǰ���] ";

                        if (ret == CCT_MOUSE_EVENT)
                        {
                            if (X <= 4 * cols && Y <= 2 * rows + 1)
                            {
                                hang = 'A' + Y / 2 - 1;
                                lie = int(X / 4) + 1;
                                if ((X % 4 == 2 || X % 4 == 3) && Y % 2 == 0 && Y > 0)
                                {
                                    cout << hang << "��" << lie << "��";
                                    switch (maction)
                                    {
                                        case MOUSE_LEFT_BUTTON_CLICK:
                                            if (base_check2(array, directions, Y / 2 - 1, lie - 1, rows, cols))
                                            {
                                                cct_gotoxy(x8, y8);
                                                cout << "��ǰѡ��" << hang << "��" << lie << "��";
                                                loop = 0;
                                            }
                                            else
                                            {
                                                cct_gotoxy(x8, y8);
                                                cout << "����ѡ��" << hang << "��" << lie << "��";
                                            }
                                            break;
                                        case MOUSE_RIGHT_BUTTON_CLICK:
                                            loop = 0;
                                            cct_gotoxy(x8, y8);
                                            break;
                                    }
                                }
                                else
                                {
                                    cout << "λ�÷Ƿ�";
                                }
                                cout << "        ";
                                cct_gotoxy(x8, y8);
                            }
                            else
                            {
                                cout << "λ�÷Ƿ�";
                                cout << "        ";
                                cct_gotoxy(x8, y8);
                            }

                        }

                    }
                }
                cct_setcolor();
                set_botton(0, 0);
                break;
              case 9:
                  draw_nine(array, rows, cols, choice);
                  set_botton(0, 0);
                  break;

        }

        if (choice != 7 && choice != 8 && choice != 9)
            cout << endl;
    }


    // ���������������������

    return 0;
}

/***************************************************************************
  �������ƣ�print_origin
  ��    �ܣ���ӡ��ʼ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_origin(int rows, int cols, int array[MIN_ROWS][MAX_ROWS])
{
    cout << endl;
    cout << "��ʼ���飺" << endl;
    cout << "  | ";
    for (int j = 0; j < cols; ++j)
        cout << " " << j + 1 << " ";
    cout << endl;
    cout << "--+-";;
    for (int i = 0; i < cols; ++i)
        cout << "---";
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << static_cast<char>('A' + i) << " | ";
        for (int j = 0; j < cols; ++j)
            cout << " " << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

/***************************************************************************
  �������ƣ�print_mark
  ��    �ܣ���ӡ��ʼ��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_mark(int rows, int cols, int array[MIN_ROWS][MAX_ROWS])
{
    cout << endl;
    cout << "��ʼ���������ͬɫ��ʶ����" << endl;
    cout << "  | ";
    for (int j = 0; j < cols; ++j)
        cout << " " << j + 1 << " ";
    cout << endl;
    cout << "--+-";;
    for (int i = 0; i < cols; ++i)
        cout << "---";
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << static_cast<char>('A' + i) << " | ";
        for (int j = 0; j < cols; ++j)
        {
            // ��鲢��ǿ�������
            if (base_check0(array, i, j, rows, cols))
            {
                cout << " ";
                cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
                cout << array[i][j];
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
                cout << " ";
            }
            else
                cout << " " << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/***************************************************************************
  �������ƣ�print_tips
  ��    �ܣ���ӡ��ʾ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_tips(int rows, int cols, int array[MIN_ROWS][MAX_ROWS])
{
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };   //��������
    cout << endl;
    cout << "��ѡ���������ʾ����ͬɫ��ʶ����" << endl;
    cout << "  | ";
    for (int j = 0; j < cols; ++j)
        cout << " " << j + 1 << " ";
    cout << endl;
    cout << "--+-";;
    for (int i = 0; i < cols; ++i)
        cout << "---";
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << static_cast<char>('A' + i) << " | ";
        for (int j = 0; j < cols; ++j)
        {
            // ��鲢��ǿ�������
            if (base_check2(array, directions, i, j, rows, cols))
            {
                cout << " ";
                cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
                cout << array[i][j];
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
                cout << " ";
            }
            else
                cout << " " << array[i][j] << " ";
        }
        cout << endl;
    }
}

/***************************************************************************
  �������ƣ�base_check0
  ��    �ܣ�����Ƿ��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
bool base_check0(const int array[MAX_ROWS][MAX_COLS], int row, int col, int rows, int cols)
{
    if (row >= rows || col >= cols)
        return 0;

    int count = 1; // ��Ŀ��Ԫ�ؿ�ʼ����
    for (int j = col + 1; j < cols && count < 3; j++) //���Ҽ��
    {
        if (array[row][j] == array[row][col])
        {
            count++;
            if (count >= 3)
                return 1;
        }
        else
            break; // ������ͬ��Ԫ�أ�ֹͣ���
    }
    for (int j = col - 1; j >= 0 && count < 3; j--) //������
    {
        if (array[row][j] == array[row][col])
        {
            count++;
            if (count >= 3)
                return 1;
        }
        else
            break; // ������ͬ��Ԫ�أ�ֹͣ���
    }

    count = 1; // ���ü���
    for (int i = row + 1; i < rows && count < 3; i++) //���¼��
    {
        if (array[i][col] == array[row][col])
        {
            count++;
            if (count >= 3)
                return 1;
        }
        else
            break; // ������ͬ��Ԫ�أ�ֹͣ���
    }
    for (int i = row - 1; i >= 0 && count < 3; i--) //���ϼ��
    {
        if (array[i][col] == array[row][col])
        {
            count++;
            if (count >= 3)
                return 1;
        }
        else
            break; // ������ͬ��Ԫ�أ�ֹͣ���
    }

    return 0; // û���ҵ���������
}

/***************************************************************************
  �������ƣ�base_check1
  ��    �ܣ�����Ƿ��г�ʼ��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
bool base_check1(const int array[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int num = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (base_check0(array, i, j, rows, cols))
                num++;
        }
    }
    if (num)
        return 1;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�base_check2
  ��    �ܣ�����Ƿ������ʾ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
bool base_check2(const int array[MAX_ROWS][MAX_COLS], const int directions[4][2], int row, int col, int rows, int cols)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return 0;

    // ����һ������ĸ�����ģ�⽻��
    int arrayCopy[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            arrayCopy[i][j] = array[i][j];
    }

    // �������Ԫ�ؽ������Ƿ�������������
    for (int i = 0; i < 4; ++i)
    {
        int nextRow = row + directions[i][0];
        int nextCol = col + directions[i][1];
        if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols)   //����
        {
            int temp = arrayCopy[nextRow][nextCol];
            arrayCopy[nextRow][nextCol] = arrayCopy[row][col];
            arrayCopy[row][col] = temp;

            if (col - 1 >= 0 && row - 1 >= 0)
            {
                if (base_check0(arrayCopy, row, col, rows, cols) || base_check0(arrayCopy, row + 1, col, rows, cols) || base_check0(arrayCopy, row - 1, col, rows, cols)
                    || base_check0(arrayCopy, row, col + 1, rows, cols) || base_check0(arrayCopy, row, col - 1, rows, cols))
                    return 1;
            }
            else if (col - 1 >= 0 && row - 1 < 0)
            {
                if (base_check0(arrayCopy, row, col, rows, cols) || base_check0(arrayCopy, row + 1, col, rows, cols) || base_check0(arrayCopy, row, col + 1, rows, cols)
                    || base_check0(arrayCopy, row, col - 1, rows, cols))
                    return 1;
            }
            else if (col - 1 < 0 && row - 1 >= 0)
            {
                if (base_check0(arrayCopy, row, col, rows, cols) || base_check0(arrayCopy, row + 1, col, rows, cols) || base_check0(arrayCopy, row - 1, col, rows, cols)
                    || base_check0(arrayCopy, row, col + 1, rows, cols))
                    return 1;
            }
            else
            {
                if (base_check0(arrayCopy, row, col, rows, cols) || base_check0(arrayCopy, row + 1, col, rows, cols) || base_check0(arrayCopy, row, col + 1, rows, cols))
                    return 1;
            }

            // �ָ�����ǰ������״̬
            temp = arrayCopy[nextRow][nextCol];
            arrayCopy[nextRow][nextCol] = arrayCopy[row][col];
            arrayCopy[row][col] = temp;
        }
    }

    return 0;
}

/***************************************************************************
  �������ƣ�base_remove
  ��    �ܣ���ͬ���ֵ�������0������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void base_remove(int array[MAX_ROWS][MAX_COLS], int rows, int cols, int choice)
{
    bool can_remove;
    do {

        can_remove = 0;
        // ��¼���������λ�ú�����
        int remove_position[100][2];
        int remove_count = 0;

        // Ѱ�ҿ��������¼λ��
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (base_check0(array, i, j, rows, cols))
                {
                    remove_position[remove_count][0] = i; // ��
                    remove_position[remove_count][1] = j; // ��
                    remove_count++;
                    can_remove = 1;
                }
            }
        }

        if (!can_remove)
            break;
        print_mark(rows, cols, array);
        cout << "���س����������������0����...";
        char ch1 = _getch();
        while (1)
        {
            if (ch1 == '\r')
                break;
            ch1 = _getch();

        }
        cout << endl;
        cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
        // ִ��������������������������Ϊ0
        for (int k = 0; k < remove_count; ++k) {
            int i = remove_position[k][0];
            int j = remove_position[k][1];
            array[i][j] = 0;
        }
        // �Ӿ���ײ���ʼ���ϱ�������0����ķ�0Ԫ������
        for (int j = 0; j < cols; ++j)   //�Ӿ���ײ���ʼ���ϱ���
        {
            for (int i = rows - 1; i >= 0; --i)   //�����ǰԪ����0������Ҫ��������ķ�0Ԫ��
            {
                if (array[i][j] == 0)  //�ӵ�ǰλ�����ϲ��ҵ�һ����0Ԫ��
                {
                    for (int k = i - 1; k >= 0; --k)
                    {
                        if (array[k][j] != 0)
                        {
                            // ���ҵ��ķ�0Ԫ���ƶ�����ǰ0��λ��
                            array[i][j] = array[k][j];
                            // ����ԭ����λ������Ϊ0
                            array[k][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        cout << "  | ";
        for (int j = 0; j < cols; ++j)
            cout << " " << j + 1 << " ";
        cout << endl;
        cout << "--+-";;
        for (int i = 0; i < cols; ++i)
            cout << "---";
        cout << endl;
        for (int i = 0; i < rows; ++i)
        {
            cout << static_cast<char>('A' + i) << " | ";
            for (int j = 0; j < cols; ++j)
            {
                // ��鲢��ǿ�������
                if (array[i][j] == 0)
                {
                    cout << " ";
                    cct_setcolor(COLOR_YELLOW, COLOR_BLACK);
                    cout << array[i][j];
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE); // ������ɫ
                    cout << " ";
                }
                else {
                    cout << " " << array[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;


        cout << "���س���������ֵ���...";
        char ch2 = _getch();    // �ȴ��û����»س���
        while (1)
        {
            if (ch2 == '\r')
                break;
            ch2 = _getch();  // ��ȡ�û����µļ��� ASCII ֵ

        }
        cout << endl;
        // ������ķ�0������

        srand(static_cast<unsigned int>(time(nullptr)));


        cout << "  | ";
        for (int j = 0; j < cols; ++j)
            cout << " " << j + 1 << " ";
        cout << endl;
        cout << "--+-";;
        for (int i = 0; i < cols; ++i)
            cout << "---";
        cout << endl;
        for (int i = 0; i < rows; ++i) {
            cout << static_cast<char>('A' + i) << " | ";
            for (int j = 0; j < cols; ++j) {
                // ��鲢��ǿ�������
                if (array[i][j] == 0) {
                    cout << " ";
                    cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
                    array[i][j] = (rand() % 9) + 1;
                    cout << array[i][j];
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE); // ������ɫ
                    cout << " ";
                }
                else {
                    cout << " " << array[i][j] << " ";
                }
            }
            cout << endl;
        }


    } while (can_remove); // ����п�������ظ����Ϲ���
    cout << endl;
    cout << "��ʼ���޿�������";
    if (choice == 3)
    {
        print_tips(rows, cols, array);
    }
}