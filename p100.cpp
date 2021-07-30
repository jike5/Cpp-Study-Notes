#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    string name;
    string ID;

    void showName()
    {
        cout << name << endl;
    }
    void showID()
    {
        cout << ID << endl;
    }
    void setName(string n)
    {
        name = n;
    }
};

int main()
{
    Student Bob;
    Bob.name = "Bob";
    Bob.ID = "183";
    Bob.setName("bob");
    Bob.showID();
    Bob.showName();
    
    system("pause");
    return 0;
}