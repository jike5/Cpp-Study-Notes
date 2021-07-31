#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string s1 = "abcdeade";
    int pos = s1.find("df"); // 没有返回-1
    cout << pos << endl; 

    // rfind
    pos = s1.rfind("de");
    cout << pos << endl;
}

void test2()
{
    string s1 = "abcde";
    s1.replace(1, 3, "1111");
    cout << s1 << endl;
}

int main(){
    test1();
    test2();
    system("pause");
    return 0;
}