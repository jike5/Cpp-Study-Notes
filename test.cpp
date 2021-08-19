#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (auto p : v)
    {
        cout << p << endl;
    }
    system("pause");
    return 0;
}