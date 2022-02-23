all:
	gcc -g -c main.c -o main.o
	gcc -g main.o -o main -lpthread

run:
	./main