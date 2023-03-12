#include <iostream>
using namespace std;
#include <windows.h> //为解决exe中文乱码而添加


/*
4.6.6 继承同名静态成员处理方式
问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致

访问子类同名成员 直接访问即可
访问父类同名成员 需要加作用域
*/
//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问

class Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "This is func() from superclass Base." << endl;
    }
    
    static void func(int)
    {
        cout << "This is func(int) from superclass Base." << endl;
    }
};
int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "This is func() from subclass Son." << endl;
    }
};
int Son::m_A = 1;

//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
void test01()
{
    //通过对象来访问 静态成员变量
    Son s1;
    cout << "the value of m_A from the object s1 (subclass) is " << s1.m_A << endl;
    cout << "the value of m_A from the object s1 (superclass) is " << s1.Base::m_A << endl;
    
    //通过类名来访问 静态成员变量
    cout << "the value of m_A from the object s1 (subclass) is " << Son::m_A << endl;
    cout << "the value of m_A from the object s1 (superclass) is " << Son::Base::m_A << endl;
    
}

//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
void test02()
{
    //通过对象来访问 静态成员函数
    Son s2;
    s2.func();
    s2.Base::func();
    s2.Base::func(10);

    //通过类名来访问 静态成员函数
    cout << endl;
    cout << "//通过类名来访问 静态成员变量" << endl;
    
    Son::func();
    Son::Base::func();
    Son::Base::func(20);
}

int main()
{
    SetConsoleOutputCP(65001);//为解决exe中文乱码而添加

    //test01();

    test02();

    system("pause");
    return 0;
}