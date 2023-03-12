#include <iostream>
using namespace std;


int * fun_1()
{
    int a = 10;//定义的局部变量放在 栈区，栈区的数据在函数执行完后自动释放
    return &a;//注意事项：不要返回局部变量的地址
}

int * fun_2()
{
    int * b = new int(10);//利用new关键字，可以将数据开辟到堆区
    return b;//指针本质也是局部变量，这里定义的指针放在栈上，指针指向的数据放在堆区
}

/*
利用new开辟数组
*/
int * fun_3()
{
    int *arr = new int[10];//10代表数组有10个元素，创建数组利用中括号

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 10;    
    }
    return arr;
}


int main()
{
    int *p1 = fun_1();
    //cout << "fun_1函数里的a = " << * p << endl; //vscode中g++编译器会直接报错
    int *p2 = fun_2();
    cout << "fun_2函数里的b = " << * p2 << endl;
    cout << "fun_2函数里的b = " << * p2 << endl;

    //利用delete释放堆区数据
    delete p2;
    //cout << "fun_2函数里的b = " << * p2 << endl; //p2释放空间后，p2指向的值是随机的（也可能报错，空间不可访问）

    int *array = fun_3();

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;    
    }
    
    //释放数组
    delete[] array;
    //delete array;//对于简单数据类型也可以使用，但是对于类对象数组等复杂结构体会造成内存泄漏

    /*
    引用
    
    引用的本质：给已经使用的一块内存取别名
    */
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    /*
    引用的注意事项
    1.引用必须初始化
    2.引用一旦初始化后，就不能改变
    */
    int c = 100;
    //int &d;//报错，引用必须初始化
    int &d = c;//d是c的别名，一旦初始化后，就不可以更改
    int e = 20;
    d = e;//这是赋值操作，不是更改引用

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
}