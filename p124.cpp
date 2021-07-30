// 赋值运算符重载
#include<iostream>
using namespace std;
class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    // p2 = operator(p1); ==>  p2 = p1;
    Person & operator=(Person &p) // 输入引用
    {
        if(m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
        return * this;
    }
    int * m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(28);
    p3 = p2 = p1;
    cout << * p1.m_Age << endl;
    cout << * p2.m_Age << endl;
    cout << * p3.m_Age << endl;
}

int main(){
    test01();
    // 内置数据类型允许连续赋值
    int a = 10;
    int b = 10;
    int c = 10;
    cout << a << b << c << endl;

    system("pause");
    return 0;
}