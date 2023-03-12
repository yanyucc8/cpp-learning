#include <iostream>
using namespace std;

/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为 虚析构 或者 纯虚析构

虚析构语法：

virtual ~类名(){}

纯虚析构语法：

virtual ~类名() = 0;

类名::~类名(){}
*/

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数调用" << endl;
    }

    virtual void speak() = 0;

    //析构函数加上virtual关键字，变成虚析构函数
    //方法一：采用 虚析构函数
    // virtual ~Animal()
    // {
    //     cout << "Animal 析构函数调用" << endl;
    // }

    //方法二：采用 纯虚析构函数，类内申明，类外初始化
    virtual ~Animal() = 0;
};
Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:
    string *m_Name;//定义一个指向堆区的指针

public:
    Cat(string name)
    {
        cout << "Cat 构造函数调用" << endl;
        m_Name = new string(name);
    }

    void speak()
    {
        cout << "Cat is speaking." << endl;
    }

    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat 析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
        
    }
};

void test()
{
    Animal * little_animal = new Cat("多多");
    little_animal->speak();
    delete little_animal;
    /*
    如果没有定义父类的虚析构或纯虚析构函数，那么：
    
    1.如果不主动释放由 little_animal 指向堆区的内存 Cat类，该部分内存不会随着函数调用的结束而自动释放
    即，不会调用 基类Animal和子类Cat的析构函数。
    2.如果主动释放由 little_animal 指向堆区的内存 Cat类，则只会调用基类 Animal 的析构函数。
    原因是：我们定义了父类的指针，指向堆区的子类数据，父类指针在析构的时候不会调用子类中的析构函数，
    导致子类如果有堆区属性，出现内存泄漏
    */

    //怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象

    /*
    如果定义了父类的虚析构或纯虚析构函数，那么：

    1.非虚函数 都是 静态绑定，绑定对象的静态类型，而对象的静态类型是指对象声明时的类型，在编译时确定。
    即，普通析构函数也是静态绑定，所以执行的是 Animal 的析构函数
    2.虚函数是动态绑定，虚析构的特性也是基于动态绑定产生的，我们采用虚析构函数后，虚析构函数会执行动态绑定，
    绑定对象的动态类型，而对象的动态类型是：指针当前所指的对象的类型，在运行时确定。
    因为指针指向的对象是 Cat 类，所以执行了 Cat 类的析构函数
    */
}

int main()
{
    test();

    system("pause");
    return 0;
}