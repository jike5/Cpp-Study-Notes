// 常函数
#include<iostream>
using namespace std;

class Person
{
public:
    // 常函数
    // const Person * const this;
    void showPerson() const
    {
        this->m_B = 100;
    }

    int m_A;
    mutable int m_B; // 特殊变量，常函数可以修改
};

void test1()
{
    Person p;
    p.showPerson();
    cout << p.m_B << endl;
}

void test2()
{
    const Person p; // 常对象
    p.m_B = 100;
}

int main(){
    test1();
    system("pause");
    return 0;
}  