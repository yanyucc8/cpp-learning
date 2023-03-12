#include <iostream>
#include <set>
using namespace std;

/*
3.8.2 set构造和赋值

set<T> st; //默认构造函数：
set(const set &st); //拷贝构造函数
set& operator=(const set &st); //重载等号操作符

*/

// set 和 multiset容器 是关联式容器。底层结构是用二叉树实现的。

inline void print_int_set(const set<int> & s_)
{
    for (set<int>::const_iterator ptr = s_.begin(); ptr != s_.end(); ptr++)
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(30);
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(10);

    auto s2 = s1;
    auto s3(s1);

    // set 不允许容器中有重复元素
    // set 对元素自动进行弱排序
    print_int_set(s1);
    print_int_set(s2);
    print_int_set(s3);
}

/*

3.8.3 set大小和交换

函数原型：

size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器

*/

void test02()
{
    set<int> s1;
    s1.insert(30);
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(40);

    cout << "the size of s1 is " << s1.size() << endl;

    auto s2 = s1;
    s2.insert(200);
    cout << "before swap the element in s1 is :" << endl;
    print_int_set(s1);

    s1.swap(s2);
    cout << "after swap the element in s1 is :" << endl;
    print_int_set(s1);


}

/*
3.8.4 set插入和删除

函数原型：

insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem); //删除容器中值为elem的元素。

*/

void test03()
{
    set<int> s1;
    s1.insert(30);
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(40);
    print_int_set(s1);
    
    auto s2 = s1;
    s1.erase(s1.begin());
    s1.erase(--s1.end()); // 在set容器里 直接使用 s1.erase(s1.end()) 会抛出异常，因为set不是可解引用的迭代器
    print_int_set(s1);  // 将s1.end()往前移到set最后一个元素

    s2.insert(300);
    print_int_set(s2);
    
    // 删除容器中值为elem的元素。
    s2.erase(30);
    print_int_set(s2);

    s1.erase(s1.begin(), s1.end());
    s2.clear();
}

/*
3.8.5 set查找和统计

函数原型：

find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
*/

void test04()
{
    set<int> s1;
    s1.insert(30);
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(40);
    print_int_set(s1);

    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "is found" << endl;
    }
    else
    {
        cout << "is not found" << endl;
    }
    
    cout << "the count of 10 is " << (int)s1.count(10) << endl;
}

/*
3.8.6 set和multiset区别

区别：

set不可以插入重复数据，而multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
*/

void test05()
{
    // multiset
    multiset<int> s1;
    s1.insert(100);
    s1.insert(200);
    s1.insert(100);

    for (multiset<int>::iterator i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << "  ";
    }
    cout << endl;

    // set
    set<int> s2;
    pair<set<int>::iterator, bool> ret = s2.insert(10);

    if (ret.second)
    {
        cout << "insert successed" << endl;
    }
    else
    {
        cout << "insert failed" << endl;
    }
    
    ret = s2.insert(10);
    if (ret.second)
    {
        cout << "insert successed" << endl;
    }
    else
    {
        cout << "insert failed" << endl;
    }
}

/*
3.8.7 pair对组创建

两种创建方式：

pair<type, type> p ( value1, value2 );
pair<type, type> p = make_pair( value1, value2 );

利用p.first和p.second进行访问元素
*/

void test06()
{
    pair<string, int> p1 = make_pair("Tom", 100);
    pair<int, bool> p2(1, true);
    cout << "name: " << p1.first << "  " << "salary:" << p1.second << endl;
    cout << p2.first << "  " << (p2.second == 1 ? "true" : "false") << endl;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    return 0;
}