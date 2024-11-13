/* 2352018 ��06 ���� */
#include <iostream>  
using namespace std;

void Sort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int scores[1000];
    int score_count = 0;
    int score;

    cout << "������ɼ������1000������������������" << endl;

    while (score_count < 1000 && cin >> score && score >= 0) 
    {
        scores[score_count++] = score;
    }

    if (score_count == 0) 
    {
        cout << "����Ч����" << endl;
        return 0;
    }
 
    cout << "���������Ϊ:" << endl;
    for (int i = 0; i < score_count; ++i)
    {
        cout << scores[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    Sort(scores, score_count);

    int r = 1;
    int last_score = scores[0]; // ���ڼ�¼��һ���ɼ�
    cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
    for (int i = score_count - 1; i >= 0; --i)
    {
        if (scores[i] != last_score) // �����ǰ�ɼ�����һ���ɼ���ͬ
        {
            r = i + 1; // ��������Ϊ��ǰ��������1
            last_score = scores[i]; // ������һ���ɼ�
        }
        int rank = score_count - r + 1;
        cout << scores[i] << " " << rank << endl; // ����ɼ�������
    }

    return 0;
}