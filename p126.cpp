// 函数调用运算符重载
#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("hello"); // 仿函数
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
    // 匿名函数对象
    cout << MyAdd()(100, 100) << endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}