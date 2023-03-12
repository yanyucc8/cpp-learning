#include <iostream>
using namespace std;

/*

深拷贝 和 浅拷贝

*/

class Person
{
public:
    int m_age;
    int* m_height; //创建的指针

public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    
    Person(int input_age, int input_height)
    {
        m_age = input_age;
        m_height = new int(input_height); //在堆区创建的内存，并由new返回该内存的地址，即m_height是个地址（指针）
        
        cout << "Person的有参构造函数调用" << endl;
    }

    //拷贝构造函数
    Person(const Person & _p)
    {
        m_age = _p.m_age;
        m_height = new int(*_p.m_height);
        //m_height = _p.m_height; 系统 浅拷贝采取的赋值方式
        //如果不利用深拷贝在堆区创建新的内存空间，会导致浅拷贝带来的重复释放堆区内存的问题
        cout << "Person的拷贝构造函数调用" << endl;
    }
/*
    如果用户不定义拷贝构造函数
    系统默认的拷贝构造函数，采取 浅拷贝 策略
    1. man_1在参数初始化时，在堆区申请了一块空间，man_1.m_height 是指向堆区内存的地址，
    2. 浅拷贝是对成员变量的简单赋值，即man_2复制man_1的参数，man_2.m_height 与 man_1.m_height 是指向同一块堆区内存的地址。 
    3. 当test01()结束调用后 ，析构函数释放man_1和man_2所占用的内存空间，
    4. 而 man_2.m_height 与 man_1.m_height 指向同一块堆区内存的地址，由于 man_1 和 man_2 的属性放在栈区，
       根据 栈区 先进后出 的原则，man_2.m_height先将堆区的内存释放掉，之后由于man_1.m_height依旧指向这块已经释放掉的内存，会报错。
*/
    ~Person()
    {   
        cout << "Person的析构函数调用" << endl;
        
        //利用析构函数来将堆区的数据释放
        if (m_height != NULL)
        {
            delete m_height;
        }
    }
};

void test01()
{
    Person man_1(18, 160);
    Person man_2(man_1);

    cout << "man_1的年龄： " << man_1.m_age << " 身高： " << *man_1.m_height << endl;

    cout << "man_2的年龄： " << man_2.m_age << " 身高： " << *man_2.m_height << endl;
}

int main()
{
    test01();

    system("pause");
    return 0;
}