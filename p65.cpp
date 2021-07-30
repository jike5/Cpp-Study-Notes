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
    // Method One
    struct Student stuArray[3] = 
    {
        {"Sam", 18, 100},
        {"Bob", 19, 100},
        {"Jue", 20, 80}
    };
    // Method Two
    struct Student Array[3];
    Array[0].name = "Test";
    cout << "test's name:" << Array[0].name << endl;

    for (int i; i < 3; i++)
    {
        cout << "name:" << stuArray[i].name 
            << "age:" << stuArray[i].age << endl;
    }

    system("pause");
    return 0;
}