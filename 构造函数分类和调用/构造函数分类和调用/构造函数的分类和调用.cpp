#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person {
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	Person(int a)
	{
		cout << "�������Ĺ��캯��" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "�������캯��" << endl;
	}

	~Person()
	{
		cout << "��������" << endl;
	}

	int age;

};


void test01()
{
	Person p1(1);		//�в�
	p1.age = 10;

	Person p2(p1);		//����

	Person p3;		//Ĭ��
}



int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;

}