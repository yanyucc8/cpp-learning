#include <iostream>
using namespace std;

int main(){
    //1、在switch 语句中使用break
	cout << "请选择您挑战副本的难度：" << endl;
	cout << "1、普通" << endl;
	cout << "2、中等" << endl;
	cout << "3、困难" << endl;

    int choose_num = 0;
    cin >> choose_num;
    switch (choose_num)
    {
    case 1:
        cout << "你选择的副本难度为：1、普通" << endl;
        break;
    case 2:
        cout << "你选择的副本难度为：2、中等" << endl;
        break;
    case 3:
        cout << "你选择的副本难度为：3、困难" << endl;
        break;
    }

    //2、在循环语句中用break
    // for (int i = 0; i < 10; i++)
    // {
    //     if (i == 5)
    //     {
    //         break;//跳出循环语句
    //     }
    //     cout << i << endl;
    // }
    

    //3、在嵌套循环语句中使用break，退出内层循环，常配合内层if语句使用
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //该if语句用于控制生成的*的列数
            if (j == 5)
            {
                break;  
            }
            cout << "*" << " ";
        }
        cout << endl;
    }
    
    system("pause");
	return 0;
}