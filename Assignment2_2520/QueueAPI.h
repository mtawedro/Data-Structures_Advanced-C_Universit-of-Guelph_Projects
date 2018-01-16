/**

 * @file QueueAPI.h

 * @author Martina Tawedrous

 * @date October 2017

 * @brief File containing the function definitions of a Queue list

 */

#ifndef _QUEUE_API_

#define _QUEUE_API_



#include <stdio.h>

#include <stdlib.h>


/**

*Struct of type Queue that points to of type List that points to linked list along with 

**/

typedef struct Queue{

   List *list;
  
   int count;

} Queue;

/**Function to point the list head to the appropriate functions. Allocates memory to the struct.

*@return pointer to the list head

*@param printFunction function pointer to print a single node of the list

*@param deleteFunction function pointer to delete a single piece of data from the list

*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order

**/

List *createQueue(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**Function to remove first node from the list and alter the pointers accordingly to not disrupt the order of the 

 *data structure by calling Remove function. 

 *@pre List must exist and have memory allocated to it

 *@post toBeDeleted will have its memory freed if it exists in the list.

 *@param Queue that points to list pointer to the dummy head of the list containing deleteFunction function pointer

 *@param toBeDeleted pointer to data that is to be removed from the list

 *@return within Remove function of returns 1 on success. Returns -1 when the node cannot be found.

 **/

void dequeue(Queue *l); //change var

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 

 *data structure. 

 *@pre List must exist and have memory allocated to it

 *@post toBeDeleted will have its memory freed if it exists in the list.

 *@param Queue that points to list pointer to the dummy head of the list containing deleteFunction function pointer

 *@param toBeDeleted pointer to data that is to be removed from the list

 *@return returns 1 on success. Returns -1 when the node cannot be found.

 **/
int Remove(Queue *l, void *toBeDeleted); //change var


/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param Queue taht points to list pointer to the List-type dummy node

**/
void destroyQueue(Queue *l);


/**Function to return the data at the front of the list.

 *@pre The list exists and has memory allocated to it

 *@param Queue that list pointer to the dummy head of the list containing the head of the list

 *@return pointer to the data located at the head of the list

 **/

void *peek(Queue *l);

/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param list pointer to the dummy head of the list

*@param toBeAdded a pointer to data that is to be added to the linked list

**/
void enqueue(Queue *l, void *toBeAdded);

/**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.

 *@pre List must exist, but does not have to have elements.

 *@param Queue that points to list Pointer that points to linked list dummy head.

 **/

void printQueue(Queue *l);


/**function in the List struct to place the element in the appropriate position in the list.

*this is intended to be used from the beginning in order to keep the list completely sorted.

*@pre List exists and has memory allocated to it. Node to be added is valid.

*@post The node to be added will be placed immediately before or after the first occurrence of a related node

*@param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well 

as a pointer to the first and last element of the list.

*@param toBeAdded a pointer to data that is to be added to the linked list
* 
@param pointer of type new_node with data pointer added 

**/
void priortyEnqueue(Queue *l, void *toBeAdded, Node *new_node);

/**Function to check if list is empty if head is pointing to NULL.

 *@pre List must exist, but does not have to have elements.

 *@param Queue that points to list Pointer that points to linked list dummy head.

 **/
void listEmpty(Queue *l);



#endif
