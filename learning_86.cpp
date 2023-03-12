#include <iostream>
using namespace std;
/*
1.2.6 模板的局限性

局限性：模板的通用性并不是万能的

对于一些自定义的类，我们无法在函数模板中有效完成对类的属性进行关系型、逻辑型运算符等的使用。
（或者需要进行运算符重载）
*/

class Person
{
public:
    int m_age;
    string m_name;

    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

};

template<typename T>
bool compare(T &m1, T &m2)
{
    if (m1 == m2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//这里直接传入 compare(Person p1, Person p2) 会报错
//我们需要对函数模板进行具体化实现
//具体化优先于普通函数模板
template<>bool compare(Person &p1, Person &p2)
{
    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a = 10;
    int b = 10;
    //内置数据类型可以直接调用普通的函数模板
    cout << "a is equal to b. the judgement is " << (compare(a,b) ? "true" : "false") << endl;

    Person p1("LiLei", 20);
    Person p2("LiLei", 20);
    //自定义数据类型，不会调用普通的函数模板
    //需要创建具体化的Person数据类型的模板，用于处理特殊的数据类型
    cout << "p1 is equal to p2. the judgement is " << (compare(p1,p2) ? "true" : "false") << endl;

}

int main()
{
    test01();

    system("pause");
    return 0;
}