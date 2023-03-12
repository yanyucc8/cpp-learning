
/*
智能指针：智能指针是类模板实现的

shared_ptr

shared_ptr智能指针可以共同使用同一块堆内存，并且在该类型的指针采用 引用计数机制，
即，可以有多个shared_ptr指向同一个堆内存地址，当有一个shared_ptr被释放则引用计数 -1，
当所有指向该堆内存的shared_ptr都被释放，则引用计数为0，堆内存自动释放。
*/

#include <memory> //包含智能指针的头文件
#include <iostream>

// 创建shared_ptr
void test01()
{
    // 创建shared_ptr
    
    // 1.创建 空shared_ptr
    // 注意：空的shared_ptr指针，其初始引用计数为0
    std::shared_ptr<int> p1;// 不传入实参
    std::shared_ptr<int> p2(nullptr);// 传入空指针

    // 2.创建有具体指向的shared_ptr
    std::shared_ptr<int> p3(new int(100));
    // 采用make_shared<>是最安全的分配和使用动态内存的方法
    std::shared_ptr<int> p4 = std::make_shared<int>(42);
    std::shared_ptr<std::string> p5 = std::make_shared<std::string>(4, '9');    // tips: 如果没有using namespace std,使用string类必须加上std
    // make_shared<T>利用类型T来构造对象，即必须使用与T的构造函数相匹配的参数来完成 shared_ptr的初始化

    // 3.利用拷贝构造函数和移动构造函数创建shared_ptr
    std::shared_ptr<int> p6(p4); // 拷贝构造
    //std::shared_ptr<int> p6 = p4;
    std::shared_ptr<std::string> p7(std::move(p5));// 移动构造
    //std::shared_ptr<std::string> p7 = std::move(p5);

    std::cout << p5.use_count() << "  " << ((p5 == nullptr) ? "p5 is nullptr" : "p5 is not null") << std::endl;
    std::cout << p7.use_count() << "  " << "string p7 is :" << *p7 << std::endl;
    
    /*

    如上所示，p4 和 p6 都是 shared_ptr 类型的智能指针，因此可以用 p4 来初始化 p6，由于 p4 是左值，因此会调用拷贝构造函数。
    需要注意的是，如果 p4 为空智能指针，则 p6 也为空智能指针，其引用计数初始值为 0；
    反之，则表明 p4 和 p6 指向同一块堆内存，同时该堆空间的引用计数会加 1。
    
    而对于 std::move(p5) 来说，该函数会强制将 p5 转换成对应的右值，因此初始化 p7 调用的是移动构造函数。
    另外和调用拷贝构造函数不同，用 std::move(p5) 初始化 p7，会使得 p7 拥有了 p5 的堆内存，而 p5 则变成了空智能指针。

    */

    // 4.利用普通指针创建 shared_ptr
    // 注意：不要使用同一个普通指针 给多个shared_ptr对象赋值！
    int *p = new int(10);
    std::shared_ptr<int> p8(p);
    //std::shared_ptr<int> p9(p);//error
}

void delete_int_array(int* p)
{
    delete[] p;
}

void test02()
{
    // 在初始化 shared_ptr 智能指针时，还可以自定义所指堆内存的删除器Deleter(释放规则)，
    // 这样当堆内存的引用计数为 0 时，会优先调用我们自定义的释放规则。

    // 动态数组的释放
    // 1.指定 default_delete 作为释放规则
    std::shared_ptr<int> p1(new int[10], std::default_delete<int[]>());

    // 2.自定义释放规则
    std::shared_ptr<int> p2(new int[10], delete_int_array);

    // 利用rest()来将当前的对象重置为空指针，当前 shared_ptr 所指内存的引用计数-1
    // 当指向同一个对象的 shared_ptr 都被重置了，引用计数为 0 ，则该对象的内存被释放
    std::cout << "p1所指的引用计数" << p1.use_count() << std::endl;
    p1.reset();
    std::cout << "p1所指的引用计数" << p1.use_count() << "  " 
              << ((p1 == nullptr) ? "p1 is nullptr" : "p1 is not null") << std::endl;
    
    // 当为reset()函数传递一个新申请的堆内存时，则调用该函数的 shared_ptr 对象会获得该存储空间的所有权，并且引用计数的初始值为 1。
    std::shared_ptr<int> p3(p2);
    std::shared_ptr<int> p4 = std::make_shared<int>(42);
    //p3.reset(p4);//error 不能使用一个shared_ptr去reset另外一个
    p3.reset(new int(42));//在堆区new一块新内存，让p3指向它
    std::cout << "p2所指的引用计数" << p2.use_count() << std::endl;
    
}

class Ball
{
public:
    Ball()
    {
        std::cout << "a ball appears." << std::endl;
    }

    void Bounce()
    {
        std::cout << "a ball bounce." << std::endl;
    }

    ~Ball()
    {
        std::cout << "a ball disappears." << std::endl;
    }
};

void test03()
{
    std::shared_ptr<Ball> p1 = std::make_shared<Ball>();
    //auto p1 = std::make_shared<Ball>();
    std::cout << p1.use_count() << std::endl;
    std::shared_ptr<Ball> p2(p1);
    std::cout << p1.use_count() << "\t" << p2.use_count() << std::endl;
    std::shared_ptr<Ball> p3(p1);
    std::cout << p1.use_count() << "\t" << p2.use_count() << "\t" << p3.use_count() << std::endl;

    p1.reset();
    p2.reset();
    p3.reset();//当所有指向ball对象的指针都被重置以后，引用计数归0，内存被释放
}

int main()
{
    //test01();

    test02();

    //test03();
    return 0;
}