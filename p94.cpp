#include<iostream>
using namespace std;

void showValue(const int &val)
{
    cout << val << endl;
}

int main(){
    // int a = 10;
    // int &b = a;
    int a = 10;
    showValue(a);

    system("pause");
    return 0;
}  