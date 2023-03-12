#include <iostream>
using namespace std;

int main(){
/*
嵌套循环
作用： 在循环体中再嵌套一层循环，解决一些实际问题

双层嵌套循环的时间复杂度为 O(n^2)
*/
    //外层循环
    //外层循环执行1次，内层循环执行1轮
    //外层定义行，内层定义列
    
    for (int i = 0; i < 10; i++)
    {
        //内层循环
        for (int j = 0; j < 10; j++)
        {
            cout << "* ";
        }
    cout << endl;    
    }
  
    system("pause");
    return 0;
}