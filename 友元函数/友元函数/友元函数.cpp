#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Buiding 
{
    friend void goodGay(Buiding* buiding);      //友元函数，可以访问该类私有成员变量
public:
    Buiding()
    {
        this->m_Bedroom = "卧室";
        this->m_Sittingroom = "客厅";
    }

public:
    string m_Sittingroom;

private:
    string m_Bedroom;
};

//全局函数
void goodGay(Buiding * buiding)
{
    cout<<"好友正在访问："<<buiding->m_Sittingroom<<endl;
    cout << "好友正在访问：" << buiding->m_Bedroom<<endl;        //友元以后可以访问
}

void test01()
{
    Buiding* buiding = new Buiding;
    goodGay(buiding);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}