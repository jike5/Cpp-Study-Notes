// 继承方式
#include<iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 : public Base1
{
    public:
    void func()
    {
        m_A = 1;
        m_B = 1;
        m_C = 1;
    }
};

int main(){
    
    system("pause");
    return 0;
}