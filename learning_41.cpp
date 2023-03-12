#include <iostream>
using namespace std;

/*

封装

封装是C++面向对象的三大特性之一

语法：class 类名{ 访问权限： 属性 / 行为 };

封装的意义：1.在设计类的时候，将属性和行为写在一起，表现事物
           2.将属性和行为加以权限控制
*/

/*

设计一个圆类，求圆的周长

*/

const double PI = 3.1415926;  //定义全局常量

class Circle
{
    public:
        int radius;
        double calcu_perimeter()
        {
            return 2 * PI * radius;
        }
};

/*

设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

*/

class Student
{
    public:
        //类中的属性和方法 统称为 类的成员
        //属性
        string name;
        int number;
        
        //方法
        void set_name(string input_name)
        {
            name = input_name;
        }

        void set_id(int input_number)
        {
            number = input_number;
        }

        void showStudent()
        {
            cout << "学生的姓名是：" << name << endl;
            cout << "学生的学号是：" << number << endl;
        }
};

int main()
{
    Circle c1;
    c1.radius = 10;

    cout << "the perimeter of this circle is: " << c1.calcu_perimeter() << endl;

    //通过方法给对象赋值
    Student s1;
    s1.set_name("张三");
    s1.set_id(15);
    s1.showStudent();

    //通过属性给对象赋值
    Student s2;
    s2.name = "李四";
    s2.number = 16;
    s2.showStudent();

    system("pause");
    return 0;
}
