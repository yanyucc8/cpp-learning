#include <iostream>
using namespace std;

//全局变量
int gobal_a = 100;
int gobal_b = 100;

//const修饰全局变量
const int const_gobal_c = 100;
const int const_gobal_d = 100;

int main()
{
    //局部变量
    int local_e = 100;
    int local_f = 100;

    //打印 全局变量 和 局部变量 的地址
    cout << "全局变量gobal_a的地址为：" << (long long)&gobal_a << endl;
    cout << "全局变量gobal_b的地址为：" << (long long)&gobal_b << endl;

    cout << "局部变量local_e的地址为：" << (long long)&local_e << endl;
    cout << "局部变量local_f的地址为：" << (long long)&local_f << endl;

    //静态变量
    static int local_g = 100;
    static int local_h = 100;
    cout << "静态变量local_g的地址为：" << (long long)&local_g << endl;
    cout << "静态变量local_h的地址为：" << (long long)&local_h << endl;

    //字符串变量
    cout << "字符串变量的地址为：" << (long long)&"Hello C++" << endl;
    cout << "字符串变量的地址为：" << (long long)&"Hello World" << endl;

    //const修饰局部变量
    const int const_local_i = 100;
    const int const_local_j = 100;
    cout << "const修饰全局变量 const_local_c的地址为" << (long long)&const_gobal_c << endl;
    cout << "const修饰全局变量 const_local_d的地址为" << (long long)&const_gobal_d << endl;
    
    cout << "const修饰局部变量 const_local_i的地址为" << (long long)&const_local_i << endl;
    cout << "const修饰局部变量 const_local_j的地址为" << (long long)&const_local_j << endl;
}