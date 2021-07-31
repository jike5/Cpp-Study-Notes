// 文本文件写文件
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream ofs;
    ofs.open("test143.txt",ios::out);
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs.close();
    system("pause");
    return 0;
}
