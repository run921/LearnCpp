#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include"MyString.h"
using namespace std;

//����MyString��
void test01()
{
    MyString str = "abc";
    cout << str << endl;
  
    /*cout << "����str�µ����ݣ�" << endl;
    cin >> str;
    cout << "����������Ϊ��" << str << endl;*/

    MyString str2(str);
    MyString str3 = "aaaaa";

    str3 = str2;
    cout<<"str3:"<<str3<<endl;
    
    str3 = "nihao";         //operator=(char*)
    cout <<"str3:"<< str3 << endl;      //operator=(MyString &)
    
    //operator[]()
    str3[0] = 'w';
    cout << "str3��һ��λ���ǣ�" << str3[0]<<endl;     

    //�ַ���ƴ��
    MyString str4 = "";
    str4 = str3 + str2;     
    cout << "str4:" << str4 << endl;

    //operator==
    if (str == )
    {
        cout << "str3����str4" << endl;
    }
    else
    {
        cout << "str3������str4" << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}