#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<thread>
#include<string>
using namespace std;

class A
{
public:
    int m_i;
    A(int i) :m_i(i) { cout << "�вι��캯��ִ�У�" << this <<"threadID = " << this_thread::get_id() << endl; }
    A(const A &a) :m_i(a.m_i) { cout << "�������캯��ִ��" << this << "threadID = " << this_thread::get_id() << endl; }
    ~A() { cout << "����  ����ִ��" << this << "threadID = " << this_thread::get_id() << endl; }

    void thread_work(int num)
    {
        cout << "���Ա����ִ��" << "threadID = " << this_thread::get_id() << endl;
    }

};

//����һ
//void myprint(const int &i,char *pmybuf)       //detach��Ҫ�ô����ã������ã���Ҳ��Ҫ��ָ��   
void myprint(const int i,const string &pmybuf)
{
    cout << "i:" << i << endl;      //i������mvar�����ã�ʵ����ֵ���ݣ��������߳�detach�����̣߳�����i�ǰ�ȫ��
    //cout << "pmybuff:" << pmybuf << endl;   //ָ����detach���߳�ʱ�����Ի�������
    cout << "pmybuff:" << pmybuf.c_str() << endl;       //ʹ��c_str()��
}


void myprint2(const A& pmybuf)
{
    cout << "���߳�myprint2�Ĳ�����ַ��" << &pmybuf << "threadID = " << this_thread::get_id() << endl;
}

int main()
{
    int mvar = 1;
    int mvary = mvar;
    char mybuf[] = "this is a test!";
    //thread myobj(myprint,mvar,mybuf);   //����������Ϊmyprint�Ĳ���
                                        //����mvar�Ǳ����ƽ�ȥ�ģ�
                                         //����string�ӵķ�ʽ������mainִ������ˣ�mybuf�����ˣ�ϵͳ����mybufת��string������string�ӵ�������Ч���ڴ�

    //thread myobj(myprint, mvar, string(mybuf));     //����ֱ�ӽ�mybufֱ��ת����string�����������Ա�֤���߳��о�����Ч
    //myobj.join();
    //myobj.detach();


    cout << "���߳�id�ǣ�" << this_thread::get_id() << endl;

    //std::ref ���ڰ�װ�����ô��ݵ�ֵ��
    //std::cref ���ڰ�װ��const���ô��ݵ�ֵ��
    //thread myobj2(myprint2, mvar);      //mvar��int��ʽת��ΪA����,�����߳��й���
    //thread myobj2(myprint2, A(mvar));   //��ʽת���������߳��й���
    ////myobj2.join();
    //myobj2.detach();

    //���Ա�������̲߳���
    A myobj_A(10);
    thread myobj3(&A::thread_work,myobj_A,15);  //15��thread_work�Ĳ���
    myobj3.join();

    system("pause");
    return EXIT_SUCCESS;

}