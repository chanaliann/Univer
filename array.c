#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

/*функция ввода массива*/
void inputArr(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = -50 + rand() % 101;
}

/*функция вывода массива*/
void outputArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d; ", arr[i]);
	puts("\n");
}

/*функция подсчета отрицательных элементов в массиве*/
void countElA(int* arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 0)
			arr[i] = arr[i] * arr[i];
}