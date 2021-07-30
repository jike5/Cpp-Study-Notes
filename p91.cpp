// 引用做函数参数
#include<iostream>
using namespace std;

void mySawp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 9;
    mySawp(a, b);
    cout << "a=" << a << endl;

    system("pause");
    return 0;
}  