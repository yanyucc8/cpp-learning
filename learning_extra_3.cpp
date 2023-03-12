/*
内联函数

与 C宏定义 的区别:
宏定义的函数没有类型检测，内联函数有类型检测

*/


/*
内联函数有一些优点和缺点。

优点：

1.内联函数可以避免函数调用的开销(函数在栈上的反复进出)，提高程序的执行效率。
2.内联函数有类型检测，更加安全。

缺点：

1.内联函数会使代码变长，占用更多的内存。
2.内联函数不适合定义复杂的函数

*/

//关键字 inline 必须和函数定义体都放在 .h头文件 中

//注意：
//inline的使用时有所限制的，inline只适合函数体内部代码简单的函数使用，
//不能包含复杂的结构控制语句例如while、switch，
//并且不能内联函数本身不能是直接递归函数（即，自己内部还调用自己的函数）。

#include <iostream>

//将fun()都放在 .h头文件中
inline int fun(int x)
{
    return x * x;
}

/*
类中的成员函数与inline
*/

//1.定义在类内的成员函数缺省inline的都是默认inline函数
class A
{
public:
    int func_1(int x_)//隐含的内联函数
    {
        return x_ * x_;
    }

    int func_2(int y_);
};

//2.定义在类外的成员函数必须加关键字 inline 才是内联函数
inline A::func_2(int y_)
{
    return y_ % 10;
}

int main()
{
    class A obj;
    std::cout << obj.func_1(10) << std::endl;
    std::cout << obj.func_2(10) << std::endl;

    system("pause");
}