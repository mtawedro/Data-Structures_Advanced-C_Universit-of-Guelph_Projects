CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o

main:

		gcc $(CFLAGS) src/main.c main.o

book:
		gcc $(CFLAGS) src/book.c book.o

build: main book
		gcc main.o book.o libLinkedList.a -o main

run:

		-/bin/runMe

clean:

