#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string s1 = "ssfherh";
    cout << s1[0] << endl;
    cout << s1.at(0) << endl;
    s1[0] = 'k';
    cout << s1[0] << endl;
    s1.at(0) = 'g';
    cout << s1.at(0) << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}