#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

class MyCompare
{
    public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(60);
    s.insert(40);
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    set<int, MyCompare>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(60);
    s2.insert(40);
    for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
}

int main(){
    test1();
    system("pause");
    return 0;
}