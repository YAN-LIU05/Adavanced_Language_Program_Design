/* 2352018 ��06 ���� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include "read_stulist.h"
#include <iomanip>
#include <fstream>
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
#define LENGTH 60
#define MAX_STUDENT_NUM 10000

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_merge {
private:
	int  stu_no;					//ѧ�� 
	char stu_name[MAX_NAME_LEN];  //����
	int statue;
	friend stu_list;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	void handle_data(int choice);
	void handle_check();
	void handle_order();
	void handle_change1(stu_merge* a1, stu_merge* a2);
	void handle_change2(stu_merge* a1, stu_merge* a2);
	void bubbleSort(student list[], int count);
	void remove_repeat(student list[], int& count);

	char* tj_strcpy(char* s1, const char* s2)
	{
		if (s1 == NULL)
		{
			return s1;
		}

		char* s = s1;

		if (s2 == NULL)
		{
			*s = '\0';
		}
		else
		{
			for (; *s2 != '\0'; s++, s2++)
			{
				*s = *s2;
			}
			*s = '\0';
		}

		return s1;
	}
	int tj_strlen(const char* str)
	{
		/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
		int length = 0;
		if (str == NULL)
		{
			return 0;
		}

		while (*str != '\0')
		{
			length++;
			str++;
		}

		return length;
	}


	
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};


// ð��������
void stu_list::bubbleSort(student list[], int count)
{
	for (int i = 0; i < count - 1; i++) 
	{
		for (int j = 0; j < count - i - 1; j++) 
		{
			if (list[j].no > list[j + 1].no) 
			{
				int tempNo = list[j].no;
				char tempName[MAX_NAME_LEN];
				tj_strcpy(tempName, list[j].name);

				list[j].no = list[j + 1].no;
				tj_strcpy(list[j].name, list[j + 1].name);

				list[j + 1].no = tempNo;
				tj_strcpy(list[j + 1].name, tempName);
			}
		}
	}
}

// ȥ�غ���
void stu_list::remove_repeat(student list[], int& count) 
{
	for (int i = 0; i < count - 1;) 
	{
		if (list[i].no == list[i + 1].no) 
		{
			// �ƶ������ظ���
			for (int k = i + 1; k < count - 1; k++) 
			{
				list[k] = list[k + 1];
			}
			count--; // ���¼���
		}
		else 
		{
			i++;
		}
	}
}

void stu_list::handle_data(int choice)
{

	// ���� choice ִ�в�ͬ���������
	if (choice == 1)
	{
		bubbleSort(list_round_1, list_num_1);
	}
	else if (choice == 2)
	{
		bubbleSort(list_round_2, list_num_2);
	}

	// ���� choice ִ�в�ͬ��ȥ�ز���
	if (choice == 1)
	{
		remove_repeat(list_round_1, list_num_1);
	}
	else if (choice == 2)
	{
		remove_repeat(list_round_2, list_num_2);
	}
}

void stu_list::handle_change1(stu_merge* a1, stu_merge* a2)
{
	int temp = a1->stu_no;
	a1->stu_no = a2->stu_no;
	a2->stu_no = temp;;
}

void stu_list::handle_change2(stu_merge* a1, stu_merge* a2)
{
	int temp = a1->statue;
	a1->statue = a2->statue;
	a2->statue = temp;;
}

void stu_list::handle_order()
{
	int i, j;
	char temp_name[MAX_NAME_LEN];

	for (i = 0; i < list_merge_num - 1; i++)
	{
		for (j = 0; j < list_merge_num - i - 1; j++)
		{
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no)
			{
				// ����ѧ��
				stu_list::handle_change1(&list_merge[j], &list_merge[j + 1]);

				// ��������
				tj_strcpy(temp_name, list_merge[j + 1].stu_name);
				tj_strcpy(list_merge[j + 1].stu_name, list_merge[j].stu_name);
				tj_strcpy(list_merge[j].stu_name, temp_name);
				// ����״̬
				stu_list::handle_change2(&list_merge[j], &list_merge[j + 1]);
			}
		}
	}
}


void stu_list::handle_check()
{
	int i, j;
	for (i = 0; i < list_num_1; i++)
	{
		list_merge[i].stu_no = list_round_1[i].no;
		list_merge[i].statue = 0;
		for (j = 0; j < tj_strlen(list_round_1[i].name) + 1; j++) 
		{
			list_merge[i].stu_name[j] = list_round_1[i].name[j];
		}
	}
	list_merge_num = list_num_1;


	for (i = 0; i < list_num_2; i++)
	{
		int round_num = 0;
		for (j = 0; j < list_num_1; j++)
		{
			if (list_merge[j].stu_no == list_round_2[i].no)
			{
				round_num = 1;
				list_merge[j].statue = 1;
				break;
			}
		}
		if (round_num == 0)
		{
			if (list_merge_num < MAX_STUDENT_NUM) 
			{
				list_merge[list_merge_num].stu_no = list_round_2[i].no;
				list_merge[list_merge_num].statue = 2;
				for (j = 0; list_round_2[i].name[j] != '\0'; j++)
				{
					list_merge[list_merge_num].stu_name[j] = list_round_2[i].name[j];
				}
				list_merge[list_merge_num].stu_name[j] = '\0'; // ȷ���ַ����� '\0' ��β
				list_merge_num++;
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	for (int i = 0; i < MAX_STU_NUM; i++)
	{
		list_merge[i].stu_no = 0;
		list_merge[i].statue = 0;
		list_round_1[i].no = 0;
		list_round_2[i].no = 0;
	}
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}




/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}
	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* t)
{
	cout << t << endl;
		for (int i = 0; i < LENGTH; i++)
			cout << "=";
		cout << endl;
		cout << "��� ѧ��     ����";
		for (int i = 0; i < 28; i++)
			cout << " ";
		cout << "��һ�� �ڶ���" << endl;
		for (int i = 0; i < LENGTH; i++)
			cout << "=";
		cout << endl;
		for (int i = 0; list_merge[i].stu_no > 0; i++)
		{
			cout << setiosflags(ios::left);
			cout << setw(4) << i + 1; // ���
			if (list_merge[i].stu_no == '\0')
			{ 
				cout << " " << "  "; 
			}
			else {
				cout << " " << list_merge[i].stu_no;
			}
			cout << "  " << setw(32) << list_merge[i].stu_name; 
	
			switch (list_merge[i].statue)
			{
				case 1:
					cout << "Y      Y";
					break;
				case 0:
					cout << "Y      �˿�";
					break;
				default:
					cout << "/      ��ѡ";
			}
			
			cout << endl;
	
		}
		for (int i = 0; i < LENGTH; i++)
			cout << "=";
		cout << endl;
		return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	// �ϲ���һ\��������
	list.handle_data(1);
	list.handle_data(2);

	// ����ִ�
	list.handle_check();

	//�б�����
	list.handle_order();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

