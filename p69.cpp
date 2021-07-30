// 结构体中const使用场景
#include<iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

void printStudents(const Student * p)
{
    cout << "name:" << p->name << "age" << p->age << endl;
}

int main()
{
    Student s = {"Bob", 18, 100};
    Student * p = &s;
    cout << "test's name:" << p->name << endl;

    system("pause");
    return 0;
}