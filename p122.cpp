//使用全局函数实现
#include<iostream>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream & cout, Person &p);
public:
	Person(int a, int b):m_A(a), m_B(b){ }    
private:
    int m_A;
    int m_B;
};

ostream & operator<<(ostream & cout, Person &p)
{
    cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
    return cout;
}

void test1()
{
    Person p(10, 10);
    cout << p << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}  