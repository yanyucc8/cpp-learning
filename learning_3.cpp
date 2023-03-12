#include <iostream>
using namespace std;

int main(){
    //数据的输入，从键盘上获取数据
    //整型输入
    int x = 0;
    cout << "请输入整型变量：" << endl;
    cin >> x;
    cout << "你输入的整型变量是：" << x << endl;
 
    //浮点型输入
    float f = 0;
    cout << "请输入浮点型变量：" << endl;
    cin >> f;
    cout << "你输入的浮点型变量是：" << f << endl;
    
    //字符型输入
    char c = 0;
    cout << "请输入字符型变量：" << endl;
    cin >> c;
    cout << "你输入的字符型变量是：" << c << endl;

    //字符串型输入
    string s;
    cout << "请输入字符串型变量：" << endl;
    cin >> s;
    cout << "你输入的字符串型变量是：" << s << endl;

    
    system("pause");
    return 0;
}