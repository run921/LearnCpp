#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Animal        //sizeof(Animal)不加virtual大小为1，加上后大小为4，多了个vfptr指针
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
    virtual void eat()
    {
        cout << "动物在吃" << endl;
    }

};

class Cat :public Animal
{
public:
     void speak()
    {
        cout << "猫在说话" << endl;
    }

     void eat()
     {
         cout << "猫在吃鱼" << endl;
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

void tast02()
{
    cout << sizeof(Animal) << endl;
    //父类指针指向子类对象，多态
    Animal* animal = new Cat;
    //animal->speak();        //调用的Cat的speak方法
    //上述语句本质
    //*(int*)*(int*)animal表示Cat::speak的地址
    ((void(*)()) * (int*)*(int*)animal)();
    //*((int*)*(int*)animal+1)表示Cat::eat的地址
    ((void(*)())(*((int*)*(int*)animal + 1)))();
} 

int main()
{
    //test01();
    tast02();

    system("pause");
    return EXIT_SUCCESS;

}