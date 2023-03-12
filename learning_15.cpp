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
    
    // for (int i = 0; i < 10; i++)
    // {
    //     //内层循环
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << "* ";
    //     }
    // cout << endl;    
    // }
/*
案例描述：利用嵌套循环，实现九九乘法表
*/ 
    //利用printf函数输出
    //乘法口诀表以 上三角 矩阵形式
    // for (int i = 1; i < 10; i++)
    // {
    //     for (int j = i; j < 10; j++)
    //     {
    //         printf("%d x %d = %d \t", i, j, i*j);
    //     }
    //     printf("\n"); 
    // }

    //利用printf函数输出
    //乘法口诀表以 下三角 矩阵形式
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d x %d = %d \t", i, j, i*j);
        }
        printf("\n"); 
    }

    //利用cout输出
    //乘法口诀表以 下三角 矩阵形式
    // for (int i = 1; i <= 9; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << j << "x" << i << "=" << j*i << "\t";
    //     }
    //     cout << endl;
    // }
        
    system("pause");
    return 0;
}