#include <iostream>
using namespace std;

/*
4.3.4 const修饰成员函数

1.常函数：

    1.1 成员函数后加const后我们称为这个函数为常函数
    1.2 常函数内不可以修改成员属性
    1.3 成员属性声明时加关键字mutable后，在常函数中依然可以修改

2.常对象：

    2.1 声明对象前加const称该对象为常对象
    2.2 常对象只能调用常函数
*/

class Person
{
public:
    int m_A;
    mutable int m_B; //mutable修饰属性，在常函数中也可以修改

    Person(int a, int b) : m_A(a), m_B(b) {}

    //1.常函数
    //长函数声明是在 括号后面加 const
    
    //this指针 的本质是一个 指针常量，即指针的指向是不可以修改的
    //this 等价于 Person * const this
    //在常函数中，由于函数加了const，又限制了 指针指向的值也不可以修改了
    //即等价于 const Person * const this

    //如果想修改值，可以利用 mutable修饰属性 
    void func1() const
    {
        this->m_B = 100;
    }

    void func2()
    {
        this->m_A = 200;
    }

};

void test01()
{
    Person p1(10, 20);
    p1.func1();
    cout << p1.m_A << endl;
    cout << p1.m_B << endl;
}

//2.常对象
void test02()
{
    //常对象声明
    //在对象前加const
    const Person p2(30, 40);
    //p2.m_A = 300;//常对象不能修改成员变量的值，但是可以访问
    p2.m_B = 400;//常对象可以修改mutable修饰的成员变量

    p2.func1();
    //p2.func2();//常对象只能调用常函数，func2()是普通函数，可以修改属性，所以不可以调用普通函数

    cout << p2.m_A << endl;
    cout << p2.m_B << endl;
}

int main()
{
    //test01();

    test02();

    system("pause");
    return 0;
}
