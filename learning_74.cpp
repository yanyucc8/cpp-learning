#include <iostream>
using namespace std;

/*
案例描述：

制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料

利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
class MakeDrinking
{
public:
    virtual void heatwater() = 0;
    virtual void dipin() = 0;
    virtual void pourincup() = 0;
    virtual void addthing() = 0;

    //MakeDrinking(){}

    void Makeit()
    {
        heatwater();
        dipin();
        pourincup();
        addthing();
    }
};

//定义制作咖啡的子类
class MakeCoffee : public MakeDrinking
{
public:
    //MakeCoffee(){}

    void heatwater()
    {
        cout << "烧纯净水" << endl;
    }

    void dipin()
    {
        cout << "滴滤咖啡" << endl;
    }

    void pourincup()
    {
        cout << "咖啡倒入杯中" << endl;
    }

    void addthing()
    {
        cout << "加入牛奶" << endl;
    }
};

//定义制作茶的子类
class MakeTea : public MakeDrinking
{
public:
    //MakeTea(){}

    void heatwater()
    {
        cout << "烧矿泉水" << endl;
    }

    void dipin()
    {
        cout << "泡壶茶" << endl;
    }

    void pourincup()
    {
        cout << "绿茶倒入杯中" << endl;
    }

    void addthing()
    {
        cout << "不加东西" << endl;
    }
};

//方法一 按指针传入
void test01()
{
    MakeDrinking *exercise_1 = new MakeCoffee;
    exercise_1->Makeit();
    delete exercise_1;

    cout << "---------------------" << endl;

    MakeDrinking *exercise_2 = new MakeTea;
    exercise_2->Makeit();
    delete exercise_2;
}

//方法二 按指针传入
void DoExercise(MakeDrinking * _exer)
{
    _exer->Makeit();
    delete _exer;
}

void test02()
{
    DoExercise(new MakeCoffee);
    cout << "---------------------" << endl;
    DoExercise(new MakeTea);
}

//方法三 按引用传入
void DoExercise(MakeDrinking & _exer)
{
    _exer.Makeit();
}

void test03()
{
    MakeCoffee coffee;
    DoExercise(coffee);
    cout << "---------------------" << endl;
    MakeTea tea;
    DoExercise(tea);
}

int main()
{
    test01();

    test02();

    test03();

    system("pause");
    return 0;
}