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

	auto task = std::make_shared<std::packaged_task<int()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

	std::function<int()> funtask = [task](){ (*task)();};
	int res = funtask();
	return res;

}
int main()
{	
	
	//变参函数调用
	

	
	typedef int(*funprocess)(void*...);
	typedef std::function<int(void)> TWOINTFUNCTION;
	HMODULE pf = nullptr;
	pf = LoadLibrary(TEXT("./Testdll.dll"));
	TWOINTFUNCTION fn  = GetProcAddress(pf, "add");

	//std::ifstream dllfile;
	int j = 7;
	int k = 8;
	int i = EnqueueTask(fn,j,k);
	std::cout << i << std::endl;
	system("pause");
	
    return 0;
}


