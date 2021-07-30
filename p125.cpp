// 关系运算符重载
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    Person(string name, int age) : m_Name(name), m_Age(age)
    {

    }
    bool operator==(Person & p)
    {
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return true;
        }
        return false;
    }
    bool operator!=(Person & p)
    {
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return false;
        }
        return true;
    }

    string m_Name;
    int m_Age;
};

void test1()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2)
    {
        cout << "=" << endl;
    }
    else
    {
        cout << "!=" << endl;
    }
    if (p1 != p2)
    {
        cout << "!=" << endl;
    }

}
int main(){
    test1();
    system("pause");
    return 0;
}