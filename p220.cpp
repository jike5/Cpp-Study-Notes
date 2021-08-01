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
    cout << L1.front() << endl;
    cout << L1.back() << endl;

}

int main()
{
    test1();
    system("pause");
    return 0;
}