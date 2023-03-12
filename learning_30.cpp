#include <iostream>
using namespace std;

/*
定义结构体

语法：struct 结构体名 {结构体成员列表};

(跟函数一样，写在main函数之前)
*/

//结构体定义
struct Student
{
    string name;
    int age;
    int score;
};

int main(){

    //方式1，结构体变量创建
    struct Student st1;
    //Student st1;//C++中可省略 struct
    
    st1.name = "张三";
    st1.age = 12;
    st1.score = 100;

    cout << "姓名：" << st1.name << " 年龄：" << st1.age  << " 分数：" << st1.score << endl;

    //方式2，结构体变量创建    
    struct Student st2 = {"李四", 13, 80};
    
    cout << "姓名：" << st2.name << " 年龄：" << st2.age  << " 分数：" << st2.score << endl;
    
}