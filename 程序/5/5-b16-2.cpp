/* 2352018 ��06 ���� */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_STUDENTS 10
#define MAX_ID_LENGTH 8
#define MAX_NAME_LENGTH 8

// ����ѧ����Ϣ
void input(string id[], string name[], int scores[])
{
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        cout << "�������" << (i + 1) << "���˵�ѧ�š��������ɼ�" << endl;
        cin >> id[i];
        cin >> name[i];
        cin >> scores[i];
        cin.ignore(65536, '\n');
    }
}

// ð�����򣬰��ɼ���������
void sort(int scores[], string id[], string name[])
{
    for (int i = 0; i < MAX_STUDENTS - 1; ++i)
    {
        for (int j = 0; j < MAX_STUDENTS - i - 1; ++j)
        {
            if (scores[j] > scores[j + 1])
            {
                // �����ɼ�
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                // ����ѧ��
                string tempId = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempId;

                // ��������
                string tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
            }
        }
    }
}

// ��ӡ������ѧ������
void print(string id[], string name[], int scores[])
{
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        if (scores[i] < 60)
        {
            cout << name[i] << " " << id[i] << " " << scores[i] << endl;
        }
    }
}

int main()
{
    string id[MAX_STUDENTS];
    string name[MAX_STUDENTS];
    int scores[MAX_STUDENTS];

    // ����ѧ����Ϣ
    input(id, name, scores);

    // ���ɼ���������
    sort(scores, id, name);
    cout << endl;

    // ��ӡ������ѧ������
    cout << "����������(�ɼ�����):" << endl;
    print(id, name, scores);

    return 0;
}