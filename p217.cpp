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
    list<int> L2;
    L2 = L1;
    printList(L2);
    list<int> L3;
    L3.assign(L1.begin(), L1.end());
    printList(L3);
    list<int> L4;
    L4.assign(10, 1000);
    printList(L4);
    L1.swap(L4);
    printList(L1);
    printList(L4);
}

int main()
{
    test1();
    system("pause");
    return 0;
}