// 开辟堆区数据
#include<iostream>
using namespace std;

int * func()
{
    int * p = new int(10);
    return p;
}

int main(){
    int * p = func();
    cout << *p << endl;

    system("pause");
    return 0;
}  