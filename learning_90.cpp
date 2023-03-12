#include <iostream>
using namespace std;

/*
类模板与继承

1.当子类继承的父类是一个类模板时，子类在声明时，要指出父类中 T 的类型
2.灵活指定父类中 T 的类型，子类也要变成类模板

*/

//定义父类
template<class T>
class Base
{
public:
    T m_attribution;
};

//定义子类1
class Son_1 : public Base<int> {};  //指定从父类继承而来的 T 的类型为 int

//定义子类2
template <class T1, class T2>
class Son_2 : public Base<T1>   //这里T2是来指定父类中的 T 的类型
{
public:
    T2 m_attribution_owned_son; // 子类2中定义了一个只属于子类的 T1 类型的属性，要将子类写成类模板的形式
    void showSon_2();//成员函数类内声明
};
//成员函数类外实现
template <class T1, class T2>
void Son_2<T1, T2>::showSon_2()
{
    cout << "T1的类型是：" << typeid(T1).name() << endl;
    cout << "T2的类型是：" << typeid(T2).name() << endl;
}

void test()
{
    //Son_1 son;
    Son_2<float, int> son;//由类生成对象 需要指定NameType 为string类型，AgeType 为 int类型
    son.showSon_2();
}

int main()
{
    test();

    system("pause");
    return 0;
}