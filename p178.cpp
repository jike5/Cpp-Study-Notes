// 类模板与继承
#include<iostream>
using namespace std;

template<class T>
class Base
{
public:
    T m;
};
// 1. 指定类型
class Son1 : public Base<int>
{

};
// 2. 子类也作为模板
template<class T, class T2>
class Son2 : public Base<T>
{
    T2 obj;
};

int main(){
    Son1 s1;
    Son2<int, int> s2;
    system("pause");
    return 0;
}