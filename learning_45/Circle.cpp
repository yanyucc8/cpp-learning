#include "Circle.h"


//设置圆心
void Circle::set_center(Point input_center)
{
    center = input_center;
}
//设置半径
void Circle::set_radius(int input_radius)
{
    radius = input_radius;
}
//获取圆心
Point Circle::get_center()
{
    return center;
}
//获取半径
int Circle::get_radius()
{
    return radius;
}