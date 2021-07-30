// 初始化列表
#include<iostream>
using namespace std;

class Person
{
public:
    // 构造函数
    // Person():m_a(10), m_b(20), m_c(30)
    // {
    //     cout << "Person默认构造函数" << endl;
    // }
    Person(int a, int b, int c) : m_a(a), m_b(b), m_c(c)
    {
        cout << "Person默认构造函数" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }

    int m_a;
    int m_b;
    int m_c;
};

int main(){
    Person p(10, 20, 30);
    cout << p.m_a << endl;
    system("pause");
    return 0;
}  