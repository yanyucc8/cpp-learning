#include <iostream>
#include <stack>
#include <queue>

/*
Stack
先进后出
*/

void test01()
{
    // 插入数据操作 push()， 移除栈顶数据 pop(), 返回栈顶数据 top()
    std::stack<int> s1;
    for (int i = 0; i < 5; i++)
    {
        s1.push(i); //向栈中添加元素，即入栈，入栈的先后顺序为 0 1 2 3 4
    }
    std::cout << "the size of stack is " << s1.size() << std::endl;

    while (!s1.empty())// s1.empty()判断栈是否为空，为空则返回true
    {
        // 出栈是从栈顶一个一个取出元素，与入栈顺序相反，4 3 2 1 0
        std::cout << s1.top() << std::endl; // s1.top()返回栈顶元素
        s1.pop(); // 移除栈顶元素
    }
    
    // stack容器的拷贝构造和赋值=
    std::stack<int> s2(s1);
    std::stack<int> s3 = s1;
}


/*
Queue
先进先出
*/

class Person
{
public:
    int usr_age;
    std::string usr_name;
public:
    Person(const std::string &name_, const int &age_) : usr_name(name_), usr_age(age_){}
};

void test02()
{
    Person man1("lilei", 20);
    Person man2("huahua", 18);
    Person man3("minmin", 29);
    Person man4("jiaer", 17);

    std::queue<Person> q1;
    
    q1.push(man1);// 向queue中插入元素
    q1.push(man2);
    q1.push(man3);
    q1.push(man4);

    std::cout << "the count of queue is " << q1.size() << std::endl;

    while (!q1.empty())
    {
        //queue 先进先出，跟入queue的顺序是一致的
        std::cout << q1.front().usr_name << "\t" << q1.front().usr_age << std::endl;
        q1.pop();// 从队头移除第一个元素
    }

}


int main()
{
    //test01();
    test02();
    return 0;
}
