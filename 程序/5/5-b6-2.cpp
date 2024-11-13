/* 2352018 ��06 ���� */
#include <iostream>  
#include <iomanip>
using namespace std;

void hanoi(int n, char src, char tmp, char dst);

int hanoi0[3][10];
int top[3];
int Count = 0;// �ƶ�����������

char capital(char x)
{
    if (x == 'a' || x == 'A')
        x = 'A';
    if (x == 'B' || x == 'b')
        x = 'B';
    if (x == 'c' || x == 'C')
        x = 'C';
    return x;
}

void printTower1(int tower[], char label)
{
    cout << label << ":";
    for (int i = 0; i < 10; ++i)
    {
        if (hanoi0[0][i] == 0)
        {
            cout << "  "; // �����ո��ʾû����
        }
        else
        {
            cout << setw(2) << tower[i];
        }
    }
    cout << " ";
}
void printTower2(int tower[], char label)
{
    cout << label << ":";
    for (int i = 0; i < 10; ++i)
    {
        if (hanoi0[1][i] == 0)
        {
            cout << "  "; // �����ո��ʾû����
        }
        else
        {
            cout << setw(2) << tower[i];
        }
    }
    cout << " ";
}
void printTower3(int tower[], char label)
{
    cout << label << ":";
    for (int i = 0; i < 10; ++i)
    {
        if (hanoi0[2][i] == 0)
        {
            cout << "  "; // �����ո��ʾû����
        }
        else
        {
            cout << setw(2) << tower[i];
        }
    }
    cout << " ";
}
void print()
{
    printTower1(hanoi0[0], 'A');
    printTower2(hanoi0[1], 'B');
    printTower3(hanoi0[2], 'C');
}

void moveA(char dst)
{
    int a;
    a = hanoi0[0][--top[0]];
    hanoi0[0][top[0]] = 0;
    if (dst == 'B')
    {
        hanoi0[1][top[1]++] = a;
    }
    if (dst == 'C')
    {
        hanoi0[2][top[2]++] = a;
    }
}
void moveB(int dst)
{
    int b;
    b = hanoi0[1][--top[1]];
    hanoi0[1][top[1]] = 0;
    if (dst == 'A')
    {
        hanoi0[0][top[0]++] = b;
    }
    if (dst == 'C')
    {
        hanoi0[2][top[2]++] = b;
    }
}
void moveC(int dst)
{
    int c;
    c = hanoi0[2][--top[2]];
    hanoi0[2][top[2]] = 0;
    if (dst == 'A')
    {
        hanoi0[0][top[0]++] = c;
    }
    if (dst == 'B')
    {
        hanoi0[1][top[1]++] = c;
    }
}
void move(char src, char dst)
{
    if (src == 'A')
        moveA(dst);
    if (src == 'B')
        moveB(dst);
    if (src == 'C')
        moveC(dst);
}

int main()
{
    int storey, i;
    char src, dst, tmp;
    tmp = 0;

    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> storey;
        if (cin.good() && storey >= 1 && storey <= 10)
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
        src = capital(src);
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
        dst = capital(dst);
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

    src = capital(src);
    dst = capital(dst);
    if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
        tmp = 'A';
    if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
        tmp = 'B';
    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
        tmp = 'C';   //ȷ��������

    // ��ʼ��Բ��
    if (src == 'A')
    {
        for (i = 0; i < storey; i++)
        {
            hanoi0[0][i] = storey - i;
        }
        top[0] = storey;
    }
    if (src == 'B')
    {
        for (i = 0; i < storey; i++)
        {
            hanoi0[1][i] = storey - i;
        }
        top[1] = storey;
    }
    if (src == 'C')
    {
        for (i = 0; i < storey; i++)
        {
            hanoi0[2][i] = storey - i;
        }
        top[2] = storey;
    }
    // ��ӡ��ʼ״̬
    cout << "��ʼ:";
    cout << "                ";
    print();
    cout << endl;


    hanoi(storey, src, tmp, dst);
    return 0;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        Count++;
        cout << "��" << setw(4) << Count << " ��" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
        move(src, dst);
        // ��ӡԲ��
        print();
        cout << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        Count++;
        cout << "��" << setw(4) << Count << " ��" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
        move(src, dst);
        // ��ӡԲ��
        print();
        cout << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}