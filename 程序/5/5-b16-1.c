/* 2352018 ��06 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_ID_LENGTH 8
#define MAX_NAME_LENGTH 8

// ����ѧ����Ϣ
void input(char id[][MAX_ID_LENGTH], char name[][MAX_NAME_LENGTH], int scores[]) 
{
    int i;
    for (i = 0; i < MAX_STUDENTS; ++i) 
    {
        printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
        scanf("%s %s %d", id[i], name[i], &scores[i]);
    }
}

// ð�����򣬰�ѧ�Ž�������
void sort(char id[][MAX_ID_LENGTH], char name[][MAX_NAME_LENGTH], int scores[], int n) 
{
    int i, j;
    char id0[MAX_ID_LENGTH];
    char name0[MAX_NAME_LENGTH];
    int temp;
    for (i = 0; i < n - 1; ++i) 
    {
        for (j = 0; j < n - i - 1; ++j) 
        {
            if (strcmp(id[j], id[j + 1]) < 0) 
            {
                // ��������
                strcpy(name0, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], name0);
                // ����ѧ��
                strcpy(id0, id[j]);
                strcpy(id[j], id[j + 1]);
                strcpy(id[j + 1], id0);
                // �����ɼ�
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

// ��ӡ����ѧ������
void print(char id[][MAX_ID_LENGTH], char name[][MAX_NAME_LENGTH], int scores[]) 
{
    int i;
    for (i = 0; i < MAX_STUDENTS; ++i) 
    {
        if (scores[i] >= 60)
        {
            printf("%s %s %d\n", name[i], id[i], scores[i]);
        }
    }
}

int main()
{
    char id[MAX_STUDENTS][MAX_ID_LENGTH];
    char name[MAX_STUDENTS][MAX_NAME_LENGTH];
    int scores[MAX_STUDENTS];

    // ����ѧ����Ϣ
    input(id, name, scores);

    // ��ѧ�Ž�������
    sort(id, name, scores, MAX_STUDENTS);
    printf("\n");

    // ��ӡ����ѧ������
    printf("��������(ѧ�Ž���):\n");
    print(id, name, scores);

    return 0;
}