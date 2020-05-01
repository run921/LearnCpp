#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() 
{
	extern const int a;
	printf("a = %d\n", a);

	system("pause");
	return 1;
}