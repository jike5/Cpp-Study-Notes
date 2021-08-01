#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

class Person
{
    public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class MyCompare
{
    public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age; // 按年龄降序
    }
};
void test1()
{
    set<Person, MyCompare> s;
    Person p1("Tom", 19);
    Person p2("Bob", 20);
    Person p3("Mary", 15);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->m_Name << it->m_Age << endl;
    }
}

int main(){
    test1();
    system("pause");
    return 0;
}