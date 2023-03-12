#include <iostream>
#include <fstream>
using namespace std;

/*
创建流对象的三种类：

1. ofstream: 写操作
2. ifstream：读操作
3. fstream：读写操作

*/

//写文件
void test()
{
    //创建流对象
    ofstream ofs;
    
    //打开文件 ofs.open("文件路径", 打开方式)
    ofs.open("test.txt", ios::out);

    //写入数据
    ofs << "这是一个 测试  文件！" << endl;
    ofs << "张三" << endl;
    ofs << "He is 18 year old." << endl;
    
    //关闭文件
    ofs.close();
}

int main()
{
    test();

    system("pause");
    return 0;
}