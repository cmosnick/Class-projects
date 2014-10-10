all: distance ddistance components dcomponents clean

distance: distance.o fileReadSingle.o bfs.o printDistance.o
	gcc -o distance distance.o

ddistance: ddistance.o fileReadSingle.o bfs.o printDdistance.o
	gcc -o ddistance ddistance.o

components: components.o fileReadDouble.o dfs.o printComponents.o
	gcc -o components components.o

dcomponents: dcomponents.o fileReadDouble.o dfs.o printdComponents.o
	gcc -o dcomponents dcomponents.o

printDistance.o: printDistance.c printDistance.h
	gcc -c printDistance.c

printComponents.o: printComponents.c printComponents.h
	gcc -c printComponents.c

printdComponents.o: printdComponents.c printdComponents.h
	gcc -c printdComponents.c

fileReadDouble.o: fileReadDouble.h
	gcc -c fileReadDouble.c

fileReadSingle.o:  fileReadSingle.h
	gcc -c fileReadSingle.c

distance.o: distance.c distance.h
	gcc -c distance.c

ddistance.o: ddistance.c ddistance.h
	gcc -c ddistance.c

components.o: components.c components.h
	gcc -c components.c

dcomponents.o: dcomponents.c dcomponents.h
	gcc -c dcomponents.c

bfs.o: bfs.c bfs.h
	gcc -c bfs.c

dfs.o:	dfs.c dfs.h
	gcc -c dfs.c

clean:
	rm *.o all