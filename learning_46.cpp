#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
};

//构造函数
Person::Person(/* args */)
{
    cout << "Person的构造函数调用" << endl;
}
//析构函数
Person::~Person()
{
    cout << "Person的析构函数调用" << endl;
}

void test01()
{
    Person p1;//在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{
    //构造函数和析构函数都是类必须有的，如果不提供，编译器会自动创建一个空实现的构造、析构函数
    test01();

    system("pause");
    return 0;
}
