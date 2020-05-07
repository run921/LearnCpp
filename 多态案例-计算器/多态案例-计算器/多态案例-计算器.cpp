#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

//�ɷ���������չ�Բ�
class Calculator
{
public:
    void setv1(int v)
    {
        this->val1 = v;
    }
    void setv2(int v)
    {
        this->val2 = v;
    }

    int getResult(string oper)
    {
        if (oper == "+")
        {
            return val1 + val2;
        }
        else if (oper == "-")
        {
            return val1 - val2;
        }

    }

private:
    int val1;
    int val2;
};

void test01()
{
    Calculator cal;
    cal.setv1(10);
    cal.setv2(10);
    cout << cal.getResult("+") << endl;
    cout << cal.getResult("-") << endl;
}

//�����Ŀ������и�����ԭ�򣺿���ԭ��
//����չ���ţ����޸Ĺر�

//���ö�̬ʵ�ּ�����
class abstractCalculator
{
public:
    //�麯��
    //virtual int getResult(){   return 0;}

    //���麯��
    //����������˴��麯������ô����̳оͱ���ʵ�ִ��麯��
    //����������˴��麯������ô������޷�ʵ��������
    //���˴��麯������ �ֳ�Ϊ������ 
    virtual int getResult() = 0;
    void setv1(int v)
    {
        this->val1 = v;
    }
    void setv2(int v)
    {
        this->val2 = v;
    }

    int val1;
    int val2;
};
//�ӷ�������
class PlusCalculator :public abstractCalculator 
{
public:
    virtual int getResult()
    {
        return val1 + val2;
    }
};
//����������
class SubCalculator :public abstractCalculator 
{
public:
    virtual int getResult()
    {
        return val1 - val2;
    }
};

void test02()
{
    abstractCalculator* abc;       
    //�ӷ�
    abc = new PlusCalculator;
    abc->setv1(10);
    abc->setv2(20);

    cout << abc->getResult() << endl;
    delete abc;

    //����
    abc = new SubCalculator;
    abc->setv1(10);
    abc->setv2(20);

    cout << abc->getResult() << endl;
    delete abc;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;

}