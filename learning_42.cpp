#include <iostream>
using namespace std;

/*
三种权限

1.public 公共权限：类内可以访问，类外可以访问
2.protected 保护权限：类内可以访问，类外不可以访问(子类可以继承)
3.private 私有权限: 类内可以访问，类外不可以访问(子类不可以继承)

*/

class Cat       
{
public:
    string nick_name;
    string varity;

protected:
    string coat_color;

private:
    string character;

public:
    void set_cat()
    {
        nick_name = "多多";
        varity = "中华田园猫";
        coat_color = "橘色";
        character = "好奇粘人";
    }

    void show_cat()
    {
        cout << "猫猫的名字是：" << nick_name << endl;
        cout << "猫猫的品种是：" << varity << endl;
        cout << "猫猫的毛色是：" << coat_color << endl;
        cout << "猫猫的性格是：" << character << endl;
    }
};

int main()
{
    Cat c1;
    c1.nick_name = "小咪";
    c1.varity = "三花";
    c1.show_cat();

    Cat c2;
    c2.set_cat();
    c2.show_cat();
    
    //c1.coat_color = "橘白色"; //保护权限类外访问不到
    //c1.character = "话痨粘人"; //保护权限类外访问不到
}