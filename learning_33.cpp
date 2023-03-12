#include <iostream>
using namespace std;

/*
const的用法
*/

struct Student
{
    string name;
    int age;
    int score;
};

//值传递
//值传递会加大内存开销
void print_Student_1(struct Student stu){

    cout << "子函数1中 姓名：" << stu.name << "年龄：" << stu.age << "分数：" << stu.score << endl;
}

//地址传递
//地址传递会节省内存开销，但可能会改变主函数中的数据
//(将函数的形参改为指针，可以减少内存空间，而且不会复制新的副本出来)
//为了防止有些在调用函数时改变主函数的实参，需要加 const
void print_Student_2(const struct Student *stu){ 
    //用 const 修饰指针，即常量指针
    //只读不写
    //常量指针：指针的指向可以改，指针指向的值不能改
    
    //stu -> age = 0; //报错，因为常量指针不能修改指针指向的值
    cout << "子函数2中 姓名：" << stu -> name << "年龄：" << stu -> age << "分数：" << stu -> score << endl;

}

int main(){
    struct Student stu_1 = {"李四", 20, 100};
    cout << "main函数中 姓名：" << stu_1.name << " 年龄： " << stu_1.age  << " 分数：" << stu_1.score << endl;

    print_Student_2(&stu_1);

    system("pause");
    return 0;
}