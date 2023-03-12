#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    //定义一个指针，指向数组的首地址
    //数组名 arr 就是数组的首地址
    int *p = arr;

	cout << "第一个元素： " << arr[0] << endl;
	cout << "指针访问第一个元素： " << *p << endl;
    
    //利用指针遍历数组
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d] = %d \n", i, *p);
        p++;    
    }
    
}