#include<iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main(){
    Student s = {"Bob", 18, 100};
    Student * p = &s;
    cout << "test's name:" << p->name << endl;

    system("pause");
    return 0;
}