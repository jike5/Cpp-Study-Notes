#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "构造函数" << endl;
    }
public:
    ~Person()
    {
        cout << "析构函数" << endl;
    }

};

void test01()
{
    Person p1;
}

int main(){
    test01();

    system("pause");
    return 0;
}  