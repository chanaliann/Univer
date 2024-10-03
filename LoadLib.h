#ifndef LOADLIB_H
#define LOADLIB_H

#include <stdio.h>

#ifdef _WIN32
	#include <Windows.h>
#else
	#include <dlfcn.h>
#endif

void LoadRun(const char*, int);

void LoadEnd(const char*);

#endif // !LOADLIB_H
