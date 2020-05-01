#include<iostream>
using namespace std;

void func()
{
	cout << "没有参数的函数" << endl;
}

void func(int a)
{
	cout << "有参数" << a << "的函数" << endl;
}


int main()
{
	func();
	func(10);
	system("pause");
	return 1;
}