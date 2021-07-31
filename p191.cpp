#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string str1 = "hello";
    str1 += " world";
    str1 += ';';
    cout << str1 << endl;
    string str2 = "hhh";
    str1 += str2;
    cout << str1 << endl;
    string str3 = "I";
    str3.append(" love");
    cout << str3 << endl;
    str3.append("game abcd", 3);
    cout << str3 << endl;
    str3.append(str2);
    cout << str3 << endl;
    str3.append(str2, 0, 1); // 从0开始（包括0）截1个
    cout << str3 << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}