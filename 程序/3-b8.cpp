/* 2352018 ��06 ���� */
#include <iostream>  
#include <cmath>  
#include <iomanip>  
using namespace std;

int main() {
    double e, t;
    e = 0, t = 1;
    int i, x;
    i = 0;

    while (1) {
        cout << "������x��ֵ[-10 ~ +65]" << endl;
        cin >> x;
        if (x >= -10 && x <= 65) {
            while (fabs(t) >= 1e-6) {
                e += t;
                ++i;
                t *= (x * 1.0 / i);
            }
            break;
        }
        else {
            cout << "����Ƿ�,����������" << endl;
        }
    }

    cout << "e^" << x << "=" << setprecision(10) << e << endl;

    return 0;
}