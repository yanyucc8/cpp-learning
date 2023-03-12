#include "Point.h"

void Point::set_point(int input_x, int input_y)
{
    x = input_x;
    y = input_y;
}
//获取x坐标
int Point::get_point_x()
{
    return x;
}
//获取y坐标
int Point::get_point_y()
{
    return y;
}
