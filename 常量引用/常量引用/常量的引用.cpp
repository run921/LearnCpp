#include<iostream>
using namespace std;

void test01() 
{
	//int &ref = 10;	//�����˲��Ϸ����ڴ�
	const int& ref = 10;	//��const�󣬱���������ʽ��int temp = 10;const int &ref = temp;

	//ref = 10;	//������ֱ���޸�
	int* p = (int*)&ref;
	*p = 1000;
	cout << "ref =" << ref << endl;
}	

//��������ʹ�ó��������������β�
void showValue(const int &val)
{
	//val += 100;		//���ֻ������ʾ���ݶ����޸ģ���ô��const�����β�
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