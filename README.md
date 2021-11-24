# hw1_ibrahim-GUOUAL-BELHAMIDI

PARALLEL DENSE MATRIX-MATRIX MULTIPLICATION 


# 1/ Introduction

The purpose of this program is to calculate the matrix product in classical sequence and
in parallel.The code is in c using the pthread library.

# 2/ Architecture

## main.c:
 - Creation une structure BLOCKSIZE.
 
 - Calling "sequentieleMult" "generateRandomMatrix" "printMatrix" "freeUpSpace" functions.
 
 - Allocation of matrices.
 
 - Creation and display of matrices A and B.
 
 - Display and calculation of the sequential and parallel time in seconds.
            
            
## sequentieleMult.c:
   
   - calculating the matrix multiplication sequately



## generateRandomMatrix.c:

   - genirating valus for matrixes.



## printMatrix.c:

   - Display of the result of parallel and sequential computation.




## freeUpSpace.c:

   - freeing allocated RAM space


## paralelleMult.c:

   - Creating threads.
   - taking in charge of the parallel computing.
       
# 3/ Execution:
                                                              
                                                              
- a makefile compiles all the files and creates an executable mmm file

           -  ./mmm [p / P calculation mode for parallel or s / S for sequential] [the dimension of the matrices] [number of threads] [paralleleVersion]



2 thread 100    ->  s 0.010498  0.010128  p 0.009872 0.010596 / 0.010651 0.010796 / 0.011020 0.010634 /   0.010770 0.010397

4 200            ->  s 0.492604 0.468841 p 0.808526  0.779946 / 0.779406  0.789195 / 0.792635  0.778527 /  0.774943  0.756273

8 400            ->  s 

16 600

32 800


# 4 Results:


| # threads              	| 2    	| 2    	| 4    	| 4    	| 8    	| 8    	| 16   	| 16   	| 32   	| 32   	|
|------------------------	|------	|------	|------	|------	|------	|------	|------	|------	|------	|------	|
| /                      	| Tpar 	| SpUp 	| Tpar 	| SpUp 	| Tpar 	| SpUp 	| Tpar 	| SpUp 	| Tpar 	| SpUp 	|
| Row- wise distr        	|      	|      	|      	|      	|      	|      	|      	|      	|      	|      	|
| column -wise distr     	|      	|      	|      	|      	|      	|      	|      	|      	|      	|      	|
| 2D- decomp (Fig. 2(a)  	|      	|      	|      	|      	|      	|      	|      	|      	|      	|      	|
| 2D- decomp (Fig. 1(b)) 	|      	|      	|      	|      	|      	|      	|      	|      	|      	|      	|


# 5 Decomposition of dense matrix-matrix multiplication:

![sc](https://user-images.githubusercontent.com/59414164/143321476-008eee95-6e0d-49ac-9197-47bb86835a00.png)
