#include<iostream>
using namespace std;

void func(int a = 10,int b = 20)
{
	cout << "a + b =" << a + b << endl;
}

int main()
{
	func();
	
	system("pause");
	return 1;
}