// 构造函数调用规则
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
    Person(int a) // 有参构造
    {
        age = a;
        cout << "Person有参构造函数" << endl;
    }
    // 拷贝构造函数
    // Person(const Person &p)
    // {
    //     age = p.age;
    //     cout << "Person拷贝构造函数" << endl;
    // }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }

    int age;
};

void test1()
{
    Person p;
    p.age = 18;
    Person p2(p);
    cout << p2.age << endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}  