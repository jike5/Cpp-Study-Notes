// vector初识
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // 
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器
    vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向v中元素的最后一个的下一个 位置
    // 遍历方式一
    while(itBegin != itEnd)
    {
        cout << * itBegin << endl;
        itBegin ++;
    }
    // 遍历方式二
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << * it << endl;
    }
    // 第三种 使用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);

}

int main()
{
    test01();
    system("pause");
    return 0;
}