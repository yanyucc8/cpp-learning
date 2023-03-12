#include <iostream>
using namespace std;

/*
模板
泛型编程思想，利用模板

语法：
template<typename T>
函数声明

*/

//实现一个交换函数的模板，用于交换各种类型的数据

template<typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test()
{
    int a = 10;
    int b = 20;

    //1.自动推断
    MySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //2.显式指定类型
    float c = 2.9;
    float d = 5.3;
    MySwap<float>(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

}

int main()
{
    test();

    system("pause");
    return 0;
}