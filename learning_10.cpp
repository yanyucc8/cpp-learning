#include <iostream>
using namespace std;

/*
1.switch语句表达式类型只能是整型或字符型
2.多个case必须加break
*/
int main(){
    //请给电影评分 
	//10 ~ 9   经典   
	// 8 ~ 7   非常好
	// 6 ~ 5   一般
	// 5分以下 烂片
    int score = 0;
    cout << "请给电影打分："  << endl;
    cin >> score;

    switch (score)
    {
    //整数区间的写法
    case 9 ... 10: 
        cout << "您对该电影的评价： 经典！"  << endl;
        break;
    // case 10:
    //     // cout << "您对该电影的评价： 经典！"  << endl;
    //     // break;
    // case 9:
    //     cout << "您对该电影的评价： 经典！"  << endl;
    //     break;
    case 8:
        // cout << "您对该电影的评价： 非常好！"  << endl;
        // break;
    case 7:
        cout << "您对该电影的评价： 非常好！"  << endl;
        break;        
    case 6:
        // cout << "您对该电影的评价： 一般！"  << endl;
        // break;
    case 5:
        cout << "您对该电影的评价： 一般！"  << endl;
        break;
    default:
        cout << "您对该电影的评价： 烂片！"  << endl;
        break;
    }
}