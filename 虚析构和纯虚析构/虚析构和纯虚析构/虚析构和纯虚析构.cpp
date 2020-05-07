#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal 
{
public:
    virtual void speak()
    {
        cout << "������˵��" << endl;
    }

    //��ͨ�����ǲ���������������ģ����ܻᵼ���ͷŲ��ɾ�
    //����������������������
    /*virtual ~Animal()
    {
        cout << "Animal����������" << endl;
    }*/
    //��������
    //������������Ҫ����������Ҫʵ�֣�������������ʵ��
    virtual ~Animal() = 0;      //��ʵ�֣��ڴ���������Ҳ��������壬��������
    //�д�����������Ҳ������࣬������ʵ����
}; 
Animal::~Animal()
{
    cout << "Animal�Ĵ�����������" << endl;
}

class Cat :public Animal
{
public:
    Cat(const char* name)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name,name);
    }
    virtual void speak()
    {
        cout << "Сè��˵��" << endl;
    }

    ~Cat()
    {
        cout << "Cat��������" << endl;
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char* m_Name;
};

void test01()
{
    Animal* anmial = new Cat("TOM");
    anmial->speak();

    delete anmial;
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}