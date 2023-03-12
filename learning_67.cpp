#include <iostream>
using namespace std;

/*
继承的语法：class 子类 : 继承方式 父类

继承方式一共有三种：
                1.公共继承
                2.保护继承
                3.私有继承
*/

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son_1: public Base
{
public:
    Son_1()
    {
        m_A = 10; //父类中的public属性，可以公共继承，继承后是public属性
        m_B = 10; //父类中的protected属性，可以公共继承，继承后是protected属性
        //m_C = 10; //父类中的private属性，无法公共继承
    }

    int m_D;
};

class Son_2: protected Base
{
public:
    Son_2()
    {
        m_A = 100; //父类中的public属性，可以保护继承，继承后是protected属性
        m_B = 100; //父类中的protected属性，可以保护继承，继承后是protected属性
        //m_C = 100; //父类中的private属性，无法保护继承
    }
};

class Son_3: private Base
{
public:
    Son_3()
    {
        m_A = 1000; //父类中的public属性，可以私有继承，继承后是private属性
        m_B = 1000; //父类中的protected属性，可以私有继承，继承后是private属性
        //m_C = 1000; //父类中的private属性，无法私有继承
    }
};

void test()
{
    Son_1 s1;
    Son_2 s2;
    Son_3 s3;
    
    //子类采用公有继承后，不改变父类的属性权限，protected 和 private 属性类外都无法访问
    //子类采用保护继承后，原父类的public属性都会变为protected属性，protected 和 private 属性 类外都无法访问
    //子类采用私有继承后，原父类的public和protected属性都会变为private属性，private 属性 类外无法访问
    cout << s1.m_A << endl; 
    // cout << s2.m_A << endl; 
    // cout << s3.m_A << endl; 
}

int main()
{
    test();

    system("pause");
    return 0;
}