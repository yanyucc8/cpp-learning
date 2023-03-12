#include <iostream>
using namespace std;
/*
4.5 运算符重载
运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

4.5.1 加号运算符重载
作用：实现两个自定义数据类型相加的运算
*/

class Person
{
public:
    int m_A;
    int m_B;

    // 如果在以下成员函数或全局函数中初始化Person对象temp时，
    // 可以写成 Person temp;
    // 需要写构造函数Person(){}

    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }

    //利用成员函数实现 + 号运算符重载
    Person operator+(const Person & _person)
    {
        Person temp(0, 0);
        temp.m_A = this->m_A + _person.m_A;
        temp.m_B = this->m_B + _person.m_B;
        return temp;
    }
};

//利用全局函数实现 + 号运算符重载
//注意成员函数重载和全局函数重载 只能有一个，不然会出现ambiguous overload for 'operator+'报错
//或者给 成员函数的形参 和 全局函数的形参 都加上 const

//常量引用主要用来修饰形参，防止误操作
//在函数形参列表中，可以加const修饰形参，防止形参改变实参

Person operator+(const Person &_p1, const Person &_p2)
{
    Person temp(0, 0);
    temp.m_A = _p1.m_A + _p2.m_A;
    temp.m_B = _p1.m_B + _p2.m_B;
    return temp;
}

//运算符重载 也可以发生 函数重载
Person operator+(const Person &_p, int val)
{
    Person temp(0, 0);
    temp.m_A = _p.m_A + val;
    temp.m_B = _p.m_B + val;
    return temp;
}

void test()
{
    Person p1(10, 10);
    Person p2(20, 20);

    //利用成员函数实现 + 号运算符重载
    //本质是：Person p3 = p1.operator+(p2);
    // Person p3 = p1 + p2;
    
    //利用全局函数实现 + 号运算符重载
    //本质是：Person p3 = operator+(p1, p2);
    //Person p3 = p1 + p2; 

    //运算符重载 也可以发生 函数重载
    //本质是：Person p3 = operator+(p1, 10);
    Person p3 = p1 + 10;
    
    cout << "p3.m_A = " << p3.m_A << endl;
    cout << "p3.m_B = " << p3.m_B << endl;
    
}

int main()
{
    test(); 

    system("pause");
    return 0;
}