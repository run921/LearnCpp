#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

//һ����Ĭ�ϴ��� Ĭ�Ϲ��졢�������������졢operator=��ֵ��������м򷽵�ֵ����
class Person 
{
public:
    Person(int a)
    {
        this->m_A = a;
    }

    int  m_A;
};

void test01()
{
    Person p1(10);

    Person p2(0);
    p2 = p1;        //����Ĭ�ϵ�operator=

    cout << "p2��m_AΪ" << p2.m_A << endl;
}


class Person2 
{
public:
    Person2(const char *name)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName,name);
    }

    Person2& operator=(const Person2 &p)        //void����ֻ��p2=p1�����ã�����p3=p2=p1����
    {
        //�ж�ԭ�ж����Ƿ������ݣ������ͷ�
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }

        this->pName = new char[strlen(p.pName)+1];
        strcpy(this->pName,p.pName);

        return *this;
    }

    ~Person2()
    {
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }

    char* pName;
};

void test02()
{
    Person2 p1("����");
    Person2 p2("��ʣ");
    Person2 p3("");

    p2 = p1;        //����Ĭ�ϼ򵥸�ֵֻ������ǳ������
                      //�����������������ͷŵ��±�����ֻ�ж�=��������
    p3 = p2 = p1;       //=������Ҫ����ֵΪPerson2 &���� ��return *this��
    
    cout << p2.pName << endl;
    cout << p3.pName << endl; 
    ////���ڻ�������
    //int a = 10;
    //int b = 20;
    //int  c;
    //c = b = a;      //���߶�Ϊ20
    //cout << "a:" << a << "b:" << b << "c:" << c << endl;
}


int main()
{
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;

}