#include <iostream>
using namespace std;

/*
虚继承的构造函数

1.在虚继承中，虚基类是由最终的派生类初始化的，换句话说，最终派生类的构造函数必须要调用虚基类的构造函数。
对最终的派生类来说，虚基类是间接基类，而不是直接基类。
这跟普通继承不同，在普通继承中，派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类的。
*/

/*
2.需要关注的是构造函数的执行顺序。虚继承时构造函数的执行顺序与普通继承时不同：
在最终派生类的构造函数调用列表中，不管各个构造函数出现的顺序如何，
编译器总是先调用虚基类的构造函数，再按照出现的顺序调用其他的构造函数；
而对于普通继承，就是按照构造函数出现的顺序依次调用的。
*/

//基类A
class A
{
public:
    A(int a);

protected:
    int m_A;
};
A::A(int a) : m_A(a){}

//派生类B
class B : virtual public A
{
public:
    B(int a, int b);
    void display();

protected:
    int m_B;
};
B::B(int a, int b) : A(a), m_B(b){}
void B::display()
{
    cout << "m_A = " << m_A << " , m_B = " << m_B << endl;
}

//派生类C
class C : virtual public A
{
public:
    C(int a, int c);
    void display();

protected:
    int m_C;
};
C::C(int a, int c) : A(a), m_C(c){}
void C:: display()
{
    cout << "m_A = " << m_A << " , m_C = " << m_C << endl;
}

//最终派生类D
class D : public B, public C
{
public:
    D(int a, int b, int c, int d);
    void display();
protected:
    int m_D;
};
//在最终派生类 D 的构造函数中，除了调用 B 和 C 的构造函数，还调用了 A 的构造函数，
//这说明 D 不但要负责初始化直接基类 B 和 C，还要负责初始化间接基类 A。
//而在普通继承中，派生类的构造函数只负责初始化它的直接基类，
//再由直接基类的构造函数初始化间接基类，用户尝试调用间接基类的构造函数将导致错误。
D::D(int a, int b, int c, int d) : A(a), B(50,b), C(60,c), m_D(d){}
void D::display()
{
    cout << "m_A = " << m_A << " , m_B = " << m_B << " , m_C = " << m_C 
    << " , m_D = " << m_D << endl;
}

void test()
{
    class B h_b(10,20);
    h_b.display();

    class C h_c(30,40);
    h_c.display();

    class D h_d(100, 200, 300, 400);
    h_d.display();
}

/*
C++ 规定必须由最终的派生类 D 来初始化虚基类 A，直接派生类 B 和 C 对 A 的构造函数的调用是无效的。
在第 75 行代码中，调用 B 的构造函数时试图将 m_a 初始化为 50，
调用 C 的构造函数时试图将 m_a 初始化为 60，但是输出结果有力地证明了这些都是无效的，
m_a 最终被初始化为 100，这正是在 D 中直接调用 A 的构造函数的结果。
*/
int main()
{
    test();
}