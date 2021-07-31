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
    // 预留空间
    v1.reserve(10000);
    int num = 0;
    int * p = NULL;
    for (int i = 0; i < 10000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "Num = " << num << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}