// ��Ա��������Ԫ
#include<iostream>
#include<string>
using namespace std;

class Building;

class GoodGay
{
public:
    void visit();
    GoodGay();
    Building* building;
};

class Building
{
    // ����Ԫs
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
    cout << "ȫ�ֺ������ڷ���" << building->m_SittingRoom << endl;
    cout << "ȫ�ֺ������ڷ���" << building->m_BedRoom << endl;
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

int main() {
    test01();

    system("pause");
    return 0;
}