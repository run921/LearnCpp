#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Buiding 
{
    friend void goodGay(Buiding* buiding);      //��Ԫ���������Է��ʸ���˽�г�Ա����
public:
    Buiding()
    {
        this->m_Bedroom = "����";
        this->m_Sittingroom = "����";
    }

public:
    string m_Sittingroom;

private:
    string m_Bedroom;
};

//ȫ�ֺ���
void goodGay(Buiding * buiding)
{
    cout<<"�������ڷ��ʣ�"<<buiding->m_Sittingroom<<endl;
    cout << "�������ڷ��ʣ�" << buiding->m_Bedroom<<endl;        //��Ԫ�Ժ���Է���
}

void test01()
{
    Buiding* buiding = new Buiding;
    goodGay(buiding);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}