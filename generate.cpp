#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ofstream file;
    file.open("data.txt");
    file << "编号" << "\t" << "名字" << "\t" << "职位编号" << "\t" << "薪资" << endl;
    srand(time(0));
    string names[] = {"李华", "王芳", "张伟", "刘艳", "赵静", "黄明", "周洋", "吴刚", 
    "郑磊", "冯娜","成龙","李连杰","刘德华","张学友","黎明","关淑怡","邓丽君","林青霞",
    "刘晓庆","赵雅芝"};
    for (int i = 0; i < 100; i++) {
        int id = i;
        string name = names[rand() % 20];
        int position_id = rand() % 3 + 1;
        int salary = rand() % 1001;
        file << id << "\t" << name << "\t" << position_id << "\t" << salary << endl;
    }
    file.close();
    cout<<"文件已生成"<<endl;
}