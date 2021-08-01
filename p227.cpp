#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10);
    cout << ret.second << endl;
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    multiset<int> s2;
    s2.insert(30);
    s2.insert(30);
}

int main()
{
    test1();
    system("pause");
    return 0;
}