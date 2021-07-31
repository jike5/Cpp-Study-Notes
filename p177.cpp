// 类模板对象做函数参数
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person (T1 name , T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void showPerson()
    {
        cout << m_Name << m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};
// 1. 指定传入类型
void printPerson1(Person<string, int>&p)
{
    p.showPerson();
}
// 2. 参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
    p.showPerson();
    cout << typeid(T1).name() << endl; // 查看类型
    cout << typeid(T2).name() << endl;
}
// 3. 整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
     cout << typeid(T).name() << endl;
}
void test1()
{
    Person<string, int>p("Tom", 18);
    printPerson1(p);
    printPerson2(p);
    printPerson3(p);
}

int main(){
    test1();
    system("pause");
    return 0;
}