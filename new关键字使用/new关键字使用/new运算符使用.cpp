#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
public:
    Person()
    {
        cout << "Ĭ�Ϲ���" << endl;
    }

    ~Person() 
    {
        cout << "��������" << endl;
    }
};

void test01()
{
    //Person p1;     //ջ������
    //Person* p2 = new Person;        //��������
    void* p3 = new Person;
    delete p3;      //void���ͽ���new�����޷��ͷ�
}


int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}