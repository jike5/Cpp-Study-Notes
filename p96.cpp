// 函数的占位参数
#include<iostream>
using namespace std;

void func(int a, int)
{
    cout << "hello" << endl;
}
int main(){
    func(10, 10);

    system("pause");
    return 0;
}  