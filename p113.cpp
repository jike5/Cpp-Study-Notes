// 静态成员
#include<iostream>
using namespace std;

class Person
{
public:
    static int m_A;  // 类内声明

    static void func()
    {
        m_A = 1000;
        cout << "static void func调用" << endl;
    }

private:
    static int m_B;
};

int Person::m_A = 100; // 类外初始化
int Person::m_B = 100; // 类外初始化


// 访问：1、通过对象进行访问； 2、通过类名进行访问
void test02()
{
    cout << Person::m_A << endl; // 通过类名访问
    Person::func();
}
// 访问权限


int main(){
    Person p;
    p.m_A = 200;
    cout << p.m_A << endl;
    p.func();
    test02();

    system("pause");
    return 0;
}  