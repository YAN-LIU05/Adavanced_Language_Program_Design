/* 2352018 ��06 ���� */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, y, x, x0;   //�ꡢ�¡�����

	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> n >> y;

		if (cin.good()) {
			if ((n >= 2000 && n <= 2030) && (y >= 1 && y <= 12)) {
				break;
			}
			else {
				cout << "����Ƿ�������������" << endl;
			}
		}
		else {
			cin.clear();
			while (getchar() != '\n');
			cout << "����Ƿ�������������" << endl;
		}

	}
	while (1) {
		cout << "������" << n << "��" << y << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> x;

		if (cin.good()) {
			if (x >= 0 && x <= 6) {
				break;
			}
			else {
				cout << "����Ƿ�������������" << endl;
			}
		}
		else {
			cin.clear();
			while (getchar() != '\n');
			cout << "����Ƿ�������������" << endl;
		}

	}
	cout << endl;
	cout << n << "��" << y << "�µ�����Ϊ:" << endl;

	int i;
	for (i = 0; i < 7; i++) {
		switch (i)
		{
			case(0):
				cout << "������  ";
				break;
			case(1):
				cout << "����һ  ";
				break;
			case(2):
				cout << "���ڶ�  ";
				break;
			case(3):
				cout << "������  ";
				break;
			case(4):
				cout << "������  ";
				break;
			case(5):
				cout << "������  ";
				break;
			case(6):
				cout << "������";
				break;
		}
	}
	cout << endl;
	cout << setiosflags(ios::right);
	x0 = x;

	if ((n % 4 != 0) || (n % 100 == 0) && (n % 400 != 0))
	{
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) 
		{
			for (i = 1; i <= 31; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 31) {
					cout << "    ";
				}
			}
			cout << endl;
		}
		else if (y == 2) {
			for (i = 1; i <= 28; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 28) {
					cout << "    ";
				}
			}
			cout << endl;
		}
		else {
			for (i = 1; i <= 30; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 30) {
					cout << "    ";
				}
			}
			cout << endl;
		}
	}
	else
	{
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) {
			for (i = 1; i < 32; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 31) {
					cout << "    ";
				}
			}
			cout << endl;
		}
		else if (y == 2) {
			for (i = 1; i < 30; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 29) {
					cout << "    ";
				}
			}
			cout << endl;
		}
		else {
			for (i = 1; i < 31; i++)
			{
				if (i == 1) {
					cout << setw((2 * x + 1) * 4) << i;
				}
				else if (x0 == 0) {
					cout << setw(4) << i;
				}
				else {
					cout << setw(8) << i;
				}

				x0++;

				if (x0 == 7) {
					cout << "    " << endl;
					x0 = 0;
				}
				else if (i == 30) {
					cout << "    ";
				}
			}
			cout << endl;
		}
	}

	return 0;
}