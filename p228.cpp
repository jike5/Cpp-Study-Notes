#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
    pair<string, int> p("Tom", 18);
    cout << p.first << p.second << endl;
    pair<string, int> p1 = make_pair("Bob", 19);
    cout << p1.first << p1.second << endl;
    system("pause");
    return 0;
}