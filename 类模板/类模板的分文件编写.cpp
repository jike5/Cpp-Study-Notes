#include<iostream>
#include<string>
// ��һ�� ֱ�Ӱ���cpp�ļ���ֻ����ͷ�ļ������������ᴴ����ģ���Ա��������˵���ʱ�����
//#include"Person.cpp"

// �ڶ��� ��.h��.cppд��һ�𣬺�׺Ϊ.hpp�ļ�
#include"Person.hpp"
using namespace std;

int main()
{
	Person<string, int> p("Tom", 18);
	p.showPerson();

	system("pause");
	return 0;
}