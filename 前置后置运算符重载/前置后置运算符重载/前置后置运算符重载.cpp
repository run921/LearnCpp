#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class MyInteger 
{
    //friend ostream & operator<<(ostream & cout, MyInteger & m);    //可以访问私有成员变量
public:
    MyInteger()
    {
        m_Num = 0;
    }
    //前置++重载
    MyInteger & operator++()       //返回“引用”以便输出，
    {
        this->m_Num++;
        return *this;
    }

    //MyInteger operator++()       //如果返回不是引用，那么
    //{                            //myInt = 0; ++(++myInt)之后myInt的值为1 
    //    this->m_Num++;
    //    return *this;
    //}

    //后置++重载
    MyInteger operator++(int)   //int占位区分前后置,返回“值”
    {
        MyInteger tmp = *this;
        m_Num++;
        return tmp;
    }

    int m_Num;
};

//ostream & operator<<(ostream & cout,MyInteger & m)        //输出myInt++会不匹配
//{
//    cout << m.m_Num;
//    return cout;
//}
ostream& operator<<(ostream& cout, MyInteger m)
{
    cout << m.m_Num;
    return cout;
}

void test01()
{
    MyInteger myInt;
    //++myInt;        //前置++
    //myInt++;        //后置++

    //输出++myInt
     cout << ++myInt << endl;    //需要重写

    //输出myInt++
     cout << myInt++ << endl;
     cout << myInt << endl;
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}