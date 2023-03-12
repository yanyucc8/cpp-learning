#include <iostream>
using namespace std;

/*
4.3.1 成员变量和成员函数分开存储

在C++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上
*/

class Person_0 {};

class Person
{
public:
    //非静态成员变量  属于类的对象上
    int m_A;                        //非静态成员变量占对象空间
    
    //静态成员变量  不属于类的对象上
    static int m_B;                 //静态成员变量不占对象空间
    
    //非静态成员函数  不属于类的对象上
    void func1(){}	                //函数也不占对象空间，所有函数共享一个函数实例
    
    //静态成员函数  不属于类的对象上
    static void func2(){}           //静态成员函数也不占对象空间
};

void test01()
{
    Person_0 p1;
    //空对象（类）占用的内存空间为：1
    //C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "the size of p1 is " << sizeof(p1) << endl;
}


void test02()
{
    Person p2;
    cout << "the size of p1 is " << sizeof(p2) << endl; //占四个字节，即int的内存占用空间大小
}
int main() {

    //test01();

    test02();

    system("pause");
	return 0;
}