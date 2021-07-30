// 函数重载
#include<iostream>
using namespace std;

void func()
{
    cout << "hello" << endl;
}

void func(int a)
{
    cout << "hello int a" << endl;
}

void func(double a)
{
    cout << "hello double a" << endl;
}

int main(){
    func();
    func(10);
    func(3.14);

    system("pause");
    return 0;
}  