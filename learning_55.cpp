#include <iostream>
using namespace std;

class Person
{
public:
    int m_age;
    static int m_height;

    void showClassName()
    {
        cout << "I am an instance of Person ！" << endl;
    }

    void showPerson_age()
    {
        //在所有的对象属性之前都隐式包含了this->,指向 该实例化后的对象
        //由于 定义了Person类的空指针，使得 this—> 指向为 空，也就没有所谓的对象属性了
        
        //为了防止出现赋空指针的情况
        if (this == NULL)
        {
            return;
        }
        
        cout << "the age of this person is :" << m_age << endl;
    }

    void showPerson_height()
    {
        cout << "the height of this person is :" << m_height << endl;
    }
};
int Person::m_height = 160;

void test01()
{
    Person *p = NULL; //创建一个Person类的空指针
    
    // 空指针可以调用成员函数和静态成员变量
    // 因为成员函数不占用对象的空间，静态成员变量在编译时期就分配内存，所有对象共享，所以也不占用对象的空间
    // 所以空指针能够调用 对象以外的成员函数和静态成员变量
    p->showClassName();
    p->showPerson_height();

    //报错，，但是由于是空指针无法访问对象的非静态成员变量
    p->showPerson_age();
}

int main()
{
    test01();

    system("pause");
    return 0;
}


