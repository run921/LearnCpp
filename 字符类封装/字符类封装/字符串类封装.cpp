#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include"MyString.h"
using namespace std;

//测试MyString类
void test01()
{
    MyString str = "abc";
    cout << str << endl;
  
    /*cout << "输入str新的内容：" << endl;
    cin >> str;
    cout << "输入内内容为：" << str << endl;*/

    MyString str2(str);
    MyString str3 = "aaaaa";

    str3 = str2;
    cout<<"str3:"<<str3<<endl;
    
    str3 = "nihao";         //operator=(char*)
    cout <<"str3:"<< str3 << endl;      //operator=(MyString &)
    
    //operator[]()
    str3[0] = 'w';
    cout << "str3第一个位置是：" << str3[0]<<endl;     

    //字符串拼接
    MyString str4 = "";
    str4 = str3 + str2;     
    cout << "str4:" << str4 << endl;

    //operator==
    if (str == )
    {
        cout << "str3等于str4" << endl;
    }
    else
    {
        cout << "str3不等于str4" << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}