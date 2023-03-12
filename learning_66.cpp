#include <iostream>
using namespace std;

/*
4.5.6 函数调用运算符重载

函数调用运算符 () 也可以重载
由于重载后使用的方式非常像函数的调用，因此称为仿函数

仿函数没有固定写法，非常灵活
*/

//写一个用于打印的字符串的类
class MyPrint
{
public:
    void operator()(string _text) const
    {
        cout << _text << endl;
    }
};

void Printfunc(string _text)
{
    cout << _text << endl;
}

void test01()
{
    MyPrint print;
    print("this is a free message from China");//此种方式与定义的打印函数非常相似
    Printfunc("this is a free message from China");
}

//写一个向量内积的类
class Inner_product
{
public:
int operator()(int arr1[],int arr2[], int size)
{
    
    int arr_resl[size];
    
    for (int i = 0; i < size; i++)
    {
        arr_resl[i] = arr1[i] * arr2[i];
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr_resl[i];
    }
    
    return sum;
}
};


void test02()
{
    int array_1[] = {1, 2, 3, 4, 5};
    int array_2[] = {1, 2, 3, 4, 5};
    
    int size = sizeof(array_1) / sizeof(array_1[0]);

    //匿名对象调用
    cout << Inner_product()(array_1, array_2, size) << endl;
}

int main()
{
    //test01();

    test02();

    system("pause");
    return 0;
}