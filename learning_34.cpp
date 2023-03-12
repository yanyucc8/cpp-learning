#include <iostream>
#include <ctime>
#include <windows.h> //为解决exe中文乱码而添加
using namespace std;
/*
案例描述：

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。
*/

//定义学生结构体
struct Student
{
    string stu_name;
    int stu_score;
};

//定义老师结构体
struct Teacher
{
    string tea_name;
    struct Student stu_array[5];
};

//定义一个为老师和学生赋值的函数
void allocator_value(Teacher *arr, int length){ //也可以使用 Teacher arr[] 
    string tea_front_name = "教师";
    string stu_front_name = "学生";
    string nameSeed = "ABCDE";
    
    for (int i = 0; i < length; i++)
    {
        arr[i].tea_name = tea_front_name + nameSeed[i];
        
        for (int j = 0; j < 5; j++)
        {
            int rand_score = rand() % 40; //系统生成随机数0~39
            arr[i].stu_array[j].stu_name = stu_front_name + nameSeed[j];
            arr[i].stu_array[j].stu_score = rand_score + 60;//对学生的成绩进行随机赋值
        }
    }
    
}

void printInfo(Teacher *arr, int length){ //也可以使用 Teacher arr[] 
    for (int i = 0; i < length; i++)
    {
        cout << "教师的名字：" << arr[i].tea_name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生的名字: " << arr[i].stu_array[j].stu_name << " 学生的分数："
                 << arr[i].stu_array[j].stu_score << endl;
        }        
    }
}


int main(){
    SetConsoleOutputCP(65001);//为解决exe中文乱码而添加
    
    //添加随机数种子，作用：利用当前系统时间生成随机数
    srand((unsigned int)time(NULL));
    
    struct Teacher t_arr[3];
    int length_array = sizeof(t_arr) / sizeof(t_arr[0]);

    //为老师和学生赋值
    allocator_value(t_arr, length_array);

    //打印老师和学生信息
    printInfo(t_arr, length_array);

    system("pause");
    return 0;
}