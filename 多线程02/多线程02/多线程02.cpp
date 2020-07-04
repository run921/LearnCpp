#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<thread>
#include<string>
using namespace std;

class A
{
public:
    int m_i;
    A(int i) :m_i(i) { cout << "有参构造函数执行！" << this <<"threadID = " << this_thread::get_id() << endl; }
    A(const A &a) :m_i(a.m_i) { cout << "拷贝构造函数执行" << this << "threadID = " << this_thread::get_id() << endl; }
    ~A() { cout << "析构  函数执行" << this << "threadID = " << this_thread::get_id() << endl; }

    void thread_work(int num)
    {
        cout << "类成员函数执行" << "threadID = " << this_thread::get_id() << endl;
    }

};

//陷阱一
//void myprint(const int &i,char *pmybuf)       //detach不要用传引用（假引用），也不要用指针   
void myprint(const int i,const string &pmybuf)
{
    cout << "i:" << i << endl;      //i并不是mvar的引用，实际是值传递，所以主线程detach了子线程，但是i是安全的
    //cout << "pmybuff:" << pmybuf << endl;   //指针在detach子线程时，绝对会有问题
    cout << "pmybuff:" << pmybuf.c_str() << endl;       //使用c_str()接
}


void myprint2(const A& pmybuf)
{
    cout << "子线程myprint2的参数地址是" << &pmybuf << "threadID = " << this_thread::get_id() << endl;
}

int main()
{
    int mvar = 1;
    int mvary = mvar;
    char mybuf[] = "this is a test!";
    //thread myobj(myprint,mvar,mybuf);   //后面两个作为myprint的参数
                                        //其中mvar是被复制进去的，
                                         //对于string接的方式，可能main执行完毕了，mybuf回收了，系统才用mybuf转的string，导致string接到的是无效的内存

    //thread myobj(myprint, mvar, string(mybuf));     //这里直接将mybuf直接转换成string对象，这样可以保证在线程中绝对有效
    //myobj.join();
    //myobj.detach();


    cout << "主线程id是：" << this_thread::get_id() << endl;

    //std::ref 用于包装按引用传递的值。
    //std::cref 用于包装按const引用传递的值。
    //thread myobj2(myprint2, mvar);      //mvar从int隐式转换为A类型,在子线程中构造
    //thread myobj2(myprint2, A(mvar));   //显式转换，在主线程中构造
    ////myobj2.join();
    //myobj2.detach();

    //类成员函数做线程参数
    A myobj_A(10);
    thread myobj3(&A::thread_work,myobj_A,15);  //15是thread_work的参数
    myobj3.join();

    system("pause");
    return EXIT_SUCCESS;

}