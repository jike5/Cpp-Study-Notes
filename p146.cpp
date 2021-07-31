// 二进制 读文件
#include<iostream>
#include<fstream>
using namespace std;

class Person
{
public:
    char m_Name[64]; // string会有问题，使用char
    int m_Age;
};

void test1()
{
    ifstream ifs;
    ifs.open("person145.txt", ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout << "Failed" << endl;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person)); // 转成const char * 形式
    cout << p.m_Name << p.m_Age << endl;
    ifs.close();
}

int main(){
    test1();
    system("pause");
    return 0;
}