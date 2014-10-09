all: distance ddistance clean

distance: distance.o fileReadSingle.o bfs.o printDistance.o
	gcc -o distance distance.o

ddistance: ddistance.o fileReadSingle.o bfs.o printDdistance.o
	gcc -o ddistance ddistance.o

printDistance.o: printDistance.c printDistance.h
	gcc -c printDistance.c

fileReadDouble.o: fileReadDouble.c fileReadDouble.h
	gcc -c fileReadDouble.c

fileReadSingle.o:  fileReadSingle.h
	gcc -c fileReadSingle.c

distance.o: distance.c distance.h
	gcc -c distance.c

ddistance.o: ddistance.c ddistance.h
	gcc -c ddistance.c

bfs.o: bfs.c bfs.h
	gcc -c bfs.c

dfs.o:	dfs.c dfs.h
	gcc -c dfs.c

clean:
	rm *.o all