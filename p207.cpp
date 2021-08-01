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
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

    d1.insert(d1.begin(), 1000);
    printDeque(d1);
    d1.insert(d1.begin(), 2, 1000);
    printDeque(d1);
    
}

int main(){
    test1();
    system("pause");
    return 0;
}