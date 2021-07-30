// 成员函数做友元
#include<iostream>
#include<string>
using namespace std;

// 提前声明Building类
class Building;

class GoodGay
{
public:
    void visit();
    GoodGay();
    Building * building;
};

class Building
{
    // 成员函数做友元
    friend void GoodGay::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};



void GoodGay::visit()
{
    cout << "全局函数正在访问" << building->m_SittingRoom << endl;
    cout << "全局函数正在访问" << building->m_BedRoom << endl;
}

Building::Building()
{
    m_SittingRoom = "SittingRoom";
    m_BedRoom = "BedRoom";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main(){
    test01();

    system("pause");
    return 0;
}  