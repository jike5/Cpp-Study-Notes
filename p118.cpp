// 全局函数做友元
#include<iostream>
#include<string>
using namespace std;

class Building
{
    friend void goodGay(Building *building);
public:
    Building()
    {
        m_SittingRoom = "SittingRoom";
        m_BedRoom = "BedRoom";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

// 全局函数
void goodGay(Building *building)
{
    cout << "全局函数正在访问" << building->m_SittingRoom << endl;
    cout << "全局函数正在访问" << building->m_BedRoom << endl;
}

void test1()
{
    Building building;
    goodGay(&building);
}

int main(){
    test1();

    system("pause");
    return 0;
}  