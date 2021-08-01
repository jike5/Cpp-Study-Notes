#include<stack>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void test1()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.size() << endl;;
}

int main()
{
    test1();
    system("pause");
    return 0;
}