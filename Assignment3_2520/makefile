CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o


main:
	
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) $(CFLAGS) bin/dict.o src/dict.c 
	$(CC) $(CFLAGS) bin/HashTable.o src/HashTable.c 
	$(CC)  bin/dict.o  bin/linkedList.o  bin/HashTable.o -o bin/runMe

test:
	
	$(CC) $(CFLAGS) bin/mainTest.o src/mainTest.c 
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) $(CFLAGS) bin/HashTable.o src/HashTable.c 
	$(CC) bin/mainTest.o  bin/linkedList.o  bin/HashTable.o -o bin/runTest

clean:
	rm bin/*.o bin/runTest bin/runMe


