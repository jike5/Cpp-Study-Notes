#include<map>
#include<iostream>
#include<string>
using namespace std;
class MyCompare
{
    public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(make_pair(4, 40));
    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second <<endl;
    }
    cout << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}