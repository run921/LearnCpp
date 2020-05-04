#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<string>
using namespace std;

//()重载
class Myprint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

void test01()
{
    Myprint myPrint;
    myPrint("hello world22");      //仿函数
}

class myAdd 
{
public:
    int operator()(int v1,int v2)
    {
        return v1 + v2;
    }
};
void test02()
{
    /*myAdd myadd;
    cout << myadd(1,1) << endl;*/

    //匿名对象
    cout << myAdd()(1, 1) << endl;
}


int main()
{
    test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;

}