#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
    friend ostream& operator<<(ostream& cout, Person& p);       //私有成员也能访问
public:
    Person(){}
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    //void operator<<(){}       //重载左移运算符不能作为成员函数，否则只能是p1<<形式调用 

private:
    int m_A;
    int m_B;
};

/*void operator<<(ostream &cout,Person &p)       //第一个参数为cout，第二个参数为p1
{
    cout << "m_A=" << p.m_A;                    //输出后不能加<<endl
    cout << "m_B=" << p.m_B;
}*/

ostream &operator<<(ostream& cout, Person& p)       //输出后能继续添加内容<<
{
    cout << "m_A=" << p.m_A;                    //作为Person友元函数，从而访问私有成员
    cout << "m_B=" << p.m_B;

    return cout;
}


void test01()       
{
    Person p1(10,10);
    cout << p1 << endl;
}


int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}