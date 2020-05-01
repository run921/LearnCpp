#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

class Person
{
public:
    void show()
    {
        cout << "Person show" << endl;
    }
    void showAge() 
    {
        if (this == NULL)
        {
            cout << "¿ÕÖ¸Õë·ÃÎÊ»á±À" << endl;
            return;
        }
        cout << "m_Age" << m_Age << endl;
    }

    int m_Age;
};

void test01()
{
    Person* p = NULL;
    p->show();
   p->showAge();
}


int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;

}