
#include <iostream>
using namespace std;
/*
案例需求：

提示用户输入一个高考考试分数，根据分数做如下判断
分数如果大于600分视为考上一本，大于500分考上二本，大于400考上三本，其余视为未考上本科；
在一本分数中，如果大于700分，考入北大，大于650分，考入清华，大于600考入人大。
*/
int main()
{
    // 单行格式 if 语句： if(条件){条件满足时执行的语句}
    // 多行格式if语句：if(条件){ 条件满足执行的语句 }else{ 条件不满足执行的语句 };
    // if(条件1){ 条件1满足执行的语句 }else if(条件2){条件2满足执行的语句}... else{ 都不满足执行的语句}

    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    cout << "您输入的分数为： " << score << endl;

    if (score > 600)
    {
        if (score > 700)
        {
            cout << "您考上北大" << endl;
        }
        else if (score > 650)
        {
            cout << "您考上了清华" << endl;
        }
        else
        {
            cout << "您考上了人大" << endl;
        }
    }
    else if (score > 500)
    {
        cout << "您考上了二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "您考上了三本大学" << endl;
    }
    else
    {
        cout << "您未考上本科" << endl;
    }

    system("pause");
    return 0;
}
