/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
	bool leap(int y) {
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}

	int total_days(int y, int m) 
	{
		int days = 0;
		int days_of_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (leap(y)) 
		{
			days_of_month[1] = 29;
		}
		for (int i = 0; i < m - 1; ++i) 
		{
			days += days_of_month[i];
		}
		return days;
	}

public:
	// �����ǵ���ĵڼ���
	int calc_days() 
	{
		if (year < 1 || month < 1 || month > 12 || day < 1) 
		{
			return -1; // �Ƿ����ڷ���-1
		}
		int totalDays = total_days(year, month);
		return totalDays + day;
	}
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int y, int m, int d);
};

/* --- �˴��������Ա����������ʵ�� --- */
Days::Days(int y, int m, int d) 
{
	year = y;   // ��ֵ��
	month = m;  // ��ֵ��
	day = d;    // ��ֵ��

	int days_of_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leap(year))
	{
		days_of_month[1] = 29;
	}
	if (month < 1 || month > 12 || day < 1 || day > days_of_month[month - 1])
	{
		year = month = day = -1;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}