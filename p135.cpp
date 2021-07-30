// 多态
#include<iostream>
using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "Animal" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat" << endl;
    }
};
// 早绑定，在编译阶段确定执行Animal的doSpeak函数
void doSpeak(Animal & animal) // Animal & animal = Cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}

int main(){
    test01();
    system("pause");
    return 0;
}