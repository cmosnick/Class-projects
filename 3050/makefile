all: distance clean

distance: distance.o fileReadSingle.o bfs.o printDistance.o
	gcc -o distance distance.o

printDistance.o: printDistance.c printDistance.h
	gcc -c printDistance.c

fileReadDouble.o: fileReadDouble.c fileReadDouble.h
	gcc -c fileReadDouble.c

fileReadSingle.o:  fileReadSingle.h
	gcc -c fileReadSingle.c

distance.o: distance.c distance.h
	gcc -c distance.c

bfs.o: bfs.c bfs.h
	gcc -c bfs.c

dfs.o:	dfs.c dfs.h
	gcc -c dfs.c

clean:
	rm *.o all