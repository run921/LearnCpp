#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person 
{
public:
    Person() {}
    Person(const char* name,int age)
    {
        m_name = (char*)malloc(strlen(name) + 1);
        strcpy(m_name,name);

        m_age = age;
    }

    ~Person()
    {
        cout << "析构函数" << endl;

        if (m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
    }
    


    char* m_name;
    int m_age;
};

void test01()
    {
        Person p1("张三",10);
        Person p2(p1);

    }

int main()
{

    system("pause");
    return EXIT_SUCCESS;

}