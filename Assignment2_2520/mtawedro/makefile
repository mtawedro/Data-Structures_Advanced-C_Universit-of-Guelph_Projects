CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o


main:
	
	$(CC) $(CFLAGS) bin/patient.o src/patient.c
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) $(CFLAGS) bin/createPatient.o src/createPatient.c 
	$(CC) $(CFLAGS) bin/PriorityQueue.o src/PriorityQueue.c 
	$(CC)  bin/patient.o  bin/createPatient.o  bin/linkedList.o  bin/PriorityQueue.o -o bin/runMe

test:
	
	$(CC) $(CFLAGS) bin/createPatient.o src/createPatient.c 
	$(CC) $(CFLAGS) bin/testMain.o src/testMain.c 
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) $(CFLAGS) bin/PriorityQueue.o src/PriorityQueue.c 
	$(CC) bin/testMain.o  bin/linkedList.o  bin/createPatient.o  bin/PriorityQueue.o -o bin/runTest

clean:
	rm bin/*.o bin/runTest bin/runMe

