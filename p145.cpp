// 二进制 写文件
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
    ofstream ofs;
    ofs.open("person145.txt", ios::out | ios::binary);
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person)); // 转成const char * 形式
    ofs.close();
}

int main(){
    test1();
    system("pause");
    return 0;
}