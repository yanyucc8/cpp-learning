#pragma once
#include <iostream>
using namespace std;

//圆类
//将圆类和点类的声明分别放在头文件.h中，圆类和点类的函数具体实现放在源文件.cpp中
class Circle
{
private:
    Point center; //在类中可以让另一个类作为本类中的成员
    int radius;

public:
    //设置圆心
    void set_center(Point input_center);

    // 设置半径
    void set_radius(int input_radius);

    // 获取圆心
    Point get_center();

    // 获取半径
    int get_radius();
};