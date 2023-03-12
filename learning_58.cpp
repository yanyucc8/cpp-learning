#include <iostream>
using namespace std;

/*
友元：可以让类外的函数或其他类来访问自己类中的私有成员 

4.4.2 类做友元
*/
class Building
{
    friend class GoodGuy;

private:
    string bedroom;

public:
    string sitting_room;
    Building();
};

Building::Building()
{
    sitting_room = "my sitting room";
    bedroom = "my bedroom";
}

class GoodGuy
{
public:
    Building *building; //定义Building类的指针
    GoodGuy();
    void visit();
};

//在初始化GoodGuy类对象中，由于定义了Building类的指针
//必须开辟一块内存空间，让Building类的指针指向这块内存空间
//所以用 new 关键字

GoodGuy::GoodGuy()
{
    //创建建筑物对象
    building = new Building; //在堆区开辟一块空间，让building指向Building类的对象
}

void GoodGuy::visit()
{
    cout << "My good friend is in " << building->sitting_room << endl; //指针利用 -> 访问对象的属性
    cout << "My good friend is in " << building->bedroom << endl;
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
