#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
    friend ostream& operator<<(ostream& cout, Person& p);       //˽�г�ԱҲ�ܷ���
public:
    Person(){}
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    //void operator<<(){}       //�������������������Ϊ��Ա����������ֻ����p1<<��ʽ���� 

private:
    int m_A;
    int m_B;
};

/*void operator<<(ostream &cout,Person &p)       //��һ������Ϊcout���ڶ�������Ϊp1
{
    cout << "m_A=" << p.m_A;                    //������ܼ�<<endl
    cout << "m_B=" << p.m_B;
}*/

ostream &operator<<(ostream& cout, Person& p)       //������ܼ����������<<
{
    cout << "m_A=" << p.m_A;                    //��ΪPerson��Ԫ�������Ӷ�����˽�г�Ա
    cout << "m_B=" << p.m_B;

    return cout;
}


void test01()       
{
    Person p1(10,10);
    cout << p1 << endl;
}


int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}