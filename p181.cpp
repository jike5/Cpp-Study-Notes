#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
    friend void showPerson(Person<T1, T2> &p)
    {
        cout << p.m_Name << p.m_Age << endl;
    }
public:
    Person(T1 name, T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

private:
    T1 m_Name;
    T2 m_Age;
};
void printPerson();
int main(){
    Person<string, int> p("Tom", 18);
    showPerson(p);
    system("pause");
    return 0;
}