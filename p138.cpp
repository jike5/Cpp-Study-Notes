// 纯虚函数
#include<iostream>
using namespace std;

class Base
{
public:
    // 纯虚函数
    virtual void func() = 0;
};

class Son : public Base
{
public:
    void func()
    {
        cout << "func" << endl;
    }
};

void test1()
{
    Base * b = new(Son);
    b->func();
}

int main(){
    test1();
    system("pause");
    return 0;
}