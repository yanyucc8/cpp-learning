#include <iostream>
using namespace std;


/*
string 查找和替换

函数原型：
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s

*/

//1.字符串查找
void test01()
{
    string str1 = "abcdefge";

    int pos = str1.find("cd");//返回的是s第一次出现位置的索引，如果未找到返回-1

    if (pos == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "is found, located in " << pos << endl;
    }

    //rfind 方法返回最后一次出现字符串或字符出现位置的索引
    int pos1 = str1.rfind("e");
    cout << pos1 << endl;
}

//2.字符串替换
void test02()
{
    string str2 = "apple";
    str2.replace(0, 1, "an a");//替换从pos开始n个字符为字符串str
    cout << str2 << endl;
}

/*
string字符串比较

函数原型：

int compare(const string &s) const; //与字符串s比较
int compare(const char *s) const; //与字符串s比较

*/


//3.字符串比较（通常是比较是否相等）
void test03()
{
    string str1 = "neither";
    string str2 = "either";

    int judge = str1.compare(str2);//相等返回0
    if (judge != 0)
    {
        cout << "str1 is not equal to str2" << endl;
    }
    else
    {
        cout << "str1 is equal to str2" << endl;
    }    
}

/*
3.1.7 string字符存取

string中单个字符存取方式有两种

char& operator[](int n); //通过[]方式取字符
char& at(int n); //通过at方法获取字符

*/

void test04()
{
    string str3 = "cat loves fish";
    //利用索引
    for (int i = 0; i < str3.size(); i++)
    {
        cout << str3[i];
    }

    cout << "*****************" << endl;
    
    //利用at方法
    for (int i = 0; i < str3.size(); i++)
    {
        cout << str3.at(i);
    }
    
    cout << "*****************" << endl;

    //字符修改
    int index = str3.find("f");
    str3[index] = 'd';
    cout << str3 << endl;
}

/*
3.1.8 string插入和删除

函数原型：

string& insert(int pos, const char* s); //在原字符串索引为pos的地方插入字符串,
string& insert(int pos, const string& str); //在原字符串索引为pos的地方插入字符串
string& insert(int pos, int n, char c); //在指定位置插入n个字符c
string& erase(int pos, int n = npos); //删除从Pos开始的n个字符

*/

void test05()
{
    string str4 = "hello";
    str4.insert(str4.size(), " world!"); //str4.size()=5 //
    cout << str4 << endl;
    str4.insert(1, "xxx");
    cout << str4 << endl;

    //删除字符串
    str4.erase(1, 3);//删除原字符串索引从1开始的3个字符 
    cout << str4 << endl;
}

/*
3.1.9 string子串

从字符串中获取想要的子串
函数原型：

string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串

*/

void test06()
{
    string email = "yanyu@sina.com";
    int pos = email.find("@");
    string usr_name = email.substr(0, pos);
    cout << usr_name << endl;
}

int main()
{
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    test06();

    system("pause");
    return 0;
}