/* 2352018 ��06 ���� */
#include <iostream>

using namespace std;

int main() 
{
    char strL3[3][128];   //����һ����ά�ַ����飬���ڴ洢����������ı�
    int count[5] = { 0 };   //����
    int i, j;

    cout << "�������1��" << endl;
    cin.getline(strL3[0], 128);
    cout << "�������2��" << endl;
    cin.getline(strL3[1], 128);
    cout << "�������3��" << endl;
    cin.getline(strL3[2], 128);

    // ���������ı���ͳ���ַ�
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; strL3[i][j] != '\0'; ++j) 
        {
            if (strL3[i][j] >= 'A' && strL3[i][j] <= 'Z') 
            {
                count[0]++; // Ӣ�Ĵ�д��ĸ
            }
            else if (strL3[i][j] >= 'a' && strL3[i][j] <= 'z') 
            {
                count[1]++; // Ӣ��Сд��ĸ
            }
            else if (strL3[i][j] >= '0' && strL3[i][j] <= '9') 
            {
                count[2]++; // ����
            }
            else if (strL3[i][j] == ' ') 
            {
                count[3]++; // �ո�
            }
            else {
                count[4]++; // �����ַ�
            }
        }
    }

    cout << "��д : " << count[0] << endl;
    cout << "Сд : " << count[1] << endl;
    cout << "���� : " << count[2] << endl;
    cout << "�ո� : " << count[3] << endl;
    cout << "���� : " << count[4] << endl;

    return 0;
}