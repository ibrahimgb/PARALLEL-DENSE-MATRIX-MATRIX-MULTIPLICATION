
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "printMatrix.h"
#include "paralelleMult.h"


void *calcul2(void *arg);
void *calcul1(void *arg);
void *calcul3(void *arg);
void *calcul4(void *arg);
int numberOfThreds;
/* global variable declaration */

/*
 * matrix multiplication with threads
 *this version uses threads to divide up the work necessary to compute the
 *product of two matrices each thread p will compute a block of n/p rows
 * numberOfThreds number of threads
 * n the size of the matrix
 */



void *calcul1(void *arg) {
  int row_start, row_end;
  int i, j, k;
  // int threadID = *((int*) args);  //cast argument to an int
  int threadID = (long)arg;

  // calculate  a block of n/p rows per thread
  int b = matrixSize / numberOfThreds;
  row_start = threadID * b;
  row_end = row_start + b - 1;
  // calculate the last rows for the last thread
  if (threadID == (numberOfThreds - 1)) {

    row_end = matrixSize - 1;
  }

  for (i = row_start; i <= row_end; i++) {
    for (j = 0; j < matrixSize; j++) {
		C[i][j]=0;
        for (k = 0; k < matrixSize; k++) {
        	C[i][j] += A[i][k] * B[k][j];
        }
    }
  }

  pthread_exit(NULL); // exit threads
}





void paralelleMult1(int numberOfThred) {
	numberOfThreds  = numberOfThred;
  // allocate space for storing N threads
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * numberOfThreds);

  // spawn off N threads, each calling threadFunction(i)
  long i;

  for (i = 0; i < numberOfThreds; i++)
    pthread_create(&threads[i], NULL, calcul1, (void *)i);

  // wait for all threads to finish
  for (i = 0; i < numberOfThreds; i++)
    pthread_join(threads[i], NULL);
}




void paralelleMult2(int numberOfThred) {
  	numberOfThreds  = numberOfThred;	
  // allocate space for storing N threads
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * numberOfThreds);

  // spawn off N threads, each calling threadFunction(i)
  long i;

  for (i = 0; i < numberOfThreds; i++)
    pthread_create(&threads[i], NULL, calcul2, (void *)i);

  // wait for all threads to finish
  for (i = 0; i < numberOfThreds; i++)
    pthread_join(threads[i], NULL);
}

void *calcul2(void *arg) {

  int col_start, col_end;
  int i, j, k;
  // int threadID = *((int*) args);  //cast argument to an int
  int threadID = (long)arg;
  // calculate  a block of n/p columns per thread
  int b = matrixSize / numberOfThreds;
  col_start = threadID * b;
  col_end = col_start + b - 1;
  // calculate the last columns for the last thread
  if (threadID == (numberOfThreds - 1)) {
    col_end = matrixSize - 1;
  }

  for (i = col_start; i <= col_end; i++) {
    for (j = 0; j < matrixSize; j++) {
		C[j][i]=0;
      	for (k = 0; k < matrixSize; k++) {

        	C[j][i] += A[j][k] * B[k][i];

      	}
    }
  }

  pthread_exit(NULL); // exit threads
}







void paralelleMult3(int numberOfThred) {
  	numberOfThreds  = numberOfThred;	
  // allocate space for storing N threads
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * numberOfThreds);

  // spawn off N threads, each calling threadFunction(i)
  long i;

  for (i = 0; i < numberOfThreds; i++)
    pthread_create(&threads[i], NULL, calcul3, (void *)i);

  // wait for all threads to finish
  for (i = 0; i < numberOfThreds; i++)
    pthread_join(threads[i], NULL);
}

void *calcul3(void *arg) {

	int col_start, col_end , row_start , row_end;
	int i, j, k;
	int block_size = matrixSize/sqrt(numberOfThreds);
	//int threadID = *((int*) *args);  //cast argument to an int
	int threadID = (long)arg;
	// calculate  a block of n/p columns per thread
	int b = matrixSize / numberOfThreds;
	col_start = threadID/sqrt(numberOfThreds)*block_size;
	
	// calculate the last columns for the last thread
	if (threadID < (sqrt(numberOfThreds)*sqrt(numberOfThreds-1))) {
		col_end = col_start + block_size - 1;
	}else{
		col_end = matrixSize-1;
	}

	for (i = col_start; i <= col_end; i++) {
		for (j = row_start; j < row_end; j++) {
			C[j][i]=0;
			for (k = 0; k < matrixSize; k++) {

				C[j][i] += A[j][k] * B[k][i];

			}
		}
	}

  pthread_exit(NULL); // exit threads
}









void paralelleMult4(int numberOfThred) {
  	numberOfThreds  = numberOfThred;	
  // allocate space for storing N threads
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * numberOfThreds);

  // spawn off N threads, each calling threadFunction(i)
  long i;

  for (i = 0; i < numberOfThreds; i++)
    pthread_create(&threads[i], NULL, calcul4, (void *)i);

  // wait for all threads to finish
  for (i = 0; i < numberOfThreds; i++)
    pthread_join(threads[i], NULL);
}

void *calcul4(void *arg) {

	int col_start, col_end , row_start , row_end;
	int i, j, k;
	int block_size = matrixSize/numberOfThreds/2;
	//int threadID = *((int*) *args);  //cast argument to an int
	int threadID = (long)arg;
	// calculate  a block of n/p columns per thread
	col_start = threadID%(numberOfThreds/2); 
	
	if(((threadID+1)%numberOfThreds/2) != 0){
		col_end = col_start + block_size - 1;

	}else{
		col_end = matrixSize - 1;
	}
	
	// calculate the last columns for the last thread
	if (threadID < (numberOfThreds/2)) {
		row_start = 0;
		row_end = matrixSize/2-1;
		
		
	}else{
		row_start = matrixSize / 2;
		row_end = matrixSize - 1;

	}

	for (i = col_start; i <= col_end; i++) {
		for (j = row_start; j < row_end; j++) {
			C[j][i]=0;
			for (k = 0; k < matrixSize; k++) {

				C[j][i] += A[j][k] * B[k][i];

			}
		}
	}

  pthread_exit(NULL); // exit threads
}

