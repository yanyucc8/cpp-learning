#include <iostream>
using namespace std;

/*
4.1.3 成员属性设置为私有

优点1：将所有成员属性设置为私有，可以自己控制读写权限

优点2：对于写权限，我们可以检测数据的有效性
*/

class Person
{
public:
//姓名设置可读可写
    void set_name(string input_name)
    {
        usr_name = input_name;
    }

    string get_name()
    {
        return usr_name;
    }

    void set_age(int input_age)
    {
        if (input_age > 140 || input_age < 0)
        {
            cout << "输入数据无效！" << endl;
            usr_age = 0;
        }
        usr_age = input_age;
    }

    int get_age()
    {
        return usr_age;
    }

    string get_property()
    {
        usr_property = "一佰万";
        return usr_property;
    }

private:
    string usr_name; //可读可写
    int usr_age;//可读可写
    string usr_property;//只读
};

int main()
{
    class Person individual;

    individual.set_name("LiLi");
    cout << individual.get_name() << endl;

    individual.set_age(20);
    cout << individual.get_age() << endl;

    cout << individual.get_property() << endl;
}