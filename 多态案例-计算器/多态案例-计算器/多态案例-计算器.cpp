#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

//旧方法，可扩展性差
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

//真正的开发中有个开发原则：开闭原则
//对扩展开放，对修改关闭

//利用多态实现计算器
class abstractCalculator
{
public:
    //虚函数
    //virtual int getResult(){   return 0;}

    //纯虚函数
    //如果父类有了纯虚函数，那么子类继承就必须实现纯虚函数
    //如果父类有了纯虚函数，那么父类就无法实例化对象
    //有了纯虚函数的类 又称为抽象类 
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
//加法计算器
class PlusCalculator :public abstractCalculator 
{
public:
    virtual int getResult()
    {
        return val1 + val2;
    }
};
//减法计算器
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
    //加法
    abc = new PlusCalculator;
    abc->setv1(10);
    abc->setv2(20);

    cout << abc->getResult() << endl;
    delete abc;

    //减法
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