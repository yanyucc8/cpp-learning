#include <iostream>
using namespace std;

/*
1.2.4普通函数与函数模板的区别：
    
    1.普通函数调用时，可以发生自动隐式类型转换
    2.函数模板调用时，如果利用自动类型转换，不会发生隐式类型转换
    3.函数模板调用时，如果利用显示指定类型，可以发生隐式类型转换

建议在使用函数模板调用时，使用显式指定类型的方式
*/

//普通函数
int MyAdd01(int a, int b)
{
    return a + b;
}

//函数模板
template <typename T>
T MyAdd02(T a, T b)
{
    return a + b;
}

void test()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << "在普通函数中： a + b = " << MyAdd01(a, b) << endl;
    cout << "在函数模板中： a + b = " << MyAdd02(a, b) << endl;
    cout << "在普通函数中： a + c = " << MyAdd01(a, c) << endl; //在普通函数中，会自动发生隐式类型转换
    //cout << "在函数模板中： a + c = " << MyAdd02(a, c) << endl; //在函数模板中，如果利用自动类型推导，不会发生隐式类型转换
    cout << "在函数模板中： a + b = " << MyAdd02<int>(a, c) << endl;//在函数模板中，如果利用显示指定类型，可以发生隐式类型转换
}

int main()
{
    test();

    system("pause");
    return 0;
}