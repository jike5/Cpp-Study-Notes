#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2;
    v2 = v1;
    printVector(v2);
    vector<int> v3;
    v3.assign(v1.begin(), v1.end()-1);
    printVector(v3);
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test1();
    system("pause");
    return 0;
}