// 虚析构和纯虚析构
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
    string * m_Name;
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat speak" << endl;
    }
    Cat(string name)
    {
        m_Name = new string(name);
    }
};

void test1()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
}

int main(){
    test1();
    system("pause");
    return 0;
}