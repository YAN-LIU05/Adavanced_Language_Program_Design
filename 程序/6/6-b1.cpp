/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */

    cout << "�����������������������ֵ��ַ���" << endl;
    gets_s(str, sizeof(str));

    p = str;
    pnum = a;
    pa = a;
    is_num = false;

    while (*p != '\0' && pnum - pa < N)   // ȷ���������������
    { 
        if (*p >= '0' && *p <= '9')   // ����Ƿ�Ϊ����
        { 
            if (!is_num) 
            {
                *pnum = 0; // ��ʼ����ǰ����
            }
            *pnum = (*pnum * 10) + (*p - '0');
            is_num = true;
        }
        else if (is_num)   // �����ǰ�������֣���֮ǰ�����֣����ƶ�����һ������Ԫ�� 
        {
            pnum++;
            is_num = false;
        }
        p++;
    }

    if (is_num) 
    {
        pnum++;
    }
    cout << "����" << (pnum - pa) << "������" << endl; 
    for (; pa < pnum; pa++)
    {
        cout << *pa << " ";
    }
    cout << endl;

	return 0;
}