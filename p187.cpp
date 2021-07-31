// vector 存放自定义数据类型
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person
{
public:
Person(string name, int age)
{
    this->m_Age = age;
    this->m_Name = name;
}
    string m_Name;
    int m_Age;
};

void test1()
{
    vector<Person> v;
    Person p1("Tom", 20);
    Person p2("Tom", 20);
    Person p3("Tom", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << (*it).m_Age << endl;
        cout << it->m_Name << it->m_Age << endl;
    }
}

void test2()
{
    vector<Person*> v;
    Person p1("Tom", 20);
    Person p2("Tom", 20);
    Person p3("Tom", 20);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_Name << (*it)->m_Age << endl;
    }
}

int main(){
    test1();
    test2();
    system("pause");
    return 0;
}