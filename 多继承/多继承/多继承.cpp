#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base1 
{
public:
    Base1()
    {
        m_A = 10;
    }


    int m_A;
};

class Base2 
{
public:
    Base2()
    {
        m_B = 20;
    }

    int m_A;        //同Base1一样都有m_A;
    int m_B;
};

class Son :public Base1, public Base2
{
public:

    int m_C;
    int m_D;
};

//多继承容易引发二义性

void test01() 
{
    cout << sizeof(Son) << endl;

    Son s1;
    //s1.m_A;       //二义性
    cout << s1.Base1::m_A << endl;      //加作用域避免
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}