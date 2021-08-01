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
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    multiset<int> s2;
    s2.insert(30);
    s2.insert(30);
    s2.insert(10);
    cout << s2.count(30) << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}