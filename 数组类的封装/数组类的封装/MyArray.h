#pragma once
#include<iostream>
using namespace std;

class MyArray
{
public:
	MyArray();	//Ĭ�Ϲ���
	MyArray(int capacity);
	MyArray(const MyArray &array);		//��������

	~MyArray();

	//β�巨
	void push_Back(int val);
	//����������ȡֵ
	int getData(int index);
	//������������ֵ
	void setData(int index,int val);
private:
	int *pAddress;		//ָ�������洢���ݵ�ָ��
	int m_Size;
	int m_Capacity;
};
