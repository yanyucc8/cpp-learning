#include <iostream>
using namespace std;

/*案例描述：

在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};

找出并打印最重的小猪体重。
*/
int main(){

    int max = 0;
    int arr[5] = {300,350,200,400,250};
    int arg_j = 0;
    int len_arr = 0;
    len_arr = sizeof(arr) / sizeof(arr[0]); //确定数组元素个数
    for (int i = 0; i < len_arr; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i]; //遍历记录最大值
            arg_j = i; //记录数组索引
        }        
    }

    //利用三目运算符写，缺点是得不到索引
    // for (int i = 0; i < len_arr; i++)
    // {
    //     max = arr[i] > max ? arr[i] : max;
    // }
    
    cout << "五只小猪中最重的是第 " << arg_j + 1 << " 只" << "，它的体重是 " << max << endl;
    //cout << "五只小猪中最重的体重是 " << max << endl;
    system("pause");
    return 0; 
}