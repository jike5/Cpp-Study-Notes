# C++学习笔记

[toc]

# 1. 指针

1. 指针常量&常量指针

   **指针常量**：指针是一个常量，即指针的指向不可以修改(指针的值不能改)，但是指针指向的值可以修改

   `int * const p = &a;`

   **常量指针**：一个常量的指针，指针指向的值不可以修改，但是指针指向可以修改(指针的值可以修改)

   `const int * p = &a;`

   *需要注意区分指针指向和指针指向的值*

2. `const int * const p = &a;`指针的指向和指向的值都不能修改

   > 记忆方式: `const`翻译为常量, `*`翻译为指针.则`int * const p = &a`表示指针常量。

# 2. 结构体

1. 定义

   定义时末尾都有`;`

   ```c++
   #include<string>
   struct Student
   {
       string name;
       int age;
       int score;
   };
   ```

2. 实例化

   ```c++
   // Method One
   struct Student s1;
   s1.name = "Sam";
   s1.age = 10;
   // Method Two
   struct Student s2 = {"Sam", 19, 80};
   //Method Three 定义结构体时创建结构体变量
   struct Student
   {
       string name;
       int age;
       int score;
   }s3;
   ```

3. 结构体数组

   `struct 结构体名 数组名[元素个数] = { {}, {}};`

   ```c++
   // Method One 定义时幅值
       struct Student stuArray[3] = 
       {
           {"Sam", 18, 100},
           {"Bob", 19, 100},
           {"Jue", 20, 80}
       };
   // Method Two 先定义后赋值
       struct Student Array[3];
       Array[0].name = "Test";
   ```

4. 结构体指针

   ```c++
   Student s = {"Bob", 18, 100};
   Student * p = &s;
   cout << "test's name:" << p->name << endl;
   ```


# 3.  内存分区模型

   内存大致分为四个区域:

* 代码区: 存放函数体的二进制代码,由操作系统进行管理
* 全局区: 存放全局变量和静态变量以及常量
* 栈区: 由编译器自动分配释放,存放函数的参数值,局部变量等
* 堆区: 由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

运行前:

1. 代码区: 共享和只读

2. 全局区:

   局部变量和const修饰的局部变量(局部常量)都不在全局区中

   全局变量,静态变量,字符串常量和const修饰的全局变量都在全局区中.

运行后:

1. 栈区：不要返回局部变量的地址(栈区的数据由编译器管理和释放)

2. 堆区：

   在堆区开辟数据：

   ```c++
   // 开辟一个值为整型，值为10的数据，返回其地址
   int * p = new int(10);
   // 开辟堆区数据
   #include<iostream>
   using namespace std;
   
   int * func()
   {
       int * p = new int(10);
       return p;
   }
   
   int main(){
       int * p = func();
       cout << *p << endl;
   
       system("pause");
       return 0;
   }
   // 10存放在堆区，func函数内指针存放在栈区



# 4. new操作符



1. 释放：

	```c++
int * p = new int(10);
delete p;
	```

2. 开辟数组

	```c++
	int * arr = new int[10]; //10代表该数组有10个元素，arr表示该数组的首地址
	// 操作该数组
	for(int i = 0; i < 10; i++)
	{
    arr[i] = i + 100; // 给十个数幅值
	}
	```

# 5. 引用

## 5.1 定义

引用：给变量起别名

```c++
int a = 10;
int  &b = a; // b为a的别名 
```

操作b会影响a的值。

## 5.2 注意事项

* 引用必须初始化
* 引用一旦初始化后不可以更改

## 5.3 引用做函数参数

* 简化形参修改实参，比指针简化

## 5.4 引用做函数返回值

* 不要返回局部变量的引用

* **函数的调用可以作为左值存在**

  ```c++
  int & test02()
  {
      static int a = 10;
      return a;
  }
  int main(){
      int & ref2 = test02();
      cout << "ref2=" << ref2 << endl;
      // 函数调用作为左值
      test02() = 1000;
      cout << "ref2=" << ref2 << endl;
  	// 输出结果分别为10和1000
      system("pause");
      return 0;
  }  
  ```

## 5.5 引用的本质

引用的本质是一个指针常量，编译器会自动做解引用的操作(语法糖)

## 5.6 常量引用

作用：常量引用主要用来修饰形参，防止误操作

在函数列表中可以加const修饰形参防止形参改变实参

```c++
int &a = 10; //会报错，引用需要指向合法的内存空间
const int &a = 10; //不会报错，相当于int temp =10; int &a = temp;
a = 20; //会报错，因为是const
```

```c++
void showValue(const int &val) // 形参中加入const修饰，防止误操作
{
    cout << val << endl;
}

int main(){
    int a = 10;
    showValue(a);
    return 0;
}  
```

# 6. 函数

## 6.1 函数默认参数

```C++
int func(int a, int b = 20, int c = 10)
{
    return a+b+c;
}
```

**如果函数声明有默认参数，函数实现就不能有默认参数，即声明和实现只能有一个有默认参数**

```C++
// 函数声明
int func(int a = 10, int b = 10);

// 函数实现
int func(int a, int b)
{
    return a+b;
}
```

## 6.2 函数占位参数

占位参数可以有默认参数

```C++
// 函数的占位参数
#include<iostream>
using namespace std;

void func(int a, int) // void func(int a, int = 10) 占位参数默认参数
{
    cout << "hello" << endl;
}
int main(){
    func(10, 10); // 此处必须传入第二个int，当有默认参数时，可以不传入

    system("pause");
    return 0;
}  
```

## 6.3 函数重载

**函数重载满足条件**

* 同一作用域下
* 函数名相同
* 函数参数类型不同或个数不同或顺序不同

函数的返回值不可以作为重载条件

**函数重载的注意事项**

* 引用作为重载条件

  ```C++
  void func(int &a)
  {
      cout << "func(int &a)" << endl;
  }
  
  void func(const int &a)
  {
      cout << "func(const int &a)" << endl;
  }
  
  int main(){
      int a = 10;
      func(a); // 会调用第一个
      func(10); // 会调用第二个，const int &a = 10合法，而如果调用第一个int &a = 10 不合法
      system("pause");
      return 0;
  }  
  ```

* 函数重载遇到默认参数

  ```C++
  // 函数重载遇到默认参数
  void func2(int a, int b = 10)
  {
      cout << "func(const int &a)" << endl;
  }
  
  void func2(int a)
  {
      cout << "func(const int &a)" << endl;
  }
  // 需要尽量避免
  ```

# 7. 类和对象

面向对象的三大特性：封装、继承和多态

## 7.1 封装

* **封装的意义**：

  访问权限：

1. public：成员 类内可以访问，类外可以访问
2. protected：成员 类内可以访问，类外 **不可以访问**；儿子可以访问父亲的保护内容
3. private：成员 类内可以访问，类外 **不可以访问**；儿子不可以访问父亲的私有内容

* **struct和class的区别**

  struct的默认权限的 **公共**

  class的默认权限是 **私有**

* **成员属性的设置为私有**

  可以自己控制读写权限

  对于写，可以检测数据的有效性

## 类分文件声明与定义

类的成员函数可以是其他类。为了简化代码文件，常常将类的声明与定义分开

如下：

`point.h`

```C++
#include<iostream>
using namespace std;

class Point
{
public:
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int m_x;
    int m_y;
};
```

`point.cpp`

```C++
#include "point.h"

int Point::getX() { return m_x; }
int Point::getY() { return m_y; }
void Point::setX(int x) { m_x = x; }
void Point::setY(int y) { m_y = y; }
```

## 7.2 对象的初始化和清理

### 7.2.1 构造函数与析构函数

构造函数：类名(){}

1. 没有返回值，也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以重载
4. 程序会自动调用构造函数，且只会调用一次

析构函数：~类名(){}

1. 同上
2. 同上
3. 不能有参数，不能重载
4.  程序销毁前会自动调用

### 7.2.3 **构造函数的分类和调用**

两种分类方式：

​	按参数：有参构造和无参构造

​	按类型：普通构造和拷贝构造: `Person(const Person &p)`

三种调用方式：

​	括号法

​	显示法

​	隐式转换法

```C++
// 构造函数的分类和调用
#include<iostream>
using namespace std;

class Person
{
public:
    // 构造函数
    Person() // 无参构造、默认构造
    {
        cout << "Person构造函数" << endl;
    }
    Person(int a) // 有参构造
    {
        age = a;
        cout << "Person构造函数" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "Person构造函数" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }
    int age;
};

int main(){
    // 调用
    // 1. 括号法
    Person p1; // 默认构造函数时不加'()', Person p1() 编译器认为是一个函数声明
    Person p2(10); // 括号法调用有参构造函数
    Person p3(p2);  // 拷贝
    // 2. 显示法
    Person p1;
    Person p2 = Person(10); // 有参
    Person p3 = Person(p2); // 拷贝

    Person(10); // 匿名对象，当前行执行结束后会回收匿名对象
    // 不要用拷贝构造函数初始化匿名对象
    // Person(p3); // 此句话等价为 Person p3, 即变为对象的声明

    // 3. 隐式法
    Person p4 = 10; // 相当于Person p4 = Person(10)
    Person p5 = p3;

    system("pause");
    return 0;
}  
```

### 7.2.4 **拷贝构造函数调用时机**

* 使用一个 已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象

### 7.2.5 **构造函数调用规则**

默认情况下，C++编译器会给一个类添加 三个函数

1. 默认构造函数
2. 默认析构函数
3. 默认拷贝构造函数

构造函数调用规则如下：

* 如果用户定义有参构造函数，C++不会提供默认无参构造函数，但是会提供默认拷贝构造函数
* 如果用户定义拷贝构造函数，C++不会提供默认无参构造函数

### 7.2.6 **深拷贝与浅拷贝**

浅拷贝：简单的幅值操作，带来问题：堆区的内存重复释放

深拷贝：在堆区重新申请空间，进行拷贝操作

```C++
class Person
{
public:
    // 构造函数
    Person() // 无参构造、默认构造
    {
        cout << "Person默认构造函数" << endl;
    }
    Person(int a, int height) // 有参构造
    {
        age = a;
        m_Height = new int(height);
        cout << "Person有参构造函数" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        // 深拷贝
        m_Height = new int(*p.m_Height);
        
        cout << "Person拷贝构造函数" << endl;
    }

    ~Person()
    {
        // 析构函数作用：释放构造函数申请的内存
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person析构函数" << endl;
    }

    int age;
    int * m_Height;
};

void test1()
{
    Person p(18, 160);
    cout << "p1身高" << *p.m_Height << endl;
    Person p2(p);
    cout << p2.age << endl;
    cout << "p2身高" << *p2.m_Height << endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}  
```

浅拷贝只会简单的复制`m_Height`，即一个地址，该地址在堆区中，当p2执行析构函数时会被释放，导致p析构函数执行时无法正确释放。因此，需要用到深拷贝，在堆区中重新申请空间，进行拷贝操作。

> 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题。

### 7.2.7 初始化列表

语法： `构造函数():属性1(值1), 属性2(值2)...{ }`

```C++
class Person
{
public:
    // 构造函数1
    // Person():m_a(10), m_b(20), m_c(30)
    // {
    //     cout << "Person默认构造函数" << endl;
    // }
    // 构造函数 2
    Person(int a, int b, int c) : m_a(a), m_b(b), m_c(c)
    {
        cout << "Person默认构造函数" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }

    int m_a;
    int m_b;
    int m_c;
};
```

### 7.2.8 类对象作为类成员

C++中类的成员是另一个类的对象，称为 对象成员

* 构造时，先构造其他类的对象，再构造自身
* 析构时，先析构自身，再析构其他类，与构造相反。

### 7.2.9 静态成员

* 静态成员变量
  * 所有对象共享一份数据
  * 在编译阶段分配内存
  * 类内声明，类外初始化
* 静态成员函数
  * 所有对象共享同一个函数
  * 静态成员函数只能访问静态成员变量

`静态成员变量`

```C++
class Person
{
public:
    static int m_A;  // 类内声明
};

int Person::m_A = 100; // 类外初始化

void test02()
{
    cout << Person::m_A << endl; // 通过类名访问
}
// 访问权限
// 类外只能访问到public的静态变量
```

`静态成员函数`

```C++
static void func()
{
    m_A = 1000;
    cout << "static void func调用" << endl;
}
// 访问权限：类外无法访问到私有权限。
// 只能访问静态成员变量
```

访问：1. 通过对象；2. 通过类名(::)

## 7.3 C++对象模型和this指针 

**成员变量和成员函数分开存储**

​	空对象(没有成员函数 、成员变量)占用内存空间为 **1个字节**

​	含有1个int成员变量的类对象占用 4个字节

​	非静态成员函数不属于类的对象上；

​	静态成员函数和成员变量也不属于类的对象上，不增加类的空间

**this指针概念**

​	每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一份代码，那么这一块代码是如何区分哪个对象调用自己呢？

​	C++ 中通过this指针解决上述问题。**this指针指向被调用的成员函数所属的对象**

this指针用途：

* 当形参和成员变量同名时，可用this指针来区分
* 在类的非静态成员函数中返回对象本身，可使用return *this
* this本质上 是指针常量

```C++
class Person
{
public:
    Person (int age)
    {
        this->age = age; // 区别形参与成员变量
    }
    int age;
};
```

```C++
class Person
{
public:
    Person (int age)
    {
        this->age = age;
    }
    Person & PersonAddAge(Person &p) // 此处返回值类型为引用，不然返回*this的拷贝
    {
        this->age += p.age;
        return *this; // 返回当前对象自身
    }
    int age;
};

void test2()
{
    Person p1(10);
    Person p2(10);
    // 链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1);
    cout << p2.age << endl;
}
```

**空指针访问成员函数**

```C++
class Person
{
public:
    void showClassName()
    {
        cout << "Person" << endl;
    }
    void showPersonAge()
    {
        cout << "Age" << m_Age << endl;
    }
    int m_Age;
};

void test1()
{
    Person * p = NULL;
    p->showClassName(); // 可以访问成员函数
    // p->showPersonAge();
}

```

**const修饰成员函数**

​	**常函数**：成员函数加上const后

* 常函数内不可以修改成员属性
* 成员属性 声明时加关键字**mutable**后，在常函数中依然可以修改

**常对象**：

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数

## 7.4 友元

关键字: friend

友元三种实现：

* 全局函数做友元
* 类做友元
* 成员函数做友元

### 7.4.1 全局函数做友元

```C++
class Building
{
    // 全局函数做友元，可以访问私有成员变量
    friend void goodGay(Building *building); 
public:
    Building()
    {
        m_SittingRoom = "SittingRoom";
        m_BedRoom = "BedRoom";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
// 全局函数
void goodGay(Building *building)
{
    cout << "全局函数正在访问" << building->m_SittingRoom << endl;
    cout << "全局函数正在访问" << building->m_BedRoom << endl; // 访问私有成员
}

void test1()
{
    Building building;
    goodGay(&building);
}

int main(){
    test1();
    system("pause");
    return 0;
}  
```

### 7.4.2 类做友元

```C++
class Building
{
    // 类做友元
    friend class GoodGay;
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
```

### 7.4.3 成员函数做友元

```C++
// ******************提前声明Building类 *****************
class Building;

class GoodGay
{
public:
    void visit();
    GoodGay();
    Building * building;
};

class Building
{
    // 成员函数做友元
    friend void GoodGay::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
```

## 7.5 运算符重载

### 7.5.1 加号运算符重载

语法：`类名 operator+ (参数){...}`

**运算符也可以函数重载**

`成员函数实现运算符重载`

```C++
class Person
{
public:
    Person(int a, int b) : m_A(a), m_B(b)
    { }
    Person(){ }
    int m_A;
    int m_B;
    // 成员函数实现运算符重载
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    
};

void test1()
{
    Person p1(10, 10);
    Person p2(10, 10);
    Person p3 = p1 + p2;
    cout << "m_A = " <<p3.m_A << endl << "m_B = " << p3.m_B << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}  
```

`全局函数实现运算符重载`

```C++
#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a, int b) : m_A(a), m_B(b)
    { }
    Person(){ }
    int m_A;
    int m_B;
};
// 全局函数实现 operator+(p1, p2)
Person operator+(Person & p1, Person & p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

void test1()
{
    Person p1(10, 10);
    Person p2(10, 10);
    Person p3 = p1 + p2;
    cout << "m_A = " <<p3.m_A << endl << "m_B = " << p3.m_B << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}  
```

### 7.5.2 左移运算符重载

用于输出自定义的数据类型

通常不使用成员函数实现，因为这样`cout`位于运算符右侧，而通常是在左侧。

```C++
//使用全局函数实现
#include<iostream>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream & cout, Person &p);
public:
	Person(int a, int b):m_A(a), m_B(B){ }    
private:
    int m_A;
    int m_B;
};
// 全局函数实现，并且设置为友元
ostream & operator<<(ostream & cout, Person &p)
{
    cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
    return cout;
}

void test1()
{
    Person p(10, 10);
    cout << p << endl;
}
int main(){
    test1();
    system("pause");
    return 0;
}  
```

### 7.5.3 递增运算符重载

* 前置递增返回引用
* 后置递增返回值

```C++
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
```

### 7.5.4 赋值运算符重载

C++至少给一个类添加4个函数：

1. 默认构造
2. 默认析构
3. 默认拷贝
4. 赋值运算符operator=，对属性进行值拷贝

如果类中有属性指向堆区也会出现深浅拷贝的问题

`operator=`

```c++
// 赋值运算符重载
#include<iostream>
using namespace std;
class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    // p2 = operator(p1); ==>  p2 = p1;
    Person & operator=(Person &p) // 输入p1的引用
    {
        // 这里是m_Age是p2的，因此对m_Age重新赋值前先判断一下是否有指向，如果有先删除
        if(m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
        return * this;
    }
    
    int * m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(28);
    p3 = p2 = p1;
    cout << * p1.m_Age << endl;
    cout << * p2.m_Age << endl;
    cout << * p3.m_Age << endl;
}

int main(){
    test01();
    // 内置数据类型允许连续赋值
    int a = 10;
    int b = 10;
    int c = 10;
    cout << a << b << c << endl;

    system("pause");
    return 0;
}
```

### 7.5.5 关系运算符重载

```C++
class Person
{
public:
    Person(string name, int age) : m_Name(name), m_Age(age)
    {

    }
    bool operator==(Person & p)
    {
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return true;
        }
        return false;
    }
    bool operator!=(Person & p)
    {
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return false;
        }
        return true;
    }

    string m_Name;
    int m_Age;
};
```

### 7.5.6 函数调用运算符重载

* 函数调用运算符（）也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为仿函数
* 仿函数没有固定的写法，非常灵活

```C++
class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("hello"); // 仿函数
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
    // 匿名函数对象
    cout << MyAdd()(100, 100) << endl;
}
```

## 7.6 继承

减少重复的代码

语法：`class 子类 ： 继承方式 父类`

### 7.6.1 继承的基本语法

```C++
class BasePage
{
public:
    void header()
    {}
    
};
// 继承
class JavePage : public BasePage
{
    public:
    void content()
    {}
}
```

### 7.6.2 继承方式 

* 公共继承：父类中`public`的属性在子类中依然是`public`，父类中`protected`的属性在子类中依然是`protected`
* 保护继承：父类中`public`，`protected`的属性在子类中均是`protected`
* 私有继承：父类中`public`，`protected`的属性在子类中均是`private`

**父类中 `private`的属性无论哪种方式都无法继承**

### 7.6.3 继承中的对象模型

* 父类中所有非静态成员属性都会被子类继承下去，即子类的占用大小会需要考虑父类中继承来的
* 父类中私有成员属性是被编译器给隐藏了，因此访问不到

### 7.6.4 继承中构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数

先构造父类，再构造子类，析构与构造顺序相反

### 7.6.5 继承同名成员处理方式

访问子类同名成员时，直接访问即可

访问父类同名成员时，需要加作用域 `子类对象.父类名称::m_A`

子类中同名成员函数会隐藏掉父类中同名函数，包括重载函数

```C++
// 继承同名成员处理方式
#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base" << endl;
    }
    void func(int a)
    {
        cout << "Base int" << endl;
    }
    int m_A;
    
};
class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son" << endl;
    }
    int m_A;
};
void test01()
{
    Son s;
    cout << s.m_A << endl; // 子类中m_A
    cout << s.Base::m_A << endl; // 父类中
    s.func();
    s.Base::func();
    s.Base::func(10);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

### 7.6.6 继承同名静态成员处理方式

* 访问子类同名成员 直接访问即可
* 访问父类同名成员 需要加作用域

```C++
class Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base" << endl;
    }
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Son" << endl;
    }
};

int Son::m_A = 200;

void test1()
{
    Son s;
    // 通过对象
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    // 通过类名
    cout << Son::m_A << endl;
    cout << Son::Base::m_A << endl;
    // 静态成员函数
    // 通过对象
    s.func();
    s.Base::func();
    // 通过类名
    Son::func();
    Son::Base::func();
}
int main(){
    test1();
    system("pause");
    return 0;
}
```

### 7.6.7 多继承语法

C++允许一个类继承多个类

语法：`class 子类 : 继承方式  父类1 , 继承方式 父类2...`

多继承可能会引发父类中有同名函数出现，需要加作用域区分

C++中不建议使用多继承

### 7.6.8 菱形继承

<img src="http://typora-tuchuang-cx.oss-cn-beijing.aliyuncs.com/img/620942ff5adb2b15c51afbf43098d25.jpg" alt="620942ff5adb2b15c51afbf43098d25" style="zoom: 50%;" />

```C++
class Animal
{
public:
    int m_Age;
};
// 利用虚继承 解决菱形继承问题；继承之前加上关键字virtual 变为虚继承
// Animal 称为虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.m_Age << endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```



## 7.7 多态

### 7.7.1 多态的基本概念

多态分为两类

* 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别

* 静态多态的函数地址早绑定 - 编译阶段确定函数地址
* 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

动态多态满足条件：

* 有继承关系
* 子类**重写**父类的虚函数，父类的要加关键字`virtual`

> 重写指函数参数列表、返回值都相同 

动态多态使用

* **父类的指针或者引用指向子类对象**

```C++
class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "Animal" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat" << endl;
    }
};
// 早绑定，在编译阶段确定执行Animal的doSpeak函数
void doSpeak(Animal & animal) // Animal & animal = Cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

###  7.7.2 多态案例一-计算器

案例描述：

分别利用普通写法和多态技术，设计两个实现操作数进行运算的计算器类



多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期和后期的拓展以及维护

**开闭原则**：对拓展进行开放，对修改进行封闭

```C++
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
```

### 7.7.3 纯虚函数和抽象类

纯虚函数语法：`virtual 返回值类型 函数名 (参数列表) = 0`

当类中有纯虚函数，这个类也称为**抽象类**

抽象类的特点：

* 无法实例化对象
* 子类必须重新抽象类中的纯虚函数，否则也属于抽象类

```C++
class Base
{
public:
    // 纯虚函数
    virtual void func() = 0;
};

class Son : public Base
{
public:
    void func()
    {
        cout << "func" << endl;
    }
};

void test1()
{
    Base * b = new(Son);
    b->func();
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

### 7.7.4 多态案例二-制作饮品

```C++
class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    void makedrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮山泉水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入蜂蜜" << endl;
    }
};

void dowork(AbstractDrinking * abs)
{
    abs->makedrink();
    delete abs; // 释放
}

void test1()
{
    dowork(new Tea);
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

### 7.7.5 虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构函数

解决方式：将父类中的析构函数改为**虚析构**或**纯虚析构**

虚析构和纯虚析构共性：

* 都可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构的区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：`virtual  ~类名(){}`

纯虚析构语法：`virtual ~类名(){} = 0`

```C++
class Animal
{
public:
    virtual void speak() = 0;
    Animal()
    {
        cout << "Animal 构造函数" << endl;
    }
    // // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal 析构函数" << endl;
    // }
    // 纯虚构函数也需要实现，不然无法释放父类中的变量
    virtual ~Animal() = 0;
    string * m_Name;
};
// 纯虚析构函数的实现
Animal::~Animal()
{
    cout << "Animal 析构函数" << endl;
}
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat speak" << endl;
    }
    Cat(string name)
    {
        cout << "Cat 的构造函数" << endl;
        m_Name = new string(name);
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat 的析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
};

void test1()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
    
    delete animal;
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

* 虚析构或纯虚析构就是用来解决父类指针释放子类对象
* 如果子类中没有堆区数据可以不写虚析构或纯虚析构
* 拥有纯虚析构函数的类也属于抽象类

### 7.7.6 多态案例3-电脑组装



# 8 文件操作

C++包含头文件`<fstream>`

操作文件包含三个类：

1. ofstream：写操作
2. ifstream：读操作
3. fstream：读写操作

## 8.1 文本文件

### 8.1.1 写文件

1. 包含头文件

   #include<fstream>

2. 创建流对象

   ofstream ofs;

3. 打开文件

   ofs.open("文件路径", 打开方式);

4. 写数据

   ofs << "先写入数据"

5. 关闭文件

   ofs.close();

文件打开方式

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置:文件尾            |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |

文件打开方式可以配合使用，利用操作符`|`

```C++
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
```

### 8.1.2 读文件

1. 包含头文件

   #include<fstream>

2. 创建流对象

   ifstream ifs;

3. 打开文件并判断文件是否打开成功

   ifs.open("文件路径", 打开方式);

4. 读数据

   四种方式读取

5. 关闭文件

   ifs.close();

**四种方式读取**

```C++
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
```

## 8.2 二进制文件

打开方式：ios::binary

### 8.2.1 写文件

函数原型：`ostream& write(const char * buffer, int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

```C++
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
```

### 8.2.2 读文件

函数原型：`istream& read(const buffer, int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

```C++
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
    ifs.read((char *)&p, sizeof(Person)); // 转成char * 形式
    cout << p.m_Name << p.m_Age << endl;
    ifs.close();
}

int main(){
    test1();
    system("pause");
    return 0;
}
```

