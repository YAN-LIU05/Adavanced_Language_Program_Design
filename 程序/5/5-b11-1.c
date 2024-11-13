/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
/***************************************************************************
  �������ƣ�connect
  ��    �ܣ������ַ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void connect(char dst[], const char src[], unsigned int n)
{

    unsigned int len = 0;
    unsigned int i = 0;

    // ����Ŀ���ַ����ĳ���
    while (dst[len] != '\0')
    {
        len++;
    }

    // ����Դ�ַ�����Ŀ���ַ���
    while (src[i] != '\0' && i < n)
    {
        dst[len + i] = src[i];
        i++;
    }

    // ����ַ�����β��־
    dst[len + i] = '\0';
}

/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ�ת��д
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
    char arr[] = " ";
    if (num == 0 && flag_of_zero)
    {
        connect(result, chnstr, 2);
    }
    if (num > 0 && num < 10)
    {
        arr[0] = chnstr[2 * num];
        arr[1] = chnstr[2 * num + 1];
        connect(result, arr, 2);
    }
}
/***************************************************************************
  �������ƣ�main
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    int yuan, shi, bai, qian, wan, shiwan, baiwan, qianwan, yi, shiyi, jiao, fen;
    double x, y;
    int flag1, flag2, flag3, flag4, flag5, flag6, flag7;   //�ж�������
    bool f, g, h, m, n, p, q, u, v, w;   //�ж�flag

    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &x);

    x += 0.00001;
    shiyi = (int)(x / 1000000000);
    yi = (int)(x / 100000000 - shiyi * 10);
    qianwan = (int)(x / 10000000 - shiyi * 100 - yi * 10);
    baiwan = (int)(x / 1000000 - shiyi * 1000 - yi * 100 - qianwan * 10);
    shiwan = (int)(x / 100000 - shiyi * 10000 - yi * 1000 - qianwan * 100 - baiwan * 10);
    wan = (int)(x / 10000 - shiyi * 100000 - yi * 10000 - qianwan * 1000 - baiwan * 100 - shiwan * 10);
    qian = (int)(x / 1000 - shiyi * 1000000 - yi * 100000 - qianwan * 10000 - baiwan * 1000 - shiwan * 100 - wan * 10);
    bai = (int)(x / 100 - shiyi * 10000000 - yi * 1000000 - qianwan * 100000 - baiwan * 10000 - shiwan * 1000 - wan * 100 - qian * 10);
    shi = (int)(x / 10 - shiyi * 100000000 - yi * 10000000 - qianwan * 1000000 - baiwan * 100000 - shiwan * 10000 - wan * 1000 - qian * 100 - bai * 10);
    yuan = (int)((x / 10.0 - floor(x / 10)) * 10);
    y = floor(x);
    jiao = (int)((x - y) * 10);
    fen = (int)((x - y) * 100 - 10 * jiao);

    printf("��д�����:\n");

    daxie(shiyi, 0);
    if (shiyi)
    {
        connect(result, "ʰ", 2);
    }

    daxie(yi, 0);
    if (shiyi || yi)
    {
        connect(result, "��", 2);
    }

    f = (!shiyi && !yi) || (!baiwan);
    if (f) 
    {
        flag1 = 0;
    }
    else 
    {
        flag1 = 1;
    }
    daxie(qianwan, flag1);
    if (qianwan) 
    {
        connect(result, "Ǫ", 2);
    }
    g = (!shiyi && !yi && !qianwan) || (!shiwan);
    if (g) 
    {
        flag2 = 0;
    }
    else
    {
        flag2 = 1;
    }
    daxie(baiwan, flag2);
    if (baiwan) 
    {
        connect(result, "��", 2);
    }
    h = !shiyi && !yi && !qianwan && !baiwan;
    if (h) 
    {
        flag3 = 0;
    }
    else if (wan) 
    {
        flag3 = 1;
    }
    else 
    {
        flag3 = 0;
    }
    daxie(shiwan, flag3);
    if (shiwan) 
    {
        connect(result, "ʰ", 2);
    }
    daxie(wan, 0);
    m = qianwan || baiwan || shiwan || wan;
    if (m) 
    {
        connect(result, "��", 2);
    }
    n = (!shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan) || !bai;
    if (n) 
    {
        flag4 = 0;
    }
    else
    {
        flag4 = 1;
    }
    daxie(qian, flag4);
    if (qian) 
    {
        connect(result, "Ǫ", 2);
    }

    u = (!shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan && !qian) || !shi;
    if (u) 
    {
        flag5 = 0;
    }
    else 
    {
        flag5 = 1;
    }
    daxie(bai, flag5);
    if (bai) 
    {
        connect(result, "��", 2);
    }

    v = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai;
    switch (v) 
    {
        case 0:
            flag6 = 0;
            break;
        case 1:
            switch (yuan)
            {
                case 1:
                    flag6 = 1;
                    break;
                default:
                    flag6 = 0;
                    break;
            }
    }
    daxie(shi, flag6);
    if (shi) 
    {
        connect(result, "ʰ", 2);
    }

    p = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || jiao || fen;
    q = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi;
    if (p == 0) 
    {
        daxie(yuan, 1);
        connect(result, "Բ", 2);
    }
    else if (q || yuan) 
    {
        daxie(yuan, 0);
        connect(result, "Բ", 2);
    }

    w = !shiyi && !yi && !qianwan && !baiwan && !shiwan && !wan && !qian && !bai && !shi && !yuan;
    switch (w) 
    {
        case 1:
            flag7 = 0;
            break;
        case 0:
            switch (fen)
            {
                case 0:
                    flag7 = 0;
                    break;
                default:
                    flag7 = 1;
            }
    }
    daxie(jiao, flag7);
    if (jiao) 
    {
        connect(result, "��", 2);
    }
    daxie(fen, 0);
    if (fen) 
    {
        connect(result, "��", 2);
    }
    else 
    {
        connect(result, "��", 2);
    }

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}