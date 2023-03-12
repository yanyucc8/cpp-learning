#include <iostream>
using namespace std;
/*
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

    cout << "小猪A的体重：" << pig_a << endl;
    cout << "小猪B的体重：" << pig_b << endl;
    cout << "小猪C的体重：" << pig_c << endl;
    
    if (pig_a > pig_b)
    {
        if (pig_a > pig_c)
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
        if (pig_b > pig_c)
        {   
            cout << "小猪B是最重的！" << endl;
        }
        else
        {
            cout << "小猪C是最重的！" << endl;
        }   
    }    
}
