#include <iostream>
using namespace std;

/*
4.5.4 赋值运算符重载
c++编译器至少给一个类添加4个函数

    1.默认构造函数(无参，函数体为空)
    2.默认析构函数(无参，函数体为空)
    3.默认拷贝构造函数，对属性进行值拷贝
    4.赋值运算符 operator=, 对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
即浅拷贝在执行析构函数过程中，由于堆区内存会被释放两次，而产生内存重复释放的问题。
*/

class Person
{
public:
    int* m_Age;//创建指针

    Person(int input_age)
    {
        m_Age = new int(input_age); //在堆区开辟一块内存空间，并由 m_Age指针 指向这块内存。
    }

    //重载赋值运算符
    //为实现链式编程的效果，需要返回 类对象的引用
    Person& operator=(Person& _person)
    {
        //先释放掉左值原先在堆区的内存
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        // m_Age = _person.m_Age; //编译器提供的浅拷贝，即将 _person的m_Age地址传给 m_Age 

        //再在堆区开辟一块新的内存空间,指向 m_Age
        m_Age = new int(*_person.m_Age); //_person.m_Age 是地址，需要解引用成m_Age的值

        return *this;//返回自身值
    }

    //析构函数
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }        
    }
};

void test()
{
    Person p1(20);
    Person p2(18);
    Person p3(29);

    p3 = p1 = p2;

    cout << "p1 = " << *p1.m_Age << endl;
    cout << "p2 = " << *p2.m_Age << endl;
    cout << "p3 = " << *p3.m_Age << endl;
}

int main()
{
    test();

    system("pause");
    return 0;
}
