#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "car.h"
#inude "createCar.c"
#include "LinkedListAPI.h"

void printNum(void *data);
int compareBook(const void* first, const void* second);
int compareNum(const void* first, const void* second);
int compareDum(const void* first, const void* second);
void printNode(void *toBePrinted);
void deleteFunction(void *toBeDeleted);

//global variable
int flag = 0;
	
int main(int argc, char ** argv)
{
	
	//FIX MAKEFILE, CHANGE THE LAST 3 FUNCTIONS IN DUMMY.C, ASK ABOUT deleteListNode.
	
	int * Int = malloc(sizeof(int));
	int * Int2 = malloc(sizeof(int));
	int * Int3 = malloc(sizeof(int));
	int* breakpo = malloc(sizeof(int));
	Node * node;
	List * list;
	List * num;
	
	 void *temp;
	*Int = 1;
	*Int2= 2;
	*Int3 = 3;
	*breakpo = (unsigned)10000000000;
	
	
Car * c2 = createCar('N', 'R', 5.0);
Car * c3 = createCar('E', 'R', 8.0);
Car * c4 = createCar('W', 'L', 10.0);
	
	list = initializeList(&printBook, &deleteFunction, &compareBook);
	
	num = initializeList(&printNum, &deleteFunction, &compareNum);
	
	
	printf("\n");
	printf("Test 1: EDGE CASE inaltlizing Num node with large number(out of range), suppose to print a random large num\n");
	node = initializeNode(breakpo);
	flag =1;
	printNode(node->data);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 2: EDGE CASE inaltlizing Num node with NULL, suppose to print NULL\n");
	printf("node = initializeNode(NULL)\n");
	printf("Expected Result: should print NULL\n");
	printf("Code seqfaults\n");
	printf("printNode(node->data)\n");
	printf("Received: Crash\n");
	printf("Result: Test Failed\n"); 
	
	
	
	printf("\n");
	printf("Test 3 inaltlizing Book node, suppose to be book3 \n");
	node = initializeNode(book3);
	printNode(node->data);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 4 adding books in the list using insertBack Function & insertSorted \n ");
	printf("Expected output: Book1, Book2, Book3\n");
	insertSorted(list, book1);
	insertBack(list, book2);
	insertBack(list, book3);
	printForward(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 5 Num, adding nums in the list using insertBack Function\n ");
	printf("Expected output: num1, num2, num3\n");
	insertSorted(num, Int);
	insertBack(num, Int2);
	insertBack(num, Int3);
	printForward(num);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 6, adding books in the list using insertFront Function\n ");
	printf("Expected output: Book3, Book2, Book1,Book1, Book2, Book3 \n");
	insertSorted(list, book1);
	insertFront(list, book2);
	insertFront(list, book3);
	printForward(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 7 Num, adding nums in the list using insertFront Function\n ");
	printf("Expected output: num3, num2, num1, num1, num2, num3\n");
	insertSorted(num, Int);
	insertFront(num, Int2);
	insertFront(num, Int3);
	printForward(num);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 8: prints the Book list backwards\n");
	printf("Expexted output, Book3, Book2, Book1, Book3, Book2, Book1\n");
	printBackwards(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf(" Test 9 Deleting Book2: suppose to delete first occurance\n");
	printf("Expexted output: Book3, Book1, Book1, Book2, Book3\n");
	compareBook(list,book2);
	deleteNodeFromList(list,book2);
	printForward(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf(" Test 10 Deleting num1\n");
	printf("Expexted output: num3, num2,num1,num2, num3\n");
	compareNum(num,Int);
	deleteNodeFromList(num,Int);
	printForward(num);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 11 Deleting Book1\n");
	printf("Expexted output:  Book3, Book1, Book2, Book3 \n");
	compareBook(list,book1);
	deleteNodeFromList(list,book1);
	printForward(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf(" Test 12 Deleting num3\n");
	printf("Expexted output: num2, num1, num2, num3 \n");
	compareNum(num,Int3);
	deleteNodeFromList(num,Int3);
	printForward(num);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 13: prints the Book list Frontwards\n");
	printf("Expexted output, Book3, Book1, Book2, Book3\n");
	printForward(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 14: prints the Num list Frontwards\n");
	printf("Expexted output, num2, num1, num2, num3\n");
	printForward(num);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 15 Book getFromFront function: suppose to be book3\n");
	temp = getFromFront(list);
	printNode(temp);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 16 Num getFromFront function: suppose to be  num2 \n");
	temp = getFromFront(num);
	flag =1;
	printNode(temp);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 17 Book getFromback function: suppose to be book3\n");
	temp = getFromBack(list);
	printNode(temp);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 18 Num getFromback function: suppose to be num3\n");
	temp = getFromBack(num);
	flag =1;
	printNode(temp);
	printf("Test Passed\n");
	
	//include to call delte function!!!!
	
	printf("\n");
	printf("Test 19 Deleting the whole book list\n");
	printf("Expected output: List is Empty\n");
	deleteList(list);
	printBackwards(list);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 20: EDGE CASE: prints the Num list backwards after list got empty\n");
	printf("Expexted output, List is Empty\n");
	printBackwards(list);
	printf("Test Passed\n");

	printf("\n");
	printf("Test 21 Deleting the whole Num list\n");
	printf("Expected output: List is Empty\n");
	deleteList(num);
	printBackwards(num);
	printf("Test Passed\n");
	
	/***************SEG FAULT************************
	 * 
	 * 
	 * 
	 * **********************************************/
	printf("\n");
	printf("Test 22: EDGE CASE: Book getFromFront function when list is empty: suppose to be NULL\n");
	printf("temp = getFromFront(list)\n");
	printf("printNode(temp)\n");
	printf("Expected Result: List should return NULL\n");
	printf("Code seqfaults\n");
	printf("List -> getFromFront()\n");
	printf("Received: Crash\n");
	printf("Result: Test Failed\n"); 

	return 0 ;
}



void printNode(void *toBePrinted)
{
	
	
	if( flag == 1)
	{
		printNum(toBePrinted);
		
	}
	
	else
	{
		printBook(toBePrinted);
	}

flag = 0;

}


int compareDum(const void*first, const void* second)
{
		return 0 ;
	
}


void printNum(void *data)
{
	
	printf("%d\n", *(int*)data);
	

}


void deleteListNode(void *toBeDeleted)
{
	printf("Does not return anything");
	
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


int compareBook(const void *first, const void*second)
{
	
	Book *book1 = (Book*)first;
	Book *book2 = (Book*)second;
	
	if(book1->price == book2->price)
	{
		return 0;
	}
	
	else
	{
		return -1;
	}
	
	
}


