// 读文件
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream ifs;
    ifs.open("test143.txt",ios::in);
    if(!ifs.is_open())
    {
        cout << "Failed" << endl;
        return 0;
    }
    char buf1[1024] = {0};
    // 第一种
    while(ifs >> buf1)
    {
        cout << buf1 << endl;
    }
    // 第二章
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    }
    // 第三种
    string buf3;
    while(getline(ifs, buf3))
    {
        cout << buf3 << endl;
    }
    // 第四种 效率低
    char c;
    while ((c = ifs.get()) != EOF ) // EOF End of File
    {
        cout << c;
    }

    ifs.close();
    system("pause");
    return 0;
}