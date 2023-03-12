#include <iostream>
using namespace std;

/*
案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，
请分别输出三名同学的总成绩
*/

int main(){

    int score[3][3] = 
    {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };
    string name[3] = {"张三", "李四", "王五"};

    int score_sum[3] = {};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            score_sum[i] += score[i][j];
        }         
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << "的总分是： " << score_sum[i] << " 分" << endl;
    }

    system("pause");
    return 0; 
}
