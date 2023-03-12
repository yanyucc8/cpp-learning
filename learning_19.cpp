#include <iostream>
using namespace std;

int main(){
    /*
    一维数组 数组名的用途
    1、统计整个数组占用内存空间大小   sizeof(arr)
    2、获取数组在内存中的首地址       cout << arr <<endl;
    */
    
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    //1、可以获取整个数组占用内存空间大小
    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
    cout << "数组中每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
    cout << "数组中元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
    
    //2、可以通过数组名获取到数组首地址
    //cout << "数组首地址为： " << (int)arr << endl; //(int)将十六进制地址转成十进制地址
    //64位系统上指针类型占用8个字节，而int类型占用4个字节，所以会出现loses precision。
    //可以先将int转成long类型，long类型可以隐式类型转换到int类型。
    //或直接修改为long long即可
    cout << "数组首地址为： " << (long long)arr << endl; //将十六进制地址转成十进制地址 
    cout << "数组中第一个元素地址为： " << &arr[0] << endl; // 获取数组元素内存地址需要加 &
    
    system("pause");
    return 0;
}