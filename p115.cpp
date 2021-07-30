// this指针
#include<iostream>
using namespace std;

class Person
{
public:
    Person (int age)
    {
        this->age = age;
    }
    Person & PersonAddAge(Person &p)
    {
        this->age += p.age;
        return *this;
    }
    int age;
};

void test1()
{
    Person p(10);
    cout << p.age << endl;
}
void test2()
{
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1).PersonAddAge(p1);
    cout << p2.age << endl;
}
int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}  