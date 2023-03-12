#include <iostream>
using namespace std;

//1.无参无返
void test01(){
    cout << "this is test01" << endl;
}

//2.有参无返
void test02(int a){
    cout << "this is test02" << endl;
    cout << "a = " << a << endl;
}
//3.无参有返
int test03(){
    cout << "this is test03" << endl;
    return 10;
}
//4.有参有返
int test04(int a, int b){
    cout << "this is test04" << endl;
    int sum = a + b;
    return sum;
}

// 在值传递时，形参发生改变，不会影响实参
// 值传递 实质是 实参将数值传入给形参，形参的改变并不会影响到实参。
void swap(int num1, int num2){
    
    cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}

int main(){
    // test01();
    // test02(3);
    // test03();
    // int a = test04(2,3);
    // cout << a;
    
    int c = 10;
    int d = 20;
    swap(c,d);
    cout << "mian中的 c = " << c << endl;
	cout << "mian中的 d = " << d << endl;
}