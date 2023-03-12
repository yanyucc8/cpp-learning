#include <iostream>
using namespace std;

/*
函数模板的注意事项：

1.自动类型推导，必须推导出一致的数据类型T 才可以使用
2.模板必须要确定出T的数据类型才可以使用

*/

template<typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//1.自动类型推导，必须推导出一致的数据类型T 才可以使用

void test01()
{
    int a = 10;
    int b = 20;
    float c = 2.14; 

    MySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //Myswap(b, c); //错误，推导不出一致的T类型
}

//模板必须要确定出T的数据类型，才可以使用
template<typename T>
void fun()
{
    cout << "this is a function." << endl;
}

void test02()
{
    //fun();//错误，模板不能独立使用，必须确定出T的类型
    fun<int>();//利用显式指定类型的方法，给T一个类型，才可以使用模板
}

int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}
