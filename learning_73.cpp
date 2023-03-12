#include <iostream>
using namespace std;

//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护

//定义计算器父类
class Calculator
{
public:
    int num_1;
    int num_2;

    virtual int getResult()
    {
        return 0;
    }
};

//定义加法子类
class PlusCal : public Calculator
{
public:
    int getResult()
    {
        return num_1 + num_2;
    }
};

//定义减法子类
class SubCal : public Calculator
{
public:
    int getResult()
    {
        return num_1 - num_2;
    }
};

//定义乘法子类
class MultiCal : public Calculator
{
public:
    int getResult()
    {
        return num_1 * num_2;
    }
};

//定义计算外函数，将父类的引用作为形参 
int Compute(Calculator& _cacul)
{
    return _cacul.getResult();
}

//多态的使用方式1：父类引用 指向 子类对象
void test01()
{
    //创建加法计算器
    PlusCal c1;
    c1.num_1 = 10;
    c1.num_2 = 20;

    cout << c1.num_1 << " + " << c1.num_2 << " = " << Compute(c1) << endl;

    //创建减法计算器
    SubCal c2;
    c2.num_1 = 10;
    c2.num_2 = 20;

    cout << c2.num_1 << " - " << c2.num_2 << " = " << Compute(c2) << endl;

    //创建乘法计算器
    MultiCal c3;
    c3.num_1 = 10;
    c3.num_2 = 20;

    cout << c3.num_1 << " * " << c3.num_2 << " = " << Compute(c3) << endl;    
}

//多态的使用方式2：父类指针 指向 子类对象
void test02()
{
    //创建加法计算器
    Calculator* c1 = new PlusCal; //定义父类的指针c1 指向 在堆区 new 出来的子类
    c1->num_2 = 20;
    c1->num_1 = 10;
    
    cout << c1->num_1 << " + " << c1->num_2 << " = " << c1->getResult() << endl;
    delete c1;//打印后再释放堆区空间

    //创建减法计算器
    Calculator* c2 = new SubCal;//定义父类的指针c1 指向 在堆区 new 出来的子类
    c2->num_1 = 10;
    c2->num_2 = 20;

    cout << c2->num_1 << " - " << c2->num_2 << " = " << c2->getResult() << endl;
    delete c2;//打印后再释放堆区空间

    //创建乘法计算器
    Calculator* c3 = new MultiCal;//定义父类的指针c1 指向 在堆区 new 出来的子类
    c3->num_1 = 10;
    c3->num_2 = 20;

    cout << c3->num_1 << " * " << c3->num_2 << " = " << c3->getResult() << endl;
    delete c3;//打印后再释放堆区空间
}

int main()
{
    test01();//多态的使用方式1：父类引用 指向 子类对象

    test02();//多态的使用方式2：父类指针 指向 子类对象

    system("pause");
    return 0;
}