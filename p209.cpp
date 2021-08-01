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
        d1.push_back(10 - i);
    }
    printDeque(d1);
    sort(d1.begin(), d1.end());
    printDeque(d1);
}

int main(){
    test1();
    system("pause");
    return 0;
}