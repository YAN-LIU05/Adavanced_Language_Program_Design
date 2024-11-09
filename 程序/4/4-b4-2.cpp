/* 2352018 ��06 ���� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

int menu(const HANDLE hout)
{
	int in;
	while (1)
	{
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ�������������ʹ��)" << endl;
		cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ������������ʹ��)" << endl;
		cout << "0.�˳�" << endl;
		cout << "[��ѡ��0-6] ";
		in = _getche();
		if (in < '0' || in >'6')
			cls(hout);
		else
			break;
	}
	return in;
}
void move_by_ijkl(const HANDLE hout, int x)
{
	int m, xl, yl;
	xl = (MAX_X + 1) / 2;
	yl = (MAX_Y + 1) / 2;

	if (x == '1')
	{
		while (1)
		{
			m = _getch();
			if (m == ' ')
			{
				showch(hout, xl, yl, ' ');
				gotoxy(hout, xl, yl);
			}
			if (m == 'Q' || m == 'q')
				break;
			if (m == 'I' || m == 'i')
			{
				if (yl == 1)
					continue;
				else
				{
					yl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'K' || m == 'k')
			{
				if (yl == 17)
					continue;
				else
				{
					yl++;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'J' || m == 'j')
			{
				if (xl == 1)
					continue;
				else
				{
					xl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'L' || m == 'l')
			{
				if (xl == 69)
					continue;
				else
				{
					xl++;
					gotoxy(hout, xl, yl);
				}
			}
		}
	}
	else if (x == '2')
	{
		while (1)
		{
			m = _getch();
			if (m == ' ')
			{
				showch(hout, xl, yl, ' ');
				gotoxy(hout, xl, yl);
			}
			if (m == 'Q' || m == 'q')
				break;
			if (m == 'I' || m == 'i')
			{
				if (yl == 1)
				{
					yl = 17;
					gotoxy(hout, xl, yl);
				}
				else
				{
					yl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'K' || m == 'k')
			{
				if (yl == 17)
				{
					yl = 1;
					gotoxy(hout, xl, yl);
				}
				else
				{
					yl++;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'J' || m == 'j')
			{
				if (xl == 1)
				{
					xl = 69;
					gotoxy(hout, xl, yl);
				}
				else
				{
					xl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'L' || m == 'l')
			{
				if (xl == 69)
				{
					xl = 1;
					gotoxy(hout, xl, yl);
				}
				else
				{
					xl++;
					gotoxy(hout, xl, yl);
				}
			}
		}
	}
	else if (x == '5')
	{
		while (1)
		{
			m = _getch();
			if (m == 224)
			{
				_getch();
				continue;
			}
			if (m == ' ')
			{
				showch(hout, xl, yl, ' ');
				gotoxy(hout, xl, yl);
			}
			if (m == 'Q' || m == 'q')
				break;
			if (m == 'I' || m == 'i')
			{
				if (yl == 1)
					continue;
				else
				{
					yl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'K' || m == 'k')
			{
				if (yl == 17)
					continue;
				else
				{
					yl++;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'J' || m == 'j')
			{
				if (xl == 1)
					continue;
				else
				{
					xl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'L' || m == 'l')
			{
				if (xl == 69)
					continue;
				else
				{
					xl++;
					gotoxy(hout, xl, yl);
				}
			}
		}
	}
	else if (x == '6')
	{
		while (1)
		{
			m = _getch();
			if (m == 224)
			{
				_getch();
				continue;
			}
			if (m == ' ')
			{
				showch(hout, xl, yl, ' ');
				gotoxy(hout, xl, yl);
			}
			if (m == 'Q' || m == 'q')
				break;
			if (m == 'I' || m == 'i')
			{
				if (yl == 1)
				{
					yl = 17;
					gotoxy(hout, xl, yl);
				}
				else
				{
					yl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'K' || m == 'k')
			{
				if (yl == 17)
				{
					yl = 1;
					gotoxy(hout, xl, yl);
				}
				else
				{
					yl++;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'J' || m == 'j')
			{
				if (xl == 1)
				{
					xl = 69;
					gotoxy(hout, xl, yl);
				}
				else
				{
					xl--;
					gotoxy(hout, xl, yl);
				}
			}
			if (m == 'L' || m == 'l')
			{
				if (xl == 69)
				{
					xl = 1;
					gotoxy(hout, xl, yl);
				}
				else
				{
					xl++;
					gotoxy(hout, xl, yl);
				}
			}
		}
	}
}

void move_by_arrow(const HANDLE hout, int x)
{
	int m, xa, ya;
	int a1 = 0;
	int a2 = 0;
	xa = (MAX_X + 1) / 2;
	ya = (MAX_Y + 1) / 2;

	if (x == '3')
	{
		while (1)
		{
			m = _getch();
			if (m == ' ')
			{
				showch(hout, xa, ya, ' ');
				gotoxy(hout, xa, ya);
			}
			if (m == 'q' || m == 'Q')
				break;
			if (m == 224)
			{
				m = _getch();

				if (m == 72)
				{
					if (ya == 1)
						continue;
					else
					{
						ya--;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 75)
				{
					if (xa == 1)
						continue;
					else
					{
						xa--;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 80)
				{
					if (ya == 17)
						continue;
					else
					{
						ya++;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 77)
				{
					if (xa == 69)
						continue;
					else
					{
						xa++;
						gotoxy(hout, xa, ya);
					}
				}
			}
		}
	}
	else if (x == '4')
	{
		while (1)
		{
			m = _getch();
			if (m == ' ')
			{
				showch(hout, xa, ya, ' ');
				gotoxy(hout, xa, ya);
			}
			if (m == 'q' || m == 'Q')
				break;
			if (m == 224)
			{
				m = _getch();

				if (m == 72)
				{
					if (ya == 1)
					{
						ya = 17;
						gotoxy(hout, xa, ya);
					}
					else
					{
						ya--;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 75)
				{
					if (xa == 1)
					{
						xa = 69;
						gotoxy(hout, xa, ya);
					}
					else
					{
						xa--;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 80)
				{
					if (ya == 17)
					{
						ya = 1;
						gotoxy(hout, xa, ya);
					}
					else
					{
						ya++;
						gotoxy(hout, xa, ya);
					}
				}
				if (m == 77)
				{
					if (xa == 69)
					{
						xa = 1;
						gotoxy(hout, xa, ya);
					}
					else
					{
						xa++;
						gotoxy(hout, xa, ya);
					}
				}
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	while (1) {
		int x, y;
		int c_in;
		const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
		x = (MAX_X + 1) / 2;
		y = (MAX_Y + 1) / 2;

		/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
		srand((unsigned int)(time(0)));


		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
		c_in = menu(hout);
		if (c_in == '0') {
			break;
		}
		else {
			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);
			gotoxy(hout, x, y);

			if (c_in == '1' || c_in == '2' || c_in == '5' || c_in == '6') {
				move_by_ijkl(hout, c_in);
			}
			else {
				move_by_arrow(hout, c_in);
			}

			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س������ز˵�.";
			while (1) {
				if (_getch() == 13)
					break;
			}
		}
	}
	return 0;

}