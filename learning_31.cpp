#include <iostream>
using namespace std;

/*
I.结构体数组

语法： struct 结构体名 数组名[元素个数] = { {} , {} , ... {} }
*/

//1.定义结构体
struct Student
{
    string name;
    int age;
    int score;
};


/*
III.结构体嵌套结构体
*/

struct Teacher
{
    int id;
    string name;
    int age;
    string sex;
    struct Student stu;
};

int main(){
    
    //2.创建结构体数组
    struct Student stu_arr[3] = 
    {
        {"张三", 18, 80},
        {"张三", 18, 80},
        {"王五", 20, 70}
    };
    
    //3.给结构体数组中的元素赋值
    stu_arr[1].name = "李四";
    stu_arr[1].age = 20;
    stu_arr[1].score = 90;
    
    //4.遍历结构体数组
    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：\t" << stu_arr[i].name << "年龄：\t" << stu_arr[i].age << "分数：\t" << stu_arr[i].score << endl;
    }
    
/*
II.结构体指针

利用操作符 ->可以通过结构体指针访问结构体属性
*/

    //1.创建结构体变量
    struct Student stu = {"张三",18,100,};
    
    //2.通过指针指向结构体变量
    struct Student * p = &stu;

    //3.通过指针访问结构体变量中的数据
    cout << p ->name << endl;
    cout << p ->age << endl;
    cout << p ->score << endl; 

    cout << (*p).name << endl;
    cout << (*p).age << endl;
    cout << (*p).score << endl;

/*
III.结构体嵌套结构体
*/

    // struct Teacher
    // {
    //     int id;
    //     string name;
    //     int age;
    //     string sex;
    //     struct Student stu;
    // };

    struct Teacher tea;
    tea.id = 10000;
    tea.name = "老王";
    tea.age = 40;
    
    tea.stu.name = "小李";
    tea.stu.age = 18;
    tea.stu.score = 90;

    cout << "教师 职工编号： " << tea.id << " 姓名： " << tea.name << " 年龄： " << tea.age << endl;
	
	cout << "辅导学员 姓名： " << tea.stu.name << " 年龄：" << tea.stu.age << " 考试分数： " << tea.stu.score << endl;

    system("pause");
    return 0;
}
