#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<string>
using namespace std;

class Person
{
public:
    Person(string name,int age) 
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //==重写
    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
    //!=重写
    bool operator!=(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
            return false;
        return true;
    }

public:
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("小明", 10);
    Person p2("小强", 15);
    Person p3("小强", 15);
    //p1对比p2
    if (p1 == p2)
    {
        cout << "p1等于p2" << endl;
    }
    else
    {
        cout << "p1不等于p2" << endl;
    }
    //p2对比p3
    if (p2 == p3)
    {
        cout << "p2等于p3" << endl;
    }
    else
    {
        cout << "p2不等于p3" << endl;
    }

    //不等比较
    if (p2 != p3)
    {
        cout << "p2不等于p3" << endl;
    }
    else
    {
        cout << "p2等于p3" << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}