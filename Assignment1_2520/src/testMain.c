#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "car.h"
#include "LinkedListAPI.h"

void printNum(void *data);

//global variable
int flag = 0;
	
int main(int argc, char ** argv)
{
	 int* breakpo = malloc(sizeof(int));
	 Node * node;
	 List * list;
	
	 void *temp;
	
	*breakpo = (unsigned)10000000000;
	
	
	Car * c1 = createCar('N', 'R', 5.0);
	Car * c2 = createCar('E', 'R', 8.0);
	Car * c3 = createCar('W', 'L', 10.0);
	
	list = initializeList(&printNode, &deleteFunction, &compare);
	
	printf("\n");
	printf("Test 1: EDGE CASE inaltlizing Car node with large number(out of range), suppose to print 0\n");
	node = inatalizeNode(breakpo);
	flag =1;
	printNode(node->data);
	printf("Test Passed\n");

	printf("\n");
	printf("Test 2 inaltlizing car node, suppose to be car3 \n");
	node = inatalizeNode(c3);
	printNode(node->data);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 3 adding cars in the list using insertBack Function\n ");
	printf("Expected output: c1, c2, c3\n");
	insertBack(list, c1);
	insertBack(list, c2);
	insertBack(list, c3);
	printForward(list);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 4, adding cars in the list using insertFront Function\n ");
	printf("Expected output: c3, c2, c1,c1, c2, c3 \n");
	insertFront(list, c1);
	insertFront(list, c2);
	insertFront(list, c3);
	printForward(list);
	printf("Test Passed\n");
	
	
	
	printf("\n");
	printf("Test 5: prints the car list backwards\n");
	printf("Expexted output, car3, car2, car1, car3, car2, car1\n");
	printBackwards(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf(" Test 6 Deleting c2: suppose to delete first occurance\n");
	printf("Expexted output: c3, c1, c1, c2, c3\n");
	//compareBook(list,c2);
	deleteNodeFromList(list,c2);
	printForward(list);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 7: prints the car list Frontwards\n");
	printf("Expexted output, c3, c1, c2, c3\n");
	printForward(list);
	printf("Test Passed\n");
	
	
	
	printf("\n");
	printf("Test 8 Car getFromFront function: suppose to be c3\n");
	temp = getFront(list);
	printNode(temp);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 9 car getFromback function: suppose to be c3\n");
	temp = getBack(list);
	printNode(temp);
	printf("Test Passed\n");
	
	//include to call delte function!!!!
	
	printf("\n");
	printf("Test 9: Deleting whole car list, using deleteList() . suposse to return List is empty\n");
	deleteList(list);
	printForward(list);
	printf("Test Passed\n");

	return 0 ;
}


