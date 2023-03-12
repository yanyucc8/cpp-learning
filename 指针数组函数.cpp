#include <iostream>
using namespace std;

/*
**案例描述：**封装一个函数，利用冒泡排序，实现对整型数组的升序排序

例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
*/

//当数组名传入到函数作为参数时，被退化为指向首元素的指针
//因为函数实参传的是数组地址，所以形参要用指针 int * 接收地址
void bubbleSort(int *arr, int arr_length){ 
    
    //外层 排序总轮数：元素个数-1
    for (int i = 0; i < arr_length - 1; i++)
    {
        //内层 每轮的相邻数字相互对比 每轮对比次数：元素个数-1-当前轮数
        for (int j = 0; j < arr_length - 1 - i; j++)
        {
            //如果第一数字大，则跟第二个数字交换位置
            //把arr当成指针，它代表数组的首地址，
            //同时arr作为数组名，也代表数组的首地址，所以指针也可以有索引
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArrary(int *arr, int arr_length){
    for (int i = 0; i < arr_length; i++)
    {
        printf("array[%d] = %d \n", i, arr[i]);
    }    
}

int main(){
    int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    
    //函数调用时，传入的是数组名，即数组的首地址
    bubbleSort(arr, arr_length);
    printArrary(arr, arr_length);
 
    system("pause");
    return 0;
}