#include <iostream>
using namespace std;

/*
友元：可以让类外的函数或其他类来访问自己类中的私有成员 

4.4.1 全局函数做友元
*/

class Building
{
    //告诉编译器 GoodGuy全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void GoodGuy_1(Building *_building);
    friend void GoodGuy_2(Building &_building);

public:
    string meeting_room;
private:
    string bedroom;

public:
    Building()
    {
        meeting_room = "my meeting room";
        bedroom = "my bedroom";
    }
};

//让Building类外的函数访问Building类内的私有成员

void GoodGuy_1(Building *_building) //利用指针接收对象
{
    cout << "My good friend is in " << _building->meeting_room << endl; //指针利用 -> 访问对象的属性
    cout << "My good friend is in " << _building->bedroom << endl;
}

void GoodGuy_2(Building &_building) //利用引用接收对象
{
    cout << "My good friend is in " << _building.meeting_room << endl; //引用利用 . 访问对象的属性
    cout << "My good friend is in " << _building.bedroom << endl;
}


void test()
{
    Building my_buliding;
    //GoodGuy_1(&my_buliding); //指针利用 & 取对象的地址
    GoodGuy_2(my_buliding);
}

int main()
{
    test();

    system("pause");
    return 0;
}