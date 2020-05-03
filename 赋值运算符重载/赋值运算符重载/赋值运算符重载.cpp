#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

//一个类默认创建 默认构造、析构、拷贝构造、operator=赋值运算符进行简方的值传递
class Person 
{
public:
    Person(int a)
    {
        this->m_A = a;
    }

    int  m_A;
};

void test01()
{
    Person p1(10);

    Person p2(0);
    p2 = p1;        //调用默认的operator=

    cout << "p2的m_A为" << p2.m_A << endl;
}


class Person2 
{
public:
    Person2(const char *name)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName,name);
    }

    Person2& operator=(const Person2 &p)        //void返回只对p2=p1有作用，对于p3=p2=p1不行
    {
        //判断原有堆区是否有内容，进行释放
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }

        this->pName = new char[strlen(p.pName)+1];
        strcpy(this->pName,p.pName);

        return *this;
    }

    ~Person2()
    {
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }

    char* pName;
};

void test02()
{
    Person2 p1("狗蛋");
    Person2 p2("狗剩");
    Person2 p3("");

    p2 = p1;        //调用默认简单赋值只进行了浅拷贝，
                      //两个对象两次析构释放导致崩溃，只有对=进行重载
    p3 = p2 = p1;       //=重载需要返回值为Person2 &类型 （return *this）
    
    cout << p2.pName << endl;
    cout << p3.pName << endl; 
    ////对于基础类型
    //int a = 10;
    //int b = 20;
    //int  c;
    //c = b = a;      //三者都为20
    //cout << "a:" << a << "b:" << b << "c:" << c << endl;
}


int main()
{
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;

}