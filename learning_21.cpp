#include <iostream>
using namespace std;

/*
案例描述：请声明一个5个元素的数组，并且将元素逆置.

(如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1);
*/

int main(){
    int arr[] = {1, 3, 2, 5, 4};
    int arr_length = 0;
    arr_length = sizeof(arr) / sizeof(arr[0]); // arr_length = 5
    // int arr_swap[arr_length] = {};//定义空数组
    
    // //原数组索引从4开始，递减
    // for (int i = arr_length -1 ; i >= 0; i--)
    // {
    //     arr_swap[arr_length -1 - i] = arr[i];
    // }
    
    // //打印逆序后的数组
    // for (int i = 0; i < arr_length; i++)
    // {
    //     cout << arr_swap[i] << endl;
    // }

    int start_index = 0;
    int end_index = arr_length - 1;
    int temp = 0;
    // 利用for循环
    // for (int i = 0; i < arr_length; i++)
    // {
    //     if (start_index >= end_index)
    //     {
    //         break;
    //     }
    //     temp = arr[start_index];
    //     arr[start_index] = arr[end_index];
    //     arr[end_index] = temp;
    //     start_index++;
    //     end_index--;
    // }
    
    // 利用while条件判断
    while (start_index < end_index)
    {
        temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;
        start_index++;
        end_index--;
    }

    //打印逆序后的数组
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << endl;
    }

    system("pause");
    return 0;
}