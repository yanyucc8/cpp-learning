 #include <iostream>
#include <string>
using namespace std;

/*

3.1.2 string构造函数

构造函数原型：

const char* 传入的必须是 "字符串"
const char 传入的必须是 '字符'
const string & 传入的必须是string类对象

string(); //创建一个空的字符串 例如: string str;
string(const char* s); //使用字符串s初始化
string(const string& str); //使用一个string对象初始化另一个string对象
string(int n, char c); //使用n个字符c初始化

*/

//1.利用构造函数 生成字符串
void test01()
{
    //空字符串
    string str1;
    cout << "str1 = " << str1 << endl;

    //单字符或字符串都要用 双引号
    const char* ch1 = "apple";
    string str2(ch1);
    //string str2("apple");
    cout << "str2 = " << str2 << endl;

    //使用一个string类对象初始化另一个string类对象
    string str3(str2);
    cout << "str3 = " << str3 << endl;

    //使用5个字符s初始化
    string str4(5, 's');
    cout << "str4 = " << str4 << endl;
 
}

/*

3.1.3 string赋值操作
功能描述：

给string字符串进行赋值
赋值的函数原型：

const char* 传入的必须是 "字符串"
const char 传入的必须是 '字符'
const string & 传入的必须是string类对象

string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s); //把字符串s赋给当前的字符串
string& operator=(char c); //字符赋值给当前的字符串
string& assign(const char *s); //把字符串s赋给当前的字符串
string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s); //把字符串s赋给当前字符串
string& assign(int n, char c); //用n个字符c赋给当前字符串

*/

//2.利用操作符 = 或 类方法assign() 生成字符串

void test02()
{
    //1.char*类型字符串 赋值给当前的字符串
    const char *ch1 = "orange";
    string str1 = ch1;
    //string str1;
    //str1 = "orange";
    cout << "str1 = " << str1 << endl;

    //2.把 字符串string类对象 赋值给当前的字符串
    string str2 = str1;
    cout << "str2 = " << str2 << endl;

    //3.字符 赋值给当前的字符串
    string str3;//单字符用=赋值时，必须先初始化对象
    str3 = 's';
    cout << "str3 = " << str3 << endl;

    //4.把字符串s赋给当前的字符串
    const char *ch2 = "banana fantacy";
    string str4;//使用string类的方法，必须先初始化对象
    str4.assign(ch2);
    cout << "str4 = " << str4 << endl;

    //5.把字符串的前n个字符赋给当前的字符串
    string str5;
    str5.assign(ch2, 6);
    //str5.assign("banana fantacy", 6);
    cout << "str5 = " << str5 << endl;

    //6.把字符串string类对象赋给当前字符串
    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    //用 6 个字符 a 赋给当前字符串
    string str7;
    str7.assign(6, 'a');
    cout << "str7 = " << str7 << endl;

}

/*
3.1.4 string字符串拼接
功能描述：

实现在字符串末尾拼接字符串
函数原型：

const char* 传入的必须是 "字符串"
const char 传入的必须是 '字符'
const string & 传入的必须是string类对象

string& operator+=(const char* str); //重载+=操作符
string& operator+=(const char c); //重载+=操作符
string& operator+=(const string& str); //重载+=操作符
string& append(const char *s); //把字符串s连接到当前字符串结尾
string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s); //同operator+=(const string& str)
string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾

*/

void test03()
{
    //1.操作符 += 拼接另一个字符串
    string str1 = "I would";
    str1 += "like to ride circle in the path.";
    cout << "str1 = " << str1 << endl;

    //2.操作符 += 拼接另一个字符
    str1 += '&';
    cout << "str1 = " << str1 << endl;

    //3.操作符 += 拼接另一个string
    string str2 = "I also like ";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    //4.类方法append 连接字符串到当前字符串尾
    str1.append("listening to music.");

    //5.把字符串的 前7 个字符连接到当前字符串结尾
    //注意调用该函数，必须直接传入字符串，传入string是错误的
    // string str3 = "I wish you would find ";
    // str1.append(str3, 7);//错误
    str1.append("I wish you would find ", 7);
    cout << "str1 = " << str1 << endl;

    //6.类方法append 连接string类对象到当前字符串尾
    string str4;
    str4.assign("you happy ");
    str1.append(str4);
    cout << "str1 = " << str1 << endl;

    //7.类方法append string类对象中从 第0 开始的 12 个字符连接到字符串结尾
    string str5;
    str5.assign("all the time if i were by your side.");
    str1.assign(str5, 0, 12);
}


int main()
{
    //test01();

    //test02();

    test03();

    system("pause");
    return 0;
}