#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string str1;
    str1 = "hello world";
    string str2;
    str2 = str1;
    string str3;
    str3 = 'a';
    string str4;
    str4.assign("hello C++");
    string str5;
    str5.assign("hello", 3);
    string str6;
    str6.assign(str5);
    string str7;
    str7.assign(10, 'w');
}
int main(){
    test1();
    system("pause");
    return 0;
}