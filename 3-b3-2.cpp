/* 2352018 ��06 ���� */
#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
	double a, b, c, d, e, f, g, h, i, j, m, n, x, y;
	cout << "������[0-100��)֮�������" << endl;
	cin >> x;

	x += 0.00001;
	j = int(x / 1000000000);
	i = int(x / 100000000 - j * 10);
	h = int(x / 10000000 - j * 100 - i * 10);
	g = int(x / 1000000 - j * 1000 - i * 100 - h * 10);
	f = int(x / 100000 - j * 10000 - i * 1000 - h * 100 - g * 10);
	e = int(x / 10000 - j * 100000 - i * 10000 - h * 1000 - g * 100 - f * 10);
	d = int(x / 1000 - j * 1000000 - i * 100000 - h * 10000 - g * 1000 - f * 100 - e * 10);
	c = int(x / 100 - j * 10000000 - i * 1000000 - h * 100000 - g * 10000 - f * 1000 - e * 100 - d * 10);
	b = int(x / 10 - j * 100000000 - i * 10000000 - h * 1000000 - g * 100000 - f * 10000 - e * 1000 - d * 100 - c * 10);
	a = int(x / 1 - j * 1000000000 - i * 100000000 - h * 10000000 - g * 1000000 - f * 100000 - e * 10000 - d * 1000 - c * 100 - b * 10);
	y = floor(x);
	m = int((x - y) * 10);
	n = int((x - y) * 100 - 10 * m);

	cout << setiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left);
	cout << setw(10) << "ʮ��λ" << " : " << j << endl;
	cout << setw(10) << "��λ" << " : " << i << endl;
	cout << setw(10) << "ǧ��λ" << " : " << h << endl;
	cout << setw(10) << "����λ" << " : " << g << endl;
	cout << setw(10) << "ʮ��λ" << " : " << f << endl;
	cout << setw(10) << "��λ" << " : " << e << endl;
	cout << setw(10) << "ǧλ" << " : " << d << endl;
	cout << setw(10) << "��λ" << " : " << c << endl;
	cout << setw(10) << "ʮλ" << " : " << b << endl;
	cout << setw(10) << "Բ" << " : " << a << endl;
	cout << setw(10) << "��" << " : " << m << endl;
	cout << setw(10) << "��" << " : " << n << endl;

	return 0;
}