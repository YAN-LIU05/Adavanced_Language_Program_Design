/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ

		if ((x >= 0 && x <= 100) && cin.good() == 1) {
			break;
		}
		else if (cin.good() == 0) {
			cin.clear();   //������������״̬
			while (getchar() != '\n');   //ʹ��getchar()����������ȡ�ַ���ֱ����ȡ�����з�\nΪֹ
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}