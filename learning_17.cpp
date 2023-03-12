#include <iostream>
using namespace std;

int main(){
    //continue的效果是跳出本次循环，执行下一次循环
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            continue;   
        }
        cout << i << endl;
    }
    
    //goto语句
    //无条件跳转语句

    system("pause");
    return 0;
}