#include<iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
public:
    int m_r;
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main(){
    Circle cl;
    cl.m_r = 10;

    system("pause");
    return 0;
}  