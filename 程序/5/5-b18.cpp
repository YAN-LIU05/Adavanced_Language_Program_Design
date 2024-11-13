/* 2352018 ��06 ���� */
#include <iostream>

using namespace std;

static const char other[] = "~!@#$%^&*()-_=+[],.?";

// �������ڼ���ַ��Ƿ������ض��ַ���
bool Other_check(char c) 
{
    int Length = sizeof(other) - 1;
    for (int i = 0; i < Length; ++i) 
    {
        if (c == other[i]) 
        {
            return true;
        }
    }
    return false;
}

// �������ڼ�鵥�������Ƿ���Ч
bool check1(const char password[], int length, int Capital, int Lower, int Digit, int Other) 
{
    int capitalCount = 0, lowerCount = 0, digitCount = 0, otherCount = 0, special = 0;

    // ���������ַ�������������ַ�������
    for (int i = 0; i < length; ++i)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            capitalCount++;
        else if (password[i] >= 'a' && password[i] <= 'z')
            lowerCount++;
        else if (password[i] >= '0' && password[i] <= '9')
            digitCount++;
        else if (Other_check(password[i]))
            otherCount++; 
        else
            special++;
    }

    bool ck1= (capitalCount >= Capital) && (lowerCount >= Lower) && (digitCount >= Digit) && (otherCount >= Other) && (special == 0);
    return ck1;
}

// ������볤�Ⱥ����������Ƿ����Ҫ��
bool check2(int length, int Capital, int Lower, int Digit, int Other)
{
    bool ck2_1, ck2_2, ck2_3, ck2_4, ck2_5, ck2_6;
    ck2_1 = length >= 12 && length <= 16;
    ck2_2 = Capital >= 2 && Capital <= length;
    ck2_3 = Lower >= 2 && Lower <= length;
    ck2_4 = Digit >= 2 && Digit <= length;
    ck2_5 = Other >= 2 && Other <= length;
    ck2_6 = Capital + Lower + Digit + Other <= length;
    return ck2_1 && ck2_2 && ck2_3 && ck2_4 && ck2_5 && ck2_6;
}

int main()
{
    int code, Capital, Lower, Digit, Other;
    char password[100]; // �洢����������ַ�����
	char sentence[5][20];

    // ��ȡ������ܳ��Ⱥ͸����ַ�����С����
	for (int i = 0; i < 5; i++)  //���һ��
    {
		cin >> sentence[i];
	}
    cin >> code >> Capital >> Lower >> Digit >> Other;
    cin.ignore(); // ���Ի��з�

    bool valid = true;
    for (int i = 0; i < 10; ++i) 
    {
        // �������������׼����ȡ��һ������
        for (int j = 0; j < 100; ++j) 
        {
            password[j] = 0;
        }

        // ��ȡһ�����룬ֱ���������з���ﵽ��󳤶�
        for (int k = 0; k < code; ++k)
        {
            cin >> password[k];
        }

        // ��鵱ǰ�����Ƿ���Ч
        if (!check1(password, code, Capital, Lower, Digit, Other) || !check2(code, Capital, Lower, Digit, Other)) 
        {
            valid = false;
            break; // �������һ��������Ч�����ж�ѭ��
        }
    }

    // ��������
    if (valid)
        cout << "��ȷ" << endl;
    else 
        cout << "����" << endl;

    return 0;
}