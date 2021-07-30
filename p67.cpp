// 结构体嵌套结构体
#include<iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

void printStudents(Student * p)
{
    cout << "name:" << p->name << "age" << p->age << endl;
}

int main(){
    Student s = {"Bob", 18, 100};
    Student * p = &s;
    cout << "test's name:" << p->name << endl;

    system("pause");
    return 0;
}