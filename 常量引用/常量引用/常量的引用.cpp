#include<iostream>
using namespace std;

void test01() 
{
	//int &ref = 10;	//引用了不合法的内存
	const int& ref = 10;	//加const后，编译器处理方式：int temp = 10;const int &ref = temp;

	//ref = 10;	//不可以直接修改
	int* p = (int*)&ref;
	*p = 1000;
	cout << "ref =" << ref << endl;
}	

//常量引用使用场景，用来修饰形参
void showValue(const int &val)
{
	//val += 100;		//如果只是想显示内容而不修改，那么用const修饰形参
	cout << "val=" << val << endl;
}

void test02()
{
	int a = 10;
	showValue(a);
}

int main()
{
	test02();
	//test01();
	system("pause");
	return 1;
}