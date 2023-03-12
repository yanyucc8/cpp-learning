#include <iostream>
using namespace std;

int main(){
/*
for循环语句
语法：for(起始表达式;条件表达式;末尾循环体){循环语句;}
*/
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i << endl;
    // }
 /*
 案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，
 或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。
 */ 
    int start_num = 0;
    cout << "敲桌子游戏，输入起始值（1~100）：" << endl;
    cin >> start_num;
    
    for (int i = start_num; i < 100; i++)
    {
        if (i % 7 == 0)
        {
            cout << "敲桌子" << endl;
        }
        else if (i % 10 == 7)   
        {
            cout << "敲桌子" << endl;
        }
        else if (i / 10 == 7)
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }        
    }
    
    system("pause");
    return 0;
}