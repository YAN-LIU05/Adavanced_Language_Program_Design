/* 2352018 ��06 ���� */

/* 1���������ͷ�ļ�
   2����������ȫ��������������̬ȫ�֣�������ʾconst��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "7-b2.h"
using namespace std;

#define MAX_ITEMS 10
#define MAX_VISIBLE_ITEMS 10  // ���������������ʾ�Ĳ˵�������
/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */

static int tj_strncpy(char s1[], const char s2[], const int len) {
    int i;

    // ����s2��s1����ิ��len���ַ�
    for (i = 0; i < len && s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }

    // ���s2�ĳ���С��len��ʣ���s1[i]���Ϊnull�ַ�
    for (; i < len; i++) {
        s1[i] = '\0';
    }

    // ����ʵ�ʸ��Ƶ��ַ������������ַ���ֹ��
    return i;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const PopMenu* original_para)
{
    if (!original_para || !menu) return -1; // �������

    int selected = 0; // ��ǰѡ�еĲ˵�������
    int itemCount = 0;
    int scrollOffset = 0; // ���ڹ�����ƫ����

    // ����˵�������
    for (int i = 0; itemCount < 10; ++i) {
        ++itemCount;
    }

    // ѭ����ʾ�˵���ֱ���û�ѡ��һ����
    while (true) {
        
        int itemY = original_para->start_y;
        int titleLength = strlen(original_para->title);
        int titleStartX;
        int width0;
        if (original_para->width % 2 != 0)
        {
            width0 = original_para->width + 1;
            if (original_para->width < int(strlen(original_para->title)))
                width0 = strlen(original_para->title);
        }
            
        else
        {
            width0 = original_para->width;
            if (original_para->width < titleLength)
                width0 = strlen(original_para->title);
        }
            
        if (original_para->width < titleLength)
            titleStartX = original_para->start_x;
        else
            titleStartX = (width0 - titleLength) / 2;
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        if (original_para->start_x != 0)
            cct_gotoxy(original_para->start_x - 1, original_para->start_y);
        else
            cct_gotoxy(original_para->start_x, original_para->start_y);
        // �����ϱ߿�ͱ���
        int actualHigh = 10;
        int height = original_para->high;
        if (original_para->high > 10) {
            height = actualHigh; // �����߶�����Ӧʵ�ʵĲ˵�������
        }
        cout << "�X";
        if (original_para->width >= int(strlen(original_para->title)))
        {
            if (strlen(original_para->title) % 2 != 0)
            {
                for (int j = 0; j < titleStartX - 1 + original_para->start_x; j += 2) {
                    cout << "�T";
                }
            }
            else
            {
                for (int j = 0; j < titleStartX - 1 + original_para->start_x + 2; j += 2) {
                    cout << "�T";
                }
            }
            cct_setcolor(original_para->bg_color, original_para->fg_color);
            if (strlen(original_para->title) % 2 != 0)
                cct_gotoxy(titleStartX + original_para->start_x - 4, original_para->start_y);
            else
            {
                cout << "�T";
                cct_gotoxy(titleStartX + original_para->start_x - 2, original_para->start_y);
            }
        }
        else
            cct_setcolor(original_para->bg_color, original_para->fg_color);
       

        cout << original_para->title;

        if (original_para->width >= int(strlen(original_para->title)))
        {
            if (strlen(original_para->title) % 2 != 0)
                cct_gotoxy(titleStartX + original_para->start_x + titleLength - 3, original_para->start_y);
            else
                cct_gotoxy(titleStartX + original_para->start_x + titleLength - 2, original_para->start_y);

        }
        
        
        if (original_para->width >= int(strlen(original_para->title)))
        {
            for (int j = original_para->start_x + 10; j < width0 - 2; j += 2) {
                cout << "�T";
            }
        }


        cout << "�[" << endl;
        if (strlen(original_para->title) % 2 != 0)
        {
            for (int i = 0; i < height + 1; i++) {
                cct_gotoxy(original_para->start_x - 1, original_para->start_y + i + 1);
                cout << "�U";

                cct_gotoxy(original_para->start_x + width0 - 1, original_para->start_y + i + 1);
                cout << "�U" << endl;
            }
        }
        else
        {
            for (int i = 0; i < height + 1; i++) {
                cct_gotoxy(original_para->start_x - 1, original_para->start_y + i + 1);
                cout << "�U";

                cct_gotoxy(original_para->start_x + width0 + 1, original_para->start_y + i + 1);
                cout << "�U" << endl;
            }
        }
        
        // �����±߿�
        cct_gotoxy(original_para->start_x - 1, original_para->start_y + height + 1);
        cout << "�^";

        if (strlen(original_para->title) % 2 != 0)
        {
            for (int j = 0; j < width0 - 2; j += 2) {
                cout << "�T";
            }
        }
        else
        {
            for (int j = 0; j < width0; j += 2) {
                cout << "�T";
            }
        }

        cout << "�a" << endl;

        // ���Ʋ˵�����
        cct_setcolor(original_para->bg_color, original_para->fg_color);



        // ���Ʋ˵���
        for (int i = 0; i < original_para->high && i + scrollOffset < itemCount; ++i) {
            int itemX = original_para->start_x + 1; // �˵����x����
            int itemY = original_para->start_y + 2 + i; // �˵����y����
            char displayItem[MAX_ITEM_LEN + 1];
            cct_gotoxy(itemX, itemY - 1);


            if (i == selected)
            {
                cct_setcolor(original_para->fg_color, original_para->bg_color);
            }
            else
            {
                cct_setcolor(original_para->bg_color, original_para->fg_color);
            }

            tj_strncpy(displayItem, menu[i + scrollOffset], width0);
            if (itemCount % 2 != 0)
            {

                displayItem[width0 + 1] = '\0';
            }
            else
                displayItem[width0] = '\0';
            int content_width = width0 - 2;


            // ��ӡ�˵���
            cout << displayItem;

            int itemLength = strlen(menu[i + scrollOffset]);
            int spaces = content_width - itemLength; // ��Ҫ��ӡ�Ŀո���

            // ȷ��spaces�ǷǸ�������������ѭ��
            if (spaces >= 0) {
                for (int j = 0; j < spaces; ++j) {
                    cout << ' '; // ��ӡ�ո�
                }
            }

        }

        // �ȴ��û�����
        char key = _getch();
        if (key == 13) { // �û����س���
            break;
        }
        else if (key == 72 && selected > 0) { // �û����ϼ�ͷ��
            --selected;
            if (selected < scrollOffset) scrollOffset = selected;
        }
        else if (key == 80 && selected < itemCount - 1 - scrollOffset) { // �û����¼�ͷ��
            ++selected;
            if (selected - scrollOffset == original_para->high - 1) scrollOffset = selected - original_para->high + 2;
        }
        else if (key == 27) { // �û���Esc���˳�
            selected = -1;
            break;
        }
    }

    // ����ѡ�еĲ˵�����������1��ʼ��������δѡ���򷵻�-1
    return selected + 1;
}