

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "printMatrix.h"
#include "paralelleMult.h"

/*
extern	int **A;
extern	int **B;
extern	int **C;
*/

int start;
int end;
int i;



void *mult(void * args){	
	printf("going well \n");

	for(int ii = start; ii<= end; ii++){
		for(int j=0; j<matrixSize; j++)
			//C[i][j] = 0;
			for(int k=0; k<matrixSize; k++){
				C[ii][j] += A[ii][k] * B[k][j];			
			}
		}
	//*/
	return NULL;
}

void paralelleMult1 (int numberOfThreds){
	
	start = 0;
	int count = 0;
	end = (int)matrixSize/numberOfThreds;

	
	pthread_t *threads = (pthread_t*)malloc(numberOfThreds*sizeof(pthread_t));
	
	
	for(i = 0; i< numberOfThreds ; i++){
		

		//start = end;
		//end = end + ((int)matrixSize/numberOfThreds);


		start = i * ((int)matrixSize/numberOfThreds);
		end = start +  ((int)matrixSize/numberOfThreds)-1 + matrixSize % numberOfThreds;


		
		printf("start value is %d\n",start);
		printf("end value is %d\n \n",end);


		pthread_create(&threads[i],NULL,mult, NULL);
		pthread_join(threads[i], NULL);
	
		
		printf("done ! \n \n");
		
	}

	printMatrix(C, matrixSize);	

	
}





/////////////////////////////////////////////////////////////////////////////////colemwise





void *mult2(void * args){	
	printf("going well \n");

	for(int ii = start; ii<= end; ii++){
		for(int j=0; j<matrixSize; j++)
			//C[i][j] = 0;
			for(int k=0; k<matrixSize; k++){
				//C[ii][j] += A[ii][k] * B[k][j];	

				C[j][ii] += A[k][ii] * B[j][k];			
			}
		}
	//*/
	return NULL;
}

void paralelleMult2 (int numberOfThreds){
	
	start = 0;
	int count = 0;
	end = (int)matrixSize/numberOfThreds;

	
	pthread_t *threads = (pthread_t*)malloc(numberOfThreds*sizeof(pthread_t));
	
	
	for(i = 0; i< numberOfThreds ; i++){
		

		//start = end;
		//end = end + ((int)matrixSize/numberOfThreds);


		start = i * ((int)matrixSize/numberOfThreds);
		end = start +  ((int)matrixSize/numberOfThreds)-1 + matrixSize % numberOfThreds;


		
		printf("start value is %d\n",start);
		printf("end value is %d\n \n",end);


		pthread_create(&threads[i],NULL,mult, NULL);
		pthread_join(threads[i], NULL);
	
		
		printf("done ! \n \n");
		
	}

	printMatrix(C, matrixSize);	

	
}
