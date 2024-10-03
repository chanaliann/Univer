#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

/*������� ����� �������*/
void inputArr(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = -50 + rand() % 101;
}

/*������� ������ �������*/
void outputArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d; ", arr[i]);
	puts("\n");
}

/*������� �������� ������������� ��������� � �������*/
void countElA(int* arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 0)
			arr[i] = arr[i] * arr[i];
}