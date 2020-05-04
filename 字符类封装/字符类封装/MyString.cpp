#include "MyString.h"

//重载<<
ostream & operator<<(ostream & cout,MyString &str)
{
	cout << str.pString;		//私有不可访问，做友元
	return cout;
}
//重载>>
istream& operator>>(istream & cin,MyString & str)
{
	//先判断原有str里是否有内容，有的话清空
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}

	//让用户输入内容
	char buf[1024];
	cin >> buf;

	//输入内容赋值给str
	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString,buf);
	str.m_Size = strlen(buf);

	return cin;
}

MyString::MyString(const char* str)
{
	//cout << "有参构造调用" << endl;
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
	//cout << "析构调用" << endl;
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
	//计算返回的字符串大小
	int newSize = this->m_Size + strlen(str) +1;
	char* tmp = new char[newSize];
	
	memset(tmp,0,newSize);		//初始化tmp所有值为0

	//拼接字符串
	strcat(tmp,this->pString);
	strcat(tmp,str);

	//赋值tmp给newStr
	MyString newStr(tmp);
	delete[] tmp;

	return newStr;
}

MyString MyString::operator+(const MyString& str)
{
	//计算返回的字符串大小
	int newSize = this->m_Size + strlen(str.pString) + 1;
	char* tmp = new char[newSize];

	memset(tmp, 0, newSize);		//初始化tmp所有值为0

	//拼接字符串
	strcat(tmp, this->pString);
	strcat(tmp, str.pString);

	//赋值tmp给newStr
	MyString newStr(tmp);
	delete[] tmp;

	return newStr;
}

bool MyString::operator==(const char* str)
{
	if (strcmp(this->pString, str) == 0 && this->m_Size == strlen(str))		//strcmp(*,*)比较两个字符串是否相同
		return true;
	return false;
}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) && this->m_Size == strlen(str.pString))
		return true;
	return false;
}
