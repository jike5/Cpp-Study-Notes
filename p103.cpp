// 成员属性私有化
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
private:
    string m_Name;
    int m_Age;
    string m_Lover;
};

int main(){
    Person p1;
    p1.setName("Bob");
    cout << p1.getName() << endl;

    system("pause");
    return 0;
}  