// 继承同名成员处理方式
#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base" << endl;
    }
    void func(int a)
    {
        cout << "Base int" << endl;
    }
    int m_A;
};
class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son" << endl;
    }
    int m_A;
};
void test01()
{
    Son s;
    cout << s.m_A << endl; // 子类中m_A
    cout << s.Base::m_A << endl; // 父类中
    s.func();
    s.Base::func();
    s.Base::func(10);
}
int main(){
    test01();
    system("pause");
    return 0;
}