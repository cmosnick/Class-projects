all: main.o fileReadFuncs.o graphAlgs.o bfs.o
	gcc -o all main.o 

main.o: fileReadFuncs.h graphAlgs.h bfs.h main.c 
	gcc -c main.c

fileReadFuncs.o: 
	gcc -c fileReadFuncs.c 

graphAlgs.o: 
	gcc -c graphAlgs.c

bfs.o:
	gcc -c bfs.c

clean:
	rm *.o all