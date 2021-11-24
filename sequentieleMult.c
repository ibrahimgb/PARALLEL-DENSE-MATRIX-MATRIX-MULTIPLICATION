#include "sequentieleMult.h"

void sequentieleMult ( int **C ){
    
    

    
    for (int i=0; i< matrixSize; i++){
        for (int j=0; j< matrixSize; j++){
            C[i][j] = 0;
            for (int k=0; k< matrixSize; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
  
}    