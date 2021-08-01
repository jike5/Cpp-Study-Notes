#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

void printList(const list<int> & L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    if (L1.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << L1.size() << endl;
    }
    L1.resize(10);
    printList(L1);
    L1.resize(15, 1000);
    printList(L1);
    L1.resize(2);
    printList(L1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}