#include "LoadLib.h"
#include "array.h"
#include "matrix.h"

#define ASIZE 20
#define MCOL 6
#define MLINE 5

void LoadRun(const char* libName, int num)
{
	void* lib;
	#ifdef _WIN32
		lib = LoadLibrary(libName);
		if (!lib)
		{
			printf("cannot open library '%s'\n", libName);
			return;
		}	
		
		if (num == 1)
		{
			void (*funArr)(int*, int);
			char *nameFunc[3] = { "inputArr", "outputArr", "countElA" };
			int flag = 1, i = 0;
			int arr[ASIZE] = { 0 };
			while (flag)
			{
				funArr = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, nameFunc[i++]);
				if (funArr == NULL)
				{
					printf("cannot load func\n");
				}
				else
				{
					funArr(arr, ASIZE);
				}

				if (i == 3)
					flag = 0;
			}
			funArr = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, nameFunc[1]);
			funArr(arr, ASIZE);

		}
		else if (num == 2)
		{
			void (*funMatr)(int*, int, int);
			char* nameFunc[3] = { "inputFunc", "outputFunc", "countEl" };
			int flag = 1, i = 0;
			int matrix[MLINE][MCOL];
			while (flag)
			{
				funMatr = (void (*)(int*, int, int))GetProcAddress((HINSTANCE)lib, nameFunc[i++]);
				if (funMatr == NULL)
				{
					printf("cannot load func\n");
				}
				else
				{
					funMatr(*matrix, MLINE, MCOL);
				}

				if (i == 3)
					flag = 0;
			}
			funMatr = (void (*)(int*, int, int))GetProcAddress((HINSTANCE)lib, nameFunc[1]);
			funMatr(*matrix, MLINE, MCOL);
		}
	#else
		lib = dlopen(libName, RTLD_LAZY);
		if (!lib)
		{
			printf("cannot open library '%s'\n", libName);
			return;
		}


		if (num == 1)
		{
			void (*funArr)(int*, int);
			char* nameFunc[3] = { "inputArr", "outputArr", "countElA" };
			int flag = 1, i = 0;
			int arr[ASIZE] = { 0 };
			while (flag)
			{
				funArr = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, nameFunc[i++]);
				if (funArr == NULL)
				{
					printf("cannot load func\n");
				}
				else
				{
					funArr(arr, ASIZE);
				}

				if (i == 3)
					flag = 0;
			}
			funArr = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, nameFunc[1]);
			funArr(arr, ASIZE);

		}
		else if (num == 2)
		{
			void (*funMatr)(int*, int, int);
			char* nameFunc[3] = { "inputFunc", "outputFunc", "countEl" };
			int flag = 1, i = 0;
			int matrix[MLINE][MCOL];
			while (flag)
			{
				funMatr = (void (*)(int*, int, int))GetProcAddress((HINSTANCE)lib, nameFunc[i++]);
				if (funMatr == NULL)
				{
					printf("cannot load func\n");
				}
				else
				{
					funMatr(matrix, MLINE, MCOL);
				}

				if (i == 3)
					flag = 0;
			}
			funMatr = (void (*)(int*, int, int))GetProcAddress((HINSTANCE)lib, nameFunc[1]);
			funMatr(*matrix, MLINE, MCOL);
		}
	#endif
}

void LoadEnd(const char* libName)
{
	#ifdef _WIN32
		FreeLibrary((HINSTANCE)libName);
	#else
		dlclose(libName);
	#endif
}