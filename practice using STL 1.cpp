/*
案例描述：

有5名选手，选手ABCDE，10个评委分别对每一名选手打分，去掉一个最高分去掉一个最低分，取平均分

*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
const int EVALUATE_NUMBER = 5;//定义全局常量 评价人数
using namespace std;

// 构建选手类
class Player
{
private:
    string palyer_name;
    deque<int> player_evaluate_score;// 利用deque来接收评分
    int player_average_score;

public:
    // 初始化选手
    Player(const string &name_) : palyer_name(name_), player_average_score(0){}

    // 获得选手的成绩
    int get_average_score()
    {
        return this->player_average_score;
    }

    // 设置选手的评分
    void set_score(const int *arr)
    {
        for (size_t i = 0; i < EVALUATE_NUMBER; i++)
        {
            this->player_evaluate_score.push_back(arr[i]);
        }    
    }

    // 打印选手的评分
    void show_evaluate_score()
    {
        cout << "the evaluation from commanders of player " << this->palyer_name << " is : ";
        for (deque<int>::iterator ptr = player_evaluate_score.begin(); ptr != player_evaluate_score.end(); ptr++)
        {
            cout << *ptr << " ";
        }
        cout << endl;
    }

    // 打印选手的最终成绩
    void show_average_score()
    {
        cout << "Player " << palyer_name << "  final score is " << this->player_average_score << endl;
    }

    // 设置选手的成绩
    void set_average_score()
    {
        // 为了不修改初始的评分数组，拷贝一份评分数组
        deque<int> copy_score = player_evaluate_score;
        std::sort(copy_score.begin(), copy_score.end()); // 对数组排序
        copy_score.pop_back(); // 去掉最高分和最低分
        copy_score.pop_front();

        int sum_score = 0;
        for (deque<int>::iterator ptr = copy_score.begin(); ptr != copy_score.end(); ptr++)
        {
            sum_score += *ptr;
        }

        this->player_average_score = sum_score / copy_score.size();
    }
};

// 在creat_player函数中创建player对象，用名字和评分数组初始化每个player
Player creat_player(const string & name_ , const int *score_)
{
    Player player_(name_);
    player_.set_score(score_);// 先用数组初始化 player的评分
    player_.set_average_score();// 再计算player的平均分数
    return player_;
}

int main()
{
    cout << "请输入选手的个数：" << endl;
    int num_player;
    cin >> num_player;

    vector<Player> playerlist;

    int j = 0;
    
    // 创建一个循环 来持续输入 Player对象
    while (j < num_player)
    {
        cout << "选手的名字：" << endl;
        string name_;
        cin >> name_;

        cout << "选手的评分，共 " << EVALUATE_NUMBER << " 个：" << endl;
        int score_[EVALUATE_NUMBER];

        for (int i = 0; i < EVALUATE_NUMBER; i++)
        {
            cin >> score_[i];
        }

        // 在creat_player函数中创建player对象，用名字和评分数组初始化每个player
        // 并将所有的player 放到一个vector容器中
        playerlist.push_back(creat_player(name_, score_));

        j++;
    }

    // 遍历打印所有player的成绩
    for (vector<Player>::iterator ptr = playerlist.begin(); ptr != playerlist.end(); ptr++)
    {
        ptr->show_evaluate_score();
        ptr->show_average_score();
    }
    
    // 测试代码
    // Player p1("lili");
    // cout << p1.get_average_score();
    
    // p1.set_score({ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }); // 注意利用{}进行赋值
    // p1.show_evaluate_score();
    // p1.set_average_score();
    // cout << endl;
    // cout << p1.get_average_score();

    return 0;
}