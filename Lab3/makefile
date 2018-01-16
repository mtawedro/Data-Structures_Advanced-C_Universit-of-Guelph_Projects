CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o


main:
	
	$(CC) $(CFLAGS) bin/car.o src/car.c
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) $(CFLAGS) bin/createCar.o src/createCar.c 
	$(CC)  bin/car.o  bin/createCar.o  bin/linkedList.o  bin/runMe

test:
	
	$(CC) $(CFLAGS) bin/car.o src/car.c
	$(CC) $(CFLAGS) bin/createCar.o src/createCar.c 
	$(CC) $(CFLAGS) bin/testMain.o src/testMain.c 
	$(CC) $(CFLAGS) bin/linkedList.o src/linkedList.c 
	$(CC) bin/testMain.o  bin/car.o bin/linkedList.o  bin/createCar.o  bin/runTest

clean:
	rm bin/*.o bin/runTest bin/runMe
