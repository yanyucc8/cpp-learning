#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;

//点类
//将圆类和点类的声明分别放在头文件.h中，圆类和点类的函数具体实现放在源文件.cpp中
class Point
{
private:
    int x;
    int y;

public:
    //设置点xy坐标
    void set_point(int input_x, int input_y);

    // 获取x坐标
    int get_point_x();

    // 获取y坐标
    int get_point_y();
};
