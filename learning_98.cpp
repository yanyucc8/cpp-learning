#include <iostream>
#include <vector>
using namespace std;

/*
vector和普通数组的区别： vector支持动态扩展

动态扩展的本质是： 是在内存中找到更大的内存空间，将原数据拷贝到新空间，释放原空间
*/

/*
3.2.2 vector构造函数

函数原型：

vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem); //构造函数将n个elem拷贝给本身。
vector(const vector &vec); //拷贝构造函数。

*/

inline void print_vector(vector<int> &v_)
{
    for (vector<int>::iterator ptr = v_.begin(); ptr != v_.end(); ptr++)
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}

void test01()
{
    // 1.默认构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i * 10);
    }
    print_vector(v1);

    // 2.将vector[begin(), end())区间中的元素拷贝给本身
    vector<int> v2(v1.begin(), v1.end());
    print_vector(v2);

    // 3.将n个elem拷贝给本身
    vector<int> v3(10, 44);
    print_vector(v3);

    // 4.拷贝构造函数
    vector<int> v4(v2);
    print_vector(v4);
}

/*
3.2.3 vector赋值操作

函数原型：

vector& operator=(const vector &vec);//重载等号操作符

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

assign(n, elem); //将n个elem拷贝赋值给本身。

*/

void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i * 10);
    }
    print_vector(v1);

    // 利用 = 操作符赋值
    vector<int> v2;
    v2 = v1;
    print_vector(v2);

    // 将[beg, end)区间中的数据拷贝赋值给本身
    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    print_vector(v3);

    // assign(n, elem)方法会用n个值为elem的元素替换原vector中的所有元素
    // 这意味着原vector中的所有元素都会被删除，并且新的元素将被添加到vector中
    cout << "Before assign , the size of v1 is " << v1.size() << endl;
    v1.assign(3, 200);
    cout << "After assign , the size of v1 is " << v1.size() << endl;
    print_vector(v1);
}

/*
3.2.4 vector容量和大小

函数原型：

empty(); //判断容器是否为空

capacity(); //容器的容量

size(); //返回容器中元素的个数

resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

​                 //如果容器变短，则末尾超出容器长度的元素被删除。

resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

​                       //如果容器变短，则末尾超出容器长度的元素被删除

*/

inline void show_vector_info(vector<int> &v_)
{
    cout << "the size of vector is " << v_.size() << endl;
    cout << "the capacity of vector is " << v_.capacity() << endl;
}

void test03()
{
    vector<int> v1;
    v1.assign(10, 2);
    print_vector(v1); // 利用 assign 初始化后的 vector.size() == vector.capacity()

    if (v1.empty()) // v1.empty()若容器为空则为 true ，否则为 false
    {
        cout << "this vector is empty." << endl;
    }
    else
    {
        show_vector_info(v1);
    }

    // resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(25);    // 利用 resize 后 如果原 vector.capacity() < num ,那么 vector.size() == vector.capacity()
    print_vector(v1); // 如果原 vector.capacity() > num ,那么 vector.capacity() 大小不变
    show_vector_info(v1);

    // resize 重新指定大小 ，若指定的更小，超出部分元素被删除，但vector.capacity() 大小不变
    v1.resize(5);
    print_vector(v1);
    show_vector_info(v1);

    // 利用 resize 初始化后的 vector.size() == vector.capacity()
    vector<int> v2;
    v2.resize(8, 10);
    print_vector(v2);
    show_vector_info(v2);
}

/*
3.2.5 vector插入和删除

函数原型：

push_back(ele); //尾部插入元素ele
pop_back(); //删除最后一个元素
insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素

*/

void test04()
{

    // 尾插法
    vector<int> v1;
    v1.assign(5, 10);
    v1.push_back(100);
    print_vector(v1);

    // 尾删法
    vector<int> v2(v1);
    v2.pop_back();
    print_vector(v2);

    // 支持在迭代器指向位置begin()或end()插入元素
    // 也支持利用迭代器的偏移来插入数据
    auto p = v2.begin();
    v2.insert(++p, 100); // 注意是 ++iterator
    print_vector(v2); // 输出：10  100  10  10  10  10

    v2.insert(v2.end(), 3, 100); // 插入n个元素
    print_vector(v2);
    
    //删除迭代器指向的元素

    // for (int i = 0; i < v1.size(); i++)  // 不能将10清除干净的原因是：i < v1.size()条件中i随着迭代在增加，
    //                                      // 而size()随着删除头元素的进行在减小
    // {
    //     if (v1.front() == 10)
    //     {
    //         v1.erase(v1.begin());
    //     }
    // }
    // print_vector(v1);//输出 10  10  100

    //正确的写法
    vector<int>::iterator ptr = v1.begin();
    
    //写法一
    while (ptr != v1.end())
    {
        if (*ptr == 10)
        {
            v1.erase(ptr);
        }
        else
        {
            ++ptr;
        }
    }

    //写法二
    while (ptr != v1.end())
    {
        if(v1.front() == 10)
        {
            v1.erase(v1.begin());
        }
        else
        {
            ++ptr;
        }     
    }
    
    print_vector(v1);

    //清空容器元素
    v2.erase(v2.begin(), v2.end());
    v1.clear();

}

int main()
{
    // test01();

    // test02();

    // test03();

    test04();

    system("pause");
    return 0;
}