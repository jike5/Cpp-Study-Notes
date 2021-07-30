// 深拷贝与浅拷贝
#include<iostream>
using namespace std;

class Person
{
public:
    // 构造函数
    Person() // 无参构造、默认构造
    {
        cout << "Person默认构造函数" << endl;
    }
    Person(int a, int height) // 有参构造
    {
        age = a;
        m_Height = new int(height);
        cout << "Person有参构造函数" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        // 深拷贝
        m_Height = new int(*p.m_Height);
        
        cout << "Person拷贝构造函数" << endl;
    }

    ~Person()
    {
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person析构函数" << endl;
    }

    int age;
    int * m_Height;
};

void test1()
{
    Person p(18, 160);
    cout << "p1身高" << *p.m_Height << endl;
    Person p2(p);
    cout << p2.age << endl;
    cout << "p2身高" << *p2.m_Height << endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}  