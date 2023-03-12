#include <iostream>
using namespace std;


/*
在C++中，函数的形参列表中的形参是可以有默认值的。

语法：返回值类型 函数名 （参数= 默认值）{}

*/

int fun_1(int a, int b, int c)
{
    return a + b + c;
}

//如果函数有默认参数，则从这个位置往后（由左往右），必须都要有默认值
//函数声明和函数实现中，只能有一处有默认参数（不然默认参数会出现歧义）
int fun_2(int a, int b, int c);  //函数声明

int fun_2(int a, int b = 10, int c = 20)
{
    return a + b + c;
}


/*
函数占位参数

C++形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置参数

语法：返回值类型 函数名 （数据类型）{}

*/

//函数占位参数，占位参数也可以有默认参数
void fun_3(int a, int)
{
    cout << "this is func about " << a << endl;
} 

/*
函数重载

函数名可以相同，提高复用性

函数重载的满足条件：
    1.同一个作用域下
    2.函数名相同
    3.函数参数类型不同，或个数不同，或顺序不同
*/

//注意函数的返回类型不可以作为函数重载条件

void reload()
{
    cout << "this is a reload function, intput is none." << endl;
}

void reload(int a)
{
    cout << "this is a reload function, intput is int." << endl;
}

void reload(double a)
{
    cout << "this is a reload function, intput is double." << endl;
}

void reload(int a, string b)
{
    cout << "this is a reload function, intput is (int, string)." << endl;
}

void reload(string b, int a)
{
    cout << "this is a reload function, intput is (string, int)." << endl;
}

/*
函数重载的注意事项

1.引用作为重载条件
2.函数重载碰到函数默认参数
*/

//1、引用作为重载条件

void reload_1(int &a)
{
    cout << "this is a reload function, intput is (int &a)." << endl;  
}

void reload_1(const int &a)
{
    cout << "this is a reload function, intput is (const int &a)." << endl;  
}

//2、函数重载碰到函数默认参数

void reload_2(int a, int b = 10)
{
	cout << "reload(int a, int b = 10) 调用" << endl;
}

void reload_2(int a)
{
	cout << "reload(int a) 调用" << endl;
}

int main()
{
    // cout << fun_1(10, 20, 30) << endl;
    // cout << fun_2(10) << endl;

    // fun_3(10, 10);//占位参数必须填补

    // reload();
    // reload(3);
    // reload(3.14);
    // reload("c++", 3);
    // reload(3, "c++");

    int test_input = 10;
    reload_1(test_input);//调用无const
    reload_1(10);//调用有const

    reload_2(10);//碰到默认参数产生歧义，需要避免

    system("pause");
    return 0;

}