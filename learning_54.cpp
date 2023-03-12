#include <iostream>
using namespace std;

/*
this指针指向 被调用的成员函数 所属的对象

this指针是隐含在每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的用途：

1.当形参和成员变量同名时，可用this指针来区分
2.在类的非静态成员函数中返回对象本身，可使用return *this
*/
class Person
{
public:
    int age;//此处命名不规范

    Person(int age)
    {
        //当形参和成员变量同名时，可以用this指针来区分
        this->age = age;
    }

    void add_age_1(Person &_p) //使用引用的方式传入，节省内存，不触发拷贝构造函数
    {
        this->age += _p.age;
    }

    //add_age_2函数返回的是对象本身
    Person& add_age_2(Person &_p)
    {
        this->age += _p.age;
        return *this;
    }

    // Person add_age_3(Person &_p)
    // {
    //     this->age += _p.age;
    //     return *this;
    // }

};

//1.解决名称冲突
void test01()
{
    Person p1(13);
    cout << "p1.age = " << p1.age << endl;
}

//2.返回对象本身
void test02()
{
    Person p2(10);
    Person p3(10);

    //p2.add_age_1(p3); //将p3的age加到p2的age上

    /*
    add_age_2函数返回的是对象本身，即p2.add_age_2(p3)返回的是p2本身，&本质是个指针，
    也就是用 & 接收了返回的对象本身p2。
    （按引用返回，引用的本质是指针常量，用引用的方式返回代表着永远指向p2不会改变）
    如果不加 & ，这里就是值传递，值返回会调用拷贝构造函数，即返回的是p2的浅拷贝，是一个新的对象
    */
    p2.add_age_2(p3).add_age_2(p3).add_age_2(p3);
    
    //如：p2.add_age_3(p3)整体就是一个新对象p'，链式编程中后续就是: p'.add_age_3(p3)，整体就是另一个新对象p''
    //p2.add_age_3(p3).add_age_3(p3).add_age_3(p3);
    //所以以上代码中 p2.age = 20
    cout << "p2.age = " << p2.age << endl;
}

int main()
{
    //test01();

    test02();
    system("pause");
    return 0;
}