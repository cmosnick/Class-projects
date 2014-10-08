all: main.o fileReadFuncs.o printList.o
	gcc -o all main.o 

main.o: fileReadFuncs.h  printList.h main.c
	gcc -c main.c

fileReadFuncs.o: 
	gcc -c fileReadFuncs.c

printList.o:
	gcc -c printList.c

clean:
	rm *.o all