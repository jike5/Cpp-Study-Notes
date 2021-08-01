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

bool myCompare(int v1, int v2)
{
    return v1 > v2;
}

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(60);
    L1.push_back(30);
    L1.push_back(50);
    printList(L1);
    L1.sort(); // 默认升序
    printList(L1);
    L1.sort(myCompare); // 降序操作
    printList(L1);

    L1.reverse();
    printList(L1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}