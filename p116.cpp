// 空指针访问成员函数
#include<iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout << "Person" << endl;
    }
    void showPersonAge()
    {
        cout << "Age" << m_Age << endl;
    }
    int m_Age;
};

void test1()
{
    Person * p = NULL;
    p->showClassName();
    // p->showPersonAge();

}
int main(){
    test1();

    system("pause");
    return 0;
}  