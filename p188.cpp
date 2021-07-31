#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    vector<vector<int>>v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i= 0; i < 3; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
        v3.push_back(i+2);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) //(*it)是还是一个容器
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " " ;
        }
        cout << endl;
    }
}

int main(){
    test1();
    system("pause");
    return 0;
}