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
    map<int, int>m2(m);
    printMap(m2);
    map<int, int>m3;
    m3 = m;
    printMap(m3);
}

int main()
{
    test1();
    system("pause");
    return 0;
}