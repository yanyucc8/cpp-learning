#include <iostream>
using namespace std;

/*
4.2.6 初始化列表
作用：

C++提供了初始化列表语法，用来初始化属性

语法：构造函数()：属性1(值1),属性2（值2）... {}
*/

class Person
{
public:
    //传统初始化
    // Person(int a, int b, int c)
    // {
    //     m_a = a;
    //     m_b = b;
    //     m_c = c;
    // }

    //初始化列表方式 初始化
    Person(int a, int b, int c) : m_a(a), m_b(b), m_c(c){}

    void printPerson()
    {
        cout << "m_a = " << m_a << endl;
        cout << "m_b = " << m_b << endl;
        cout << "m_c = " << m_c << endl;
    }

private:
    int m_a;
    int m_b;
    int m_c;
};

void test01()
{
    // Person p1(10, 20, 30);
    // p1.printPerson();
    Person p2(3, 2, 1);
    p2.printPerson();
}

int main()
{
    test01();

    system("pause");
    return 0;
}