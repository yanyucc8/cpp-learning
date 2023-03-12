#include <iostream>
using namespace std;
/*
友元：可以让类外的函数或其他类来访问自己类中的私有成员 

4.4.3 成员函数做友元
*/

class Building;

class GoodGuy
{
public:
    Building *_building; //定义Building类的指针
    GoodGuy();
    void visit();
};

class Building
{
    friend void GoodGuy::visit();

private:
    string bedroom; 

public:
    string sitting_room;
    Building();
};

GoodGuy::GoodGuy()
{
    _building = new Building;
}

void GoodGuy::visit()
{
    cout << "My good friend is in " << _building->sitting_room << endl;
    cout << "My good friend is in " << _building->bedroom << endl;
}

Building::Building()
{
    sitting_room = "my sitting room";
    bedroom = "my bedroom";
}

void test()
{
    GoodGuy man;
    man.visit();
}

int main()
{
    test();

    system("pause");
    return 0;
}