#include <iostream>
using namespace std;
/*
三目运算符
语法：表达式1 ? 表达式2 : 表达式3
解释：
    如果表达式1的值为真，执行表达式2，并返回表达式2的结果；
    如果表达式1的值为假，执行表达式3，并返回表达式3的结果。

练习案例： 三只小猪称体重
有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
*/
int main(){
    int pig_a = 0;
    int pig_b = 0;
    int pig_c = 0;
    
    cout << "请输入小猪A的体重：" << endl;
    cin >> pig_a;
    cout << "请输入小猪B的体重：" << endl;
    cin >> pig_b;
    cout << "请输入小猪C的体重：" << endl;
    cin >> pig_c;

    if ((pig_a > pig_b ? pig_a : pig_b) == pig_a)
    {
        if ((pig_a > pig_c ? pig_a : pig_c) == pig_a)
        {
            cout << "小猪A是最重的！" << endl;
        }
        else
        {
            cout << "小猪C是最重的！" << endl;
        }    
    }
    else
    {
        if ((pig_b > pig_c ? pig_b : pig_c) == pig_b)
        {
            cout << "小猪B是最重的！" << endl;
        }
        else
        {
            cout << "小猪C是最重的！" << endl;
        }      
    } 
}
