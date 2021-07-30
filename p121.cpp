// 加号运算符重载
#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a, int b) : m_A(a), m_B(b)
    { }
    Person(){ }
    int m_A;
    int m_B;
    // // 成员函数实现运算符重载
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A;
    //     temp.m_B = this->m_B + p.m_B;
    //     return temp;
    // }
    
};

Person operator+(Person & p1, Person & p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

void test1()
{
    Person p1(10, 10);
    Person p2(10, 10);
    Person p3 = p1 + p2;
    cout << "m_A = " <<p3.m_A << endl << "m_B = " << p3.m_B << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}  