#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    Base()
    {
        cout << "BaseĬ�Ϲ��캯������" << endl;
    }
    ~Base()
    {
        cout << "Base������������" << endl;
    }
};

//�����̳и���ĳ�Ա���ԣ���Ա����
//�������಻��̳и��� ���캯�� �� ��������
//ֻ�и����Լ�֪����ι���������Լ������ԣ������಻֪��

class Son :public Base 
{
public:
    Son()
    {
        cout << "SonĬ�Ϲ��캯������" << endl;
    }
    ~Son()
    {
        cout << "Son������������" << endl;
    }
};

void  test01()
{
    Base b1;
    Son s1;
}

class Base2 
{
public:
    Base2(int a)
    {
        this->m_A = a;
        cout << "�вι������" << endl;
    }

    int m_A;
};

class Son2:public Base2 
{
public:
    Son2() :Base2(10) {}   //���ó�ʼ���б���ʽ�����вι���
    Son2(int a) :Base2(a) {}  //ͨ��a��Base2��ֵ
};

void test02()
{
    Son2 s(1000);
    cout << "Son2:Base2:" << s.m_A << endl;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;

}