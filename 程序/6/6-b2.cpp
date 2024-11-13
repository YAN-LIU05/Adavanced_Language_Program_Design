/* 2352018 ��06 ���� */
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_LEN 81

// ���������ж��ַ����Ƿ��ǻ��Ĵ�
bool fun(char * str) 
{
    char * left = str, * right = str;
    while (* right)
        right++;
    right--; // ָ���ַ������һ���ַ�

    while (left < right)   // �����ո�
    {
        
        while (* left == ' ') 
            left++;
        while (* right == ' ') 
            right--;

        if (*left != *right) 
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() 
{
    char str[MAX_LEN];
    char * p = str;

    cout << "������һ������С��80���ַ��������Ĵ���" << endl;
    fgets(p, MAX_LEN, stdin); // ʹ��fgets��ȡ�ַ���

    // ȥ��fgets��ȡ�����һ�����з�
    char * end = p;
    while (* end) 
        end++;
    if (end > p && * (end - 1) == '\n') 
    {
        * (end - 1) = '\0';
    }

    if (fun(p)) 
    {
        cout << "yes" << endl;
    }
    else 
    {
        cout << "no" << endl;
    }

    return 0;
}