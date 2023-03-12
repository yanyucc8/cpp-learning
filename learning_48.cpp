#include <iostream>
using namespace std;

/*
4.2.4 构造函数调用规则
默认情况下，c++编译器至少给一个类添加3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下：

如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造

如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/

class Person
{
public:
    // Person()
    // {
    //     cout << "Person的默认构造函数调用" << endl;
    // }

    Person(int _age)
    {
        age = _age;
        cout << "Person的有参构造函数调用" << endl;
    }

    Person(const Person & _p)
    {
        age = _p.age;
        cout << "Person的拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }    
public:
    int age;
};

//如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
// void test01()
// {
//     //注释掉默认构造和拷贝构造函数，测试
//     Person man_;//报错，系统不再提供无参构造函数
//     Person man_1(20);
//     Person man_2(man_1);//用户没有提供拷贝构造函数，编译器会提供

//     cout << "man_2的年龄是：" << man_2.age << endl;
// }

//如果用户定义拷贝构造函数，c++不在提供其他构造函数
void test02()
{
    //注释掉默认构造和有参构造函数，测试
    //Person man_3;//此时如果用户自己没有提供默认构造，会出错
    //Person man_4(18);//此时如果用户自己没有提供有参，会出错
    Person man_5 = Person(20);//此时如果用户自己没有提供有参，会出错
    Person man_6(man_5);
}
int main()
{
    //test01();

    test02();
    system("pause");
    return 0;
}