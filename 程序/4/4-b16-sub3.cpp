/* 2352018 ��06 ���� */
#include <iostream>
#include <cmath>
using namespace std;

void fun3(double a, double b, double c)
{
	double x;
	x = (-b) / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x << endl;
}