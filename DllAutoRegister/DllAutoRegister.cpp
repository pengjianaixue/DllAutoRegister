// DllAutoRegister.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <functional>
#ifdef _WIN32
#include <Windows.h>
#endif // _win32

template < class T, typename ... ARGS>
int function(T& t, ARGS ...args)
{

	return 0;
}
int add(int x, int y)
{
	return x + y;
}
int main()
{	
	
	std::function<int(int, int)> pfadd = add;
	std::cout << pfadd(1, 2) << std::endl;
	//std::ifstream dllfile;
	system("pause");
    return 0;
}

