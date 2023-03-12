#include <iostream>
using namespace std;

/*
移动构造函数

语法
class A
{
public:
    A(A&& other)
    {
        // 移动资源
    }
};
其中，A&&表示右值引用，other是另一个对象的引用。
移动构造函数通常会将other的资源移动到当前对象上，并将other置为无效状态，以避免资源的重复释放。

移动构造函数的使用场景：
通常是在函数返回值、容器元素的插入或删除等需要频繁创建和销毁对象的场合。例如：

vector<A> v;
v.push_back(A()); // 插入临时对象，会调用移动构造函数

1.在上述代码中，当临时对象被插入到vector中时，会调用A类的移动构造函数，
将临时对象的资源移动到容器中，避免了资源的拷贝和销毁，提高了程序的性能。
3.需要注意的是，如果一个类定义了移动构造函数，则通常也需要定义移动赋值运算符和析构函数，以保证资源的正确释放和管理。

移动赋值运算符的定义：
class A
{
public:
    A& operator=(A&& other)
    {
        // 移动资源
        return *this;
    }
};

移动赋值运算符的使用场景通常是在容器元素的重新赋值或交换等需要频繁移动对象的场合。例如：

vector<A> v1, v2;
v1 = std::move(v2); //移动赋值运算符，将v2的资源移动到v1上
*/

/*
1. std::move()是C++11引入的一个函数模板，用于将一个左值强制转换为右值引用，以便进行移动操作。
2. std::move()并不会移动任何东西，它只是将一个 左值强制转换为右值引用，
    以便让移动构造函数或移动赋值运算符接管资源，从而避免了资源的拷贝和销毁，提高了程序的性能。
3. std::move()的用法很简单，只需要将需要移动的对象作为参数传入即可。

需要注意的是，使用std::move()时需要谨慎，因为它会将一个左值强制转换为右值引用，从而使得该对象的生命周期变得不确定。
如果在转换后的对象上进行了非法操作，可能会导致程序崩溃或数据损坏等问题。
因此，建议在使用std::move()时遵循以下几个原则：

1.只对可以移动的对象使用std::move()，例如可以移动的容器、字符串、智能指针等。

2.在移动对象后，不要再对原对象进行访问，以避免出现未定义行为。

3.在移动对象后，如果需要继续使用原对象，应该确保重新初始化该对象，以避免出现未定义行为。

*/
class Person
{
public:
    //初始化列表，有参构造函数
    Person(string name_ , const int & age_) : usr_name(name_), usr_age(new int(age_))
    {
        cout << "constructor fun" << endl;
    }

    //初始化列表，拷贝构造函数
    Person(const Person & person_) : usr_name(person_.usr_name), usr_age(new int(*person_.usr_age))
    {
        cout << "constructor copy" << endl;
    }

    //移动构造函数
    //右值引用接收临时对象
    Person(Person && person_) :  usr_name(person_.usr_name), usr_age(person_.usr_age)
    {
        person_.usr_age = nullptr;
        cout << "constructor move" << endl;
    }

    //移动赋值运算符
    Person& operator=(Person && person_)
    {
        if (this != &person_)
        {
            delete usr_age;
            this->usr_name = person_.usr_name;
            this->usr_age = person_.usr_age;
            person_.usr_age = nullptr;
        }
        cout << "move assignment operator" << endl;
        return *this;
    }

    //析构函数
    ~Person()
    {
        cout << "destructor fun" << endl;
    }

private:
    int *usr_age;
    string usr_name;
};

Person creat_person(const string & name_, const int & age_)
{
    return Person(name_, age_);
}

void test01()
{
    Person man = creat_person("lili", 20);//调用移动构造函数
    Person man1(move(man));//调用移动构造函数
    man1 = move(man);//调用移动赋值运算符
}

//移动赋值运算符通常在一个临时对象赋值给另一个对象时被调用
void test02()
{
    Person man3("xiaohua", 10);
    Person man4("duoduo", 5);
    man4 = move(man3);//调用移动赋值运算符
}

int main()
{
    //test01();

    test02();
 
    system("pause");
}
/*
理想的输出结果是：
constructor fun
constructor move
destructor fun
constructor move
destructor fun
destructor fun
*/
