#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    static void func()
    {
        cout << "Bese中的func()" << endl;
    }
    static void func(int a)
    {
        cout << "Bese中的func(int a)" << endl;
    }

    static int m_A;
};

int Base::m_A  = 10;        //类外初始化

class Son :public Base 
{
public:
    static void func()
    {
        cout << "Son中的func()" << endl;
    }

    static int m_A;
};

int Son::m_A = 20;      //如果子类中有同名静态成员，会隐藏父类同名静态成员

//静态成员属性可以被子类继承
void test01()
{
    cout << Son::m_A << endl;

    //访问父类
    cout << Base::m_A << endl;

    Son::func();
    Base::func();
    Base::func(10);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}