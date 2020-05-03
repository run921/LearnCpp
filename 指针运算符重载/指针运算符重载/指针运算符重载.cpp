#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
public:

    Person(int age)
    {
        this->m_Age = age;
    }
    //析构
    ~Person() 
    {
        cout << "析构调用"  << endl;
    }


    void showAge()
    {
        cout << "年龄为：" << this->m_Age << endl;
    }

    int m_Age;
};

//智能指针
//用来托管自定义类型的对象，让对象进行自动释放
class smartPointer
{
public:
    smartPointer(Person *person)
    {
        this->person = person;
    }
    
    //重载->，让智能指针对象象Person *p一样使用
    Person* operator->()
    {

        return this->person;
    }

    //重载*
    Person& operator*()
    {
        return *this->person;
    }

    ~smartPointer()
    {
        cout << "智能指针析构" << endl;
        if (this->person != NULL)
        {
            delete this->person;
            this->person = NULL;
        }
    }
private: 
    Person *person;
};


void test01()
{
    //Person p1(10);      //自动析构
    /*Person* p1 = new Person(10);
    p1->showAge();
    delete p1;   */   //delete后析构
    

    //智能指针写法
    smartPointer sp(new Person(10));        //开辟到了栈上，会自动析构（释放）
    sp->showAge();      //重载->，实现一般指针功能。sp->返回的是指针类型，实际用法为sp->->showAge(),编译器优化了

    (*sp).showAge();        //重载*
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;

}