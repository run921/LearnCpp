#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<thread>
#include<windows.h>
using namespace std;

class TA
{
public:
    int& m_i;
    TA(int& i) :m_i(i)
    {
        cout << "TA构造函数被执行" << endl;
    }
    TA(const TA& ta) :m_i(ta.m_i)
    {
        cout << "TA的拷贝构造函数被执行" << endl;
    }
    ~TA()
    {
        cout << "析构函数被执行" << endl;
    }

    void operator()() //仿函数
    {
        cout << "我的线程operator()开始执行了" << endl;

        cout << "我的线程operator()执行结束了" << endl;
        for(int a = 0;a<6;a++)
        cout << "m_i的值为：" << m_i << endl;
    }     
};

void myPrint()
{
    for (int i = 0; i < 50; i++)
    {
        cout << "这是子线程 " << i << endl;
    }
}

int main()
{
    cout << "Main开始" << endl;
    //线程创建，方法一（可调用对象：函数）
    //thread myobj(myPrint);
    
    //myobj.join();       //主线程等子线程，
    //myobj.detach();     //主线程与子线程分离
    //if(myobj.joinable())      //joinable,判断是否可以join或detach,返回bool值

    //线程创建，方法二（可调用对象：类对象仿函数）
    int i = 6;      //这种方法有bug，有可能主函数执行完，变量被回收,类成员变量的赋值不确定
    TA ta(i);       //此处并不会因为回收而出问题，因为这儿是被复制到了线程中去的，ta对象销毁，复制的对象还在
    thread myobj2(ta);  //析构函数会被执行两次，第二次析构是复制进去时产生的对象的析构函数
    //myobj2.detach();
    myobj2.join();
    
    //线程创建，方法三（Lambda表达式）
    auto mylambda = [] 
    {
        cout << "我的线程开始执行" << endl;
        //..
        cout << "我的线程执行结束" << endl;
    };
    thread myobj3(mylambda);
    myobj3.join();


    for (int i = 0; i < 50; i++)
    {
        cout << "Main线程 " << i << endl;
    }

    system("pause");
    return EXIT_SUCCESS;

}