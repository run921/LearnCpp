#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
public:
    Person()
    {
        cout << "默认构造" << endl;
    }

    ~Person() 
    {
        cout << "析构函数" << endl;
    }
};

void test01()
{
    //Person p1;     //栈区开辟
    //Person* p2 = new Person;        //堆区开辟
    void* p3 = new Person;
    delete p3;      //void类型接收new对象，无法释放
}


int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}