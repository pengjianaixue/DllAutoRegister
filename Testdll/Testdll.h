﻿#pragma once
#ifdef FUNCTIONEXPORT
#define FUNCTIONAPI   __declspec(dllexport)
#else
#define FUNCTIONAPI  _declspec (dllimport)
#endif // functionexport 

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	int FUNCTIONAPI add(int x, int y);
#ifdef __cplusplus
}
#endif // __cplusplus

