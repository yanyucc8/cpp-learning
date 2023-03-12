#include <iostream>
using namespace std;

int main(){
    // int a = 100;
    // int *p;
    // p = &a;
    //int *p = &a;

    // cout << "a = " << a << endl;
    // cout << "a 内存地址： " << &a << endl;
    // cout << "p = " << p << endl;
    
    // cout << "*p = " << *p << endl;
    // cout << "sizeof(int *) ： " << sizeof(int *) << endl;
    // cout << "sizeof(float *) ： " << sizeof(float *) << endl;
    // cout << "sizeof(double *) ： " << sizeof(double *) << endl;
    // cout << "sizeof(char *) ： " << sizeof(char *) << endl;

    /*空指针
    1.空指针用于给指针变量进行初始化
    2.空指针是不可以被访问的
    */
   
    //指针变量p指向内存地址编号为0的空间
    int *p0 = NULL;
   
    //访问空指针报错
    //cout << *p1 << endl;

    /*
    const 修饰指针
    1.const 修饰指针  --> 常量指针 
    2.const 修饰常量  --> 指针常量
    3.const 既修饰指针，又修饰常量
    
    理解：p是地址，*p是值，const修饰谁，谁就不能变
    */
    
    int a = 10;
    int b = 10;
    
    //1.const 修饰指针  --> 常量指针
    //指针的指向可以改，指针指向的值不能改
    const int * p1 = &a;
    p1 = &b;
    //*p1 = 100;//错误

    //2.const 修饰常量  --> 指针常量
    //指针的指向不可以改，指针指向的值可以改
    int * const p2 = &a;
    //p2 = &b;//错误
    *p2 = 100;

    //3.const 既修饰指针，又修饰常量
    const int * const p3 = &a;
    // p3 = &b;//错误
    // *p3 = 100;//错误
} 