#include <iostream>
#include "Point.h"
#include "Point.cpp" //VScode中必须同时包含.h和.cpp文件，才不会出现undefined reference to的报错
#include "Circle.h"
#include "Circle.cpp"
#include <windows.h> //为解决exe中文乱码而添加
using namespace std;

/*
练习案例2：点和圆的关系

设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。
*/

// class Point
// {
// private:
//     int x;
//     int y;

// public:
// //设置点xy坐标
// void set_point(int input_x, int input_y)
// {
//     x = input_x;
//     y = input_y;
// }
// //获取x坐标
// int get_point_x()
// { 
//     return x;
// }
// //获取y坐标
// int get_point_y()
// {
//     return y;
// }
// };

// class Circle
// {
// private:
//     Point center; //在类中可以让另一个类作为本类中的成员
//     int radius;

// public:
// //设置圆心
// void set_center(Point input_center)
// {
//     center = input_center;
// }
// //设置半径
// void set_radius(int input_radius)
// {
//     radius = input_radius;
// }
// //获取圆心
// Point get_center()
// {
//     return center;
// }
// //获取半径
// int get_radius()
// {
//     return radius;
// }
// };


//函数：判断点和圆的距离
void isInCircle(Circle &c, Point &p)
{
int distance = (c.get_center().get_point_x() - p.get_point_x()) * (c.get_center().get_point_x() - p.get_point_x()) +
               (c.get_center().get_point_y() - p.get_point_y()) * (c.get_center().get_point_y() - p.get_point_y());
int r_2 = c.get_radius() * c.get_radius();

if (distance == r_2)
{
    cout << "点在圆上" << endl;
}
else if (distance > r_2)
{
    cout << "点在圆外" << endl;
}
else
{
    cout << "点在圆内" << endl;
}
}


int main()
{
    SetConsoleOutputCP(65001);//为解决exe中文乱码而添加
    
    //创建点
    class Point point_1;
    point_1.set_point(10, 10);
    //创建圆
    class Circle circle_1;
    //创建圆心
    Point center_1;
    center_1.set_point(10,0);
    //设置半径，圆心
    circle_1.set_radius(10);
    circle_1.set_center(center_1);

    isInCircle(circle_1, point_1);

    system("pause");
    return 0;
}