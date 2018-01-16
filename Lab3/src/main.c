#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book.h"
#include "LinkedListAPI.h"


void printNum(void *data);
int compareNum(const void* first, const void* second);
void deleteFunction(void *toBeDeleted);

int main(int argc, char ** argv)
{
	
	//FIX MAKEFILE, CHANGE THE LAST 3 FUNCTIONS IN DUMMY.C, ASK ABOUT deleteListNode.
	
	int * Int = malloc(sizeof(int));
	int * Int2 = malloc(sizeof(int));
	int * Int3 = malloc(sizeof(int));
	List * num;
	
	*Int = 7;
	*Int2= 8;
	*Int3 = 9;

	
	num = initializeList(&printNum, &deleteFunction, &compareNum);

	insertSorted(num, Int);
	insertFront(num, Int2);
	insertFront(num, Int3);
	printBackwards(num);
	
	printf("\n");

	printForward(num);





return 0 ;
}


void printNum(void *data)
{
	
	printf("%d\n", *(int*)data);
	

}


void deleteFunction(void *toBeDeleted)
{
	
	return;
}


int compareNum(const void *first, const void*second)
{
	int *x= malloc(sizeof(int));
	int *y = malloc(sizeof(int));
	
	x = (int*)first;
	y = (int*)second;
	
	if(x == y)
	{
		return 0;
		
	}
	
	else
	{
		return -1;
	}
	
	
	
}



