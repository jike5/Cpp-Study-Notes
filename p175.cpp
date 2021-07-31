// 类模板与函数模板的区别
#include<iostream>
using namespace std;
// AgeType默认类型为int，后面可以不用显示指定Age的类型
template<class NameType, class AgeType = int>
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

int main(){
    // Age有默认类型，可以缺省
    Person<string>p("Tom", 18);
    p.showPerson();
    system("pause");
    return 0;
}