#include <iostream>
#include <cmath>
using namespace std;

int main(){
    /*
    do...while循环
    语法：do{循环语句} while(循环条件)
    与while的区别在于：do...while会先执行一次循环语句，再判断循环条件
    */

    //利用do while语句输出0~9的数字
    //以下为do while循环所写
    // int num = 0;
    // do
    // {
    //     cout << num << endl;
    //     num ++;    
    // } while (num < 10);
    
    //以下为while循环所写
    // int num = 0;
    // while (num < 10)
    // {
    //     cout << num << endl;
    //     num++;
    // }
    
    /*案例描述：水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
    例如：1^3 + 5^3+ 3^3 = 153，请利用do...while语句，求出所有3位数中的水仙花数*/
    int num = 100;
    do
    {
        int num_1 = 0;
        int num_2 = 0;
        int num_3 = 0;
        
        //通过取余运算，和int的取整特征，提取个位，十位，百位的数字
        num_1 = num % 10;
        num_2 = (num / 10) % 10;
        num_3 = num / 100;

        if (num == pow(num_3, 3) + pow(num_2 , 3) + pow(num_1 , 3))
        //如果不用cmath库的pow函数还可以写成：
        //if (num == num_3*num_3*num_3 + num_2*num_2*num_2 + num_3*num_3*num_3)
        {
            cout << num << endl;
        }       
        num++;
    } while (num <= 999);
    
    system("pause");
    return 0;
}