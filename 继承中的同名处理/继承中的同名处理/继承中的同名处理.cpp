#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    Base() 
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base��func����" << endl;
    }


    int  m_A;
};

class Son :public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son��func����" << endl;
    }

    int m_A;
};

void test01()
{
    Son s1;
    cout << s1.m_A << endl;     //�ͽ�ԭ��
    //��Ҫ���ø����е�m_A;
    cout << s1.Base::m_A << endl;       //��������
    
    s1.func();
    //����func����
    s1.Base::func();
}
//���ุ��ӵ��ͬ���ĺ��������ԣ���ô���ุ��ͬ���ĺ���������ͬʱ���ڣ�����ʱ�ͽ�ԭ��
//�����Ѹ���ͬ�����������أ���Ҫ��������

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}