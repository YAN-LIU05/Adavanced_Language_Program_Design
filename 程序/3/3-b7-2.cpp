/* 2352018 ��06 ���� */
#include <iostream>  
using namespace std;

int main() 
{
    double s;
    int a, b, c, d, e, p, q, x, y, z, sum, t;
  
    cout << "����������ֵ��" << endl;
    cin >> s;

    if (s >= 0.01 && s < 100) {
        sum = static_cast<int>(s * 100);

        a = sum / 5000; // 50Ԫ  
        b = (sum - 5000 * a) / 2000;// 20Ԫ  
        c = (sum - 5000 * a - 2000 * b) / 1000;// 10Ԫ  
        d = (sum - 5000 * a - 2000 * b - c * 1000) / 500;// 5Ԫ
        e = (sum - 5000 * a - 2000 * b - c * 1000 - 500 * d) / 100;// 1Ԫ
        p = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100) / 50);// 5��
        q = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p) / 10);// 1��
        x = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q) / 5);// 5��
        y = ((sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q - x * 5) / 2);// 2��
        z = sum - 5000 * a - 2000 * b - c * 1000 - 500 * d - e * 100 - 50 * p - 10 * q - 5 * x - 2 * y;// 1��

        t = a + b + c + d + e + p + q + x + y + z;
        cout << "��" << t << "�����㣬�������£�" << endl;

        switch (a) {
            case 0:
                break;
            default:
                cout << "50Ԫ : " << a << "��" << endl;
                break;
        }
        switch (b) {
            case 0:
                break;
            default:
                cout << "20Ԫ : " << b << "��" << endl;
                break;
        }
        switch (c) {
            case 0:
                break;
            default:
                cout << "10Ԫ : " << c << "��" << endl;
                break;
        }
        switch (d) {
            case 0:
                break;
            default:
                cout << "5Ԫ  : " << d << "��" << endl;
                break;
        }
        switch (e) {
            case 0:
                break;
            default:
                cout << "1Ԫ  : " << e << "��" << endl;
                break;
        }
        switch (p) {
            case 0:
                break;
            default:
                cout << "5��  : " << p << "��" << endl;
                break;
        }
        switch (q) {
            case 0:
                break;
            default:
                cout << "1��  : " << q << "��" << endl;
                break;
        }
        switch (x) {
            case 0:
                break;
            default:
                cout << "5��  : " << x << "��" << endl;
                break;
        }
        switch (y) {
            case 0:
                break;
            default:
                cout << "2��  : " << y << "��" << endl;
                break;
        }
        switch (z) {
            case 0:
                break;
            default:
                cout << "1��  : " << z << "��" << endl;
                break;
        }
    }
    else {
        cout << "�����������������" << endl;
    }

    return 0;
}