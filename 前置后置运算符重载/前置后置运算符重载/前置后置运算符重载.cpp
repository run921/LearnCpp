#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class MyInteger 
{
    //friend ostream & operator<<(ostream & cout, MyInteger & m);    //���Է���˽�г�Ա����
public:
    MyInteger()
    {
        m_Num = 0;
    }
    //ǰ��++����
    MyInteger & operator++()       //���ء����á��Ա������
    {
        this->m_Num++;
        return *this;
    }

    //����++����
    MyInteger operator++(int)   //intռλ����ǰ����,���ء�ֵ��
    {
        MyInteger tmp = *this;
        m_Num++;
        return tmp;
    }

    int m_Num;
};

//ostream & operator<<(ostream & cout,MyInteger & m)        //���myInt++�᲻ƥ��
//{
//    cout << m.m_Num;
//    return cout;
//}
ostream& operator<<(ostream& cout, MyInteger m)
{
    cout << m.m_Num;
    return cout;
}

void test01()
{
    MyInteger myInt;
    //++myInt;        //ǰ��++
    //myInt++;        //����++

    //���++myInt
     cout << ++myInt << endl;    //��Ҫ��д

    //���myInt++
     cout << myInt++ << endl;
     cout << myInt << endl;
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}