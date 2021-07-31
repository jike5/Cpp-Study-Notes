#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string s1;
    const char * str = "hello world";
    string s2(str);
    cout << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(10, 'a');
    cout << s4 << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}