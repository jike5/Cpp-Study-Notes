// 多态实例-计算器类
#include<iostream>
#include<string>
using namespace std;

// 普通实现
class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 * m_Num2;
        }
    }

    int m_Num1;
    int m_Num2;
};
// 多态实习
class AbstractCalcultor
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

class AddCalculator : public AbstractCalcultor
{
public:
    virtual int getResult()
    {
        return m_Num1 + m_Num2;
    }
};
// 多态实现
class SubCalculator : public AbstractCalcultor
{
public:
    virtual int getResult()
    {
        return m_Num1 - m_Num2;
    }
}; 

void test1()
{
    Calculator clt;

}
void test2()
{
    AbstractCalcultor * abc = new AddCalculator; //父类的指针或引用指向子类的对象
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
    delete abc; // 堆区释放后，abc变量还在
    // 减法
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
}
int main(){
    // test1();
    test2();
    system("pause");
    return 0;
}