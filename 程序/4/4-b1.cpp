/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int yuan, shi, bai, qian, wan, shiwan, baiwan, qianwan, yi, shiyi, jiao, fen;
	double x, y;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> x;

	x += 0.00001;
	shiyi = int(x / 1000000000);
	yi = int(x / 100000000 - shiyi * 10);
	qianwan = int(x / 10000000 - shiyi * 100 - yi * 10);
	baiwan = int(x / 1000000 - shiyi * 1000 - yi * 100 - qianwan * 10);
	shiwan = int(x / 100000 - shiyi * 10000 - yi * 1000 - qianwan * 100 - baiwan * 10);
	wan = int(x / 10000 - shiyi * 100000 - yi * 10000 - qianwan * 1000 - baiwan * 100 - shiwan * 10);
	qian = int(x / 1000 - shiyi * 1000000 - yi * 100000 - qianwan * 10000 - baiwan * 1000 - shiwan * 100 - wan * 10);
	bai = int(x / 100 - shiyi * 10000000 - yi * 1000000 - qianwan * 100000 - baiwan * 10000 - shiwan * 1000 - wan * 100 - qian * 10);
	shi = int(x / 10 - shiyi * 100000000 - yi * 10000000 - qianwan * 1000000 - baiwan * 100000 - shiwan * 10000 - wan * 1000 - qian * 100 - bai * 10);
	yuan = int((x / 10.0 - floor(x / 10)) * 10);
	y = floor(x);
	jiao = int((x - y) * 10);
	fen = int((x - y) * 100 - 10 * jiao);

	int flag1, flag2, flag3, flag4, flag5, flag6, flag7;
	cout << "��д�����:" << endl;
	daxie(shiyi, 0);
	if (shiyi) {
		cout << "ʰ";
	}

	daxie(yi, 0);
	if (shiyi || yi) {
		cout << "��";
	}

	if ((!shiyi && !yi) || (!baiwan)) {
		flag1 = 0;
	}
	else {
		flag1 = 1;
	}
	daxie(qianwan, flag1);
	if (qianwan) {
		cout << "Ǫ";
	}

	if ((!shiyi && !yi && !qianwan) || (!shiwan)) {
		flag2 = 0;
	}
	else {
		flag2 = 1;
	}
	daxie(baiwan, flag2);
	if (baiwan) {
		cout << "��";
	}

	if (!shiyi && !yi && !qianwan && !baiwan) {
		flag3 = 0;
	}
	else if (wan) {
		flag3 = 1;
	}
	else {
		flag3 = 0;
	}
	daxie(shiwan, flag3);
	if (shiwan) {
		cout << "ʰ";
		}

	daxie(wan, 0);
	if (qianwan || baiwan || shiwan || wan) {
		cout << "��";
	}

	if ((!shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan) || !bai) {
		flag4 = 0;
	}
	else {
		flag4 = 1;
	}
	daxie(qian, flag4);
	if (qian) {
		cout << "Ǫ";
	}

	if ((!shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan && !qian) || !shi) {
		flag5 = 0;
	}
	else {
		flag5 = 1;
	}
	daxie(bai, flag5);
	if (bai) {
		cout << "��";
	}

	bool u, v;
	u = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai;
	v = yuan;
	switch (u) {
		case 0:
			flag6 = 0;
			break;
		case 1:
			switch (v) {
				case 1:
					flag6 = 1;
					break;
				default:
					flag6 = 0;
					break;
			}
	}
	daxie(shi, flag6);
	if (shi) {
		cout << "ʰ";
	}

	bool p, q;
	p = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || jiao || fen;
	q = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi;
	if (p == 0) {
		daxie(yuan, 1);
		cout << "Բ";
	}
	else if (q || yuan) {
		daxie(yuan, 0);
		cout << "Բ";
	}

	bool w;
	w = !shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan && !qian && !bai && !shi && !yuan;
	switch (w) {
		case 1:
			flag7 = 0;
			break;
		case 0:
			switch (fen) {
				case 0:
					flag7 = 0;
					break;
				default:
					flag7 = 1;
			}
	}
	daxie(jiao, flag7);
	if (jiao) {
		cout << "��";
		}

	daxie(fen, 0);
	if (fen) {
		cout << "��";
	}
	else {
		cout << "��";
	}

	cout << endl;
	return 0;
}