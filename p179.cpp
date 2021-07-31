// 类模板与继承
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    // {
    //     this->m_Age = age;
    //     this->m_Name = name;
    // }
    void showPerson();
    // {
    //     cout << this->m_Name << this->m_Age << endl;
    // }

    T1 m_Name;
    T2 m_Age;
};

// 构造函数的类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Age = age;
    this->m_Name = name;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << this->m_Name << this->m_Age << endl;
}

int main(){
    Person<string, int> p("Tom", 18);
    p.showPerson();
    system("pause");
    return 0;
}