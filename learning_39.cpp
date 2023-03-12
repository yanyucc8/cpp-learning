#include <iostream>
using namespace std;

/*
引用可以作为函数的返回值存在

注意：不要返回局部变量引用

用法：函数调用作为左值
*/

//返回局部变量引用
// int& test_01()
// {
//     int b = 100; //局部变量
//     return b;
// }


//返回静态变量引用
int& test_02()
{
    static int b = 100;
    cout << "test_02 b=" << b << endl;
    return b;
}

//常量引用
//const 修饰形参，防止函数中形参改变实参
void showValue(const int & value)
{
    cout << "value =" << value << endl;
}

int main()
{
    // int a = 10;
    // //一个数据可以有多个别名
    // int &r1 = a;
    // int &r2 = a;

    // r1 = 20;
    // cout << "a = " << a << endl;

    // r2 = 40;
    // cout << "a = " << a << endl;

    // //不能返回局部变量的引用
    // int &ref = test_01();
    //cout << "ref = " << ref << endl; //直接报错

    //定义为静态变量后 数据放在全局区
    // int &ref2 = test_02();
    // cout << "ref2 = " << ref2 << endl;

    // //如果函数做左值，那么必须返回引用
    // test_02() = 2000;
    // cout << "ref2 = " << ref2 << endl;
    // test_02();

    // //引用的本质：指针常量
    // int s = 100;
    // int &ref3 = s;
    // //等价 int *const ref3 = &s;
    // //指针常量，指针的指向不能修改，指向的数值可以修改。所以引用一旦初始化后就不可以更改。

    // ref3 = 1000;
    // //等价 *ref3 = 1000;


    //函数中利用常量引用防止误操作修改实参
    int input_num = 50;
    showValue(input_num);

}