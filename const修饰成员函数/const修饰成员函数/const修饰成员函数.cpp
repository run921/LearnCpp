#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
public:
    Person()
    {
        //const Person * const this后面的const表示指向不能修改，后面的表示指向的值不能修改 
        this->m_A = 0;
        this->m_B = 0;
    }
    void showinfo() const   //常函数，不允许修改指针指向的值
    {
        //this->m_A = 1000;
        this->m_B = 1000;
        cout << "m_A = " << this->m_A << endl;
        cout << "m_B = " << this->m_B << endl;

    }

    void show2()
    {

    }

    int m_A;
    mutable int m_B;        //加关键字mutbale常函数也可修改
};

void test01()
{
    Person p1;
    p1.showinfo();

    //常对象
    const Person p2;    
    //p2.m_A = 100;     //错误，不允许修改属性
    //p2.show2();       //常对象不可以调用普通成员函数，普通成员函数可以修改属性，违背常对象性质
    p2.showinfo();                  //常对象可以调用常函数    
}


int main()
{

    system("pause");
    return EXIT_SUCCESS;

}