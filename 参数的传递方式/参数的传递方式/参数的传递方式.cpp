#include<iostream>
using namespace std;

void mySwap01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "mySwap a = " << a << endl;
	cout << "mySwap b = " << b << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap01(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void mySwap02(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	cout << "mySwap a = " << da << endl;
	cout << "mySwap b = " << b << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	mySwap02(&a,&b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main() 
{
	//test01();
	test02();
	system("pause");
	return 1;
}