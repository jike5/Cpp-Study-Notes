#include<iostream>
#include<string>
using namespace std;

void test1()
{
    string s1 = "ssfherh";
    cout << s1 << endl;
    string s2 = s1.substr(0, 3);
    cout << s2 << endl;
    string s3 = s1.substr(1, 3);
    cout << s3 << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}