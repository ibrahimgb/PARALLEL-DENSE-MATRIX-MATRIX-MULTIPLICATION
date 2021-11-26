
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "sequentieleMult.h"


///*
extern	int **A;
extern	int **B;
extern	int **C;
extern  int **check;
extern  int matrixSize;
//*/

void checking(){
    int c, d ;
    bool isCorect = true; 
	sequentieleMult( check );
     
     
    for (c = 0; c < matrixSize; c++)   
    {  
        for (d = 0; d < matrixSize; d++)   
        { 
            if((C[c][d] != check[c][d]) ){
				isCorect = false;
				break;
			}  
        }     
    }  
	if(isCorect){
		printf("the result is correct\n");
	}else{
		printf("the result is false\n");
	}

	//printMatrix(check, matrixSize);
     
	
}

