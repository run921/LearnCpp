#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal        //sizeof(Animal)����virtual��СΪ1�����Ϻ��СΪ4�����˸�vfptrָ��
{
public:
    virtual void speak()
    {
        cout << "������˵��" << endl;
    }
    virtual void eat()
    {
        cout << "�����ڳ�" << endl;
    }

};

class Cat :public Animal
{
public:
     void speak()
    {
        cout << "è��˵��" << endl;
    }

     void eat()
     {
         cout << "è�ڳ���" << endl;
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

void tast02()
{
    cout << sizeof(Animal) << endl;
    //����ָ��ָ��������󣬶�̬
    Animal* animal = new Cat;
    //animal->speak();        //���õ�Cat��speak����
    //������䱾��
    //*(int*)*(int*)animal��ʾCat::speak�ĵ�ַ
    ((void(*)()) * (int*)*(int*)animal)();
    //*((int*)*(int*)animal+1)��ʾCat::eat�ĵ�ַ
    ((void(*)())(*((int*)*(int*)animal + 1)))();
} 

int main()
{
    //test01();
    tast02();

    system("pause");
    return EXIT_SUCCESS;

}