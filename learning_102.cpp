
/*
list 链表

list的优点：动态存储分配，不会造成内存浪费和溢出
            链表执行插入和删除操作方便

list的缺点：存储空间耗费大，不支持随机访问
*/

// 所有不支持随机访问的iterator的容器，不可以使用标准算法
// 不支持随机访问的iterator的容器，内部会提供一些算法
// sort(iterator.begin(), iterator.end()) //ERROR

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
3.7.2 list构造函数

函数原型：

list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。

*/

inline void print_int_list(const list<int> &list_)
{
    for (list<int>::const_iterator ptr = list_.begin(); ptr != list_.end(); ptr++)
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}

void test01()
{
    // 1.默认构造
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    print_int_list(l1);

    // 构造函数将[beg, end)区间中的元素拷贝给本身
    list<int> l2(l1.begin(), l1.end());
    print_int_list(l2);

    // 构造函数将n个elem拷贝给本身
    list<int> l3(5, 88);
    print_int_list(l3);
    
    // 拷贝构造函数
    list<int> l4(l3);
    print_int_list(l4);
}

/*
3.7.3 list 赋值和交换

函数原型：

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
list& operator=(const list &lst); //重载等号操作符
swap(lst); //将lst与本身的元素互换。

*/

void test02()
{
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    print_int_list(l1);

    // 将[beg, end)区间中的数据拷贝赋值给本身。
    list<int> l2;
    l2.assign(l1.begin(), l1.end());
    print_int_list(l2);
    // 重载等号操作符
    list<int> l3 = l2;
    print_int_list(l3);
    // 将n个elem拷贝赋值给本身。
    l3.assign(5, 88);
    cout << "before swap l3 = " << endl;
    print_int_list(l3);
    cout << "after swap l3 = " << endl;
    // 将lst与本身的元素互换。
    l3.swap(l1);
    print_int_list(l3);
}

/*
3.7.4 list 大小操作

函数原型：

size(); //返回容器中元素的个数

empty(); //判断容器是否为空

resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

​              //如果容器变短，则末尾超出容器长度的元素被删除。

resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

  	 	 	​		//如果容器变短，则末尾超出容器长度的元素被删除。
*/

// 注意区分assign和resize的区别，assign会覆盖原来的list重写容器中的元素，resize则会在队尾添加或删除元素

void test03()
{
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // 判断容器是否为空, 空返回true
    if(l1.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "the size of list is" << l1.size() << endl;
        print_int_list(l1);
    }

    // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
    l1.resize(8);
    print_int_list(l1);

    // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
    l1.resize(10, 88);
    print_int_list(l1);
}

/*
3.7.5 list 插入和删除

函数原型：

尾插法，尾删法，左值右值都可以传入

push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void test04()
{
    list<int> l1;
    
    // 尾插
    l1.push_back(10);// 尾插法，尾删法，左值右值都可以传入
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    
    // 尾删
    l1.pop_back();
    print_int_list(l1);// 10  20  30
    
    // 头插
    l1.push_front(42);
    l1.push_front(42);
    
    // 头删
    l1.pop_front();
    print_int_list(l1);// 42  10  20  30

    list<int> l2;
    l2.assign(5, 88);
    
    // 在pos位置插elem元素的拷贝，返回新数据的位置。
    l2.insert(l2.begin(), 55);
    print_int_list(l2);// 55  88  88  88  88  88
    
    // 在pos位置插入n个elem数据，无返回值。
    l2.insert(l2.end(), 5, 42);
    print_int_list(l2);// 42  88  88  88  88  88  42  42  42  42  42
    
    // 在pos位置插入[beg,end)区间的数据，无返回值。
    list<int>::iterator pos = l2.begin();
    l2.insert(++pos, l1.begin(), l1.end());//在第二个位置插入（begin的下一个位置）
    print_int_list(l2);// 55  42  10  20  30  88  88  88  88  88  42  42  42  42  42
}

/*
3.7.6 list 数据存取

函数原型：

front(); //返回第一个元素。
back(); //返回最后一个元素。
*/

void test05()
{
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    print_int_list(l1);

    cout << "the first element in list is " << l1.front() << endl;
    cout << "the last element in list is " << l1.back() << endl;
    
    // list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = l1.begin();
    //it = it + 1;//错误，不可以跳跃访问，即使是+1
}

/*
3.7.7 list 反转和排序

函数原型：

reverse(); //反转链表
sort(); //链表排序

*/
bool self_defined_sort(const int & num1_, const int & num2_)
{
    return num1_ > num2_;
}

void test06()
{
    list<int> l1;

    l1.push_back(30);
    l1.push_back(50);
    l1.push_back(20);
    l1.push_back(40);
    l1.push_back(10);

    auto l2 = l1;
    l1.sort();//升序
    print_int_list(l1);

    l1.reverse();//逆转链表
    print_int_list(l1);

    // 自定义排序
    l2.sort(self_defined_sort);
    print_int_list(l2);
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
