#include <iostream>
using namespace std;

/*
4.5.2 左移运算符重载

作用：可以输出自定义数据类型
写法：只能写成全局函数，重载左移运算符配合友元可以实现输出自定义数据类型
*/

class Person
{
    //重载左移运算符配合友元可以实现输出自定义数据类型
    friend ostream &operator<<(ostream &new_out, Person &_p);

private:
    int m_A;
    int m_B;

public:
    Person(int a, int b):m_A(a), m_B(b){}

//在成员函数中，实现不了 cout出现在右侧的方式
};

//重载左移运算符，需要实现以下的效果，并能实现链式编程
//cout << man << endl;

//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream& new_cout, Person& _p)
{
    new_cout << "_p.m_A = " << _p.m_A << "\t"
            << "_p.m_B = " << _p.m_B;
    return new_cout;
}

void test()
{
    Person man(10,10);
    //重载左移运算符，需要实现以下的效果，并能实现链式编程
    cout << man << endl;// 这里 cout << man 等价于 operator<<(cout, man)
    operator<<(cout, man) << endl; 
}

int main()
{
    test();

    system("pause");
    return 0;
}