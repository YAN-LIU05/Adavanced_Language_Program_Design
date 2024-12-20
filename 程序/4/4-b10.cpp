/* 2352018 信06 刘彦 */
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：求num是不是base的幂
     输入参数：
     返 回 值：0 - 不是
               1 - 是
     说    明：函数名、形参、返回类型均不准动
   ***************************************************************************/
int is_power(int num, int base)
{
    if (num == 1 || num == base)
        return 1;
    if (num != 1 && num % base != 0)
        return 0;

    return is_power(num / base, base);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入、调用递归函数、输出
***************************************************************************/
int main()
{
    int n, b, x;
    cout << "请输入整数num及基数base" << endl;
    cin >> n >> b;

    x = is_power(n, b);
    if (x == 1) 
        cout << n << "是" << b << "的幂" << endl;
    else 
        cout << n << "不是" << b << "的幂" << endl;
   
    return 0;
}