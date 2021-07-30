#include<iostream>
using namespace std;

// 返回局部变量的引用
/* int & test01()
{
    int a = 10;
    return a;
}
*/

int & test02()
{
    static int a = 10;
    return a;
}
int main(){
    // int & ref = test01();
    // cout << "ref = " << ref << endl;

    int & ref2 = test02();
    cout << "ref2=" << ref2 << endl;
    // 函数调用作为左值
    test02() = 1000;
    cout << "ref2=" << ref2 << endl;

    system("pause");
    return 0;
}  