#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;

class Person
{
private:
    char m_Name[64];
    int m_Age;
public:
    Person(const char *_name, int _age);
};
Person::Person(const char *_name, int _age)
{
    strcpy(m_Name, _name);
    m_Age = _age;
}

//如果使用char类型来定义类中的字符串属性，可以使用char数组来定义，例如：
// 利用 strcpy()函数 赋值
// class Person { 
// private: 
//     char name[20];
// public: 
//     Person(char *name)
//     { 
//         strcpy(this->name, name); 
//     }
// };

void test()
{
    ofstream ofs("test_1.txt", ios::out | ios::binary);

    Person man("张三", 20);
    //Person man = {"张三", 20};

    ofs.write((const char *)&man, sizeof(Person));

    ofs.close();
}

int main()
{
    test();

    system("pause");
    return 0;
}