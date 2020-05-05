#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Base 
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;

};

//子类继承了父类的私有成员，被编译器隐藏不可访问 
class Son :public Base
{
public:
    int m_D;
};

void test01()
{
    cout << sizeof(Son) << endl;        //结果为16，继承了父类包括私有的所有成员
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}