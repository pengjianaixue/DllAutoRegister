// Testdll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Testdll.h"
#include <string>
#include <iostream>
#include "TypeResolveMarco.h"
#include  <type_traits>
int add(void *x, void *y)
{
	std::is_same<int, decltype(y)> vaule;
	int k = VOIDTO_INT_RESOLVE(x);
	int j = VOIDTO_INT_RESOLVE(y);
	int m = k + j;
	VOIDTO_INT_RESOLVE(y) = m;
	return 0;
}
int strtest(void *str)
{

	std::string a = VOIDTO_STRING_RESOLVE(str);
	std::cout << a << std::endl;
	return 0;
}
int add(int x, int y)
{
	
	return x+y;
}
int main()
{
    return 0;
}

