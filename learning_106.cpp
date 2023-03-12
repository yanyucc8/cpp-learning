#include <map>
#include <iostream>
using namespace std;

/*
map/multimap

map中所有元素都是pair
pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
所有元素都会根据元素的key自动排序
map/multimap属于关联式容器，底层结构是用二叉树实现。

*/

/*
3.9.2 map构造和赋值

map<T1, T2> mp; //map默认构造函数:
map(const map &mp); //拷贝构造函数
map& operator=(const map &mp); //重载等号操作符

*/

inline void print_int_map(const map<int,int> & m_)
{
    for (map<int,int>::const_iterator it = m_.begin(); it != m_.end(); it++)
    {
        cout << "key: " << it->first << "  "
             << "value: " << it->second << endl;
    }
}

void test01()
{
    //默认构造
    map<int, int> m1;
    m1.insert(pair<int, int>(5, 25));
    m1.insert(pair<int, int>(1, 1));
    m1.insert(pair<int, int>(4, 16));
    m1.insert(pair<int, int>(2, 4));
    m1.insert(pair<int, int>(3, 9));

    print_int_map(m1);

    //拷贝构造
    map<int, int> m2(m1);

    //=赋值
    map<int, int> m3 = m1;
}

/*
3.9.3 map大小和交换

size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器

*/

void test02()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(5, 25));
    m1.insert(pair<int, int>(1, 1));
    m1.insert(pair<int, int>(4, 16));
    m1.insert(pair<int, int>(2, 4));
    m1.insert(pair<int, int>(3, 9));

    print_int_map(m1);

    cout << "the size of map m1 is : " << m1.size() << endl;
    cout << "the map m1 is empty : " << (m1.empty() ? "true" : "false") << endl;

    map<int, int> m2;
    m2.insert(make_pair(5, 1));
    m2.insert(make_pair(1, 25));
    m2.insert(make_pair(4, 4));
    m2.insert(make_pair(2, 16));

    m1.swap(m2);
    print_int_map(m1);
}

/*
3.9.4 map插入和删除

insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key); //删除容器中值为key的元素。

*/

void test03()
{
    // insert插入元素的方式
    map<int, int> m1;
    
    m1.insert(pair<int, int>(5, 25));// 推荐
    
    m1.insert(make_pair(3, 9));// 推荐
    
    m1.insert(map<int, int>::value_type(4, 16));// 了解
    
    m1[2] = 4;// 不推荐

    print_int_map(m1);

    m1.erase(--m1.end()); // 同set容器一样，map 直接使用 m1.erase(m1.end()) 会抛出异常，因为map不是可解引用的迭代器
                          // 要删除最后的元素，需要将end()迭代器往前移一个位置，到有元素的位置
    print_int_map(m1);

    // 删除容器中值为key的元素
    m1.erase(3);
    print_int_map(m1); 

    // erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
    m1.erase(m1.begin(), m1.end());
}

/*
3.9.5 map查找和统计

find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
count(key); //统计key的元素个数
*/
void test04()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(5, 25));
    m1.insert(pair<int, int>(1, 1));
    m1.insert(pair<int, int>(4, 16));
    m1.insert(pair<int, int>(2, 4));
    m1.insert(pair<int, int>(3, 9));

    // 查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    map<int, int>::iterator pos = m1.find(3);
    cout << "the key of element in map is :" << ((pos != m1.end()) ? (*pos).first : -1) << endl;
    
    cout << "the count of element 1 in map is :" << m1.count(1) << endl;
    // map的key不重复，所以返回值 是 1 或 0
}

/*
3.9.6 map容器排序

利用仿函数，可以改变排序规则
*/

// 仿函数降序排列
class SortIntDefine
{
public:
    bool operator()(const int & num1_, const int & num2_) const
    {
        return num1_ > num2_; 
    }

};

void test05()
{
    map<int, int, SortIntDefine> m1;
    m1.insert(make_pair(5, 25)); 
    m1.insert(make_pair(1, 1));
    m1.insert(make_pair(4, 16));
    m1.insert(make_pair(2, 4));
    m1.insert(make_pair(3, 9));
    
    // 注意：这里iterator的类型一定要和定义时模板使用类型一致
    for (map<int,int,SortIntDefine>::const_iterator it = m1.begin(); it != m1.end(); it++)
    {
        cout << "key: " << it->first << "  "
             << "value: " << it->second << endl;
    }
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    return 0;
}