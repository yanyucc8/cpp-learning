#include <iostream>
using namespace std;

/*
练习案例1：设计立方体类

设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。
*/

class Cube
{
private:
    int obj_length;
    int obj_width;
    int obj_height;

private:
    int obj_area;
    int obj_volume;

public:
    void set_obj(int input_length, int input_width, int input_height)
    {
        if (input_length < 0 || input_width < 0 || input_height < 0 )
        {
            cout << "无法立方体长宽高必须为大于零！" << endl;
            
            obj_length = 0;
            obj_width = 0;
            obj_height = 0;
        }
        else
        {
            obj_length = input_length;
            obj_width = input_width;
            obj_height = input_height;
        }    
    }

    int get_obj_length()
    {
        return obj_length;
    }

    int get_obj_width()
    {
        return obj_width;
    }

    int get_obj_height()
    {
        return obj_height;
    }

    int get_area()
    {
        obj_area = obj_length * obj_height * 2 + obj_length * obj_width * 2 + obj_width * obj_height * 2;
        return obj_area;
    }

    int get_volume()
    {
        obj_volume = obj_length * obj_width * obj_height;
        return obj_volume;
    }

    //用成员函数判断两个立方体是否相等
    bool isSamewith(Cube &input_cube)
    {
        if (obj_length == input_cube.get_obj_length() &&
            obj_width == input_cube.get_obj_width() &&
            obj_height == input_cube.get_obj_height())
        {
            return true;
        }
        return false;
    }
};

//用全局函数判断两个立方体是否相等
bool judge_equal(Cube &input_cube_1, Cube &input_cube_2)
{
    if (input_cube_1.get_obj_length() == input_cube_2.get_obj_length() &&
        input_cube_1.get_obj_width() == input_cube_2.get_obj_width() &&
        input_cube_1.get_obj_height() == input_cube_2.get_obj_height())
    {
        return true;
    }
    return false;
}

int main()
{
    class Cube cube_1;
    cube_1.set_obj(5, 10, 10);

    Cube cube_2;
    cube_2.set_obj(5, 5, 5);

    cout << "the length of cube_1 is:" << cube_1.get_obj_length() << endl;
    cout << "the width of cube_1 is:" << cube_1.get_obj_width() << endl;
    cout << "the height of cube_1 is:" << cube_1.get_obj_height() << endl;
    cout << "the area of cube_1 is :" << cube_1.get_area() << endl;
    cout << "the volume of cube_1 is :" << cube_1.get_volume() << endl;

    //用全局函数判断两个立方体是否相等
    if (judge_equal(cube_1, cube_2))
    {
        cout << "both of the cubes are the same." << endl;
    }
    else
    {
        cout << "both of the cubes are different." << endl;
    }
    
    //用成员函数判断两个立方体是否相等
    if (cube_1.isSamewith(cube_2))
    {
        cout << "both of the cubes are the same using member function." << endl;
    }
    else
    {
        cout << "both of the cubes are different using member function." << endl;
    }

    
    system("pause");
    return 0;
}