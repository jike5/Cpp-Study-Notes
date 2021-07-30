// 继承中同名静态成员处理
#include<iostream>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base" << endl;
    }
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Son" << endl;
    }
};

int Son::m_A = 200;

void test1()
{
    Son s;
    // 通过对象
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    // 通过类名
    cout << Son::m_A << endl;
    cout << Son::Base::m_A << endl;
    // 静态成员函数
    // 通过对象
    s.func();
    s.Base::func();
    // 通过类名
    Son::func();
    Son::Base::func();
}
int main(){
    test1();
    system("pause");
    return 0;
}