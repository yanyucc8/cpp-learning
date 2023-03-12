#include <iostream>
using namespace std;

/*
1.3.6 类模板成员函数类外实现

*/
template<class T1, class T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;

public:
    Person(T1 _name, T2 _age);
    void ShowPerson();
};

//构造函数类外声明
template<class T1, class T2>
Person<T1, T2>::Person(T1 _name, T2 _age)
{
    this->m_name = _name;
    this->m_age = _age;
}

//成员函数类外声明
template<class T1, class T2>
void Person<T1, T2>::ShowPerson()
{
    cout << "the name of this person is : " << this->m_name << endl;
    cout << "the age of this person is : " << this->m_age << endl;
}

void test()
{
    Person<string, int> man("LIHua", 17);
    man.ShowPerson();
}

int main()
{
    test();

    system("pause");
    return 0;
}