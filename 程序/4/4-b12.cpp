/* 2352018 ��06 ���� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int storey;
    char src, dst, tmp;
    //tmp = 0;

    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> storey;
        if (cin.good() && storey >= 1 && storey <= 16)
        {
            cin.ignore(65536, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (src == 'a' || src == 'A')
            src = 'A';
        if (src == 'B' || src == 'b')
            src = 'B';
        if (src == 'c' || src == 'C')
            src = 'C';
        if (cin.good() && (src >= 'A' && src <= 'C'))
        {
            cin.ignore(65536, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (dst == 'a' || dst == 'A')
            dst = 'A';
        if (dst == 'b' || dst == 'B')
            dst = 'B';
        if (dst == 'c' || dst == 'C')
            dst = 'C';
        if (dst == src)
        {
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (cin.good() == 1 && (dst >= 'A' && dst <= 'C'))
        {
            cin.ignore(65536, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
    }

    if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C') || (src == 'c' || src == 'C') && (dst == 'b' || dst == 'B'))
        tmp = 'A';
    if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C') || (src == 'c' || src == 'C') && (dst == 'a' || dst == 'A'))
        tmp = 'B';
    if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B') || (src == 'b' || src == 'B') && (dst == 'a' || dst == 'A'))
        tmp = 'C';

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(storey, src, tmp, dst);
    return 0;
}