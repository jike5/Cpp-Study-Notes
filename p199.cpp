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
    if (v1.empty())
    {
        cout << "为空" << endl;
    }
    else 
    {
        cout << "不为空" << endl;
        cout << v1.capacity() << endl; // 容量
        cout << v1.size() << endl;
    }
    v1.resize(15); // 重新指定容量，默认用0填充
    printVector(v1);
    v1.resize(20, 100); 
    printVector(v1);
    v1.resize(5);
    printVector(v1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}