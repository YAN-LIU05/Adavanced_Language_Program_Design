/* 2352018 ��06 ���� */
#include<iostream>
#include <iomanip>
#include<math.h>
using namespace std;
#define pi 3.14159

int main()
{
	int a, b, t;
	float S;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> t;
	
	S = (a * b * sin(t * float(pi) / 180)) / 2;
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "���������Ϊ" << " : " << S << endl;

	return 0;
}