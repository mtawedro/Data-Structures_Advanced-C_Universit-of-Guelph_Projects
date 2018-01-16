CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o


main:
	
	$(CC) $(CFLAGS) bin/sortingprac.o src/sortingprac.c
	$(CC)  bin/sortingprac.o -o bin/runMe

clean:
	rm bin/*.o bin/runMe
