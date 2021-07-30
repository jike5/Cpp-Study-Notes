// 递增运算符重载实现
#include<iostream>
using namespace std;

class MyInterger
{
    friend ostream & operator<<(ostream & cout, MyInterger myint);
public:
    MyInterger()
    {
        m_num = 0;
    }
    // 重载前置++运算符
    MyInterger & operator++() // 返回引用防止拷贝
    {
        m_num ++;
        return *this;
    }
    // 重载后置++运算符
    // int占位参数，区分前置与后置；这里返回的是值，因此temp是一个局部变量，执行后会被释放
    MyInterger operator++(int)
    {
        // 先记录当前值
        MyInterger temp = *this;
        // 递增
        m_num ++; // 实际已经发生了递增，但是下面返回的是之前的
        // 返回记录结果
        return temp;
    }
private:
    int m_num;
};
// 这里myint没有加&是因为后置++时返回的拷贝的一个值，如果有& ，那么类似int &a=10 的错误，指向了非法空间
ostream & operator<<(ostream & cout, MyInterger myint) 
{
    cout << myint.m_num;
    return cout;
}

void test1()
{
    MyInterger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}
void test2()
{
    MyInterger myint2;
    cout << myint2++ << endl;
    cout << myint2 << endl;
}
int main(){
    test1();
    test2();
    system("pause");
    return 0;
}