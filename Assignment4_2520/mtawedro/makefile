CC = gcc
CFLAGS = -Wall -Iinclude -std=c99 -c -o


main:

	$(CC) $(CFLAGS) bin/asst.o src/asst.c 
	$(CC) $(CFLAGS) bin/BinSearchTree.o src/BinSearchTree.c 
	$(CC)  bin/asst.o  bin/BinSearchTree.o -o bin/runMe

test:

	$(CC) $(CFLAGS) bin/testMain.o src/testMain.c 
	$(CC) $(CFLAGS) bin/BinSearchTree.o src/BinSearchTree.c 
	$(CC) bin/testMain.o bin/BinSearchTree.o -o bin/runTest

clean:
	rm bin/*.o bin/runTest bin/runMe

