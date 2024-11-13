/* 2352018 ��06 ���� */
#include <iostream>  
#include <limits>
using namespace std;

void insert(int a[], int& size, int num)
{
    int i;
    for (i = 0; i < size && a[i] < num; ++i);
    for (int j = size; j > i; --j)
    {
        a[j] = a[j - 1];
    }
    a[i] = num;
    size++;
}

int main()
{
    const int MAX_SIZE = 20;
    int a[MAX_SIZE + 1];
    int size = 0, i = 0;
    int num;

    cout << "��������������������������20������0������������" << endl;

    while (size < MAX_SIZE && cin >> num && num > 0)
    {
        a[size++] = num;
        i++;
    }
    if (num <= 0 && i == 0)
    {
        cout << "����Ч����" << endl;
        return 1;
    }

    cin.ignore(INT_MAX, '\n');

    if (!(num <= 0 && i == 0))
    {
        cout << "ԭ����Ϊ��" << endl;
        for (int i = 0; i < size; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "������Ҫ�����������" << endl;
        cin >> num;

        insert(a, size, num);

        cout << "����������Ϊ��" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}