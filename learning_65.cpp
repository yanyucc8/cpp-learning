#include <iostream>
using namespace std;

/*
4.5.5 关系运算符重载

**作用：**重载关系运算符，可以让两个自定义类型对象进行对比操作

*/
class Person
{
private:
    string m_name;
    int m_age;
public:
    string get_name();
    int get_age();
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    //关系运算符重载
    bool operator==(Person& _p)
    {
        if (this->m_name == _p.m_name && this->m_age == _p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Person& _p)
    {
        if (this->m_name == _p.m_name && this->m_age == _p.m_age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

string Person::get_name()
{
    return this->m_name;
}

int Person::get_age()
{
    return this->m_age;
}

void show_Peron(Person &_p)
{
    cout << "the name of this person is " << _p.get_name() << "\t";
    cout << "the age of this person is " << _p.get_age() << endl;
}

void test()
{
    Person man_1("LiLei", 29);
    Person man_2("LiLei", 29);

    show_Peron(man_1);
    show_Peron(man_2);
    
    if (man_1 == man_2)
    {
        cout << "These two person are the same." << endl;
    }
    else
    {
        cout << "These two person are the different." << endl;
    }
}

int main()
{
    test();

    system("pause");
    return 0;
}
