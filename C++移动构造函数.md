#### 1. C++移动构造函数 要解决的问题

在 C++ 11 标准之前（C++ 98/03 标准中），如果想用其它对象初始化一个同类的新对象，只能借助类中的复制（拷贝）构造函数。拷贝构造函数的实现原理很简单，就是为新对象复制一份和其它对象一模一样的数据。如以下的例子：

```c++
#include <iostream>
using namespace std;
 
class Person
{
public:
    //初始化列表，有参构造函数
    Person(string name_ , const int & age_):usr_name(name_), usr_age(new int(age_))
    {
        cout << "constructor fun" << endl;
    }

    //初始化列表，拷贝构造函数
    Person(const Person & person_) : usr_name(person_.usr_name), usr_age(new int(*person_.usr_age))
    {
        cout << "constructor copy" << endl;
    }

    int* get_age() { return this->usr_age; }
    
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

int main()
{
    Person man = creat_person("lili", 20);

    system("pause");
}

```

在这个例子中，程序定义了一个可返回Person对象的creat_person()的函数，用于在main()主函数中初始化man对象。由于多数编译器优化了拷贝操作结构，输出的都是优化后的结果。

完整的结果是：

```
constructor fun        <-- 执行 Person(name_, age_)
constructor copy       <-- 执行 return Person()
destructor fun         <-- 销毁 creat_person() 产生的匿名对象
constructor copy       <-- 执行 man = creat_person();
destructor fun         <-- 销毁 creat_person() 返回的临时对象
destructor fun         <-- 销毁 man
```

利用函数返回的形式，在拷贝构造函数实现对man的初始化，底层实际进行了2次拷贝复制（深拷贝）。如果临时对象的指针成员申请了大量堆空间，那么两次深拷贝会很大程度影响Person对象的初始化效率。

那么当类中包含指针类型的成员变量，使用其它对象来初始化同类对象时，怎样才能避免深拷贝导致的效率问题呢？C++11 标准引入了解决方案，该标准中引入了右值引用的语法，借助它可以实现 `移动语义`。

#### C++移动构造函数（移动语义的具体实现）

`移动语义` 是指 利用移动而非深拷贝的方式初始化含有指针成员的类对象。简单来说，就是把 其他对象（一般是匿名对象）拥有的内存资源 以为己用。

以前面的程序为例，Person类中有一个整型的指针成员，并指向堆区的内存空间。当使用creat_person()函数时，函数返回的Person的临时对象，会在函数调用结束后析构，这时如果我们可以把临时对象的数据直接浅拷贝给man，并将临时对象的usr_age指针改为NULL，这样就完成了man对象的初始化。

> 事实上，对于程序执行过程中产生的临时对象，往往只用于传递数据（没有其它的用处），并且会很快会被销毁。因此在使用临时对象初始化新对象时，我们可以将其包含的指针成员指向的内存资源直接移给新对象所有，无需再新拷贝一份，这大大提高了初始化的执行效率。

```c++
#include <iostream>
using namespace std;

//移动构造函数

 
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

    int* get_age() { return this->usr_age; }

    //移动构造函数
    Person(Person && person_) :  usr_name(person_.usr_name), usr_age(person_.usr_age)
   //这里函数形参时 右值引用
   //因为这里函数形参接收的是 函数返回的匿名对象Person(name_, age_)
    {
        person_.usr_age = NULL;
        cout << "constructor move" << endl;
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

int main()
{
    Person man = creat_person("lili", 20);
    system("pause");
}


```

 可以看到，在之前 Person类的基础上，我们又手动为其添加了一个构造函数。和其它构造函数不同，此构造函数使用右值引用形式的参数，又称为移动构造函数。并且在此构造函数中，usr_age 指针变量采用的是浅拷贝的复制方式，同时在函数内部重置了 person_.usr_age = NULL，有效避免了“同一块对空间被释放多次”情况的发生。

在 Linux 系统中使用`g++ test.cpp -o test.exe -std=c++0x -fno-elide-constructors`命令执行此程序，输出结果为：  

![](K:\lesson_cpp\移动构造函数.PNG)

 通过执行结果我们不难得知，当为Person类添加移动构造函数之后，使用临时对象初始化man对象过程中产生的 2 次拷贝操作，都转由移动构造函数完成。

我们知道，非`const` 右值引用只能操作右值，程序执行结果中产生的临时对象（例如函数返回值、lambda 表达式等）既无名称也无法获取其存储地址，所以属于**右值**。

当类中同时包含拷贝构造函数和移动构造函数时，如果使用临时对象初始化当前类的对象，编译器会**优先调用移动构造函数**来完成此操作。只有当类中没有合适的移动构造函数时，编译器才会退而求其次，调用拷贝构造函数。  

