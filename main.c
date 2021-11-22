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
#include "generateRandomMatrix.h"
#include "printMatrix.h"
#include "freeUpSpace.h"
#include "thread.h"
#include "paralelleMult.h"



int **A;
int **B;
int **C;
int **check;
int matrixSize;

void checking(){
  int c, d ;
  bool isCorect = true; 
	sequentieleMult(A, B, check, matrixSize);
     
     
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
     
	
}


int main(int argc, char **argv)
{

	double elapsed_time;
	srand(time(0));

	

	char *Mode = argv[1];			// Variable permet l'utilisateur a choisir le mode de calcul
	matrixSize = atoi(argv[2]); //  La Dimension des matrices
	int numberOfTreds = 1;			//   Nombre des threads utilisés dans le mode paralle
	bool isParalelle;
	int paralleleVersion;

	if ((strcmp(Mode, "S")) == 0 || (strcmp(Mode, "s")) == 0)
	{ // for testing the input
		printf("Sequential execution\n");
		isParalelle = false;
	}
	else if ((strcmp(Mode, "P")) == 0 || (strcmp(Mode, "p")) == 0)
	{
		numberOfTreds = atoi(argv[3]); //   Nombre des threads utilisés dans le mode parallel
		paralleleVersion = atoi(argv[4]);
		printf("Parallel execution\n");
		numberOfTreds = atoi(argv[3]);	  //   Nombre des threads utilisés dans le mode parallel
		paralleleVersion = atoi(argv[4]); /*
												où paralleleVersion prendra la valeur 1, 2 3 ou 4 :
												1 : désigne row-wise distribution
												2 : désigne column-wise distribution
												3 : désigne la décomposition par bloc correspondant à la fig. 2(a)
												4 : désigne la décomposition par bloc correspondant à la fig. 2(b)*/

		isParalelle = true;
	}
	else
	{

		printf("errer input for sequential version 'S' and for the parallel version 'P' ");
		return 0;
	}
	if (matrixSize < 0 || matrixSize > 5000)
	{
		printf("please type the correct input for the dimension of the dies 'betwen 1 and 5000 ");
		return 0;
	}
	if (numberOfTreds < 0 || numberOfTreds > 64)
	{
		printf("please type the correct threds number");
		return 0;
	}
	if (numberOfTreds > matrixSize)
	{
		printf("the number of threads cannot accede matrix size");
		return 0;
	}
	printf("Matrix size = %d\n", matrixSize);
	/*if(isParalelle){
		printf("the threds number is : %s \n", argv[3]);
	}*/

	/*Allocation et initialisation des matrices*/
	A = (int **)malloc(matrixSize * sizeof(int *));
	for (int i = 0; i < matrixSize; i++)
		{
			A[i] = (int *)malloc(matrixSize * sizeof(int));
		}
	printf("The First Matrix : \n");
	generateRandomMatrix(A, matrixSize); // remplir la matrice A aleatoire
	printMatrix(A, matrixSize);			 // afficher la matrice A
	printf("\n");

	B = (int **)malloc(matrixSize * sizeof(int *));
	for (int i = 0; i < matrixSize; i++)
	{
		B[i] = (int *)malloc(matrixSize * sizeof(int));
	}	
	printf("The Second Matrix : \n");
	generateRandomMatrix(B, matrixSize); // remplir la matrice B aleatoire
	printMatrix(B, matrixSize);			 // afficher la matrice B
	printf("\n");

	C = (int **)malloc(matrixSize * sizeof(int *));
	for (int i = 0; i < matrixSize; i++)
	{
		C[i] = (int *)malloc(matrixSize * sizeof(int));
	}

	check = (int **)malloc(matrixSize * sizeof(int *));
	for (int i = 0; i < matrixSize; i++)
	{
		C[i] = (int *)malloc(matrixSize * sizeof(int));
	}

	//printf("Address of a: %p\n", &A);
	//printf("Address of b: %p\n", &B);

	printf("\n");

	printf("%d\n", isParalelle);

	if (isParalelle)
	{
		printf(" it is paralelle\n");

		printf("\n");
		printf("result in the paralelle calcul is :- \n");
		
		clock_t start_time;
		
		clock_t end_time;

		
		if(paralleleVersion=1){
			start_time = clock();
			paralelleMult1( numberOfTreds);
			end_time = clock();
		}
		if(paralleleVersion=2){
			start_time = clock();
			paralelleMult2( numberOfTreds);
			end_time = clock();
		}
		
		/*if(paralleleVersion=3){
			start_time = clock();
			paralelleMult3( A , B , C , matrixSize);
			end_time = clock();
		}
		if(paralleleVersion=4){
			start_time = clock();
			paralelleMult4( A , B , C , matrixSize);
			end_time = clock();
		}*/

		elapsed_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		printf("Total time taken by CPU: %f\n", (double)elapsed_time);
		//printMatrix(C, matrixSize);
	}
	if (!isParalelle)
	{
		printf("\n");
		printf("result in the seriale calcul is :- \n");

		clock_t start_time = clock();
		sequentieleMult(A, B, C, matrixSize);
		clock_t end_time = clock();


		printMatrix(C, matrixSize);

		elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		printf("Total time taken by CPU: %f\n", (double)elapsed_time);

	}


	//checking();

	freeUpSpace(A, matrixSize);
	freeUpSpace(B, matrixSize);
	freeUpSpace(C, matrixSize);
	freeUpSpace(check, matrixSize);

	return 0;
}
