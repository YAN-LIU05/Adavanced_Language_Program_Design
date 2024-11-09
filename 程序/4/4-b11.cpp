/* 2352018 ��06 ���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

void tower1(int ch)
{
	if (ch == 'A')
		cout << "A";
	else
	{
		cout << char(ch);
		tower1(ch - 1);
	}
}
void tower2(int ch)
{
	if (ch != 'A')
	{
		tower2(ch - 1);
		cout << char(ch);
	}
}


void blank(int num)
{
	if (num != 0)
	{
		cout << " ";
		blank(num - 1);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
			��ʾ����һ������order��ָ������/����
***************************************************************************/
void print_tower(int ch, int order, int flag)   //flag�����ж�����
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	static int x;
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
	if (order == 1)
	{
		if (ch != 'A')
		{
			x++;
			print_tower(ch - 1, order, flag);   
			x--;
		}
		blank(x);
		tower1(ch);
		tower2(ch);
		cout << endl;
	}
	else
	{
		if (flag)
		{
			if (ch == 'A')
			{
				blank(x);
				x = 0;
				tower1(ch);
				tower2(ch);
				cout << endl;
			}
			else
			{
				blank(x);
				x++;
				tower1(ch);
				tower2(ch);
				cout << endl;
				print_tower(ch - 1, order, flag);
			}
		}
		else
		{
			x++;
			if (ch == 'A')
			{
				blank(x);
				x = 0;
				tower1(ch);
				tower2(ch);
				cout << endl;
			}
			else if (ch == 'A' - 1)
				cout << "";
			else
			{
				blank(x);
				tower1(ch);
				tower2(ch);
				cout << endl;
				print_tower(ch - 1, order, flag);
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 1, 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 2, 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "" << endl;/* ����ĸ����������= */
	print_tower(end_ch, 1, 1);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch - 1, 2, 0);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}