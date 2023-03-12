#include <iostream>
using namespace std;

/*
4.6.4 继承中构造和析构顺序
子类继承父类后，当创建子类对象，也会调用父类的构造函数

问题：父类和子类的构造和析构顺序是谁先谁后？
*/
class Base
{
public:
    Base()
    {
        cout << "Base 构造函数" << endl;
    }

    ~Base()
    {
        cout << "Base 析构函数" << endl;
    }
};

class Son: public Base
{
public:
    Son()
    {
        cout << "Son 构造函数" << endl;
    }

    ~Son()
    {
        cout << "Son 析构函数" << endl;
    }
};

void test()
{
    Son son_1;
}

int main()
{
    //子类继承父类后，先调用父类的构造函数，再调用子类的构造函数
    //析构顺序与构造函数相反
    //比喻：盖房子(构造函数)，先有地基(父类)，再有房子(子类)；拆房子(析构函数)，先拆房子(子类)，再拆地基(父类)
    test();
    
    system("pause");
    return 0;
}