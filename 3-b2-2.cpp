/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

int main()
{
	int a, a1, a2, a3, a4, a5;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	
	a5 = a % 10;
	a4 = (a / 10) % 10;
	a3 = (a / 100) % 10;
	a2 = (a / 1000) % 10;
	a1 = a / 10000;

	cout << "��λ" << " : " << a1 << endl;
	cout << "ǧλ" << " : " << a2 << endl;
	cout << "��λ" << " : " << a3 << endl;
	cout << "ʮλ" << " : " << a4 << endl;
	cout << "��λ" << " : " << a5 << endl;
	
	return 0;
}