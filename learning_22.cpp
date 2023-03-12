#include <iostream>

using namespace std;

/*
冒泡排序
作用： 最常用的排序算法，对数组内元素进行排序

比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
重复以上的步骤，每次比较次数-1，直到不需要比较
*/

int main(){

    int arr[9] = { 4,2,8,0,5,7,1,3,9 };
    int arr_length = 0;
    arr_length = sizeof(arr) / sizeof(arr[0]);

    //外层 排序总轮数：元素个数-1
    for (int i = 0; i < arr_length - 1; i++)
    {
        //内层 每轮的相邻数字相互对比 每轮对比次数：元素个数-当前轮数-1
        for (int j = 0; j < arr_length - i - 1; j++)
        {
            //如果第一数字大，则跟第二个数字交换位置
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << endl;
    }
    
    system("pause");
    return 0;
}