/* 2352018 ��06 ���� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, d, e, f, g, h, i, j, m, n;
	double x, y;
	cout << "������[0-100��)֮�������:" << endl;
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
	a = int((x / 10.0 - floor(x / 10)) * 10);
	y = floor(x);
	m = int((x - y) * 10);
	n = int((x - y) * 100 - 10 * m);

	cout << "��д�����:" << endl;

	switch (j) {
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		case 0:
			cout << "";
			break;
	}

	switch (i) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			if (j == 0) {
				cout << "";
			}
			else {
				cout << "��";
			}
			break;
	}

	switch (h) {
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		case 0:
			if ((!i && !j) || (!g)) {
				cout << "";
			}
			else {
				cout << "��";
			}
	}

	switch (g) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			if ((!h && !i && !j) || !f) {
				cout << "";
			}
			else {
				cout << "��";
			}
			break;
	}

	switch (f) {
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		case 0:
			if (!g && !h && !i && !j) {
				cout << "";
			}
			else if (e) {
				cout << "��";
			}
			break;
	}

	switch (e) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			if (f || g || h) {
				cout << "��";
			}
			break;
	}

	switch (d) {
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		case 0:
			if ((!e && !f && !g && !h && !i && !j) || !c) {
				cout << "";
			}
			else {
				cout << "��";
			}
			break;
	}

	switch (c) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			if ((!d && !e && !f && !g && !h && !i && !j) || !b) {
				cout << "";
			}
			else {
				cout << "��";
			}
			break;
	}

	bool u, v;
	u = c || d || e || f || g || h || i || j;
	v = a;
	switch (b) {
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		case 0:
			switch (u) {
				case 0:
					cout << "";
					break;
				case 1:
					switch (v) {
						case 1:
							cout << "��";
							break;
						default:
							cout << "";
							break;
					}
			}
	}

	bool p, q;
	p = b || c || d || e || f || g || h || i || j || m || n;
	q = b || c || d || e || f || g || h || i || j;
	switch (a) {
		case 1:
			cout << "ҼԲ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 9:
			cout << "��Բ";
			break;
		case 0:
			switch (p) {
				case 0:
					cout << "��Բ";
					break;
				case 1:
					switch (q) {
						case 1:
							cout << "Բ";
							break;
						default:
							cout << "";
							break;
					}
			}
			break;
	}

	bool w;
	w = !a && !b && !c && !d && !e && !f && !g && !h && !i && !j;
	switch (m) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			switch (w) {
				case 1:
					break;
				case 0:
					switch (n) {
						case 0:
							break;
						default:
							cout << "��";
					}
			}
	}

	switch (n) {
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 9:
			cout << "����";
			break;
		case 0:
			cout << "��";
			break;
	}

	cout << endl;

	return 0;
}