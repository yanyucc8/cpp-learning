#include <iostream>
#include <vector>
using namespace std;

/*
3.2.7 vector互换容器

函数原型：

swap(vec); // 将vec与本身的元素互换
*/
inline void print_vector(const vector<int> &v_) //如果对函数形参使用const修饰，那么函数内部用到的容器的iterator也必须是const的
{
    for (vector<int>::const_iterator ptr = v_.begin(); ptr!=v_.end(); ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

inline void show_vector_info(const vector<int> &v_)
{
    cout << "the size of vector is " << v_.size() << endl;
    cout << "the capacity of vector is " << v_.capacity() << endl;
}

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "before swap v1 = " << endl;
    print_vector(v1);
    
    for (int i = 9; i > -1; i--)
    {
        v2.push_back(i);
    }
    cout << "before swap v2 = " << endl;
    print_vector(v2);

    v1.swap(v2);
    cout << "after swap v1 = " << endl;
    print_vector(v1);
    cout << "after swap v2 = " << endl;
    print_vector(v2);
}

void test02()
{
    //swap函数可以使两个容器互换，达到收缩内存空间的效果
    vector<int> v1;
    for (int i = 0; i < 1000; i++)
    {
        v1.push_back(i);
    }

    v1.resize(10);//重新指定vector的size长度
    show_vector_info(v1);

    //v1的容量没有变，在内存中预分配了一大块不用的内存空间造成浪费
    //利用一个匿名vector来和他进行交换
    vector<int>(v1).swap(v1);//vector<int>(v1) 调用了v1的拷贝构造函数生成了匿名对象，在本行代码执行结束后，匿名vector被程序自动释放
    show_vector_info(v1);
}


/*
3.2.8 vector预留空间
功能描述：

减少vector在动态扩展容量时的扩展次数

函数原型：

reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/

void test03()
{
    vector<int> v1;

    //预留空间，减少动态开辟次数
    v1.reserve(10000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 10000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])//由于每次动态开辟空间都会在内存中开辟新的vector地址，将原vector释放，那么如果指针p不指向vector的首元素，那么就 计数一次
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "动态空间开辟的次数：" << num << endl; //不预留空间：15次，预留空间：1次
}

int main()
{
    test01();
    //test02();
    test03();
    system("pause");
    return 0;
}