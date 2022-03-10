# 笔记-C++模板、STL学习笔记

[toc]

# 1 模板

## 1.1 模板的概念



## 1.2 函数模板

### 1.2.1 函数模板语法

建立一个通用函数，其函数返回值和形参类型可以不具体指定

```C++
template<typename T>
函数声明或定义
```

template -- 声明创建模板

typename -- 表面其后的符号是一种函数类型

```C++
template<typename T> // 告述编译器后面紧跟的代码中T不要报错
void mySwap(T & a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;
    int b = 20;
    // 1.自动类型推导
    mySwap(a, b);
    cout << a << b << endl;
    // 2. 显示指定
    mySwap<int>(a, b);
    cout << a << b << endl;
}
```

### 1.2.2 函数模板注意事项

* 自动推导，必须推导出一致的数据类型T才能使用
* 模板必须确定出T的数据类型才能使用

### 1.2.3 函数模板案例-数组排序

```C++
template<class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 
        for (int j = i+1; j<len;j++)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            T temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;

        }
    }
}
// 打印函数的模板
template<class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test1()
{
    char charArr[] = "bcefa";
    int len = sizeof(charArr) / sizeof(charArr[0]);
    mySort(charArr, len);
    printArray(charArr, len);

    int intArr[]={1,3,2,4,5,7,5};
    int num = sizeof(intArr) / sizeof(intArr[0]);
    mySort(intArr, len);
    printArray(intArr, len);
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

### 1.2.4 普通函数与函数模板的区别

普通函数会发生隐式类型转换

函数模板 用显示类型指定也可以发生隐式类型转换

### 1.2.5 普通函数与函数模板的调用规则

* 函数模板和普通函数都可以调用（同名函数），优先调用普通函数
* 可以通过空模板参数列表 强制调用 函数模板  `函数名<>(函数参数列表)`
* 函数模板可以发生函数重载
* 如果函数模板 有更好的匹配，会优先使用函数模板

### 1.2.6 模板的局限性



## 1.3 类模板

### 1.3.1 类模板语法

建立一个通用类，类中的成员  数据类型 可以不具体指定，用一个 虚拟的类型来代表

语法：

```C++
template<typename T>
类
```

```C++
template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_Age = age;
        m_Name = name;
    }
    void showPerson()
    {
        cout << m_Name << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test1()
{
    Person<string, int> p1("Tom", 18);
    p1.showPerson();
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

### 1.3.2 类模板与函数模板区别

1. 类模板没有自动类型推导的使用方式 
2. 类模板在模板参数列表中可以有默认参数

```C++
// AgeType默认类型为int，后面可以不用显示指定Age的类型
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_Age = age;
        m_Name = name;
    }
    void showPerson()
    {
        cout << m_Name << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
}; 

int main(){
    // Age有默认类型，可以缺省
    Person<string>p("Tom", 18);
    p.showPerson();
    system("pause");
    return 0;
}
```

### 1.3.3 类模板中成员函数创建时机

* 类模板中成员函数在调用时才去创建。因为一开始无法确定数据类型

### 1.3.4 类模板对象做函数参数

1. 指定传入的类型 -- 直接显示对象的数据类型
2. 参数模板化 -- 将对象中的参数变为模板进行传递
3. 整个类模板化 -- 将这个对象类型 模板化进行传递

```C++
template<class T1, class T2>
class Person
{
public:
    Person (T1 name , T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void showPerson()
    {
        cout << m_Name << m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};
// 1. 指定传入类型
void printPerson1(Person<string, int>&p)
{
    p.showPerson();
}
// 2. 参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
    p.showPerson();
    cout << typeid(T1).name() << endl; // 查看类型
    cout << typeid(T2).name() << endl;
}
// 3. 整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
     cout << typeid(T).name() << endl;
}
void test1()
{
    Person<string, int>p("Tom", 18);
    printPerson1(p);
    printPerson2(p);
    printPerson3(p);
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

* 使用比较广泛的是第一种

### 1.3.5 类模板与继承

* 当子类继承的父类是一个类模板时，子类在声明时，要指定出父类中T的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中T的类型，子类也需要变为类模板

```C++
template<class T>
class Base
{
public:
    T m;
};
// 1. 指定类型
class Son1 : public Base<int>
{

};
// 2. 子类也作为模板
template<class T, class T2>
class Son2 : public Base<T>
{
    T2 obj;
};

int main(){
    Son1 s1;
    Son2<int, int> s2;
    system("pause");
    return 0;
}
```

###  1.3.6 类模板成员函数类外实现

类模板中成员函数类外 实现时，需要加上模板参数列表

```C++
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    // {
    //     this->m_Age = age;
    //     this->m_Name = name;
    // }
    void showPerson();
    // {
    //     cout << this->m_Name << this->m_Age << endl;
    // }

    T1 m_Name;
    T2 m_Age;
};

// 构造函数的类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Age = age;
    this->m_Name = name;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << this->m_Name << this->m_Age << endl;
}

int main(){
    Person<string, int> p("Tom", 18);
    p.showPerson();
    system("pause");
    return 0;
}
```

### 1.3.7 类模板分文件编写

```C++
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
```

`Person.hpp`

```C++
#pragma once
#include<iostream>
using namespace std;
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Age = age;
	this->m_Name = name;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << this->m_Name << this->m_Age << endl;
}
```

### 1.3.8 类模板与友元

全局函数类内实现 - 直接在类内声明友元

全局函数类外实现 - 需要提前让编译器知道全局函数的存在

```C++
#include <string>

//2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2>
class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2> & p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1、全局函数配合友元   类内实现
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}


	//全局函数配合友元  类外实现
	friend void printPerson2<>(Person<T1, T2> & p);

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;

};

//1、全局函数在类内实现
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}


//2、全局函数在类外实现
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}

```

* 建议使用全局函数类内实现

### 1.3.9 类模板实例-数组类封装



# 2 STL认识

## 2.1 STL的诞生

## 2.2 STL基本概念

* STL(Standard Template Library)
* STL广义上分为：**容器(container) 算法(algorithm) 迭代器(iterator)**
* 容器和算法之间通过迭代器无缝衔接
* STL几乎所有的代码都采用了模板类或模板函数

## 2.3 STL六大组件

包含：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

1. 容器：各种数据结构，vector, list, deque, set, map
2. 算法：各种常用算法, sort, find, copy, for_each
3. 迭代器：扮演了容器和算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或迭代接口的东西
6. 空间适配器：负责空间的配置与管理

## 2.4 STL中容器、算法、迭代器

**容器**

常用的数据结构有：数组、链表、树、栈、队列、集合、映射表等

这些容器分为 **序列式容器**和 **关联式容器**：

​	**序列式容器**：强调值的排序，序列式容器中的每个元素均有固定的位置

​	**关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系

**算法**

有限的步骤，解决逻辑或数学上的问题

算法分为 **质变算法**和 **非质变算法**

​	质变算法：运算过程中回更改区间的元素的内容，如拷贝、替换、删除等

​	非质变算法：运算中不会更改区间的元素内容，例如查找、计数、遍历、寻找极值

**迭代器**

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式

每个容器都有自己的专属的迭代器

迭代器类似指针

​	种类：

| 种类               | 功能                                                     | 支持运算                                |
| ------------------ | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器         | 对数据的只读访问                                         | 只读，支持++、++、！=                   |
| 输出迭代器         | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器         | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！=                   |
| **双向迭代器**     | 读写操作，并能向前和向后操作                             | 读写，支持++、--                        |
| **随机访问迭代器** | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器

## 2.5 容器、算法、迭代器初识

### 2.5.1 vector存放内置数据类型

容器：`vector`

算法：`for_each`

迭代器：`vector<int>::iterator`

```C++
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
```

### 2.5.2 vector存放自定义数据类型

```C++
class Person
{
public:
Person(string name, int age)
{
    this->m_Age = age;
    this->m_Name = name;
}
    string m_Name;
    int m_Age;
};

void test1()
{
    vector<Person> v;
    Person p1("Tom", 20);
    Person p2("Tom", 20);
    Person p3("Tom", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << (*it).m_Age << endl;
        cout << it->m_Name << it->m_Age << endl;
    }
}

void test2()
{
    vector<Person*> v;
    Person p1("Tom", 20);
    Person p2("Tom", 20);
    Person p3("Tom", 20);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_Name << (*it)->m_Age << endl;
    }
}

int main(){
    test1();
    test2();
    system("pause");
    return 0;
}
```

### 2.5.3 vector容器嵌套容器

```C++
void test1()
{
    vector<vector<int>>v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i= 0; i < 3; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
        v3.push_back(i+2);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) //(*it)是还是一个容器
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " " ;
        }
        cout << endl;
    }
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

# 3 STL-常用容器

## 3.1 string容器

### 3.1.1 string基本概念

**本质：**

* string本质是一个类

**string和char *的区别**

* char *是一个指针
* string是一个类，类内部封装了char*， 是一个char *型的容器

**特点**

string类内部封装了很多成员方法

string管理char *所分配的内存，不用担心复制越界和取值越界等

### 3.1.2 string构造函数

构造函数原型：

* `string();` // 创建一个空的字符串

  `string(const char* s); `  // 使用字符串s初始化

* `string(const string & str);` // 使用一个string对象初始化另一个string对象

* `string(int n, char c);`  // 使用n个字符c初始化

```C++
void test1()
{
    string s1;
    const char * str = "hello world";
    string s2(str);
    cout << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(10, 'a');
    cout << s4 << endl;
}
```

### 3.1.3 string赋值操作

赋值的函数原型：

* `string& operator=(const char* s);`
* `string& operator=(const string &s);`
* `string& operator=(char c);`
* `string& assign(const char *s);`
* `string& assign(const char *s, int n);` // 把字符串s的前n个字符赋值给当前的字符串
* `string& assign(const string &s);`
* `string& assign(int n, char c);`

```C++
void test1()
{
    string str1;
    str1 = "hello world";
    string str2;
    str2 = str1;
    string str3;
    str3 = 'a';
    string str4;
    str4.assign("hello C++");
    string str5;
    str5.assign("hello", 3);
    string str6;
    str6.assign(str5);
    string str7;
    str7.assign(10, 'w');
}
```

### 3.1.4string字符串拼接

- `string& operator+=(const char* str);` //重载+=操作符
- `string& operator+=(const char c);` //重载+=操作符
- `string& operator+=(const string& str);` //重载+=操作符
- `string& append(const char *s);` //把字符串s连接到当前字符串结尾
- `string& append(const char *s, int n);` //把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const string &s);` //同operator+=(const string& str)
- `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾

```C++
void test1()
{
    string str1 = "hello";
    str1 += " world";
    str1 += ';';
    cout << str1 << endl;
    string str2 = "hhh";
    str1 += str2;
    cout << str1 << endl;
    string str3 = "I";
    str3.append(" love");
    cout << str3 << endl;
    str3.append("game abcd", 3);
    cout << str3 << endl;
    str3.append(str2);
    cout << str3 << endl;
    str3.append(str2, 0, 1); // 从0开始（包括0）截1个
    cout << str3 << endl;
}
```



### 3.1.5 string查找和替换

- `int find(const string& str, int pos = 0) const;` //查找str第一次出现位置,从pos开始查找，返回所在位置的索引。没有的话返回-1；
- `int find(const char* s, int pos = 0) const;` //查找s第一次出现位置,从pos开始查找
- `int find(const char* s, int pos, int n) const;` //从pos位置查找s的前n个字符第一次位置
- `int find(const char c, int pos = 0) const;` //查找字符c第一次出现位置
- `int rfind(const string& str, int pos = npos) const;` //查找str最后一次位置,从pos开始查找
- `int rfind(const char* s, int pos = npos) const;` //查找s最后一次出现位置,从pos开始查找
- `int rfind(const char* s, int pos, int n) const;` //从pos查找s的前n个字符最后一次位置
- `int rfind(const char c, int pos = 0) const;` //查找字符c最后一次出现位置
- `string& replace(int pos, int n, const string& str);` //替换从pos开始n个字符为字符串str，无论str是多少个字符，都会替代掉原来的n个字符。例如n=3时，str有4个字符，那么替换后string的字符个数增加1
- `string& replace(int pos, int n,const char* s);` //替换从pos开始的n个字符为字符串s

**find与rfind区别**：find是从左开始往右查找，rfind是从右往左查找，对于字符串可能首尾都有欲查找的，rfind和find结果会不一样。

```C++
void test1()
{
    string s1 = "abcdeade";
    int pos = s1.find("df"); // 没有返回-1
    cout << pos << endl; 

    // rfind
    pos = s1.rfind("de");
    cout << pos << endl;
}

void test2()
{
    string s1 = "abcde";
    s1.replace(1, 3, "1111");
    cout << s1 << endl;
}

int main(){
    test1();
    test2();
    system("pause");
    return 0;
}
```

### 3.1 6 字符串的比较

比较方式：

* 按字符的ASCII码进行比对

  = 返回 0 ；> 返回 1 ;  < 返回 -1 

**函数原型**

- `int compare(const string &s) const;` //与字符串s比较

- `int compare(const char *s) const;` //与字符串s比较

  大于0表面自己大于s

```C++
void test1()
{
    string str1 = "xello";
    string str2 = "hello";
    if (str1.compare(str2) == 0)
    {
        cout << "equal" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 > srt2" << endl;
    }
}
```

### 3.1.7 string字符存取

- `char& operator[](int n);` //通过[]方式取字符，也可以通过这种方式改
- `char& at(int n);` //通过at方法获取字符，也可以通过这种方式改

```C++
void test1()
{
    string s1 = "ssfherh";
    cout << s1[0] << endl;
    cout << s1.at(0) << endl;
    s1[0] = 'k';
    cout << s1[0] << endl;
    s1.at(0) = 'g';
    cout << s1.at(0) << endl;
}
```

### 3.1.8 string插入和删除

- `string& insert(int pos, const char* s);` //插入字符串
- `string& insert(int pos, const string& str);` //插入字符串
- `string& insert(int pos, int n, char c);` //在指定位置插入n个字符c
- `string& erase(int pos, int n = npos);` //删除从Pos开始的n个字符

```C++
void test1()
{
    string s1 = "ssfherh";
    s1.insert(1, "hello");
    cout << s1 << endl;
    string s2 = "world";
    s1.insert(7, s2);
    cout << s1 << endl;
    s1.insert(0, 3, 'a');
    cout << s1 << endl;
    s1.erase(0, 3);
    cout << s1 << endl;
}
```

### 3.1 9 string子串

**功能描述：**

- 从字符串中获取想要的子串

**函数原型：**

- `string substr(int pos = 0, int n = npos) const;` //返回由pos开始的n个字符组成的字符串

```C++
void test1()
{
    string s1 = "ssfherh";
    cout << s1 << endl;
    string s2 = s1.substr(0, 3);
    cout << s2 << endl;
    string s3 = s1.substr(1, 3);
    cout << s3 << endl;
}
```

## 3.2vector容器

### 3.2.1 vector基本概念

**功能：**

- vector数据结构和**数组非常相似**，也称为**单端数组**

**vector与普通数组区别：**

- 不同之处在于数组是静态空间，而vector可以**动态扩展**

**动态扩展：**

- 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

- vector容器的迭代器是支持随机访问的迭代器

### 3.2.2 vector构造函数

**功能描述：**

- 创建vector容器

**函数原型：**

- `vector<T> v;` //采用模板实现类实现，默认构造函数
- `vector(v.begin(), v.end());` //将v[begin(), end())区间中的元素拷贝给本身。
- `vector(n, elem);` //构造函数将n个elem拷贝给本身。
- `vector(const vector &vec);` //拷贝构造函数。

```C++
void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    vector<int> v3(10, 100); // 10个100
    printVector(v3);
    vector<int> v4(v3);
    printVector(v4);
}
```

### 3.2.3 赋值操作

**功能描述：**

- 给vector容器进行赋值

**函数原型：**

- `vector& operator=(const vector &vec);`//重载等号操作符
- `assign(beg, end);` //将[beg, end)区间中的数据拷贝赋值给本身。
- `assign(n, elem);` //将n个elem拷贝赋值给本身。

```C++
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2;
    v2 = v1;
    printVector(v2);
    vector<int> v3;
    v3.assign(v1.begin(), v1.end()-1);
    printVector(v3);
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}
```

### 3.2.4 容量和大小

**功能描述：**

- 对vector容器的容量和大小操作

**函数原型：**

- `empty();` //判断容器是否为空 `true` or `flase`

- `capacity();` //容器的容量

- `size();` //返回容器中元素的个数

- `resize(int num);` //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置。

   //如果容器变短，则末尾超出容器长度的元素被删除。

- `resize(int num, elem);` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

   //如果容器变短，则末尾超出容器长度的元素被删除

```C++
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "为空" << endl;
    }
    else 
    {
        cout << "不为空" << endl;
        cout << v1.capacity() << endl; // 容量
        cout << v1.size() << endl;
    }
    v1.resize(15); // 重新指定容量，默认用0填充
    printVector(v1);
    v1.resize(20, 100); 
    printVector(v1);
    v1.resize(5);
    printVector(v1);
}
```

### 3.2.5 vector插入和删除

**功能描述：**

- 对vector容器进行插入、删除操作

**函数原型：**

- `push_back(ele);` //尾部插入元素ele
- `pop_back();` //删除最后一个元素
- `insert(const_iterator pos, ele);` //迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
- `erase(const_iterator pos);` //删除迭代器指向的元素
- `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
- `clear();` //删除容器中所有元素

```C++
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    v1.pop_back();
    printVector(v1);
    v1.insert(v1.begin(), 100);
    printVector(v1);
    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);
    v1.erase(v1.begin());
    printVector(v1);
    v1.erase(v1.begin(), v1.end() - 1);
    printVector(v1);
    v1.clear();
    printVector(v1);
}
```

### 3.2.6 vector数据存取

**功能描述：**

- 对vector中的数据的存取操作

**函数原型：**

- `at(int idx);` //返回索引idx所指的数据
- `operator[];` //返回索引idx所指的数据
- `front();` //返回容器中第一个数据元素
- `back();` //返回容器中最后一个数据元素

```C++
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    cout << v1[0] << endl;
    cout << v1.at(0) << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
}
```

### 3.2.7 vector互换容器

**功能描述：**

- 实现两个容器内元素进行互换

**函数原型：**

- `swap(vec);` // 将vec与本身的元素互换

```C++
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(i + 1);
    }
    printVector(v2);
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
```

**用法** -- 收缩内存 `vector<int>(v).swap(v);`

 ```C++
 void test2()
 {
     vector<int> v;
     for (int i = 0; i < 10000; i++)
     {
         v.push_back(i);
     }
     cout << v.capacity() << endl << v.size() << endl;
     v.resize(3);
     cout << v.capacity() << endl << v.size() << endl;
     // vec<in>(v) -- 匿名对象；与匿名对象交换，匿名对象用完自动回收
     vector<int>(v).swap(v);
     cout << v.capacity() << endl << v.size() << endl;
 }
 ```

### 3.2.8 vector预留空间

**功能描述：**

- 减少vector在动态扩展容量时的扩展次数

**函数原型：**

- `reserve(int len);`//容器预留len个元素长度，预留位置不初始化，元素不可访问。

```C++
void test1()
{
    vector<int> v1;
    // 预留空间
    v1.reserve(10000);
    int num = 0;
    int * p = NULL;
    for (int i = 0; i < 10000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "Num = " << num << endl;
}
```

## 3.3 deque容器

**功能：**

- 双端数组，可以对头端进行插入删除操作

**deque与vector区别：**

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度回比vector快
- vector访问元素时的速度会比deque快,这和两者内部实现有关

**deque内部工作原理**:

deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

- deque容器的迭代器也是支持随机访问的

### 3.3.2 deque构造函数

**功能描述：**

- deque容器构造

**函数原型：**

- `deque<T>` deqT; //默认构造形式
- `deque(beg, end);` //构造函数将[beg, end)区间中的元素拷贝给本身。
- `deque(n, elem);` //构造函数将n个elem拷贝给本身。
- `deque(const deque &deq);` //拷贝构造函数

```C++
void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);
    deque<int> d3(d2);
    printDeque(d3);
}
```

### 3.3.3 deque赋值操作

**功能描述：**

- 给deque容器进行赋值

**函数原型：**

- `deque& operator=(const deque &deq);` //重载等号操作符
- `assign(beg, end);` //将[beg, end)区间中的数据拷贝赋值给本身。
- `assign(n, elem);` //将n个elem拷贝赋值给本身。

```c++
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int> d2;
    d2 = d1;
    printDeque(d2);
    deque<int> d3;
    d3.assign(d2.begin(), d2.end());
    printDeque(d3);
    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}
```

### 3.3.4 deque大小操作

**功能描述：**

- 对deque容器的大小进行操作

**函数原型：**

- `deque.empty();` //判断容器是否为空

- `deque.size();` //返回容器中元素的个数

- `deque.resize(num);` //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。

   //如果容器变短，则末尾超出容器长度的元素被删除。

- `deque.resize(num, elem);` //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。

   //如果容器变短，则末尾超出容器长度的元素被删除。

- `deque`没有容量的概念，因为可以无限扩展

```c++
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    if (d1.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << d1.size() << endl;
        cout << "不为空" << endl;
    }
    d1.resize(15);
    printDeque(d1);
    d1.resize(20, 100);
    printDeque(d1);
}
```

### 3.3.5 deque的插入和删除

**功能描述：**

- 向deque容器中插入和删除数据

**函数原型：**

两端插入操作：

- `push_back(elem);` //在容器尾部添加一个数据
- `push_front(elem);` //在容器头部插入一个数据
- `pop_back();` //删除容器最后一个数据
- `pop_front();` //删除容器第一个数据

指定位置操作：位置均是迭代器！

- `insert(pos,elem);` //在pos(迭代器对象，下同)位置插入一个elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);` //在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);` //在pos位置插入[beg,end)区间的数据，无返回值。
- `clear();` //清空容器的所有数据
- `erase(beg,end);` //删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);` //删除pos位置的数据，返回下一个数据的位置。

### 3.3.6 deque数据存取

**功能描述：**

- 对deque 中的数据的存取操作

**函数原型：**

- `at(int idx);` //返回索引idx所指的数据
- `operator[];` //返回索引idx所指的数据
- `front();` //返回容器中第一个数据元素
- `back();` //返回容器中最后一个数据元素

```c++
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    cout << d1[1] << endl;
    cout << d1.at(2) << endl;
    cout << d1.front() << d1.back() << endl;
}
```

### 3.3.7 deque排序

**功能描述：**

- 利用算法实现对deque容器进行排序

**算法：**该算法是`algorithm`中的标准排序算法，默认升序

- `sort(iterator beg, iterator end)` //对beg和end区间内元素进行排序

```c++
void test1()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(10 - i);
    }
    printDeque(d1);
    sort(d1.begin(), d1.end());
    printDeque(d1);
}

```

对于支持随机访问的迭代器都可以使用sort算法进行排序，例如vector容器也可以

## 3.4 案例-评委打分

### 随机数生成：

```c++
// 随机数种子
srand((unsigned int) time(NULL));
cout << rand() % 41 + 60 << endl; // [0, 100]
```

## 3.5 stack容器

### 3.5.1 基本概念

**概念**：`stack`是一种**先进后出**(First In Last Out,FILO)的数据结构，它只有一个出口

栈中只有顶端（出口位置）的元素才可以被外界使用，**因此栈不允许有遍历行为**

栈中进入数据称为 — **入栈** `push`

栈中弹出数据称为 — **出栈** `pop`

### 3.5.2 stack常用接口

**功能描述**：栈容器常用的对外接口

**构造函数**：

- `stack<T> stk;` //stack采用模板类实现， stack对象的默认构造形式
- `stack(const stack &stk);` //拷贝构造函数

**赋值操作**：

- `stack& operator=(const stack &stk);` //重载等号操作符

**数据存取**：

- `push(elem);` //向栈顶添加元素
- `pop();` //从栈顶移除第一个元素
- `top();` //返回栈顶元素

**大小操作**：

- `empty();` //判断堆栈是否为空
- `size();` //返回栈的大小

```c++
void test1()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.size() << endl;;
}
```

## 3.6 queue容器

### 3.6.1 queue基本概念

**概念：**Queue是一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口

<img src="http://typora-tuchuang-cx.oss-cn-beijing.aliyuncs.com/img/pq.png" alt="pq" style="zoom:50%;" />

队列容器允许从一端新增元素，从另一端移除元素

队列中只有队头和队尾才可以被外界使用，**因此队列不允许有遍历行为**

队列中进数据称为 — **入队** `push`

队列中出数据称为 — **出队** `pop`

### 3.6.2 常用接口

功能描述：栈容器常用的对外接口

**构造函数**：

- `queue<T> que;` //queue采用模板类实现，queue对象的默认构造形式
- `queue(const queue &que);` //拷贝构造函数

**赋值操作**：

- `queue& operator=(const queue &que);` //重载等号操作符

**数据存取**：

- `push(elem);` //往队尾添加元素
- `pop();` //从队头移除第一个元素
- `back();` //返回最后一个元素
- `front();` //返回第一个元素

**大小操作**：

- `empty();` //判断堆栈是否为空
- `size();` //返回栈的大小

```c++
void test1()
{
    queue<Person> q;
    Person p1("Tom", 18);
    Person p2("Bob", 19);
    q.push(p1);
    q.push(p2);
    while(!q.empty())
    {
        cout << "front: " << q.front().m_Name << q.front().m_Age << endl;
        cout << "back: " << q.back().m_Name << q.back().m_Age << endl;
        q.pop();
    }
    cout << q.size() << endl;
}
```

## 3.7 list容器

### 3.7.1 list基本概念

**功能：**将数据进行链式存储

**链表**（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

链表的组成：链表由一系列**结点**组成

结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**

STL中的链表是一个双向循环链表

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于**双向迭代器**

list的优点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：

- 链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大

List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

总结：STL中**List和vector是两个最常被使用的容器**，各有优缺点

* list的迭代器只能++和--操作，不能it = it + 1，因为如果支持it = it +1，那么it = it + 3就相当随机访问了

### 3.7.2 list构造函数

**功能描述：**

- 创建list容器

**函数原型：**

- `list<T> lst;` //list采用采用模板类实现,对象的默认构造形式：
- `list(beg,end);` //构造函数将[beg, end)区间中的元素拷贝给本身。
- `list(n,elem);` //构造函数将n个elem拷贝给本身。
- `list(const list &lst);` //拷贝构造函数。

```c++
void printList(const list<int> & L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    list<int> L2(L1.begin(), L1.end()); // 不能 -1
    printList(L2);
    list<int> L4(10, 1000);
    printList(L4);
}
```

### 3.7.3 list赋值和交换

**功能描述：**

- 给list容器进行赋值，以及交换list容器

**函数原型：**

- `assign(beg, end);` //将[beg, end)区间中的数据拷贝赋值给本身。
- `assign(n, elem);` //将n个elem拷贝赋值给本身。
- `list& operator=(const list &lst);` //重载等号操作符
- `swap(lst);` //将lst与本身的元素互换。

```c++
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    list<int> L2;
    L2 = L1;
    printList(L2);
    list<int> L3;
    L3.assign(L1.begin(), L1.end());
    printList(L3);
    list<int> L4;
    L4.assign(10, 1000);
    printList(L4);
    L1.swap(L4);
    printList(L1);
    printList(L4);
}
```

### 3.7.4 list大小操作

**功能描述：**

- 对list容器的大小进行操作

**函数原型：**

- `size();` //返回容器中元素的个数

- `empty();` //判断容器是否为空

- `resize(num);` //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

   //如果容器变短，则末尾超出容器长度的元素被删除。

- `resize(num, elem);` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

```c++
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    if (L1.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << L1.size() << endl;
    }
    L1.resize(10);
    printList(L1);
    L1.resize(15, 1000);
    printList(L1);
    L1.resize(2);
    printList(L1);
}
```

### 3.7.5 list插入和删除

**功能描述：**

- 对list容器进行数据的插入和删除

**函数原型：**

- `push_back(elem);`//在容器尾部加入一个元素
- `pop_back();` //删除容器中最后一个元素
- `push_front(elem);` //在容器开头插入一个元素
- `pop_front();` //从容器开头移除第一个元素
- `insert(pos,elem);`//在pos（迭代器）位置插elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);` //在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);` //在pos位置插入[beg,end)区间的数据，无返回值。
- `clear();` //移除容器的所有数据
- `erase(beg,end);` //删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);` //删除pos位置的数据，返回下一个数据的位置。
- `remove(elem);` //删除容器中所有与elem值匹配的元素。

```c++
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    L1.push_front(100);
    L1.push_front(200);
    printList(L1);
    L1.pop_front();
    printList(L1);
    L1.insert(++L1.begin(), 1000); // ++L1.begin()
    printList(L1);
    L1.erase(L1.begin());
    printList(L1);
    L1.push_back(1000);
    L1.remove(1000);
    printList(L1);
    L1.clear();
    printList(L1);
}
```

### 3.7.6 数据存取

**功能描述：**

- 对list容器中数据进行存取

**函数原型：**

- `front();` //返回第一个元素。
- `back();` //返回最后一个元素。
- 不能使用`[]`和`at()`方式读取

```c++
void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    printList(L1);
    cout << L1.front() << endl;
    cout << L1.back() << endl;

}
```

### 3.7.7  list反转与排序

**功能描述：**

- 将容器中的元素反转，以及将容器中的数据进行排序

**函数原型：**

- `reverse();` //反转链表
- `sort();` //链表排序，该算法是list的方法，不是`algorithm`中的sort

不支持随机访问的迭代器容器不能使用 `algorithm`中的sort

```c++
bool myCompare(int v1, int v2)
{
    return v1 > v2;
}

void test1()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(60);
    L1.push_back(30);
    L1.push_back(50);
    printList(L1);
    L1.sort(); // 默认升序
    printList(L1);
    L1.sort(myCompare); // 降序操作
    printList(L1);

    L1.reverse();
    printList(L1);
}
```

## 3.8 set/multiset容器

### 3.8.1 基本概念

**简介：**

- 所有元素都会在插入时自动被排序

**本质：**

- set/multiset属于**关联式容器**，底层结构是用**二叉树**实现。

**set和multiset区别**：

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素

### 3.8.2 set构造和赋值

功能描述：创建set容器以及赋值

构造：

- `set<T> st;` //默认构造函数：
- `set(const set &st);` //拷贝构造函数

赋值：

- `set& operator=(const set &st);` //重载等号操作符

```c++
void test1()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    set<int> s2(s1);
    printSet(s2);
    set<int> s3;
    s3 = s2;
    printSet(s3);
}
```

### 3.8.3 set大小和交换

**功能描述：**

- 统计set容器大小以及交换set容器

**函数原型：**

- `size();` //返回容器中元素的数目
- `empty();` //判断容器是否为空，返回0和1
- `swap(st);` //交换两个集合容器

```c++
void test1()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    cout << s1.size() << endl;
    set<int> s2;
    s2.insert(49);
    s2.insert(39);
    s2.insert(29);
    printSet(s2);
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}
```

### 3.8.4 set插入和删除

**功能描述：**

- set容器进行插入数据和删除数据

**函数原型：**

- `insert(elem);` //在容器中插入元素。
- `clear();` //清除所有元素
- `erase(pos);` //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- `erase(beg, end);` //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
- `erase(elem);` //删除容器中值为elem的元素。

```c++
void test1()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    s1.erase(30);
    printSet(s1);
    s1.erase(s1.begin());
    printSet(s1);
}
```

### 3.8.5 set查找和统计

**功能描述：**

- 对set容器进行查找数据以及统计数据

**函数原型：**

- `find(key);` //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);` //统计key的元素个数，对于multiset可以返回大于1

```c++
void test1()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    multiset<int> s2;
    s2.insert(30);
    s2.insert(30);
    s2.insert(10);
    cout << s2.count(30) << endl;
}
```

### 3.8.6 set和multiset的区别

**学习目标：**

- 掌握set和multiset的区别

**区别：**

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据

### 3.8.7 pair对组创建

**功能描述：**

- 成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**

- `pair<type, type> p ( value1, value2 );`
- `pair<type, type> p = make_pair( value1, value2 );`

```c++
int main(){
    pair<string, int> p("Tom", 18);
    cout << p.first << p.second << endl;
    pair<string, int> p1 = make_pair("Bob", 19);
    cout << p1.first << p1.second << endl;
    system("pause");
    return 0;
}
```

### 3.8.8 set容器排序

学习目标：

- set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则

**示例一** set存放内置数据类型

```c++
class MyCompare
{
    public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(60);
    s.insert(40);
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    set<int, MyCompare>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(60);
    s2.insert(40);
    for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
}
```

**示例二** set存放自定义数据类型

```c++
class Person
{
    public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    string m_Name;
    int m_Age;
};
// 仿函数
class MyCompare
{
    public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age; // 按年龄降序
    }
};
void test1()
{
    set<Person, MyCompare> s;
    Person p1("Tom", 19);
    Person p2("Bob", 20);
    Person p3("Mary", 15);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->m_Name << it->m_Age << endl;
    }
}
```

## 3.9 map/multimap容器

### 3.9.1 map基本概念

**简介：**

- map中所有元素都是pair
- pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
- 所有元素都会根据元素的键值自动排序

**本质：**

- map/multimap属于**关联式容器**，底层结构是用二叉树实现。

**优点：**

- 可以根据key值快速找到value值

map和multimap**区别**：

- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素

### 3.9.2 构造和赋值

**功能描述：**

- 对map容器进行构造和赋值操作

**函数原型：**

**构造：**

- `map<T1, T2> mp;` //map默认构造函数:
- `map(const map &mp);` //拷贝构造函数

**赋值：**

- `map& operator=(const map &mp);` //重载等号操作符

```c++
void printMap(map<int, int> & m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second <<endl;
    }
    cout << endl;
}

void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
    map<int, int>m2(m);
    printMap(m2);
    map<int, int>m3;
    m3 = m;
    printMap(m3);
}
```

### 3.9.3 map大小和交换

**功能描述：**

- 统计map容器大小以及交换map容器

函数原型：

- `size();` //返回容器中元素的数目
- `empty();` //判断容器是否为空
- `swap(st);` //交换两个集合容器

### 3.9.4 map的插入和删除

**功能描述：**

- map容器进行插入数据和删除数据

**函数原型：**

- `insert(elem);` //在容器中插入元素。elem=pair<int,int>p(1, 10)或者make_pair(1, 10)，以<int,int>为例
- `clear();` //清除所有元素
- `erase(pos);` //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- `erase(beg, end);` //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
- `erase(key);` //删除容器中值为key的元素。

```c++
void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m[5] = 50; // 不建议去插入，可以用key去访问
    cout << m[6] << endl; // 此时会创建一个(6, 0)
    printMap(m);
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
}
```

### 3.9.5 map的查找和统计

**功能描述：**

- 对map容器进行查找数据以及统计数据

**函数原型：**

- `find(key);` //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
- `count(key);` //统计key的元素个数

```c++
void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end())
    {
        cout << pos->first << " : " << pos->second << endl;
    }
    cout << m.count(3) << endl;
}
```

### 3.9.6 map排序

**学习目标：**

- map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

**主要技术点:**

- 利用仿函数，可以改变排序规则

```c++
class MyCompare
{
    public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(make_pair(4, 40));
    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second <<endl;
    }
    cout << endl;
}
```

### 3.10 案例-员工分组



# 4 STL-函数对象

### 4.1.1 基本概念

**概念：**

- 重载**函数调用操作符**的类，其对象常称为**函数对象**
- **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**

**本质：**

函数对象(仿函数)是一个**类**，不是一个函数

### 4.1.2 函数对象的使用



# 5 STL-常用算法

