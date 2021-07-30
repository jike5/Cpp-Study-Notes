// 函数重载的注意事项
#include<iostream>
using namespace std;

// 1. 
void func(int &a)
{
    cout << "func(int &a)" << endl;
}

void func(const int &a)
{
    cout << "func(const int &a)" << endl;
}

// 函数重载遇到默认参数
void func2(int a, int b = 10)
{
    cout << "func(const int &a)" << endl;
}

void func2(int a)
{
    cout << "func(const int &a)" << endl;
}

int main(){
    // int a = 10;
    // func(a);
    // func(10);

    // func2(10); // 函数重载遇到默认参数会出现二义性，尽量避免

    system("pause");
    return 0;
}  