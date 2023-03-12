#include <iostream>
using namespace std;

/*
多态分为两类

静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
动态多态: 派生类和虚函数实现运行时多态
静态多态和动态多态区别：

静态多态的函数地址静态绑定 - 编译阶段确定函数地址
动态多态的函数地址动态绑定 - 运行阶段确定函数地址
*/

/*
多态 的 本质：
1.当将基类(Animal)的成员函数(speak)定义为虚函数时，编译器将这个虚函数 记录为 一个虚函数表指针(vfptr)，它指向基类的 虚函数表(vftable),
  在虚函数表中记录了 该虚函数的地址(&Animal::speak)
2.当子类(Cat)从基类(Animal)发生继承时，子类(Cat)继承了基类(Animal)中的所有内容(包括 虚函数表指针 和 虚函数表)，
  如果在子类中重写 基类(Animal)的虚函数，则子类(Cat)中的虚函数表内部会替换成 子类(Cat)的虚函数地址(&Cat::speak)
*/

//定义基类
class Animal
{
public:
    //speak函数就是虚函数
    //函数前加 virtual 关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
    virtual void speak()
    {
        cout << "The animal is speaking." << endl;
    }
};

//定义派生类1
class Cat : public Animal
{
public: 
    void speak()
    {
        cout << "The cat is speaking mio mio mio." << endl;
    }
};

//定义派生类2
class Dog : public Animal
{
    void speak()
    {
        cout << "The dog is speaking wang wang wang." << endl;
    }
};

//我们希望传入什么对象，就能调用什么对象的函数
//如果函数地址在编译时期就能确定，那么就是 静态联编
//如果函数地址在运行阶段才能确定，那么就是 动态联编
void dospeak(Animal& _animal)
{
    _animal.speak();
}

void test()
{
    Cat little_cat;
    dospeak(little_cat);

    Dog little_dog;
    dospeak(little_dog);
}

// 多态的满足条件
// 1.要有继承关系
// 2.子类重写父类中的虚函数（重写 即 函数返回类型、函数名、函数形参列表 都相同）
// 多态的使用条件
// 父类指针或引用 指向 子类对象

int main()
{
    test();

    system("pause");
    return 0;
}