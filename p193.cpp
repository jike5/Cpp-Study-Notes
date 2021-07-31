#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    string str1 = "xello";
    string str2 = "hello";
    if (str1.compare(str2) == 0)
    {
        cout << "equal" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 > srt2" << endl;
    }
}

int main(){
    test1();
    system("pause");
    return 0;
}