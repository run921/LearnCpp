#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    static void func()
    {
        cout << "Bese�е�func()" << endl;
    }
    static void func(int a)
    {
        cout << "Bese�е�func(int a)" << endl;
    }

    static int m_A;
};

int Base::m_A  = 10;        //�����ʼ��

class Son :public Base 
{
public:
    static void func()
    {
        cout << "Son�е�func()" << endl;
    }

    static int m_A;
};

int Son::m_A = 20;      //�����������ͬ����̬��Ա�������ظ���ͬ����̬��Ա

//��̬��Ա���Կ��Ա�����̳�
void test01()
{
    cout << Son::m_A << endl;

    //���ʸ���
    cout << Base::m_A << endl;

    Son::func();
    Base::func();
    Base::func(10);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}