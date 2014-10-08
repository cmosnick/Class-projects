all: main.o
	gcc -o all main.o

main.o:
	gcc -c main.c