#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
private:
    static void func2()
    {
        cout << "func����" << endl;
    }

public:
    Person()
    {}

    static int m_Age;       //����static���Ǿ�̬��Ա�������Ṳ������
    //���������������ʼ��

    static void func()
    {
        cout << "func����" << endl;
    }
};
int Person::m_Age = 0;

void test01()
{
    //1��ͨ�������������
    Person p1;
    p1.m_Age = 10;

    Person p2;
    p2.m_Age = 20;

    cout << "p1 = " << p1.m_Age << endl;
    cout << "p2 = " << p2.m_Age << endl;        
    
    //2��ͨ��������������
    cout << "ͨ����������" << Person::m_Age<<endl;
    
    //��̬��Ա��������
    p1.func();
    p2.func();
    Person::func();
    // Person::func2();    //˽�о�̬��Ա��������ʧ��

}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}