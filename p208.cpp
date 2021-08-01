#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    cout << d1[1] << endl;
    cout << d1.at(2) << endl;
    cout << d1.front() << d1.back() << endl;
}

int main(){
    test1();
    system("pause");
    return 0;
}