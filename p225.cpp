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
    s1.erase(30);
    printSet(s1);
    s1.erase(s1.begin());
    printSet(s1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}