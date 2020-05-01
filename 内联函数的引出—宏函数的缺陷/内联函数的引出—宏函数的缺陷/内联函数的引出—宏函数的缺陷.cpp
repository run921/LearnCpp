#include<iostream>
using namespace std;

//宏缺陷1
//定义一个加法
#define MyAdd(x,y) x+y
//#define MyAdd(x,y) x+y	//需要变为#define MyAdd(x,y) ((x)+(y))

void test01()
{
	int ret = MyAdd(10,20)*20;	//预期600结果是410，
	cout << ret << endl;
}

//宏缺陷2
#define MyCompare(a,b) (a) < (b) ? (a) : (b)

void test02()
{
	int a = 10;
	int b = 20;
	int ret = MyCompare(++a,b);		//预期结果11，(++a)<(b)?(++a):b	其中++a执行了两次
	cout << "ret-" <<ret<<endl;

}

//宏函数没有作用域

int main()
{
	//test01();
	test02();
	system("pause");
	return 1;
}