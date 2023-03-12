#include <iostream>
using namespace std;

/*
引用作函数参数

作用：函数传参时，可以利用引用的技术让形参修饰实参，即在函数内部完成修改实参的操作
优点：可以简化指针修改实参
*/

//值传递
void swap_01(int num1,int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

//地址传递
void swap_02(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//引用传递
void swap_03(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    swap_01(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap_02(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap_03(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}