#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
public:
    Person()
    {
        //const Person * const this�����const��ʾָ�����޸ģ�����ı�ʾָ���ֵ�����޸� 
        this->m_A = 0;
        this->m_B = 0;
    }
    void showinfo() const   //���������������޸�ָ��ָ���ֵ
    {
        //this->m_A = 1000;
        this->m_B = 1000;
        cout << "m_A = " << this->m_A << endl;
        cout << "m_B = " << this->m_B << endl;

    }

    void show2()
    {

    }

    int m_A;
    mutable int m_B;        //�ӹؼ���mutbale������Ҳ���޸�
};

void test01()
{
    Person p1;
    p1.showinfo();

    //������
    const Person p2;    
    //p2.m_A = 100;     //���󣬲������޸�����
    //p2.show2();       //�����󲻿��Ե�����ͨ��Ա��������ͨ��Ա���������޸����ԣ�Υ������������
    p2.showinfo();                  //��������Ե��ó�����    
}


int main()
{

    system("pause");
    return EXIT_SUCCESS;

}