/* 2352018 ��06 ���� */
#include <iostream>
#include <cmath>
#include "4-b16.h"
using namespace std;

int main()
{
	int flag = 0;
	double a, b, c, delta;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		flag = 1;
	else if ((delta) >= 1e-6)
		flag = 2;
	if (a == 0)
		fun1();
	else if (flag == 1)
		fun3(a, b, c);
	else if (flag == 2)
		fun2(a, b, c);
	else
		fun4(a, b, c);

	return 0;
}