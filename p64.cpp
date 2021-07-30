// 结构体的定义和使用

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
    // 定义变量时 struct 可以省略
    struct Student Bod;
    Bod.age = 10;
    Student Sam;
    Sam.name = "Sam";
    cout << Bod.age << Sam.name << endl;

    system("pause");
    return 0;
}