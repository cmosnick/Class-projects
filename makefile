all: main.o fileReadFuncs.o graphAlgs.o
	gcc -o all main.o 

main.o: fileReadFuncs.h graphAlgs.h main.c 
	gcc -c main.c

fileReadFuncs.o: 
	gcc -c fileReadFuncs.c 

graphAlgs.o: 
	gcc -c graphAlgs.c

clean:
	rm *.o all