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
};

class Cat :public Animal
{
public:
     void speak()
    {
        cout << "è��˵��" << endl;
    }
};

//����doSpeak,speak�����ĵ�ַ��󶨺��ˣ���󶨣���̬���࣬����׶ξ�ȷ�����˵�ַ
//��������è��speak��������ǰ�󶨺ú����ĵ�ַ����Ҫ�����е�ʱ����ȥȡ�غ�����ַ����̬���ࣩ
//д������doSpeak������Ϊ�麯��
void doSpeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);   //������ڼ̳й�ϵ�������������������ת��
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}