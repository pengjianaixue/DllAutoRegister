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
	
	typedef int(*funprocess)(void*...);
	typedef std::function<int(void*...)> TWOINTFUNCTION;
	HMODULE pf = nullptr;
	FARPROC fn  = GetProcAddress(pf, "add");
	funprocess a = (funprocess)fn;
	int i = 3, int j = 4 ,int k = 8;
	const char* name = "test";
	a(&i, &j, name);
	//std::ifstream dllfile;
	system("pause");
    return 0;
}

