#include <stdio.h>
#include <stdlib.h>
#include "LoadLib.h"

#define ASIZE 20
#define MLINE 5
#define MCOl 6

int main()
{
	int menu;
	printf("Choose what you will work with:\n");
	printf("1. Array\n");
	printf("2. Matrix\n");
	scanf_s("%d", &menu);
	if (menu == 1)
	{
		LoadRun("libarray.dll", menu);
	}
	else if (menu == 2)
	{
		LoadRun("libmatrix.dll", menu);
	}
	
	return 0;
}