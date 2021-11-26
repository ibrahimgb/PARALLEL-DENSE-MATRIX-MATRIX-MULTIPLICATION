all:	app-hw1

app-hw1:main.o freeUpSpace.o generateRandomMatrix.o paralelleMult.o printMatrix.o sequentieleMult.o cheking.o #thread.o
	gcc main.o freeUpSpace.o generateRandomMatrix.o paralelleMult.o printMatrix.o sequentieleMult.o cheking.o -o mmm -lm -lpthread

main.o:	main.c
	gcc -c main.c -o main.o 

freeUpSpace.o:	freeUpSpace.c
	gcc -c freeUpSpace.c -o freeUpSpace.o
	
generateRandomMatrix.o:	generateRandomMatrix.c
	gcc -c generateRandomMatrix.c -o generateRandomMatrix.o	

paralelleMult.o:	paralelleMult.c
	gcc -c paralelleMult.c -o paralelleMult.o
	
printMatrix.o: printMatrix.c
	gcc -c printMatrix.c -o printMatrix.o
	
sequentieleMult.o: sequentieleMult.c
	gcc -c sequentieleMult.c -o sequentieleMult.o

cheking.o: cheking.c
	gcc -c cheking.c -o cheking.o



clean:
	rm -fr app-hw1 *.o