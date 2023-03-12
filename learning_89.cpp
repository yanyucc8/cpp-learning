#include <iostream>
using namespace std;

/*
1.3.4 类模板对象做函数参数
学习目标：

类模板实例化出的对象，向函数传参的方式
一共有三种传入方式：

    1.指定传入的类型 --- 直接显示对象的数据类型
    2.参数模板化 --- 将对象中的参数变为模板进行传递
    3.整个类模板化 --- 将这个对象类型 模板化进行传递

*/

//定义一个Person类的模板
template<class NameType, class AgeType>
class Person
{
public:
    NameType m_name;
    AgeType m_age;

    Person(NameType name, AgeType age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    void ShowPerson()
    {
        cout << "name:" << this->m_name << "\tage:" << this->m_age << endl;
    }
};

//1.向函数中传入 指定的类型，即直接显示对象的数据类型（推荐，便于code review）
void ShowInfo_1(Person<string, int> &_p)
{
    _p.ShowPerson();
}

void test_1()
{
    Person<string, int> man_1("LiLei", 20);
    //man1.ShowPerson();
    ShowInfo_1(man_1);
}

//2.参数模板化，即将对象中的参数变为模板进行传递
template<typename T1, typename T2>
void ShowInfo_2(Person<T1, T2> &_p)
{
    _p.ShowPerson();

    cout << "the type of T1 is : " << typeid(T1).name() << endl;
    cout << "the type of T1 is : " << typeid(T2).name() << endl;

}

void test_2()
{
    Person<string, int> man_2("LiLei", 20);
    
    ShowInfo_2(man_2);
}

//3.整个类模板化，将这个对象类型模板化进行传递
template<class T>
void ShowInfo_3(T &_p)
{
    _p.ShowPerson();
    cout << "the type of T is : " << typeid(T).name() << endl;

}

void test_3()
{
    Person<string, int> man_3("HanMeiMei", 18);
    
    ShowInfo_3(man_3);
}

int main()
{
    //test_1();
    //test_2();
    test_3();
    system("pause");
    return 0;
}