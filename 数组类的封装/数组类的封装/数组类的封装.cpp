#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include"MyArray.h"
using namespace std;

void test01()
{
    //��������
    MyArray *array = new MyArray(30);
    MyArray array3 = *array;
   
    MyArray *array4 = new MyArray(*array);
    MyArray* array2(array);
    //delete array;     //�˴�delete����

    for (int i = 0; i < 10; i++)
    {
        array2->push_Back(i);
    }
    
    array2->setData(0,5);
    
    for (int i = 0; i < 10; i++)
    {
        cout << array2->getData(i) << endl;
    }
    delete array;

    //[]���ز���
    array3.push_Back(1000);
    cout << array3.getData(0) << endl;
    cout << array3[0] << endl;
    array3[0] = 222;        //operator[]����ֵΪint�൱����1000 = 222��������&��������Ϊ��ֵ
    cout << array3[0] << endl;
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;

}