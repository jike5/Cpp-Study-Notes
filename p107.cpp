// 构造函数的分类和调用
#include<iostream>
using namespace std;

class Person
{
public:
    // 构造函数
    Person() // 无参构造、默认构造
    {
        cout << "Person构造函数" << endl;
    }
    Person(int a) // 有参构造
    {
        age = a;
        cout << "Person构造函数" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "Person构造函数" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }

    int age;
};



int main(){
    // Person p1;
    // 调用
    // 1. 括号法
    // Person p1; // 默认构造函数时不加'()', Person p1() 编译器认为是一个函数声明
    // Person p2(10); // 括号法调用有参构造函数
    // Person p3(p2);
    // 2. 显示法
    Person p1;
    Person p2 = Person(10); // 有参
    Person p3 = Person(p2); // 拷贝

    Person(10); // 匿名对象，当前行执行结束后会回收匿名对象
    // 不要用拷贝构造函数初始化匿名对象
    // Person(p3); // 此句话等价为 Person p3, 即变为对象的声明

    //3. 隐式法
    Person p4 = 10; // 相当于Person p4 = Person(10)
    Person p5 = p3;

    system("pause");
    return 0;
}  