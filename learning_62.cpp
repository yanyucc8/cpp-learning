#include <iostream>
using namespace std;

/*
4.5.3 递增运算符重载

作用： 通过重载递增运算符，实现自己的整型数据

*/
class MyInteger
{
    friend ostream &operator<<(ostream &new_cout, MyInteger _myInt);
    //friend ostream &operator<<(ostream &new_cout, const MyInteger &_myInt);

private:
    int m_Num;

public:
    MyInteger()
    {
        m_Num = 0;
    }

    //前置++
    //++a 即，先++，再取值
    //前置++，返回引用，能实现链式编程
    MyInteger& operator++()
    {
        m_Num++;//先++
        return *this;//再返回
    }

    //后置++
    //a++ 即，先取值，后++
    //后置++，返回值
    //这是因为，我们在operator++(int)函数中返回的是局部变量temp，不能返回局部变量的地址
    //写在类内，是因为用this指针
    MyInteger operator++(int) //利用int作为函数形参的占位参数，来实现函数重载
    {
        //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        MyInteger temp = *this; // this指针 指向被调用的成员函数的所属的对象，利用 * 解引用
        m_Num++;//先返回
        return temp;//再++
    }
};


ostream& operator<<(ostream& new_cout, MyInteger _myInt)
//ostream& operator<<(ostream& new_cout, const MyInteger& _myInt)
//在后置++函数中，返回值是temp（临时对象），临时对象是不可以修改的，即默认const，
//非const引用只能绑定到与该引用同类型的对象上，（即 函数声明里形参为int型，则只能接收int型实参）
//但是const引用可以使函数接受const和非const实参
//即写成 const MyInteger& _myInt 常量引用的形式
{
    new_cout << _myInt.m_Num ;
    return new_cout;
}

//重置 前置++
void test01()
{
    MyInteger myInt_1;
    // cout << ++myInt_1 << endl; //myInt 是 MyInteger类的对象 这里需要重置左移运算符
    // cout << myInt_1 << endl;
    cout << "m_Num = " << ++(++myInt_1) << endl;
    cout << "m_Num = " << myInt_1 << endl;
}

//重置 后置++
void test02()
{
    MyInteger myInt_2;
    cout << "m_Num = " << myInt_2++ << endl;
    cout << "m_Num = " << myInt_2 << endl;
}

int main()
{
    // int a = 0;
    // cout << a++ << endl;
    // cout << a << endl;

    // test01();

    test02();

    system("pause");
    return 0;
}