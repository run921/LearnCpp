#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
    Person()
    {
        cout << "默认构造函数" << endl;
    }

    Person(int i)
    {
        cout << "有参构造函数" << endl;
    }

    Person(const Person &p)
    {
        cout << "拷贝构造函数" << endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

void test01()
{

}

int main()
{

    system("pause");
    return EXIT_SUCCESS;

}