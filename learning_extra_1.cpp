/*
构造函数初始化列表是显式的初始化类的成员；而没使用初始化列表的构造函数是对类的成员赋值，
初始化和赋值对内置类型的成员没有什么大的区别，对非内置类型成员变量，
为了避免两次构造，推荐使用类构造函数初始化列表。但有的时候必须用带有初始化列表的构造函数：

1.成员类型是没有默认构造函数的类。若没有提供显示初始化式，则编译器隐式使用成员类型的默认构造函数，
  若类没有默认构造函数，则编译器尝试使用默认构造函数将会失败

2.const成员或引用类型的成员。因为const对象或引用类型只能初始化，不能在构造函数中对他们赋值 


*/

#include <iostream>
using namespace std;

/*
两次构造是指在使用构造函数体内进行初始化时，对于非内置类型的成员变量，它会先调用默认构造函数进行一次初始化，然后再在构造函数体内通过赋值的方式进行第二次初始化。这样就会导致不必要的性能损失。

例如，假设我们有一个类 MyClass，它有一个非内置类型的成员变量 myObject：
*/

class MyObject
{
public:
    int m_a;
    
    // MyObject(int _a):m_a(_a)
    // {
    //     cout << "MyObject constructor" << endl;
    // }

    MyObject()
    {
        cout << "MyObject default constructor" << endl;
    }

    MyObject(int _a)
    {
        this->m_a = _a;
        cout << "MyObject constructor" << endl;
    }

    ~MyObject()
    {
        cout << "MyObject destructor" << endl;
    }
};

class MyClass1
{
public:
    MyObject object;

    //在构造函数中进行初始化
    MyClass1(MyObject _object)
    {
        this->object = _object;
        cout << "MyClass1 constructor" << endl;
    }

    ~MyClass1()
    {
        cout << "MyClass1 destructor" << endl;
    }
};

class MyClass2
{
public:
    MyObject* object;

    //利用初始化列表进行初始化
    MyClass2(MyObject* _object) : object(_object)
    {
        cout << "MyClass2 constructor" << endl;
    }

    ~MyClass2()
    {
        cout << "MyClass2 destructor" << endl;
    }
};


void test01()
{
    MyObject obj(10);
    cout << obj.m_a << endl;
    //1.我们在构造函数中对成员变量进行赋值操作来初始化
    //那么在创建 MyClass对象时，object成员变量会先调用MyObject类的默认构造函数进行一次初始化，然后再在
    //MyClass的构造函数体内 通过赋值的方式进行第二次初始化。
    //但如果将 MyClass1类 中的 MyObject类 object对象定义为指针，那么就不会调用 默认构造函数
    MyClass1 cla(obj);  
}

void test02()
{
    MyObject obj(100);
    cout << obj.m_a << endl;
    //2.我们使用初始化列表来代替构造函数体进行初始化操作：
    //那么在创建 MyClass对象时，object成员变量只会调用一次拷贝构造函数来完成初始化
    MyClass2 cla(&obj);  
}

int main()
{ 
    test01();
    cout << "*****************************" << endl;
    test02();

    system("pause");
}