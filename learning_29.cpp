#include <iostream>
using namespace std;

/*
指针和函数
利用指针作为函数的形参，可以修改实参的值
*/

//值传递
//不改变实参，函数形参发生改变
void swap_1(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}

//地址传递
//函数实参发生改变
void swap_2(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
}

int main(){
    int a = 10;
    int b = 20;

    //值传递
    //不改变实参，函数形参发生改变
    // swap_1(a, b);
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    //地址传递
    //函数实参发生改变
    swap_2(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");
    return 0;
}