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
        cout << "TA���캯����ִ��" << endl;
    }
    TA(const TA& ta) :m_i(ta.m_i)
    {
        cout << "TA�Ŀ������캯����ִ��" << endl;
    }
    ~TA()
    {
        cout << "����������ִ��" << endl;
    }

    void operator()() //�º���
    {
        cout << "�ҵ��߳�operator()��ʼִ����" << endl;

        cout << "�ҵ��߳�operator()ִ�н�����" << endl;
        for(int a = 0;a<6;a++)
        cout << "m_i��ֵΪ��" << m_i << endl;
    }     
};

void myPrint()
{
    for (int i = 0; i < 50; i++)
    {
        cout << "�������߳� " << i << endl;
    }
}

int main()
{
    cout << "Main��ʼ" << endl;
    //�̴߳���������һ���ɵ��ö��󣺺�����
    //thread myobj(myPrint);
    
    //myobj.join();       //���̵߳����̣߳�
    //myobj.detach();     //���߳������̷߳���
    //if(myobj.joinable())      //joinable,�ж��Ƿ����join��detach,����boolֵ

    //�̴߳��������������ɵ��ö��������º�����
    int i = 6;      //���ַ�����bug���п���������ִ���꣬����������,���Ա�����ĸ�ֵ��ȷ��
    TA ta(i);       //�˴���������Ϊ���ն������⣬��Ϊ����Ǳ����Ƶ����߳���ȥ�ģ�ta�������٣����ƵĶ�����
    thread myobj2(ta);  //���������ᱻִ�����Σ��ڶ��������Ǹ��ƽ�ȥʱ�����Ķ������������
    //myobj2.detach();
    myobj2.join();
    
    //�̴߳�������������Lambda���ʽ��
    auto mylambda = [] 
    {
        cout << "�ҵ��߳̿�ʼִ��" << endl;
        //..
        cout << "�ҵ��߳�ִ�н���" << endl;
    };
    thread myobj3(mylambda);
    myobj3.join();


    for (int i = 0; i < 50; i++)
    {
        cout << "Main�߳� " << i << endl;
    }

    system("pause");
    return EXIT_SUCCESS;

}