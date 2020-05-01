#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
private:
    static void func2()
    {
        cout << "func调用" << endl;
    }

public:
    Person()
    {}

    static int m_Age;       //加入static就是静态成员变量，会共享数据
    //类内声明，类外初始化

    static void func()
    {
        cout << "func调用" << endl;
    }
};
int Person::m_Age = 0;

void test01()
{
    //1、通过对象访问属性
    Person p1;
    p1.m_Age = 10;

    Person p2;
    p2.m_Age = 20;

    cout << "p1 = " << p1.m_Age << endl;
    cout << "p2 = " << p2.m_Age << endl;        
    
    //2、通过类名访问属性
    cout << "通过类名访问" << Person::m_Age<<endl;
    
    //静态成员函数调用
    p1.func();
    p2.func();
    Person::func();
    // Person::func2();    //私有静态成员函数调用失败

}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}