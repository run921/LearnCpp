#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal
{
public:
    int m_Age;
};

//�����Sheep
class Sheep :virtual public Animal
{
};
//�����Tuo
class Tuo :virtual public Animal
{
};

class SheepTuo :public Sheep,public Tuo 
{
};

//���μ̳еĽ��������������̳�
//��������һ�ֹ��������
void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 10;       
    st.Tuo::m_Age = 20;         

    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;      //���������Ϊ�����������ֵ��Ϊ20
    cout << st.m_Age << endl;       //��Ϊ�����֮�󣬲����ڶ����ԣ�����������Ҳ�ɷ���

    //�ҵ�Sheep��ƫ��������
    cout << *(int*)((int*)*(int*)&st + 1) << endl;

    //�ҵ�Tuo��ƫ��������
    cout << *((int*)((int*)*((int*)&st + 1) + 1)) << endl;

}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}