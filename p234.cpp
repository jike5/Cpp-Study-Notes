#include<map>
#include<iostream>
#include<string>
using namespace std;

void printMap(map<int, int> & m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second <<endl;
    }
    cout << endl;
}

void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end())
    {
        cout << pos->first << " : " << pos->second << endl;
    }
    cout << m.count(3) << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}