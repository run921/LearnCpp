#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person {
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}

	Person(int a)
	{
		cout << "带参数的构造函数" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}

	~Person()
	{
		cout << "析构函数" << endl;
	}

	int age;

};


void test01()
{
	Person p1(1);		//有参
	p1.age = 10;

	Person p2(p1);		//拷贝

	Person p3;		//默认
}



int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;

}