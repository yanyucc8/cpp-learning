#include <iostream>
using namespace std;

/*
1.2.3 函数模板案例
案例描述：

利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
排序规则从大到小，排序算法为选择排序
分别利用char数组和int数组进行测试
*/

//交换函数
template<typename T>
void MySwap(T &m1, T &m2)
{
    T temp = m1;
    m1 = m2;
    m2 = temp;
}

//打印函数
template<typename T>
void MyPrint(T arr[] , int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "  " ;
    }
}

//1.选择排序
template<typename T>
void SelectionSort(T arr[], int len)
{
    for (int i = 0; i < len -1; i++)//从第1个元素开始遍历，到第n-1个元素
    {
        int max_index = i;//假设第1（i）个元素最大，取他的index
        for (int j = i + 1; j < len ; j++)//从第二（i+1）个元素开始，逐个和比较第1（i）个元素比较大小
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;//把较大元素的index赋值给最大元素的index
            }
        }
        //交换第1（i）个元素和最大元素
        MySwap(arr[i], arr[max_index]);
    }
}

//冒泡排序
template<typename T>
void BubbleSort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j+1])
            {
                MySwap(arr[j], arr[j + 1]);
            }            
        }        
    }    
}


void test01()
{
    //测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int len = sizeof(intArr) / sizeof(int);
    SelectionSort(intArr, len);
    MyPrint(intArr, len);
}

void test02()
{
    //测试char数组
	char charArr[] = "bdcfeagh";
    int len = sizeof(charArr) / sizeof(char);
    SelectionSort(charArr, len);
    MyPrint(charArr, len);
}

void test03()
{
    //测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int len = sizeof(intArr) / sizeof(int);
    BubbleSort(intArr, len);
    MyPrint(intArr, len);
}

int main()
{
    // test01();
    // test02();
    test03();
    system("pause");
    return 0;
}