#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
    Person()
    {
        cout << "Ĭ�Ϲ��캯��" << endl;
    }

    Person(int i)
    {
        cout << "�вι��캯��" << endl;
    }

    Person(const Person &p)
    {
        cout << "�������캯��" << endl;
    }

    ~Person()
    {
        cout << "��������" << endl;
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