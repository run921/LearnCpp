#include<iostream>
using namespace std;

void func()
{
	cout << "û�в����ĺ���" << endl;
}

void func(int a)
{
	cout << "�в���" << a << "�ĺ���" << endl;
}


int main()
{
	func();
	func(10);
	system("pause");
	return 1;
}