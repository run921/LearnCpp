#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal 
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat :public Animal
{
public:
     void speak()
    {
        cout << "猫在说话" << endl;
    }
};

//调用doSpeak,speak函数的地址早绑定好了，早绑定，静态联编，编译阶段就确定好了地址
//如果想调用猫的speak，不能提前绑定好函数的地址，需要在运行的时候再去取地函数地址（动态联编）
//写法：将doSpeak方法改为虚函数
void doSpeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);   //如果存在继承关系，编译器允许进行类型转换
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}