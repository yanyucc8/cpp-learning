#include <iostream>
using namespace std;

int main(){
    // 成块注释时利用 Ctrl+/
    // 运算符
    int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;  //两个整数相除结果依然是整数

	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl; 

	int a3 = 10;
	int b3 = 0;
	//cout << a3 / b3 << endl; //报错，除数不可以为0


	//两个小数可以相除
	double d1 = 0.5;
	double d2 = 0.25;
    cout << d1 / d2 << endl; //运算结果可以是小数
    
    //取模运算
    int a3 = 20;
    int b3 = 6;
    cout << a3 % b3 <<endl;

    //两个小数不可以取模
	double d1 = 3.14;
	double d2 = 1.1;
    //cout << d1 % d2 << endl;
    
    system("pause");
    return 0;
}