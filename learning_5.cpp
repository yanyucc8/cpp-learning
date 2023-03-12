#include <iostream>
using namespace std;

int main(){
    // 成块注释时利用 Ctrl+/
    // 递增，递减运算
	
	// 前置递增
	int a = 10;
	++a;
	cout << a << endl;

	// 后置递增
	int b = 10;
	b++;
	cout << b << endl;

	// 区别
	// 前置递增先对变量进行++，再计算表达式
	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << b1 << endl;

	// 后置递增先计算表达式，后对变量进行++
	int a2 = 10;
	int b2 = a2++ * 10;
	cout << b2 << endl;

	//赋值运算符
	// =
	int a = 100;
	a = 10;
	cout << "a = " << a << endl;

	// +=
	a = 10;
	a += 2; // a = a + 2;
	cout << "a += 2 赋值后，a =" << a << endl;

	// -=
	a = 10;
	a -= 2; // a = a - 2
	cout << "a -= 2 赋值后，a = " << a << endl;

	// *=
	a = 10;
	a *= 2; // a = a * 2
	cout << "a *= 2 赋值后，a = " << a << endl;

	// /=
	a = 10;
	a /= 2;  // a = a / 2;
	cout << "a /= 2 赋值后，a = " << a << endl;

	// %=
	a = 10;
	a %= 2;  // a = a % 2;
	cout << "a %= 2 赋值后，a = " << a << endl;
   
    
    system("pause");
    return 0;
}