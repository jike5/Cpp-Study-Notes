// 类做友元
#include<iostream>
#include<string>
using namespace std;

class Building
{
    // 类做友元
    friend class GoodGay;
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

class GoodGay
{
public:
    void visit();
    GoodGay();
    Building * building;
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