#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string s1 = "ssfherh";
    s1.insert(1, "hello");
    cout << s1 << endl;
    string s2 = "world";
    s1.insert(7, s2);
    cout << s1 << endl;
    s1.insert(0, 3, 'a');
    cout << s1 << endl;
    s1.erase(0, 3);
    cout << s1 << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}