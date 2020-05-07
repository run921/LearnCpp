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

    //普通析构是不会调用子类析构的，可能会导致释放不干净
    //利用虚拟析构解决这个问题
    /*virtual ~Animal()
    {
        cout << "Animal的析构调用" << endl;
    }*/
    //纯虚析构
    //纯虚析构，需要声明，还需要实现，类内声明类外实现
    virtual ~Animal() = 0;      //不实现，在创建对象后找不到析构体，不能运行
    //有纯虚析构的类也算抽象类，不可以实例化
}; 
Animal::~Animal()
{
    cout << "Animal的纯虚析构调用" << endl;
}

class Cat :public Animal
{
public:
    Cat(const char* name)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name,name);
    }
    virtual void speak()
    {
        cout << "小猫在说话" << endl;
    }

    ~Cat()
    {
        cout << "Cat析构调用" << endl;
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char* m_Name;
};

void test01()
{
    Animal* anmial = new Cat("TOM");
    anmial->speak();

    delete anmial;
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}