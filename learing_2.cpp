#include <iostream>
#include <string> //在有些版本里C++风格字符串，需要加入头文件 #include<string>
using namespace std;

int main() {
    // 字符型 char
    char ch1 = 'a';
    cout << ch1 << endl;
    cout << sizeof(ch1) << endl;
    cout << (int)ch1 << endl;

    // 字符串型 string
    string str1 = "Hello, world!";
    cout << str1 << endl;

    // 布尔型 bool
    bool flag = true;
    cout << flag << endl;

    flag = false;
    cout << flag << endl;
    cout << "size of bool = " << sizeof(bool) << endl;

    system("pause");
    return 0;
}