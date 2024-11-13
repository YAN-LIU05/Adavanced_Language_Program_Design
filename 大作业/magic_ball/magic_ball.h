/* 2352018 ��06 ���� */
#pragma once

#define MIN_ROWS  5
#define MAX_ROWS  10
#define MIN_COLS  5
#define MAX_COLS  10
#define TIME 20

//�˵�����
int magic_menu();   //��ʾ���˵��������ȷ��ѡ��󷵻�

int ball_base_all(int choice);   //base�Ļ��ܺ���


void print_origin(int rows, int cols, int array[MIN_ROWS][MAX_ROWS]);   //��ӡ��ʼ����
void print_mark(int rows, int cols, int array[MIN_ROWS][MAX_ROWS]);   //��ӡ��ʼ��������
void print_tips(int rows, int cols, int array[MIN_ROWS][MAX_ROWS]);   //��ӡ��ʾ��
void base_remove(int array[MAX_ROWS][MAX_COLS], int rows, int cols, int choice);   //��ͬ���ֵ�������0������
void draw_border(int row, int column, bool border, int choice);   //�����߿�
void draw_ball(int i, int j, int color, int border);   //��������
void draw_clean(int i, int j, int color);   //��������
void draw_nine(int array[MIN_ROWS][MAX_ROWS], int rows, int cols, int choice);   //��9���Ļ��ܺ���
int draw_fall(int array[MAX_ROWS][MAX_COLS], int rows, int cols, int choice, int array0[MAX_ROWS][MAX_COLS], int have_score);   //��������

bool base_check0(const int array[MAX_ROWS][MAX_COLS], int row, int col, int rows, int cols);   //����Ƿ��������
bool base_check1(const int array[MAX_ROWS][MAX_COLS], int rows, int cols);   //����Ƿ��г�ʼ��������
bool base_check2(const int array[MAX_ROWS][MAX_COLS], const int directions[4][2], int row, int col, int rows, int cols);   //����Ƿ������ʾ

int tj_strcasecmp(const char* s1, const char* s2);   //�Ƚ��ַ���s1��s2�Ĵ�С,Ӣ����ĸ���ִ�Сд
void set_botton(bool set, int num);   //��������


