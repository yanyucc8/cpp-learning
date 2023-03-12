#include <iostream>
using namespace std;

int main() {
    //单精度 float
    //双精度 double
    float f1 = 3.14f;
    double d1 = 3.14;

    cout << f1 << endl;
    cout << d1 << endl;

    cout << "float sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(d1) << endl;

    float f2 = 8.88e2;
    cout << "f2 = " << f2 << endl;

    float f3 = 8.88e-2;
    cout << "f3 = " << f3 << endl;

    system("pause");
    return 0;
}