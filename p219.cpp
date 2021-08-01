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
    L1.push_front(100);
    L1.push_front(200);
    printList(L1);
    L1.pop_front();
    printList(L1);
    L1.insert(++L1.begin(), 1000); // ++L1.begin()
    printList(L1);
    L1.erase(L1.begin());
    printList(L1);
    L1.push_back(1000);
    L1.remove(1000);
    printList(L1);
    L1.clear();
    printList(L1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}