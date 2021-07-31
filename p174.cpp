// 类模板语法
#include<iostream>

using namespace std;

template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_Age = age;
        m_Name = name;
    }
    void showPerson()
    {
        cout << m_Name << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test1()
{
    Person<string, int> p1("Tom", 18);
    p1.showPerson();
}

int main(){
    test1();
    system("pause");
    return 0;
}