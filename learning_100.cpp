#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
3.3 deque容器
3.3.1 deque容器基本概念

deque与vector区别：

vector对于头部的插入删除效率低，数据量越大，效率越低
deque相对而言，对头部的插入删除速度回比vector快
vector访问元素时的速度会比deque快,这和两者内部实现有关

*/


/*
3.3.2 deque构造函数

函数原型：

deque<T> deqT; //默认构造形式
deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem); //构造函数将n个elem拷贝给本身。
deque(const deque &deq); //拷贝构造函数

*/

inline void print_deque(const deque<int> & d_)
{
    for (deque<int>::const_iterator ptr = d_.begin(); ptr != d_.end(); ptr++)
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}

void test01()
{
    //1.默认构造函数
    deque<int> deq_1;
    for (int i = 0; i < 10; i++)
    {
        deq_1.push_back(i);//0  1  2  3  4  5  6  7  8  9
    }
    print_deque(deq_1);

    //2.构造函数将[beg, end)区间中的元素拷贝给本身
    deque<int> deq_2(deq_1.begin(), deq_1.end());
    print_deque(deq_2);

    //3.构造函数将n个elem拷贝给本身
    deque<int> deq_3(10, 8);
    print_deque(deq_3);

    //4.拷贝构造函数
    deque<int> deq_4(deq_3);
    print_deque(deq_4);
}

/*
3.3.3 deque赋值操作

函数原型：

deque& operator=(const deque &deq); //重载等号操作符

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

assign(n, elem); //将n个elem拷贝赋值给本身。

*/
void test02()
{
    deque<int> deq_1;
    for (int i = 0; i < 10; i++)//deque是一个双端数组，头和尾都可以push
    {
        deq_1.push_front(i);//9  8  7  6  5  4  3  2  1  0 
    }

    deque<int> deq_2 = deq_1;
    
    print_deque(deq_1);
    print_deque(deq_2);

    deque<int> deq_3;
    deq_3.assign(deq_1.begin(), deq_1.end());
    print_deque(deq_3);

    deque<int> deq_4;
    deq_4.assign(10, 8);
    print_deque(deq_4);
}

/*
3.3.4 deque大小操作

函数原型：deque 没有capacity的概念

deque.empty(); //判断容器是否为空

deque.size(); //返回容器中元素的个数

deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除。

deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除。

*/

void test03()
{
    deque<int> deq_1;
    for (int i = 0; i < 10; i++)
    {
        deq_1.push_back(i);
    }
    print_deque(deq_1);

    if (deq_1.empty()) //deq_1.empty()若容器为空则为 true ，否则为 false
    {
        cout << "this deque is empty " << endl;
    }
    else
    {
        cout << "the size of deque is " << deq_1.size() << endl;
    }

    //重新指定容器的长度为num,若容器变长，则以默认值填充新位置
    deque<int> deq_2(deq_1);
    deq_2.resize(15);
    print_deque(deq_2);

    deq_2.resize(5);
    print_deque(deq_2);
    
    //重新指定容器的长度为num,若容器变长，则以elem值填充新位置
    deq_1.resize(15, 8);
    print_deque(deq_1);
}

/*
3.3.5 deque 插入和删除

函数原型：

两端插入操作：

push_back(elem); //在容器尾部添加一个数据
push_front(elem); //在容器头部插入一个数据
pop_back(); //删除容器最后一个数据
pop_front(); //删除容器第一个数据

指定位置操作：

insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。

insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。

insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。

clear(); //清空容器的所有数据

erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。

erase(pos); //删除pos位置的数据，返回下一个数据的位置。

*/

void test04()
{
    deque<int> d1;
    //头插法
    d1.push_front(20);
    d1.push_front(30);

    //尾插法
    d1.push_back(80);
    d1.push_back(50);
    d1.push_back(10);
    print_deque(d1);
    
    //头删法
    d1.pop_front();
    
    //尾删法
    d1.pop_back();
    print_deque(d1);

    //在pos位置插入一个elem元素的拷贝，返回新数据的位置
    d1.insert(d1.begin(), 100);
    print_deque(d1);

    //在pos位置插入n个elem数据
    d1.insert(d1.end(), 5, 88);
    print_deque(d1);

    //在pos位置插入[beg,end)区间的数据
    deque<int> d2;
    d2.assign(5, 200);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    print_deque(d1);

    //删除[beg,end)区间的数据
    d1.erase(d1.end()); //在关联式容器中是不能用迭代器end去删除尾部元素
    print_deque(d1);
    d1.erase(d1.begin(), d1.end());
    //等价于 d1.clear();
}

/*
3.3.7 deque 排序

算法：

sort(iterator beg, iterator end) //对beg和end区间内元素进行排序

*/
bool sortbydecent(int &a_, int &b_)
{
    return a_ < b_;
}

void test05()
{
    deque<int> d1;
    //头插法
    d1.push_front(20);
    d1.push_front(30);
    //尾插法
    d1.push_back(80);
    d1.push_back(50);
    d1.push_back(10);
    print_deque(d1);

    //sort算法 在 头文件algorithm中
    std::sort(d1.begin(), d1.end());//升序排列
    print_deque(d1);

    std::sort(d1.begin(), d1.end(), std::greater<int>());//降序排列
    print_deque(d1);
}
int main()
{
    //test01();

    //test02();

    //test03();

    test04();

    //test05();

    system("pause");
    return 0;
}
