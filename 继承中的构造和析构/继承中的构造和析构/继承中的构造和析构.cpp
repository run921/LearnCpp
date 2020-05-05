#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    Base()
    {
        cout << "Base默认构造函数调用" << endl;
    }
    ~Base()
    {
        cout << "Base析构函数调用" << endl;
    }
};

//子类会继承父类的成员属性，成员函数
//但是子类不会继承父类 构造函数 和 析构函数
//只有父类自己知道如何构造和析构自己的属性，而子类不知道

class Son :public Base 
{
public:
    Son()
    {
        cout << "Son默认构造函数调用" << endl;
    }
    ~Son()
    {
        cout << "Son析构函数调用" << endl;
    }
};

void  test01()
{
    Base b1;
    Son s1;
}

class Base2 
{
public:
    Base2(int a)
    {
        this->m_A = a;
        cout << "有参构造调用" << endl;
    }

    int m_A;
};

class Son2:public Base2 
{
public:
    Son2() :Base2(10) {}   //利用初始化列表，显式调用有参构造
    Son2(int a) :Base2(a) {}  //通过a给Base2赋值
};

void test02()
{
    Son2 s(1000);
    cout << "Son2:Base2:" << s.m_A << endl;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;

}