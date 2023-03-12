#include <iostream>
using namespace std;

/*
1.3.8 类模板和友元

    1.全局函数类内实现：直接在类内声明友元即可
    2.全局函数类外实现：需要提前让编译器知道全局函数的存在

    推荐使用 全局函数做类内实现，用法简单，而且编译器可以直接识别
*/

//2.全局函数，类外实现
//全局函数配合友元 类外实现 - 先写函数模板声明，下方再写函数模板定义，再写友元
template<class T1, class T2>
class Person;

//2.全局函数，类外实现
template<class T1, class T2>
void ShowPerson_2(Person<T1, T2> &_person)
{
    cout << "the name of this person is : " << _person.m_name << endl;
    cout << "the age of this person is : " << _person.m_age << endl;
}

//定义Person类
template<class T1, class T2>
class Person
{
    //1.全局函数,类内实现
    friend void ShowPerson_1(Person<T1, T2> &_person)
    {
        cout << "the name of this person is : " << _person.m_name << endl;
        cout << "the age of this person is : " << _person.m_age << endl;
    }

    //2.全局函数，类外实现
    friend void ShowPerson_2<>(Person<T1, T2> &_person);//函数名后不要漏掉 空模板参数列表<>

private:
    T1 m_name;
    T2 m_age;
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
};


void test()
{
    Person<string, int> man("HanMeiMei", 18);
    ShowPerson_1(man);
    ShowPerson_2(man);
}

int main()
{

    test();

    system("pause");
    return 0;
}
