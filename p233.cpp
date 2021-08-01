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
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m[5] = 50; // 不建议去插入，可以用key去访问
    cout << m[6] << endl; // 此时会创建一个(6, 0)
    printMap(m);
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
}

int main()
{
    test1();
    system("pause");
    return 0;
}