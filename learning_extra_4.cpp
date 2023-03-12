#include <iostream>
using namespace std;

void test01()
{
    int value = 10;
    int *const p1 = &value;// const 修饰 指针,指针的指向不可以修改，指向的值可以改，指针常量
    const int *p2 = &value;// const 修饰 常量，指针的指向可以修改，指向的值不可以修改，常量指针
    
    *p1 = 100;
    cout << "*p1 = " << *p1 << endl;

    //*p2 = 1000;//报错。常量指针的意思是，这个指针本身是不可以修改它指向的值的，但不代表它指向的值是不能修改的
    int *p3 = &value;
    *p3 = 1000;
    cout << "value = " << value << endl;

    const int value_2 = 80;//value_2是个常量
    const int *p4 = &value_2;//合法，常量指针，不会修改value_2的值
    //int *p5 = &value_2;//错误，非const的指针是不能指向const类型的变量的

}

class Person
{
public:
    Person(int age_):usr_age(age_), usr_c(1) {}
    
    int get_age() const // const声明的成员函数对于const修饰的类对象是安全的
    {
        return this->usr_age;
    }
    
    void modify_age(int age_)
    {
        this->usr_age = age_;
    }

protected:
    int usr_age;
    //如果有const 的 成员属性，那么一定要在 初始化列表里 初始化赋值
    const int usr_c;
};

void test02()
{
    //如果const修饰的是一个类对象，那么这个对象本身就是const的，里面的值是不可以修改的
    const Person man_1(20);
    cout << "the age of man is " << man_1.get_age() << endl;

    //man_1.modify_age(29);//错误，const对象调用了修改它属性的非const函数
    //const类对象只能调用 const声明的成员函数
}

int main()
{
    //test01();
    test02();

    system("pause");
}