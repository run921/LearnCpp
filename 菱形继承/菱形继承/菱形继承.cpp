#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal
{
public:
    int m_Age;
};

//虚基类Sheep
class Sheep :virtual public Animal
{
};
//虚基类Tuo
class Tuo :virtual public Animal
{
};

class SheepTuo :public Sheep,public Tuo 
{
};

//菱形继承的解决方案：利用虚继承
//操作的是一分共享的数据
void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 10;       
    st.Tuo::m_Age = 20;         

    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;      //两个子类变为虚基类后，输出的值都为20
    cout << st.m_Age << endl;       //成为虚基类之后，不存在二义性，不用作用域也可访问

    //找到Sheep的偏移量操作
    cout << *(int*)((int*)*(int*)&st + 1) << endl;

    //找到Tuo的偏移量操作
    cout << *((int*)((int*)*((int*)&st + 1) + 1)) << endl;

}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}