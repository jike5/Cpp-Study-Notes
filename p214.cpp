#include<iostream>
#include<queue>
#include<string>

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

void test1()
{
    queue<Person> q;
    Person p1("Tom", 18);
    Person p2("Bob", 19);
    q.push(p1);
    q.push(p2);
    while(!q.empty())
    {
        cout << "front: " << q.front().m_Name << q.front().m_Age << endl;
        cout << "back: " << q.back().m_Name << q.back().m_Age << endl;
        q.pop();
    }
    cout << q.size() << endl;
}

int main()
{
    test1();
    return 0;
}