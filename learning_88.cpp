#include <iostream>
using namespace std;

/*
1.3.2 类模板与函数模板区别

类模板与函数模板区别主要有两点：

    1.类模板没有自动类型推导的使用方式
    2.类模板在模板参数列表中可以有默认参数
*/

template<class NameType, class AgeType = int> //AgeType的默认类型是int
class Person
{
public:
    NameType m_name;
    AgeType m_age;

    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    ShowPerson()
    {
        cout << "name:" << this->m_name << "\tage:" << this->m_age << endl;
    }
};


void test01()
{
    //Person p1("NaNa", 18);//出错
    //1.类模板没有自动推导类型的使用，类模板必须要确定出T的数据类型
    Person<string, int> p2("NaNa", 18);
    p2.ShowPerson();
}

void test02()
{
    //2.类模板在模板参数列表中可以有默认参数
    Person<string> p3("LiLei", 20);
    p3.ShowPerson();
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
