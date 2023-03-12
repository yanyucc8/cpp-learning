#include <iostream>
#include <vector>
using namespace std;

/*
2.5.3 Vector容器嵌套容器

学习目标：容器中嵌套容器，我们将所有数据进行遍历输出
*/

void test()
{
    //创建一个包含小vector的大vector
    vector<vector<int>> outer_vector;
    
    //创建大vector里面的各个小vector
    vector<int> inner_vector_1;
    vector<int> inner_vector_2;
    vector<int> inner_vector_3;
    vector<int> inner_vector_4;

    //在各个小vector里添加数据
    for (int i = 0; i < 4; i++)
    {
        inner_vector_1.push_back(i + 1);
        inner_vector_2.push_back(i + 2);
        inner_vector_3.push_back(i + 3);
        inner_vector_4.push_back(i + 4);
    }

    //把小vector添加到大vector里
    outer_vector.push_back(inner_vector_1);
    outer_vector.push_back(inner_vector_2);
    outer_vector.push_back(inner_vector_3);
    outer_vector.push_back(inner_vector_4);

    //遍历大vector里所有的小vector数据
    //关键点：
    // *outer_ptr 的数据类型和迭代器iterator(或它指向的容器outer_vector)的模板类型是一致的，即vector<int>
    // *inner_ptr 的数据类型，即 int

    //外层迭代器，遍历大vector中的各个小vector
    //内层迭代器，遍历小vector中的各个int型数据
    for (vector<vector<int>>::iterator outer_ptr = outer_vector.begin(); outer_ptr != outer_vector.end(); outer_ptr++)
    {
        for (vector<int>::iterator inner_ptr = (*outer_ptr).begin(); inner_ptr != (*outer_ptr).end(); inner_ptr++)
        {
            cout << *inner_ptr << "  ";
        }
        cout << endl;
    }    
}

int main()
{
    test();

    system("pause");
    return 0;
}