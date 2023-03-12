#include <iostream>
using namespace std;

/*
案例描述：

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

五名英雄信息如下：

{"刘备",23,"男"},
{"关羽",22,"男"},
{"张飞",20,"男"},
{"赵云",21,"男"},
{"貂蝉",19,"女"},
*/

//定义英雄的结构体
struct Hero
{
    string name;
    int age;
    string sex;
};

//定义冒泡排序函数
void BubbleSort(Hero *arr, int length_arr){
    for (int i = 0; i < length_arr - 1; i++)
    {
        for (int j = 0; j < length_arr - 1 - i; j++)
        {
            if (arr[j].age > arr[j+1].age)
            {
                Hero temp = arr[j]; //注意这里是对Hero结构体本身排序，而不是结构体的年龄！
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }            
        }        
    }    
}

//定义打印函数
void printInfo(Hero *arr, int length_arr){
    for (int i = 0; i < length_arr; i++)
    {
        //这里利用printf()打印字符串会出错
        cout << "第" << i + 1 << "个英雄的名字:" << arr[i].name << "年龄：" << arr[i].age << "性别：" << arr[i].sex << endl;
    }  
}

int main(){
    
    //创建结构体数组
    struct Hero three_kingdom_hero[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };

    int length = sizeof(three_kingdom_hero) / sizeof(three_kingdom_hero[0]); //length = 5

    //结构体排序
    BubbleSort(three_kingdom_hero, length);

    //打印结构体
    printInfo(three_kingdom_hero, length);

    system("pause");
    return 0;
}