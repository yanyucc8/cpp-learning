/*
案例描述

公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息

*/

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

// Worker类
class Worker
{
protected:
    string worker_name;
    int worker_salary;

public:
    Worker(){}
    Worker(const string &name_, const int &salary_): worker_name(name_), worker_salary(salary_) {}
    Worker(const Worker &worker_)
    {
        this->worker_name = worker_.get_name();
        this->worker_salary = worker_.get_salary();
    }
    
    string get_name() const
    {
        return this->worker_name;
    }

    int get_salary() const
    {
        return this->worker_salary;
    }

    virtual ~Worker(){}
};

// 创建10名员工，放到vector中
void creat_worker(vector<Worker> &worker_v_)
{
    string subname = "ABCDEFGHIJ";
    // 如果想用append()函数，必须这样写
    // string sub;
    // sub = subname[i];
    for (int i = 0; i < subname.size(); i++)
    {
        string per_worker_name = "Worker ";
        per_worker_name += subname[i];
        //per_worker_name.append(sub);
        int per_worker_salary = rand() % 5000 + 10001;   // 0~4999 + 10001 -> 10001~15000
        
        Worker per_worker(per_worker_name, per_worker_salary);
        worker_v_.push_back(per_worker);
    }   
}

// 遍历vector容器，取出每个员工，进行随机分派部门编号0~2，加到multimap容器中
// 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
void group_worker(const vector<Worker> &worker_v_, multimap<int, Worker> &worker_m_)
{   
    for (vector<Worker>::const_iterator it = worker_v_.begin(); it != worker_v_.end(); it++)
    {
        int department = rand() % 3;
        worker_m_.insert(make_pair(department, *it));
    }
}

// 显示全部的员工信息
void show_worker(const multimap<int, Worker> &worker_m_)
{
    for (multimap<int, Worker>::const_iterator it = worker_m_.begin(); it != worker_m_.end(); it++)
    {
        switch (it->first)
        {
        case 0:
             cout << "department 0" << "  " << it->second.get_name() << "  " << it->second.get_salary() << endl;
            break;
        case 1:
             cout << "department 1" << "  " << it->second.get_name() << "  " << it->second.get_salary() << endl;
             break;
        case 2:
             cout << "department 2" << "  " << it->second.get_name() << "  " << it->second.get_salary() << endl;
             break;
        }
    }       
}

// 仅显示选择的department的worker （department的值为0，1，2）
void show_worker_by_select_department(const multimap<int, Worker> &worker_m_, const int &department_)
{
    multimap<int, Worker>::const_iterator pos;
    int department_count;
    int count;
    switch (department_)
    {
    case 0:
        pos = worker_m_.find(department_);
        department_count = worker_m_.count(department_);
        count = 0;
        cout << "the worker from department 0 is : " << endl;
        // 分组显示时，pos确定起始位置，department_count确定pos移动次数
        // 也可以将 pos != worker_m_.end() && 条件删掉
        for ( ; pos != worker_m_.end() && count < department_count; pos++, count++)
        {
            cout << "department 0" << "  " << pos->second.get_name() << "  " << pos->second.get_salary() << endl;
        }
        break;
    case 1:
        pos = worker_m_.find(department_);
        department_count = worker_m_.count(department_);
        count = 0;
        cout << "the worker from department 1 is : " << endl;
        for ( ; pos != worker_m_.end() && count < department_count; pos++, count++)
        {
            cout << "department 1" << "  " << pos->second.get_name() << "  " << pos->second.get_salary() << endl;
        }
        break;
    case 2:
        pos = worker_m_.find(department_);
        department_count = worker_m_.count(department_);
        count = 0;
        cout << "the worker from department 2 is : " << endl;
        for ( ; pos != worker_m_.end() && count < department_count; pos++, count++)
        {
            cout << "department 2" << "  " << pos->second.get_name() << "  " << pos->second.get_salary() << endl;
        }
        break;
    }
}

int main()
{
    ((unsigned int)time(NULL));
    
    // 定义一个worker的vector
    vector<Worker> worker_v;
    creat_worker(worker_v);
    
    // 定义一个worker的multimap
    multimap<int, Worker> worker_m;
    group_worker(worker_v, worker_m);

    // 显示全部的worker
    show_worker(worker_m);

    // 仅显示选择的department的worker （department的值为0，1，2）
    show_worker_by_select_department(worker_m, 1);

    // 测试代码
    // for (vector<Worker>::iterator it = worker_v.begin(); it != worker_v.end(); it++)
    // {
    //     cout << it->get_name() << "  " << it->get_salary() << endl;
    // }
    // for (multimap<int,Worker>::iterator it = worker_m.begin(); it != worker_m.end(); it++)
    // {
    //     cout << it->first << "  " << it->second.get_name() << "  " << it->second.get_salary() << endl;
    // }

    system("pause");
    return 0;
}