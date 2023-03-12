#include <iostream>
using namespace std;

/*
1.2.5 普通函数与函数模板的调用规则
调用规则如下：

    1.如果函数模板和普通函数都可以实现，优先调用普通函数
    2.可以通过空模板参数列表来强制调用函数模板
    3.函数模板也可以发生重载
    4.如果函数模板可以产生更好的匹配,优先调用函数模板

*/

//普通函数
void myprint(int a, int b)
{
    cout << "调用的普通函数。" << endl;
}

//函数模板
template<typename T>
void myprint(T a, T b)
{
    cout << "调用的函数模板。" << endl;
}

//函数模板的重载
template<typename T>
void myprint(T a, T b, T c)
{
    cout << "调用的重载的函数模板。" << endl;
}

void test01()
{
    //1.如果函数模板和普通函数都可以实现，优先调用普通函数
    //如果只有普通函数的声明，而没有包含函数的定义，则编译后会在运行时报错。
    int a = 10;
    int b = 20;
    myprint(a, b);//调用普通函数

    //2.可以通过空模板参数列表来强制调用函数模板
    myprint<>(a, b);//调用函数模板

    //3.函数模板也可以发生重载
    int c = 100;
    myprint(a, b, c);//调用的重载的函数模板

    //4.如果函数模板可以产生更好的匹配,优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myprint(c1, c2);//调用的函数模板
}

int main()
{
    test01();

    system("pause");
    return 0;
}
