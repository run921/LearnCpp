#define _CRT_SECURE_NO_WARNINGS
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
        cout << "Base中func调用" << endl;
    }

    int  m_A;
};

class Son :public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son中func调用" << endl;
    }

    int m_A;
};

void test01()
{
    Son s1;
    cout << s1.m_A << endl;     //就近原则
    //若要调用父类中的m_A;
    cout << s1.Base::m_A << endl;       //加作用域
    
    s1.func();
    //父类func调用
    s1.Base::func();
}
//子类父类拥有同名的函数、属性，那么子类父类同名的函数、属性同时存在，调用时就近原则
//子类会把父类同名函数都隐藏，需要加作用域

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}