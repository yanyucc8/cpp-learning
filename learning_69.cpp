 #include <iostream>
using namespace std;

/*
4.6.5 继承同名成员处理方式
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

1.访问子类同名成员 直接访问即可
2.访问父类同名成员 需要加作用域
*/

//定义父类
class Base
{
public:
    int m_A;
    
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base 类的func函数" << endl;
    }

    void func(int _a)
    {
        cout << "Base 类的func(int _a)函数" << endl;
    }
};

//定义子类
class Son : public Base
{
public:
    int m_A;//子类中的成员 与 从父类继承过来的成员同名

    Son()
    {
        m_A = 1;
    }

    void func()//子类中的成员 与 从父类继承过来的成员同名
    {
        cout << "Son 类的func函数" << endl;
    }
};

void test()
{
    // 当子类中出现新定义的 与父类中继承过来的 同名成员，那么编译器会隐藏掉
    // 从父类继承过来的 所有同名成员（类属性、类函数）
    // 可以通过添加 父类的作用域 来访问那些被隐藏的同名成员
    Son s1;
    cout << "Son 中的 m_A 的值：" << s1.m_A << endl;
    cout << "Son 中的 从 Base 中继承过来的 m_A 的值：" << s1.Base::m_A << endl;

    s1.func();
    s1.Base::func(); //通过添加 Base:: 作用域就能访问到父类中的成员了
    s1.Base::func(20);
}

int main()
{
    test();

    system("pause");
    return 0;
}