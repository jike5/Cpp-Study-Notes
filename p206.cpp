#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
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
    if (d1.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << d1.size() << endl;
        cout << "不为空" << endl;
    }
    d1.resize(15);
    printDeque(d1);
    d1.resize(20, 100);
    printDeque(d1);
}

int main(){
    test1();
    system("pause");
    return 0;
}