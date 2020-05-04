#include "MyString.h"

//����<<
ostream & operator<<(ostream & cout,MyString &str)
{
	cout << str.pString;		//˽�в��ɷ��ʣ�����Ԫ
	return cout;
}
//����>>
istream& operator>>(istream & cin,MyString & str)
{
	//���ж�ԭ��str���Ƿ������ݣ��еĻ����
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}

	//���û���������
	char buf[1024];
	cin >> buf;

	//�������ݸ�ֵ��str
	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString,buf);
	str.m_Size = strlen(buf);

	return cin;
}

MyString::MyString(const char* str)
{
	//cout << "�вι������" << endl;
	this->pString = new char[strlen(str)+1];
	strcpy(this->pString,str);
	this->m_Size = strlen(str);
}

MyString::MyString(const MyString& str)
{
	this->pString = new char[strlen(str.pString)+1];
	strcpy(this->pString,str.pString);
	this->m_Size = str.m_Size;
}

MyString::~MyString()
{
	//cout << "��������" << endl;
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
}

MyString& MyString::operator=(const char* str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str)+1];
	strcpy(this->pString,str);

	return *this;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);

	return *this;
}

char& MyString::operator[](int index)
{
	return this->pString[index];
}

MyString MyString::operator+(const char* str)
{
	//���㷵�ص��ַ�����С
	int newSize = this->m_Size + strlen(str) +1;
	char* tmp = new char[newSize];
	
	memset(tmp,0,newSize);		//��ʼ��tmp����ֵΪ0

	//ƴ���ַ���
	strcat(tmp,this->pString);
	strcat(tmp,str);

	//��ֵtmp��newStr
	MyString newStr(tmp);
	delete[] tmp;

	return newStr;
}

MyString MyString::operator+(const MyString& str)
{
	//���㷵�ص��ַ�����С
	int newSize = this->m_Size + strlen(str.pString) + 1;
	char* tmp = new char[newSize];

	memset(tmp, 0, newSize);		//��ʼ��tmp����ֵΪ0

	//ƴ���ַ���
	strcat(tmp, this->pString);
	strcat(tmp, str.pString);

	//��ֵtmp��newStr
	MyString newStr(tmp);
	delete[] tmp;

	return newStr;
}

bool MyString::operator==(const char* str)
{
	if (strcmp(this->pString, str) == 0 && this->m_Size == strlen(str))		//strcmp(*,*)�Ƚ������ַ����Ƿ���ͬ
		return true;
	return false;
}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) && this->m_Size == strlen(str.pString))
		return true;
	return false;
}
