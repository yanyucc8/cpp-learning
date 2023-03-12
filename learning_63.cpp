#include <iostream>
using namespace std;

/*
4.5.3 递减运算符重载

作用： 通过重载递减运算符，实现自己的整型数据

*/
class MyDecrement
{
    friend ostream &operator<<(ostream &new_cout, const MyDecrement& _decrement);

private:
    int m_Num;
public:
    MyDecrement()
    {
        m_Num = 0;
    }

    //前置--
    MyDecrement& operator--()
    {
        m_Num--;//先--
        return *this;//再返回值，利用 & 接收，来实现链式编程
    }
    
    //后置--
    MyDecrement operator--(int)
    {
        MyDecrement temp = *this;//this指针 指向被调用成员函数所属的对象，利用 * 解引用
        m_Num--;
        return temp;
    }
};

ostream& operator<<(ostream& new_cout, const MyDecrement& _decrement)
{
    new_cout << _decrement.m_Num;
    return new_cout;
}

//前置--
void test01()
{
    MyDecrement decrement_1;
    cout << "m_Num = " << --(--decrement_1) << endl;
    cout << "m_Num = " << decrement_1 << endl;
}

//后置--
void test02()
{
    MyDecrement decrement_2;
    cout << "m_Num = " << decrement_2-- << endl;
    cout << "m_Num = " << decrement_2 << endl;
}

int main()
{
    //test01();

    test02();
    
    system("pause");
    return 0;
}