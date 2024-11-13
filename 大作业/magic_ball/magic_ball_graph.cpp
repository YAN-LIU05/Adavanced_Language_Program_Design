/* 2352018 ��06 ���� */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"

using namespace std;

/***************************************************************************
  �������ƣ�draw_ball
  ��    �ܣ���������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_ball(int i, int j, int color, int border)
{
	int x, y;
	if (!border)
	{
		x = 2 * j + 2;
		y = i + 2;
		cct_gotoxy(x, y);
		cct_setcolor(color, COLOR_BLACK);
		cout << "��";
		cct_gotoxy(x, y + 1);
	}
	if (border == 1)
	{
		x = 4 * j + 2;
		y = 2 * i + 2;
		cct_gotoxy(x, y);
		if (color == COLOR_HWHITE)
			cct_setcolor(color, COLOR_HWHITE);
		else
			cct_setcolor(color, COLOR_BLACK);
		cout << "��";
		cct_gotoxy(x, y + 1);

	}
	if (border == 2)
	{
		x = 4 * j + 2;
		y = 2 * i + 2;
		cct_gotoxy(x, y);
		if (color == COLOR_HWHITE)
			cct_setcolor(color, COLOR_HWHITE);
		else
		{
			cct_setcolor(color, COLOR_BLACK);
		}
		cout << "��";
		cct_gotoxy(x, y + 1);


	}
}

/***************************************************************************
  �������ƣ�draw_border
  ��    �ܣ������߿�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_border(int row, int column, bool border, int choice)
{

	cout << endl;
	cct_gotoxy(0, 1);
	int temp = row;
	row = column;
	column = temp;
	cct_gotoxy(0, 1);
	int hight = (border) ? column * 3 + (column - 1) : column * 3;
	set_botton(true, border ? hight + 3 : hight + 2);

	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	if (!border)
	{
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "�X";
		for (int i = 0; i < row; i++) {
			cout << "�T";
			if (choice == 4)
				Sleep(TIME);
		}
		cout << "�[";
		for (int i = 0; i < column; i++)
		{
			cct_gotoxy(0, i + 2);
			cout << "�U";
			cct_gotoxy(row * 2 + 2, i + 2);
			cout << "�U";
			if (choice == 4)
				Sleep(TIME);
		}
		cct_gotoxy(0, column + 2);
		cout << "�^";
		for (int i = 0; i < row; i++) {
			cout << "�T";
			if (choice == 4)
				Sleep(TIME);
		}
		cout << "�a";
	}

	if (border)
	{
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "�X";
		for (int i = 0; i < row; i++)
		{
			cout << "�T";
			if (choice == 5)
				Sleep(TIME);
			if (i == row - 1)
				break;
			cout << "�j";
			if (choice == 5)
				Sleep(TIME);
		}

		cout << "�[";
		for (int i = 0; i < column * 2; i += 2)
		{
			for (int j = 0; j <= row * 4; j += 4)
			{

				if (j == 0)
				{
					cct_gotoxy(0, i + 2);
					cout << "�U ";
				}
				if (j == row * 4)
				{
					cct_gotoxy(j - 1, i + 2);
					cout << " �U";
				}
				if (j > 0 && j < row * 4)
				{
					cct_gotoxy(j - 1, i + 2);
					cout << " �U ";
				}

				if (choice == 5)
					Sleep(TIME);
			}
			if (i < column * 2 - 2)
			{
				cct_gotoxy(0, i + 3);
				cout << "�d";
				for (int i = 0; i < row; i++)
				{
					cout << "�T";
					if (choice == 5)
						Sleep(TIME);
					if (i == row - 1)
						break;
					cout << "�p";
					if (choice == 5)
						Sleep(TIME);
				}
				cout << "�g";
			}
		}
		cct_gotoxy(0, column * 2 + 1);
		cout << "�^";
		for (int i = 0; i < row; i++)
		{
			cout << "�T";
			if (choice == 5)
				Sleep(TIME);
			if (i == row - 1)
				break;
			cout << "�m";
			if (choice == 5)
				Sleep(TIME);
		}
		cout << "�a";
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << endl;
}

/***************************************************************************
  �������ƣ�draw_fall
  ��    �ܣ����㲢��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int draw_fall(int array[MAX_ROWS][MAX_COLS], int rows, int cols, int choice, int array0[MAX_ROWS][MAX_COLS], int have_score)
{
	int x, y;
	int x0, y0;
	int score = 0;
	cout << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
	cct_getxy(x0, y0);

	if (choice == 7)
	{
		cout << "���س����������������0����...";
		char ch1 = _getch();
		while (1)
		{
			if (ch1 == '\r')
				break;
			ch1 = _getch();

		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			x = 4 * j + 2;
			y = 2 * i + 2;
			cct_gotoxy(x, y);
			if (base_check0(array0, i, j, rows, cols))
			{
				cct_setcursor(CURSOR_INVISIBLE);
				for (int k = 0; k < 5; k++) {
					draw_ball(i, j, array[i][j], 1);
					Sleep(TIME * 2);
					draw_clean(i, j, array[i][j]);
					Sleep(TIME * 2);
				}
				draw_clean(i, j, COLOR_HWHITE);

			}
			cct_gotoxy(x, y + 1);
		}
	}

	bool can_remove = 1;
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
				if (base_check0(array0, i, j, rows, cols))
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

		// ִ��������������������������Ϊ0
		for (int k = 0; k < remove_count; ++k)
		{
			int i = remove_position[k][0];
			int j = remove_position[k][1];
			array0[i][j] = 0;
		}

		if (have_score == 1)
		{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (array0[i][j] == 0)
						score++;
				}
			}
		}


		//�Ӿ���ײ���ʼ���ϱ�������0����ķ�0Ԫ������
		for (int j = 0; j < cols; ++j)   //�Ӿ���ײ���ʼ���ϱ���
		{
			for (int i = rows - 1; i >= 0; --i)   //�����ǰԪ����0������Ҫ��������ķ�0Ԫ��
			{
				if (array0[i][j] == 0)  //�ӵ�ǰλ�����ϲ��ҵ�һ����0Ԫ��
				{
					for (int k = i - 1; k >= 0; --k)
					{
						if (array0[k][j] != 0)
						{

							// ���ҵ��ķ�0Ԫ���ƶ�����ǰ0��λ��
							cct_showstr(2 + 4 * j, 2 + 2 * k, "  ", COLOR_HWHITE, 0, 1);
							draw_ball(i, j, array0[k][j], 1);
							array0[i][j] = array0[k][j];
							Sleep(TIME * 5);
							// ����ԭ����λ������Ϊ0
							array0[k][j] = 0;
							break;
						}
					}
				}
				Sleep(TIME);
			}
			Sleep(TIME);
		}


		if (choice == 7)
		{
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
			cct_gotoxy(x0, y0);
			cout << "                              ";
			cct_gotoxy(x0, y0);
			cout << "���س���������ֵ���...";
			char ch2 = _getch();
			while (1)
			{
				if (ch2 == '\r')
					break;
				ch2 = _getch();

			}
		}

		srand(static_cast<unsigned int>(time(nullptr)));

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				// ��鲢��ǿ�������
				if (array0[i][j] == 0) {

					array0[i][j] = (rand() % 9) + 1;
					draw_ball(i, j, array0[i][j], 1);
					Sleep(TIME * 5);
				}
			}
		}

		cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
		cct_gotoxy(x0, y0);
		break;
		cout << "                                          ";
		cct_gotoxy(x0, y0);

	} while (can_remove); // ����п�������ظ����Ϲ���	


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

	int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };   //��������

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			// ��鲢��ǿ�������
			if (base_check2(array0, directions, i, j, rows, cols))
			{
				draw_ball(i, j, array0[i][j], 2);
			}

		}
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
	cct_gotoxy(x0, y0);
	return score;
}

/***************************************************************************
  �������ƣ�draw_clean
  ��    �ܣ���������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_clean(int i, int j, int color)
{
	int x, y;
	x = 4 * j + 2;
	y = 2 * i + 2;
	cct_gotoxy(x, y);
	cct_setcolor(color, color);
	cout << "  ";
	cct_gotoxy(x, y + 1);
}

/***************************************************************************
  �������ƣ�draw_nine
  ��    �ܣ���9���Ļ��ܺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_nine(int array[MIN_ROWS][MAX_ROWS], int rows, int cols, int choice)
{
	int a, b, c, d;
	int x, y;
	int x9, y9;
	int X = 0, Y = 0;   //���λ��
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	char hang;
	int lie;
	int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };   //��������
	int score = 0, score0 = 0;
	int arrayCopy0[MAX_ROWS][MAX_COLS];
	x9 = 0;
	y9 = 2 * rows + 2;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			arrayCopy0[i][j] = array[i][j];
	}
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
	cout << "(��ǰ������" << score << ")";
	int arrayCopy[MAX_ROWS][MAX_COLS];

	draw_border(rows, cols, 1, choice);
	int count = 0;
	if (count == 0)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
				arrayCopy[i][j] = arrayCopy0[i][j];
		}
	}



	if (base_check1(arrayCopy0, rows, cols))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				x = 4 * j + 2;
				y = 2 * i + 2;
				cct_gotoxy(x, y);
				cct_setcolor(arrayCopy0[i][j], COLOR_BLACK);
				if (base_check0(arrayCopy0, i, j, rows, cols))
					cout << "��";
				else
					cout << "��";
				cct_gotoxy(x, y + 1);
			}

		}
		while (1)
		{
			draw_fall(arrayCopy0, rows, cols, choice, arrayCopy, 0);
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
					arrayCopy0[i][j] = arrayCopy[i][j];
			}
			if (base_check1(arrayCopy0, rows, cols))
				continue;
			else
				break;

		}

	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				draw_ball(i, j, arrayCopy0[i][j], 1);
			}
		}
		int x0, y0;
		cout << endl;
		cct_getxy(x0, y0);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				// ��鲢��ǿ�������
				if (base_check2(arrayCopy0, directions, i, j, rows, cols))
				{
					draw_ball(i, j, arrayCopy0[i][j], 2);
				}

			}
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
		cct_gotoxy(x0, y0);
	}


	int x_9, y_9;
	int num0 = 1;
	int color;
	int i1, j1;
	int i2, j2;
	int count0 = 0;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
		cct_gotoxy(x9, y9);
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
							if (base_check2(arrayCopy, directions, Y / 2 - 1, lie - 1, rows, cols))
							{
								if (num0 > 1)
								{
									cct_gotoxy(x_9, y_9);
									cct_setcolor(color, COLOR_BLACK);
									cout << "��";
								}
								cct_gotoxy(int(X / 2) * 2, Y);
								x_9 = int(X / 2) * 2;
								y_9 = Y;
								color = arrayCopy[Y / 2 - 1][lie - 1];
								cct_setcolor(color, COLOR_HWHITE);
								cout << "��";
								Sleep(TIME * 20);
								cct_gotoxy(x9, y9);
								cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
								cout << "��ǰѡ��" << hang << "��" << lie << "��";
								Sleep(TIME * 20);
								for (int i = 0; i < rows; ++i)
								{
									for (int j = 0; j < cols; ++j)
										arrayCopy0[i][j] = arrayCopy[i][j];
								}
								if (num0 % 2 == 1)
								{
									i1 = Y / 2 - 1;
									j1 = lie - 1;
								}
								if (num0 % 2 == 0)
								{
									i2 = Y / 2 - 1;
									j2 = lie - 1;

									int tmp0;
									tmp0 = arrayCopy0[i1][j1];
									arrayCopy0[i1][j1] = arrayCopy0[i2][j2];
									arrayCopy0[i2][j2] = tmp0;

									if (base_check0(arrayCopy0, i1, j1, rows, cols) || base_check0(arrayCopy0, i2, j2, rows, cols))
									{
										cct_gotoxy(x9, y9);
										cout << "����" << char(i1 + 'A') << "��" << j1 + 1 << "��" << "<=>" << char(i2 + 'A') << "��" << j2 + 1 << "��";
										cct_gotoxy(x9, y9 + 1);

										int count = 0;
										if (count == 0)
										{
											for (int i = 0; i < rows; ++i)
											{
												for (int j = 0; j < cols; ++j)
													arrayCopy[i][j] = arrayCopy0[i][j];
											}
										}



										if (base_check1(arrayCopy0, rows, cols))
										{
											for (int i = 0; i < rows; i++)
											{
												for (int j = 0; j < cols; j++)
												{
													x = 4 * j + 2;
													y = 2 * i + 2;
													cct_gotoxy(x, y);
													cct_setcolor(arrayCopy0[i][j], COLOR_BLACK);
													if (base_check0(arrayCopy0, i, j, rows, cols))
														cout << "��";
													else
														cout << "��";
													cct_gotoxy(x, y + 1);
												}

											}
											while (1)
											{
												score0 = draw_fall(arrayCopy0, rows, cols, choice, arrayCopy, 1);
												score += score0;
												for (int i = 0; i < rows; ++i)
												{
													for (int j = 0; j < cols; ++j)
														arrayCopy0[i][j] = arrayCopy[i][j];
												}
												draw_fall(arrayCopy0, rows, cols, choice, arrayCopy, 1);
												if (!base_check1(arrayCopy0, rows, cols))
													break;

											}

											cct_gotoxy(0, 0);
											cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
											cout << "��Ļ��" << d << "��" << 40 << "��";
											cout << "(��ǰ������" << score << ")";
											for (int i = 0; i < rows; i++) 
											{
												for (int j = 0; j < cols; j++) 
												{
													if (base_check2(arrayCopy0, directions, i, j, rows, cols)) 
													{
														count0++; // ����ҵ�����������λ�ã����Ӽ���
													}
												}
											}

											if (count0 == 0) {
												loop = 0; // ���û���ҵ��κ�����������λ�ã��˳�ѭ��
											}
										}
										else
										{
											for (int i = 0; i < rows; i++)
											{
												for (int j = 0; j < cols; j++)
												{
													draw_ball(i, j, arrayCopy0[i][j], 1);
												}
											}
											int x0, y0;
											cout << endl;
											cct_getxy(x0, y0);
											cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
											for (int i = 0; i < rows; ++i)
											{
												for (int j = 0; j < cols; ++j)
												{
													// ��鲢��ǿ�������
													if (base_check2(arrayCopy0, directions, i, j, rows, cols))
													{
														draw_ball(i, j, arrayCopy0[i][j], 2);
													}
												}
											}
											cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
											cct_gotoxy(x0, y0);
										}
									}
									else
									{
										cct_gotoxy(x9, y9);
										cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
										cout << "���ܽ���" << char(i1 + 'A') << "��" << j1 + 1 << "��" << "<=>" << char(i2 + 'A') << "��" << j2 + 1 << "��";
										num0 = 0;
									}
								}
								num0++;
							}
							else
							{
								cct_gotoxy(x9, y9);
								cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
								cout << "����ѡ��" << hang << "��" << lie << "��";
							}
							break;
						case MOUSE_RIGHT_BUTTON_CLICK:
							loop = 0;
							cct_gotoxy(x9, y9);
							break;
					}
				}

				else
				{
					cct_gotoxy(x9, y9);
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
					cout << "λ�÷Ƿ�";
				}
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
				cout << "          ";
				cct_gotoxy(x9, y9);

			}
			else
			{
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
				cct_gotoxy(x9, y9);
				cout << "λ�÷Ƿ�";
				cout << "        ";
				cct_gotoxy(x9, y9);
			}
		}
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);// ������ɫ
	cct_gotoxy(0, 0);
	cout << "                                             ";
	cct_gotoxy(0, 0);
	cout << "�޿�������,��Ϸ����!���շ���:" << score << ")";
	cct_gotoxy(x9, y9);
	set_botton(0, 0);
}