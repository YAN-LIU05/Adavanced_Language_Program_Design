/* 2352018 ��06 ���� */
#include <iostream>
using namespace std;

#define MAX_BINARY_LENGTH 32

unsigned int change(const char * num)
{
    unsigned int decimal = 0;

    while (*num) 
    { 
        decimal = decimal * 2 + *num - '0'; // ����2Ȼ����ϵ�ǰλ��ʮ����ֵ
        num++;
    }
    return decimal;
}

int main() 
{
    char num[MAX_BINARY_LENGTH + 1];
    unsigned int decimal;

    cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
    cin >> num; // ֱ�Ӷ�ȡ�������ַ���

    decimal = change(num); 

    cout << decimal << endl; 

    return 0;
}