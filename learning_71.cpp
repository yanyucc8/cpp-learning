#include <iostream>
using namespace std;

/*
4.6.8 菱形继承
菱形继承概念：

​ 两个派生类继承同一个基类

​ 又有某个类同时继承这两个派生类

​ 这种继承被称为菱形继承，或者钻石继承
*/

//定义一个基类(虚基类)
class Animal
{
public:
    int m_Age;
};

//定义两个子类继承(虚继承)
class Sheep : virtual public Animal {};//羊类
class Camel : virtual public Animal {};//驼类

//定义一个子类多态继承
class Alpaca : public Sheep, public Camel {};//羊驼类

//Sheep和Camel都继承了Animal的m_Age属性，而Alpaca多态继承了Sheep和Camel的m_Age属性，而理应Alpaca类只有一个m_Age属性 
//为了解决菱形继承的属性 二义性 的问题
//我们需要将多态继承的两个父类，继承基类的方式改为 虚继承，此时公共的父类Animal称为 虚基类
void test01()
{
    Alpaca alp;
    alp.Sheep::m_Age = 2;
    alp.Camel::m_Age = 8;

    cout << "alp.Sheep::m_Age =" << alp.Sheep::m_Age << endl;//8
    cout << "alp.Camel::m_Age =" << alp.Camel::m_Age << endl;//8
    cout << "alp.m_Age = " << alp.m_Age << endl;//8

}

/*
虚继承 实际上是给 Sheep子类和Camel子类 分别创造了指向 虚基类表vbtable 的指针 vbptr(虚基类指针)
vbptr根据虚基类表vbtable中记录的地址偏移量，来计算并指向 虚基类m_Age的那块内存空间
即 Sheep子类和Camel子类 实际存储的是最终指向虚基类m_Age的那块内存空间的偏移后的指针。
*/


int main()
{
    test01();

    system("pause");
    return 0;
}

