#include <iostream>
using namespace std;

/*

4.2.7 类对象作为类成员

C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员

*/

class Phone
{
public:
    string m_phone_brand;

public:
        
    Phone(string phone_brand)
    {
        m_phone_brand = phone_brand;
        cout << "Phone的有参构造函数调用" << endl;
    }

    Phone(const Phone & _ph)
    {
        m_phone_brand = _ph.m_phone_brand;
        cout << "Phone的拷贝构造函数调用" << endl;
    }

    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
};

class Person
{
public:
    string m_person_name;
    Phone m_person_phone;
    int m_person_age;

public:
    //初始化列表 进行 类对象的初始化
    Person(string person_name, string person_phone, int person_age): m_person_name(person_name),
    m_person_phone(person_phone), m_person_age(person_age)
    {
        cout << "Person的有参构造函数调用" << endl;
    }

    // Person(const Person & _p)
    // {
    //     m_person_name = _p.m_person_name;
    //     m_person_phone = _p.m_person_phone;
    //     m_person_age = _p.m_person_age;

    //     cout << "Person的拷贝构造函数调用" << endl;
    // }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    void show_person()
    {
        cout << "the name of this person is " << m_person_name << "the brand of his phone is " << m_person_phone.m_phone_brand << "his age is "<< m_person_age << endl;
    }

};

//注意此处 调用其他类的属性的时候，要调用到其他类对象的属性名或函数为止！！
// void show_person(Person _person)
// {
//     cout << "the name of this person is " << _person.m_person_name << "the brand of his phone is " << _person.m_person_phone.m_phone_brand << "his age is "<< _person.m_person_age << endl;
// }

void test01()
{
    Person man_1("Lilei", "HUAWEI", 20);
    man_1.show_person();
    //show_person(man_1);
}

int main()
{
    test01();

    system("pause");
    return 0;
}