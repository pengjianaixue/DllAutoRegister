// Testdll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Testdll.h"

int add(void *x, void *y)
{
	int *k = (int*)x;
	int *j = (int*)y;
	return *k + *j;
}
int add(int x, int y)
{
	
	return x+y;
}
int main()
{
    return 0;
}

