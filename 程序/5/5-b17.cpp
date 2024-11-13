/* 2352018 ��06 ���� */
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

static const char other[] = "~!@#$%^&*()-_=+[],.?";

// ��������
int input(int code, int Capital, int Lower, int Digit, int Other);
void initialize(char password[], int length);
void fill(char password[], int code, int Capital, int Lower, int Digit, int Other);
void disrupt(char password[], int length);
void print(char password[], int length);

int main() 
{
    srand((unsigned int)(time(0)));

    int code, Capital, Lower, Digit, Other;
    cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
    cin >> code >> Capital >> Lower >> Digit >> Other;
    if (cin.fail())
    {
        cout << "����Ƿ�" << endl;
        return -1;
    }
    int in = input(code, Capital, Lower, Digit, Other);
    switch (in)
    {
        case 1:
            cout << "���볤��[" << code << "]����ȷ" << endl;
            break;
        case 2:
            cout << "��д��ĸ����[" << Capital << "]����ȷ" << endl;
            break;
        case 3:
            cout << "Сд��ĸ����[" << Lower << "]����ȷ" << endl;
            break;
        case 4:
            cout << "���ָ���[" << Digit << "]����ȷ" << endl;
            break;
        case 5:
            cout << "�������Ÿ���[" << Other << "]����ȷ" << endl;
            break;
        case 6:
            cout << "�����ַ�����֮��[" << Capital << "+" << Lower << "+" << Digit << "+" << Other << "]���������볤��[" << code << "]" << endl;
            break;
        default:
            cout << code << " " << Capital << " " << Lower << " " << Digit << " " << Other << endl;
            const int arraySize = 10; // Ҫ���ɵ���������
            for (int i = 0; i < arraySize; ++i) {
                char password[17]; // +1 �����ַ��������� '\0'
                initialize(password, code);
                fill(password, code, Capital, Lower, Digit, Other);
                disrupt(password, code);
                print(password, code);
                cout << endl; // ����֮���һ��
            }
    }

    return 0;
}

// ������֤����
int input(int code, int Capital, int Lower, int Digit, int Other)
{
    if (code < 12 || code > 16)
        return 1;
    if (Capital < 2 || Capital > code)
        return 2;
    else if (Lower < 2 || Lower > code)
        return 3;
    else if (Digit < 2 || Digit > code)
        return 4;
    else if (Other < 2 || Other > code)
        return 5;
    else if ((Capital + Lower + Digit + Other) > code)
        return 6;

    return 0;
}

// ��ʼ���������麯��
void initialize(char password[], int length) 
{
    for (int i = 0; i < length; ++i) 
    {
        password[i] = 0; 
    }
    password[length] = '\0'; // ����ַ���������
}


// ����������������
void fill(char password[], int length, int Capital, int Lower, int Digit, int Other)
{
    // ��������������СҪ��������ַ�
    for (int i = 0; i < Capital; ++i)
    {
        password[i] = 'A' + (rand() % 26); // ���ɴ�д��ĸ
    }
    for (int i = Capital; i < Capital + Lower; ++i) 
    {
        password[i] = 'a' + (rand() % 26); // ����Сд��ĸ
    }
    for (int i = Capital + Lower; i < Capital + Lower + Digit; ++i) 
    {
        password[i] = '0' + (rand() % 10); // ��������
    }
    for (int i = Capital + Lower + Digit; i < length; ++i) 
    {
        password[i] = other[rand() % strlen(other)]; // ������������
    }

    // Ȼ������������ɵ����룬��ȷ���ַ��ֲ��������
    for (int i = 0; i < length - 1; ++i) 
    {
        int j = rand() % (length - i);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}


// ������������
void disrupt(char password[], int length) 
{
    for (int i = 0; i < length; ++i) 
    {
        // ���ѡ��һ��Ԫ���뵱ǰԪ�ؽ���
        int j = rand() % (length - i) + i;

        // ֱ�ӽ�������Ԫ�ص�ֵ
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

// ��ӡ����
void print(char password[], int length)
{
    for (int i = 0; i < length; ++i) 
        cout << password[i];
}