#include <stdio.h>
#include <stdlib.h>


// Displaying matrix
void printMatrix(int **matrix, int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}
