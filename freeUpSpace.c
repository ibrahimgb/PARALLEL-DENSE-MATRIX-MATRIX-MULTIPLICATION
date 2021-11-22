#include <stdlib.h>

void freeUpSpace(int **A, int size){
	for (int i = 0; i < size; ++i) {
		free(A[i]);
	}
	free(A);
}