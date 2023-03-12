#include <memory>
#include <iostream>

void test()
{
    // std::unique_ptr<int> p1;
    // std::unique_ptr<int> p2(new int(42));
    // std::unique_ptr<int> p3(p2); //ERROR
    // std::unique_ptr<int> p4 = new int(42); //ERROR
    //std::unique_ptr<int> p5 = p2; //ERROR

    std::unique_ptr<int> p3 = std::make_unique<int>(42);
    //auto p3 = std::make_unique<int>(42);

    std::unique_ptr<std::string> p1(new std::string("Hello World"));
    auto p2(p1.release());
}

void test01()
{
    std::unique_ptr<std::string> p1(new std::string("Hello World"));
    p1.reset();// p1置空，不指向内存对象
    // p1.reset(nullptr);

    std::unique_ptr<std::string> unp1(new std::string("apple"));
    std::unique_ptr<std::string> unp2(new std::string("orange"));
    //让 unp1接管unp2指向的内存空间，unp2置为空指针
    unp1.reset(unp2.release());
std::unique_ptr<int> ptr1(new int(42));
auto ptr2 = std::move(ptr1);

}

//此种方式，不会转移unique_ptr的所有权
void fun2(int & value_)
{
    std::cout << "in func1 value is :" << value_ << std::endl;
}

//unique_ptr类的deleter,利用普通函数实现
int* my_allocate(int v)
{
    std::cout << "Allocating" << v << std::endl;
    return new int(v);
}

void my_deallocate(int *p)
{
    std::cout << "deallocating" << std::endl;
    delete p;
}

int main()
{
    //std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    //fun2(*ptr1);
    //test();

    std::unique_ptr<int, decltype(&my_deallocate)> p(my_allocate(100), my_deallocate);
    return 0;
}
