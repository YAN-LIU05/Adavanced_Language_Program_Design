/* 2352018 ��06 ���� */
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;
void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);

int main()
{
	int flag = 0;
	double delta;
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
		fun3();
	else if (flag == 2)
		fun2();
	else
		fun4();

	return 0;
}