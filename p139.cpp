// 多态案例2-制作饮品
#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    void makedrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮山泉水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入蜂蜜" << endl;
    }
};

void dowork(AbstractDrinking * abs)
{
    abs->makedrink();
    delete abs; // 释放
}

void test1()
{
    dowork(new Tea);
}

int main(){
    test1();
    system("pause");
    return 0;
}