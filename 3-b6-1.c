/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdbool.h>

int main()
{
	int a, b, c, d, e, f, g, h, i, j, m, n;
	double x, y;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &x);

	x += 0.0001;
	j = (int)(x / 1000000000);
	i = (int)(x / 100000000 - j * 10);
	h = (int)(x / 10000000 - j * 100 - i * 10);
	g = (int)(x / 1000000 - j * 1000 - i * 100 - h * 10);
	f = (int)(x / 100000 - j * 10000 - i * 1000 - h * 100 - g * 10);
	e = (int)(x / 10000 - j * 100000 - i * 10000 - h * 1000 - g * 100 - f * 10);
	d = (int)(x / 1000 - j * 1000000 - i * 100000 - h * 10000 - g * 1000 - f * 100 - e * 10);
	c = (int)(x / 100 - j * 10000000 - i * 1000000 - h * 100000 - g * 10000 - f * 1000 - e * 100 - d * 10);
	b = (int)(x / 10 - j * 100000000 - i * 10000000 - h * 1000000 - g * 100000 - f * 10000 - e * 1000 - d * 100 - c * 10);
	a = (int)((x / 10.0 - floor(x / 10)) * 10);
	y = floor(x);
	m = (int)((x - y) * 10);
	n = (int)((x - y) * 100 - 10 * m);

	printf("��д�����:\n");

	switch (j) {
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		default:
			printf("");
			break;
	}

	switch (i) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		default:
			if (j == 0) {
				printf("");
			}
			else {
				printf("��");
			}
			break;
	}

	switch (h) {
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		default:
			if ((!i && !j) || (!g)) {
				printf("");
			}
			else {
				printf("��");
			}
			break;
	}

	switch (g) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		default:
			if ((!h && !i && !j) || !f) {
				printf("");
			}
			else {
				printf("��");
			}
			break;
	}

	switch (f) {
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		default:
			if (!g && !h && !i && !j) {
				printf("");
			}
			else if (e) {
				printf("��");
			}
			break;
	}

	switch (e) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		default:
			if (f || g || h) {
				printf("��");
			}
			break;
	}

	switch (d) {
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		default:
			if ((!e && !f && !g && !h && !i && !j) || !c) {
				printf("");
			}
			else {
				printf("��");
			}
			break;
	}

	switch (c) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		default:
			if ((!d && !e && !f && !g && !h && !i && !j) || !b) {
				printf("");
			}
			else {
				printf("��");
			}
			break;
	}

	bool u, v;
	u = c || d || e || f || g || h || i || j;
	v = a;
	switch (b) {
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		default:
			switch (u) {
				case 0:
					printf("");
					break;
				case 1:
					switch (v) {
						case 1:
							printf("��");
							break;
						default:
							printf("");
							break;
					}
			}
			break;
	}

	bool p, q;
	p = b || c || d || e || f || g || h || i || j || m || n;
	q = b || c || d || e || f || g || h || i || j;
	switch (a) {
		case 1:
			printf("ҼԲ");
			break;
		case 2:
			printf("��Բ");
			break;
		case 3:
			printf("��Բ");
			break;
		case 4:
			printf("��Բ");
			break;
		case 5:
			printf("��Բ");
			break;
		case 6:
			printf("½Բ");
			break;
		case 7:
			printf("��Բ");
			break;
		case 8:
			printf("��Բ");
			break;
		case 9:
			printf("��Բ");
			break;
		default:
			switch (p) {
				case 0:
					printf("��Բ");
					break;
				case 1:
					switch (q) {
						case 1:
							printf("Բ");
							break;
						default:
							printf("");
							break;
					}
			}
			break;
	}

	bool w;
	w = !a && !b && !c && !d && !e && !f && !g && !h && !i && !j;
	switch (m) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
		default:
			switch (w) {
				case 1:
					break;
				case 0:
					switch (n) {
						case 0:
							break;
						default:
							printf("��");
					}
			}
	}

	switch (n) {
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 9:
			printf("����");
			break;
		default:
			printf("��");
			break;
	}

	printf("\n");

	return 0;
}