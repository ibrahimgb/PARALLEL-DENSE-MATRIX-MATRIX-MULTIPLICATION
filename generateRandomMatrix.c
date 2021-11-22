//randem filling
#include <math.h>
#include <stdlib.h>
void generateRandomMatrix(int **matrix, int dim){
	
	int i, j;
	for (i = 0; i < dim; ++i)
	{
		for (j = 0; j < dim; ++j)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}
