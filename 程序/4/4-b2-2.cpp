/* 2352018 ��06 ���� */
#include <iostream>
#include <limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int y0, m0, c, w;
	if (m <= 2)
	{
		m0 = m + 12;
		c = (y - 1) / 100;
		y0 = y - c * 100 - 1;
	}
	else
	{
		m0 = m;
		c = y / 100;
		y0 = y - c * 100;
	}
	w = y0 + (y0 / 4) + (c / 4) - 2 * c + (13 * (m0 + 1) / 5) + d - 1;
    while (w < 0)
	{
		w += 7;
	}
	if (w % 7 != 0)
	{
		w = w % 7;
	}
	else 
	{
		w = 0;
	}
	return w;
}

int main()
{
	int year, month, day;
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		if (cin.good()) 
		{
			if ((year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0))
			{
				if (year >= 1900 && year <= 2100)
				{
					if (month >= 1 && month <= 12)
					{
						if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
						{
							if (day >= 1 && day <= 31)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
						else if (month == 2)
						{
							if (day >= 1 && day <= 28)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
						else
						{
							if (day >= 1 && day <= 30)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
					}
					else
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "�·ݲ���ȷ������������" << endl;
						continue;
					}
				}
				else
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "��ݲ���ȷ������������" << endl;
					continue;
				}
			}
			else
			{
				if (year >= 1900 && year <= 2100)
				{
					if (month >= 1 && month <= 12)
					{
						if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
						{
							if (day >= 1 && day <= 31)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
						else if (month == 2)
						{
							if (day >= 1 && day <= 29)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
						else
						{
							if (day >= 1 && day <= 30)
								break;
							else
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "�ղ���ȷ������������" << endl;
								continue;
							}
						}
					}
					else
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "�·ݲ���ȷ������������" << endl;
						continue;
					}
				}
				else
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "��ݲ���ȷ������������" << endl;
					continue;
				}
			}
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������" << endl;
			continue;
		}
	}

	int x;
	x = zeller(year, month, day);
	switch (x) {
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		case 0:
			cout << "������" << endl;
			break;
	}

	return 0;
}