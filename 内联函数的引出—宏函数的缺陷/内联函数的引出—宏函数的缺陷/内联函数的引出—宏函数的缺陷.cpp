#include<iostream>
using namespace std;

//��ȱ��1
//����һ���ӷ�
#define MyAdd(x,y) x+y
//#define MyAdd(x,y) x+y	//��Ҫ��Ϊ#define MyAdd(x,y) ((x)+(y))

void test01()
{
	int ret = MyAdd(10,20)*20;	//Ԥ��600�����410��
	cout << ret << endl;
}

//��ȱ��2
#define MyCompare(a,b) (a) < (b) ? (a) : (b)

void test02()
{
	int a = 10;
	int b = 20;
	int ret = MyCompare(++a,b);		//Ԥ�ڽ��11��(++a)<(b)?(++a):b	����++aִ��������
	cout << "ret-" <<ret<<endl;

}

//�꺯��û��������

int main()
{
	//test01();
	test02();
	system("pause");
	return 1;
}