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
    cout << s1.size() << endl;
    set<int> s2;
    s2.insert(49);
    s2.insert(39);
    s2.insert(29);
    printSet(s2);
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
    set<int> s3;
    cout << s3.empty() << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}