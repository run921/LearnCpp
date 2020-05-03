#pragma once
#include<iostream>
using namespace std;

class MyArray
{
public:
	MyArray();	//默认构造
	MyArray(int capacity);
	MyArray(const MyArray &array);		//拷贝构造
	~MyArray();

	//重载[]运算符
	int& operator[](int index);

	//尾插法
	void push_Back(int val);
	//根据索引获取值
	int getData(int index);
	//根据索引设置值
	void setData(int index,int val);
private:
	int *pAddress;		//指向真正存储数据的指针
	int m_Size;
	int m_Capacity;
};
