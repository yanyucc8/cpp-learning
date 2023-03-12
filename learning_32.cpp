#include <iostream>
using namespace std;

struct Student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//值传递
void print_Student_1(struct Student stu){
    //函数中使用值传递，不会改变主函数中数据
    //即，值传递修饰形参，实参不会发生改变
    stu.age = 0;
    cout << "子函数1中 姓名：" << stu.name << "年龄：" << stu.age << "分数：" << stu.score << endl;
}

//地址传递
void print_Student_2(struct Student *stu){
    //函数中使用地址传递，会改变主函数中数据
    stu -> age = 0;
    cout << "子函数2中 姓名：" << stu -> name << "年龄：" << stu -> age << "分数：" << stu -> score << endl;

}
int main(){
    struct Student stu_1 = {"张三", 20, 90};
    
    //值传递打印
    print_Student_1(stu_1);
    cout << "main函数中 姓名：" << stu_1.name << " 年龄： " << stu_1.age  << " 分数：" << stu_1.score << endl;
    
    //地址传递打印
    print_Student_2(&stu_1);
    cout << "main函数中 姓名：" << stu_1.name << " 年龄： " << stu_1.age  << " 分数：" << stu_1.score << endl;
    
    system("pause");
    return 0;
}