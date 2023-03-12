#include <iostream>
#include <ctime>
#include <windows.h> //为解决exe中文乱码而添加
using namespace std;

int main(){
    SetConsoleOutputCP(65001);//为解决exe中文乱码而添加
    
    /* while 循环
    语法：while( 循环条件 ){ 循环语句 }
    解释：循环条件为真，就执行循环条件
    */ 
//    int num = 0;
//    while (num < 10)
//    {
//     cout << "num = " << num << endl;
//     num++;
//    }
    /*案例描述：系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，
    提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。*/

//添加随机数种子，作用：利用当前系统时间生成随机数
    //srand(time(0));
    srand((unsigned int)time(NULL));
//系统生成随机数1~100
    int num = rand()%100 + 1;
    //测试代码cout << num << endl;

//玩家进行猜测
    int player_val = 0;

//判断玩家的猜测
    // while (num != player_val)
    // {
    //    cout << "请输入猜测数字(1~100)：" << endl;
    //    cin >> player_val;
    //    if (num > player_val)    
    //    {
    //     cout << "猜测数字过小！" << endl;
    //    }
    //    else if (num < player_val)
    //    {
    //     cout << "猜测数字过大！" << endl;
    //    }
    //    else
    //    {
    //     cout << "恭喜猜对了！" << endl;
    //    }       
    // }
    int guess_times = 0;
    //猜测次数限制在5次以内
    while (guess_times < 6)
    {
       cout << "请输入猜测数字(1~100)：" << endl;
       cin >> player_val;
       guess_times++;
       if (num > player_val)    
       {
        cout << "猜测数字过小！" << endl;
       }
       else if (num < player_val)
       {
        cout << "猜测数字过大！" << endl;
       }
       else
       {
        cout << "恭喜猜对了！" << endl;
        break;
       }       
    }
    if (guess_times == 6)
    {
        cout << "猜测次数过多！" << endl;
    }
    
    system("pause");
    return 0;    
}