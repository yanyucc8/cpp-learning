#include <iostream>
using namespace std;

int main(){
    // 成块注释时利用 Ctrl+/
    // 比较运算符, “True”用数字“1”来表示， “False”用数字“0”来表示。
	int a = 10;
	int b = 20;

	cout << (a == b) << endl;//0

	cout << (a != b) << endl;//1

	cout << (a > b) << endl;//0
	
	cout << (a < b) << endl;//1
	
	cout << (a >= b) << endl;//0
	
	cout << (a <= b) << endl;//1

	// 逻辑运算符
	
	// 非运算 !
	// 如果a为假，则!a为真； 如果a为真，则!a为假。
	int c = 10;
	cout << "以下为 非 运算的结果：" << endl;
	cout << !c << endl; //0
	cout << !!c << endl; //1

    // 与运算 &&
	// 如果a和b都为真，则结果为真，否则为假。
	int d = 10;
	int e = 10;
	cout << "以下为 与 运算的结果：" << endl;
	cout << (d && e) << endl; //1

	int f = 10;
	int g = 0;
	cout << (f && g) << endl; //0

	int h = 0;
	int i = 0;
	cout << (h && i) << endl; //0

	// 或运算 ||
	// 如果a和b有一个为真，则结果为真，二者都为假时，结果为假。
	int a1 = 10;
	int b1 = 10;
	cout << "以下为 或 运算的结果：" << endl;
	cout << (a1 || b1) <<endl; //1

	a1 = 10;
	b1 = 0;
	cout << (a1 || b1) <<endl; //1

	a1 = 0;
	b1 = 0;
	cout << (a1 || b1) <<endl; //0

    system("pause");
    return 0;
}