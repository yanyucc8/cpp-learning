#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    //创建流对象
    ifstream ifs;

    //打开文件，并判断文件是否打开
    ifs.open("test.txt", ios::in);

    if (ifs.is_open() == false)   //if ( ! ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //第一种方法
    //逐个字符读取到字符串，会按照读取文件里的空格符或换行符 依次读取 
    // char getchr_1[1024] = {0};
    // while (ifs >> getchr_1)
    // {
    //     cout << getchr_1 << endl;
    // }
    
    //第二种方法
    //istream类的getline()方法会按行读取文件
    // char getchr_2[1024] = {0};
    // while (ifs.getline(getchr_2, sizeof(getchr_2)))
    // {
    //     cout << getchr_2 << endl;
    // }

    //第三种方法
    //string中的getline()函数会按行读取文件
    string getchr_3;
    while (getline(ifs, getchr_3))
    {
        cout << getchr_3 << endl;
    }

    //第四种方法
    //效率低
    // char c;
    // while ((c = ifs.get()) != EOF) //EOF标志 end of file
    // {
    //     cout << c;
    // }

    ifs.close();
}

int main()
{
    test();

    system("pause");
    return 0;
}