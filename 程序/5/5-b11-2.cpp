/* 2352018 ��06 ���� */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
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
        result = result + chnstr[0] + chnstr[1];
    }
    if (num > 0 && num < 10)
    {
        result = result + chnstr[2 * num] + chnstr[2 * num + 1];
    }
}
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
    int flag1, flag2, flag3, flag4, flag5, flag6, flag7;   //�ж�������
    bool f, g, h, m, n, p, q, u, v, w;   //�ж�flag

    cout << "������[0-100��)֮�������:" << endl;
    cin >> x;

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

    cout << "��д�����:" << endl;

    daxie(shiyi, 0);
    if (shiyi)
    {
        result += "ʰ";
    }

    daxie(yi, 0);
    if (shiyi || yi)
    {
        result += "��";
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
        result += "Ǫ";
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
        result += "��";
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
        result += "ʰ";
    }
    daxie(wan, 0);
    m = qianwan || baiwan || shiwan || wan;
    if (m)
    {
        result += "��";
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
        result += "Ǫ";
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
        result += "��";
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
        result += "ʰ";
    }

    p = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || jiao || fen;
    q = shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi;
    if (p == 0)
    {
        daxie(yuan, 1);
        result += "Բ";
    }
    else if (q || yuan)
    {
        daxie(yuan, 0);
        result += "Բ";
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
        result += "��";
    }
    daxie(fen, 0);
    if (fen)
    {
        result += "��";
    }
    else
    {
        result += "��";
    }


    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}