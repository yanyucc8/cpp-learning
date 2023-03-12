#include <iostream>
using namespace std;

/*
1.3 类模板
1.3.1 类模板语法
类模板作用：

建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。

*/

//类模板和函数模板语法相似，
//在声明模板的关键字template后面加类，此类称为类模板
template<class Nametype, class Agetype>
class Person
{
public:
    Nametype m_name;
    Agetype m_age;

    Person(Nametype name, Agetype age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void showPerson()
    {
        cout << "name:" << this->m_name << "\tage:" << this->m_age << endl;
    }
};

void test01()
{
    //由类生成对象 需要指定NameType 为string类型，AgeType 为 int类型
    Person<string, int> p1("NaNa", 18);
    p1.showPerson();
}

int main()
{
    test01();

    system("pause");
    return 0;
}