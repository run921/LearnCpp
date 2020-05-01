#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
public:
    Person(){}
    Person(int a, int b):m_A(a),m_B(b){}       //初始化列表
    
    //+号运算符重载（成员函数），二元重载
    /*Person operator+(Person &p)
    {
        Person tmp;
        tmp.m_A = this->m_A + p.m_A;
        tmp.m_B = this->m_B + p.m_B;
        return tmp;
    }*/

    int m_A;
    int m_B;
};

//+号运算符重载（全局函数）
Person operator+(Person &p1,Person &p2)     //两个参数，二元运算符重载
{
    Person tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp;
}

//不同类型重载
Person operator+(Person& p1, int a)     //两个参数，二元运算符重载
{
    Person tmp;
    tmp.m_A = p1.m_A + a;
    tmp.m_B = p1.m_B + a;
    return tmp;
}

void test01()
{
    Person p1(10,10);
    Person p2(10,10);
    
    Person p3 = p1 + p2;


    Person p4 = p3 + 10;        //不同类型重载
    cout << "p3的m_a为" << p3.m_A << endl << "p3的m_b为" << p3.m_B << endl;
}


int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}

    