// 多继承
#include<iostream>
using namespace std;

class Base1
{
public:
    Base1() : m_A(100)
    {

    }
    int m_A;
};
class Base2
{
public:
    Base2() : m_A(200)
    {

    }
    int m_A; 
};
class Son : public Base1, public Base2
{
public:
    Son() : m_C(10), m_D(10)
    {

    }
    int m_C;
    int m_D;
};
void test1()
{
    Son s;
    cout << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}