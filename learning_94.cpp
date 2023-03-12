#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
STL：Standard Template Library

STL容器：vector

vector存放 自定义类 数据类型

容器：vector
算法：for_each
迭代器：vector<int>::iterator

*/

class Person
{
public:
    string m_name;
    int m_age;

    Person(string name, int age) : m_name(name), m_age(age){}
};

void show_person_1(Person & person_)
{
    cout << person_.m_name << "\t" << person_.m_age << endl;
}

//1.vector中是类的对象
void test01()
{
    vector<Person> first_vector;
    //创建Person对象
    Person man1("lili", 12);
    Person man2("sasa", 13);
    Person man3("gugu", 14);
    Person man4("zizi", 15);
    //添加对象至容器
    first_vector.push_back(man1);
    first_vector.push_back(man2);
    first_vector.push_back(man3);
    first_vector.push_back(man4);
    
    //遍历容器并输出(方法1)
    for (vector<Person>::iterator ptr = first_vector.begin() ; ptr != first_vector.end() ; ptr++)
    {
        cout << ptr->m_name << "\t" << ptr->m_age << endl;
        //cout << (*ptr).m_name << "\t" << (*ptr).m_age << endl;
    }
    
    //遍历容器并输出(方法2)
    //传入 for_each()函数的 show_person()函数的参数类型，一定有 该容器模板定义的类型 （这里是Person类）
    for_each(first_vector.begin(), first_vector.end(), show_person_1);
}


void show_person_2(Person* (& person_))//传入的person_是指针
{
    //cout << (*person_).m_name << "\t" << (*person_).m_age << endl;
    cout << person_->m_name << "\t" << person_->m_age << end;
}


//2.vector中是类的对象的指针
void test02()
{
    vector<Person*> second_vector;
    //创建Person对象
    Person man1("lili", 12);
    Person man2("sasa", 13);
    Person man3("gugu", 14);
    Person man4("zizi", 15);
    //添加Person对象的指针传至容器
    second_vector.push_back(&man1);
    second_vector.push_back(&man2);
    second_vector.push_back(&man3);
    second_vector.push_back(&man4);

    //遍历容器并输出(方法1)
    //此时的iterator是一个指向Person类对象指针的指针
    //  (*ptr)  类的对象的指针 
    //  (*(*ptr)) 类的对象
    for (vector<Person*>::iterator ptr = second_vector.begin() ; ptr != second_vector.end() ; ptr++)
    {
        cout << (*ptr)->m_name << "\t" << (*ptr)->m_age << endl;
        //cout << (*(*ptr)).m_name << "\t" << (*(*ptr)).m_age << endl;

    }
    
    //遍历容器并输出(方法2)
    //传入 for_each()函数的 show_person()函数的参数类型，一定有 该容器模板定义的类型 （这里是Person*类）
    for_each(second_vector.begin(), second_vector.end(), show_person_2);
}
int main()
{
    //test01();

    test02();
    system("pause");
    return 0;
}