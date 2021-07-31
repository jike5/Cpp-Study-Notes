// 函数模板
#include<iostream>
using namespace std;

template<typename T> // 告述编译器后面紧跟的代码中T不要报错
void mySwap(T & a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;
    int b = 20;
    // 1.自动类型推导
    mySwap(a, b);
    cout << a << b << endl;
    // 2. 显示指定
    mySwap<int>(a, b);
    cout << a << b << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}