#include<iostream>
using namespace std;

struct Person
{
	int m_Age;
};

void allocatMemory(Person ** p)		//**p�Ǿ����Person���� *p�Ƕ����ָ�� p��ָ���ָ��
{
	*p = (Person *)malloc(sizeof(Person));
	(*p)->m_Age = 10;
}

void test01() 
{
	Person* p = NULL;
	allocatMemory(&p);
	cout <<"p������"<< p->m_Age << endl;
}

//����ָ�����ÿ��ٿռ�
void allocatMemoryByRef(Person* &p)		//ָ�������
{
	p = (Person*)malloc(sizeof(Person));
	p->m_Age = 20;
}

void test02()
{
	Person* p = NULL;
	allocatMemoryByRef(p);
	cout << "p�����䣺" << p->m_Age << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 1;
}