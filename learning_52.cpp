#include <iostream>
using namespace std;
/*
静态成员分为：

1.静态成员变量
    所有对象共享同一份数据
    在编译阶段分配内存
    类内声明，类外初始化
2.静态成员函数
    所有对象共享同一个函数
    静态成员函数只能访问静态成员变量
*/

class Person
{
public:
    static int m_A; //静态成员变量
    int m_C;

    //静态成员函数
    static void func_1()
    {
        m_A = 100;
        //m_C = 200; 错误，静态成员函数不能访问非静态成员变量
        /*
        静态成员函数只属于类本身，并不属于每个对象实例，独立存在。
        非静态成员函数，仅当实例化对象之后才存在。
        静态成员函数产生在前，非静态成员函数产生在后，静态成员函数不能访问一个不存在的东西
        */
        cout << "func_1调用" << endl;
    }
private:
    static int m_B; //静态成员变量

    //静态成员函数
    static void func_2()
    {
        m_B = 200;
        cout << "func_2调用" << endl;
    }
};
//类内声明，类外初始化
int Person::m_A = 10;
int Person::m_B = 10; //静态成员变量也需要访问权限，private类型的变量需要class提供访问函数

void test01()
{
    //静态成员变量两种访问方式

	//1、通过对象
    Person p1;
    p1.m_A = 200; //通过对对象属性的访问，可以修改对象的public的属性
    cout << "p1.m_A = " << p1.m_A << endl;

    Person p2;
    p2.m_A = 400; //同类的所有对象共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;
    
    //2、通过类名
    cout << "m_A = " << Person::m_A << endl;
    //cout << "m_B = " << Person::m_B << endl;//私有权限访问不到
}

void test02()
{
    //静态成员函数两种访问方式
    
    //1、通过对象
    Person p3;
    p3.func_1();

    //2、通过类名
    Person::func_1();
    //Person::func_2(); //私有权限无法访问
}

int main()
{
    //test01();

    test02();
    system("pause");
    return 0;
}