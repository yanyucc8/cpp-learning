#include <iostream>
using namespace std;

//4.2.2 构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

class Person
{
private:
    int age;
public:
    //无参构造函数
    Person()
    {
        cout << "无参构造函数" << endl;
    }
    //有参构造函数
    Person(int input_age)
    {
        age = input_age;
        cout << "有参构造函数" << endl;
    }
    //拷贝构造函数
    Person(const Person & p)
    {
        age = p.age;
        cout << "拷贝参构造函数" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

//2、构造函数的调用
//调用无参构造函数
void test01()
{
    Person p;
}

//调用有参的构造函数
void test02()
{
    //2.1括号法
    // Person p1(16);
    // Person p2(p1);//拷贝构造函数调用

    // //2.2显式法
    // Person p3 = Person(20);//Person(20)单独写就是匿名对象，会在当前行结束后，马上析构
    // Person p4 = Person(p3);//拷贝构造函数调用

    // //2.3隐式转换法
    // Person p5 = 24;//编译器自动转为：Person p5 = Person(24)
    // Person p6 = p5;//编译器自动转为：Person p6 = Person(p5) //拷贝构造函数调用
}

/*
4.2.3 拷贝构造函数调用时机
C++中拷贝构造函数调用时机通常有三种情况

1.使用一个已经创建完毕的对象来初始化一个新对象
2.值传递的方式给函数参数传值
3.以值方式返回局部对象
*/

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test03()
{
    Person man_1(20);//创建完毕一个对象man_1
    Person man_2(man_1);//调用拷贝构造函数
    Person man_3 = man_1;//拷贝构造
}


//2.值传递的方式给函数参数传值
//值传递会复制一份man_4给p，即调用拷贝构造函数
void work(Person p)
{
    cout << "work中p的地址是：" << &p << endl;
}

void test04()
{
    Person man_4;
    cout << "tset04中man_4的地址是：" << &man_4 << endl;
    work(man_4);
}


//3.以值方式返回局部对象
Person work_1()
{
    Person _p;
    cout << "work_1中_p的地址是：" << &_p << endl;
    return _p;
}

void test05()
{
    Person man_5 = work_1();
    cout << "test05中man_5的地址是：" << &man_5 << endl;
}
int main()
{
    //test01();

    //test02();

    //test03();

    //test04();

    //g++编译器优化，不会调用拷贝方法，会直接将work_01()中的对象_p存放到work_01()的返回值中，这个问题叫 复制省略。
    test05(); 
    system("pause");
    return 0;
} 