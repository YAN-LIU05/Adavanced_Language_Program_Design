/* 2352018 ��06 ���� */
#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r, h, C, S1, S2, V1, V2;
	const double pi = 3.14159;
	cout << "������뾶�͸߶�" << endl;
    cin >> r >> h;

	C = pi * r * 2;
	S1 = pi * r * r;
	S2 = pi * 4 * r * r;
	V1 = (4 * pi * r * r * r) / 3;
	V2 = pi * r * r * h;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << setiosflags(ios::left);
	cout << setw(10) << "Բ�ܳ�" << " : " << C << endl;
	cout << setw(10) << "Բ���" << " : " << S1 << endl;
	cout << setw(10) << "Բ������" << " : " << S2 << endl;
	cout << setw(10) << "Բ�����  " << " ; " << V1 << endl;
	cout << setw(10) << "Բ�����  " << " : " << V2 << endl;

	return 0;
}