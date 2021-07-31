#include<iostream>
#include<string>
// 第一种 直接包含cpp文件，只包含头文件，编译器不会创建类模板成员函数，因此调用时会出错
//#include"Person.cpp"

// 第二种 将.h和.cpp写到一起，后缀为.hpp文件
#include"Person.hpp"
using namespace std;

int main()
{
	Person<string, int> p("Tom", 18);
	p.showPerson();

	system("pause");
	return 0;
}