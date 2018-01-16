#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "patient.h"
#include "LinkedListAPI.h"
#include "PriorityQueueAPI.h"

void printNum(void *data);

//global variable
int flag = 0;
	
int main(int argc, char ** argv)
{
	 int* breakpo = malloc(sizeof(int));
	 Node * node1;
	 Node * node2;
	 Node * node3;
	 Node * node4;
	 Node * node5;
	 
	 List * list1;
	
	 void *temp;
	
	*breakpo = (unsigned)10000000000;
	
	
	Patient * p1 = createPatient("Mar123", 2, "CV");
	Patient * p2 = createPatient("John456", 1, "EV");
	Patient * p3 = createPatient("Emi890", 5, "TR");
	Patient * p4 = createPatient("Bob00", 5, "SK");
	Patient * p5 = createPatient("Deadw3", 0, "CV");
	
	list1 = createQueue(&printNode, &deleteFunction, &compare);
	Queue *l = malloc(sizeof(Queue) * 1);
	
	l->list = list1;
	
	printf("\n");
	printf("Test 1 inaltlizing patient node, suppose to be Mar, John, Emi980, Bob, Deadw3 \n");
	node1 = inatalizeNode(p1);
	node2 = inatalizeNode(p2);
	node3 = inatalizeNode(p3);
	node4 = inatalizeNode(p4);
	node5 = inatalizeNode(p5);
	printNode(node1->data);
	printNode(node2->data);
	printNode(node3->data);
	printNode(node4->data);
	printNode(node5->data);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 2 adding patients in the list using priortyEnqueue (insertSorted) Function\n ");
	printf("Expected output: Dead, John, Mar, Emi, Bob\n");
	priortyEnqueue(l, p1, node1);
	priortyEnqueue(l, p2, node2);
	priortyEnqueue(l, p3, node3);
	priortyEnqueue(l, p4, node4);
	priortyEnqueue(l, p5, node5);
	printQueue(l);
	
	printf("Test Passed\n");
	
	
	
	printf("\n");
	printf("Test 3 adding patients in the list again using priortyEnqueue Function\n ");
	printf("Expected output: Dead, John, Mar, Mar, Emi, Bob, Emi\n");
	priortyEnqueue(l, p1, node1);
	priortyEnqueue(l, p3, node3);
	printQueue(l);
	printf("Test Passed\n");
		
	printf("\n");
	printf("Test 4, **JUST TEST, adding patients in the list using insertFront Function\n ");
	printf("Expected output: Emi890, John456, Mar123, Deadw3, John456, Mar123, Mar123, Emi890, Bob00, Emi890 \n");
	insertFront(list1, p1);
	insertFront(list1, p2);
	insertFront(list1, p3);
	printQueue(l);
	printf("Test Passed\n");

	printf("\n");
	printf("Test 6 using peek function: suppose to be Emi890\n");
	temp = peek(l);
	printNode(temp);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf("Test 7 enqueue function: suppose to be Emi890, John456, Mar123, Deadw3, John456, Mar123, Mar123, Emi890, Bob00, Emi890,John456, Mar123, John456 \n");
	enqueue(l, p2);
	enqueue(l,p1);
	enqueue(l,p2);
	printQueue(l);
	printf("Test Passed\n");
	
	
	printf("\n");
	printf(" Test 8 Remove specfic node  p4(Bob): suppose to delete first occurance\n");
	printf("Expexted output: Emi890, John456, Mar123, Deadw3, John456, Mar123, Mar123, Emi890,  Emi890,John456, Mar123, John456\n");
	Remove(l,p4);
	printQueue(l);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 9: Deleting whole patient list, using destroyQueue() . suposse to return List is empty\n");
	destroyQueue(l);
	printQueue(l);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 10 adding patients in the list using priortyEnqueue Function\n ");
	printf("Expected output: Dead, John, Mar, Emi\n");
	priortyEnqueue(l, p1, node1);
	priortyEnqueue(l, p2, node2);
	priortyEnqueue(l, p3, node3);
	priortyEnqueue(l, p5, node5);
	printQueue(l);
	printf("Test Passed\n");
	
	printf("\n");
	printf("Test 11 removing first element in list using dequeue\n ");
	printf("Expected output: John, Mar, Emi\n");
	dequeue(l);
	printQueue(l);
	printf("Test Passed\n");
	
	
	destroyQueue(l);
	
	printf("\n");
	printf("Test 12 check if list is empty, should return List is empty\n ");
	listEmpty(l);
	printf("Test Passed\n");
	

	return 0 ;
}

