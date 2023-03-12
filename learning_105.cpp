#include <iostream>
#include <set>
using namespace std;

/*
3.8.8 set容器排序

set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

利用仿函数，可以改变排序规则
*/


/*
    方法一：使用仿函数来对自定义类来进行sort
*/
class Person
{
public:
    string usr_name;
    int usr_age;

    Person(const string & name_, const int & age_) : usr_name(name_), usr_age(age_){}
};

// 比较类，用来比较两个Person对象的大小, 即仿函数
// 仿函数是一种比较类class，可以把它当作函数一样调用，在成员函数中 对operator()进行重载
// learning_66.cpp

class Compare_Person
{
public:
    bool operator()(const Person & p1_, const Person & p2_) const // set容器元素不可修改
    {
        return p1_.usr_age > p2_.usr_age;
    }
};
// 非静态成员函数加const，表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，任何修改它所在的类的成员的操作都是不允许的
// 因为隐含了对this指针的const引用，唯一例外的是对于mutable修饰的成员，加了const成员函数可以被非const对象和const对象调用

void test01()
{
    // 定义set容器，指定比较类为Compare_Person
    set<Person, Compare_Person> s1;

    Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    for (set<Person, Compare_Person>::const_iterator ptr = s1.begin(); ptr != s1.end(); ptr++)
    {
        cout << ptr->usr_name << "   " << ptr->usr_age << endl;
    }
}

/*
    方法二：利用自定义比较函数
*/
bool compare_person(const Person &p1_, const Person &p2_)
{
    return p1_.usr_age < p2_.usr_age;
}

void test02()
{
    // 定义一个set容器，它的元素类型是Person，它的比较类型是一个函数指针，指向一个返回bool值，
    // 接受两个const Person引用作为参数的函数。s是set容器的对象名，comparePerson是比较函数的名字，
    // 也就是函数指针所指向的函数。
    set<Person, bool (*)(const Person &, const Person &)> s2(compare_person);

    s2.insert(Person("刘备", 23));
	s2.insert(Person("关羽", 27));
	s2.insert(Person("张飞", 25));
	s2.insert(Person("赵云", 21));

    for (set<Person, bool(*)(const Person &,const Person &)>::iterator ptr = s2.begin(); ptr != s2.end(); ptr++)
    {
        cout << ptr->usr_name << "   " << ptr->usr_age << endl;
    }
}

class Int_compare
{
    public:
    bool operator()(const int &num1_, const int &num2_)
    {
        return num1_ > num2_;
    }
};

// 对于简单的内置类型
void test03()
{
    // 默认sort是升序，我们通过仿函数来自定义一个降序
    set<int,Int_compare> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

    for (set<int,Int_compare>::iterator ptr = s1.begin(); ptr != s1.end(); ptr++)
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}


int main()
{
    //test01();

    //test02();

    test03();

    return 0;
}