#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
STL：Standard Template Library

STL容器：vector

vector存放内置数据类型

容器：vector
算法：for_each
迭代器：vector<int>::iterator

*/

void show_vector(int & value_)
{
    cout << value_ << endl;
}


void test()
{
    //创建vector对象， 通过模板参数<>指定容器中存放的数据类型
    vector<int> my_first_vector;

    //向容器中放数据
    my_first_vector.push_back(10);
    my_first_vector.push_back(20);
    my_first_vector.push_back(30);
    my_first_vector.push_back(40);

    //每个容器都有自己的迭代器，迭代器是用来遍历容器中的元素的
    //my_first_vector.begin();  返回迭代器，这个迭代器指向容器中的 第一个元素
    //my_first_vector.end();   返回迭代器，这个迭代器指向容器中的 最后一个元素的下个位置
    //vector<int>::iterator 拿到 vector<int> 这种容器的迭代器类型

    //1.遍历方式一
    vector<int>::iterator ptr_begin = my_first_vector.begin(); //将迭代器看作是 指针
    vector<int>::iterator ptr_end = my_first_vector.end(); //将迭代器看作是 指针

    while (ptr_begin != ptr_end)
    {
        cout << *ptr_begin << endl;
        ptr_begin++;
    }

    //2.遍历方式二(推荐)
    for (vector<int>::iterator ptr = my_first_vector.begin(); ptr != my_first_vector.end(); ptr++)
    {
        cout << *ptr << endl;
    }
    
    //3.遍历方式三
    //使用STL提供的标准遍历算法
    for_each(my_first_vector.begin(), my_first_vector.end(), show_vector);
}

int main()
{
    test();

    system("pause");
    return 0;
}