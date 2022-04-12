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






# 4 Results:


| # threads              	| 2        	| 2         	| 4        	| 4         	| 8        	| 8         	| 16       	| 16        	| 32       	| 32        	|
|------------------------	|----------	|-----------	|----------	|-----------	|----------	|-----------	|----------	|-----------	|----------	|-----------	|
| /                      	| Tpar     	| SpUp      	| Tpar     	| SpUp      	| Tpar     	| SpUp      	| Tpar     	| SpUp      	| Tpar     	| SpUp      	|
| Row- wise distr        	| 0.009897 	| 1.5484490 	| 0.073130 	| 0.9391768 	| 0.799205 	| 0.5830669 	| 2.798832 	| 0.6136045 	| 7.288339 	| 0.6429827 	|
| column -wise distr     	| 0.009551 	| 1.6045440 	| 0.074727 	| 0.9191055 	| 0.795295 	| 0.5859335 	| 2.786665 	| 0.6162836 	| 7.036659 	| 0.6659802 	|
| 2D- decomp (Fig. 2(a)  	| 0.014900 	| 1.0285234 	| 0.076176 	| 0.9016225 	| 0.785892 	| 0.5929440 	| 2.791095 	| 0.6153054 	| 7.070935 	| 0.6627519 	|
| 2D- decomp (Fig. 1(b)) 	| 0.013034 	| 1.1757710 	| 0.081335 	| 0.8444335 	| 0.791843 	| 0.5884878 	| 2.759806 	| 0.6222814 	| 7.092029 	| 0.6607807 	|


# 5 Decomposition of dense matrix-matrix multiplication:

![sc](https://user-images.githubusercontent.com/59414164/143321476-008eee95-6e0d-49ac-9197-47bb86835a00.png)
