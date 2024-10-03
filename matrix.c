#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

/*������� ���������� �������*/
void inputFunc(int* matrix, int line, int column)
{
	srand(time(NULL));
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i * column + j] = -50 + rand() % 101;
		}
	}
}

/*������� ������ ������� �� �����*/
void outputFunc(int* matrix, int line, int column)
{
	printf("\n");
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%-4d |", matrix[i * column + j]);
		}
		printf("\n");
	}
}

/*������� �������� ������������� ��������� � �������*/
void countEl(int* matrix, int line, int column)
{
	int count = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[i * column + j] % 2 == 0)
				matrix[i * column + j] = matrix[i * column + j] * matrix[i * column + j];
		}
	}
}