// DllAutoRegister.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <functional>
#include <future>
#include <memory>
#ifdef _WIN32
#include <Windows.h>
#endif // _win32

template < class T, typename ... ARGS>
int functionpack(T t, ARGS ...args)
{

	return 0;
}
int add(int *x, int *y)
{
	return *x + *y;
}
template < class F, class... Args>
//auto EnqueueTask(F&& f, Args&&... args)-> typename std::result_of<F(Args...)>::type
auto EnqueueTask(F&& f, Args&&... args)-> int
{
	using return_type = typename int;
	auto task = std::make_shared<std::function<int(void*...)>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
	int res = (*task)();
	return res;
}
int main()
{	
	
	//变参函数调用

	typedef int(*FUNCTIONCALL)(void*...);
	/*typedef std::function<int(void*...)> FUNCTIONCALL;*/
	HMODULE pf = nullptr;
	pf = LoadLibrary(TEXT("./Testdll.dll"));
	FUNCTIONCALL fn  = (FUNCTIONCALL)GetProcAddress(pf, "add");
	//std::ifstream dllfile;
	int i; int j;
	i = 1; j = 2;
	std::string a = "aaa";
	int k = fn(&i,&j);


	std::cout << j << std::endl;
	system("pause");

    return 0;
}


