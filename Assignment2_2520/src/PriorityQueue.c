#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "PriorityQueueAPI.h"
#include "patient.h"
#include <string.h>


/**Function to point the list head to the appropriate functions. Allocates memory to the struct.

*@return pointer to the list head

*@param printFunction function pointer to print a single node of the list

*@param deleteFunction function pointer to delete a single piece of data from the list

*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order

**/

List *createQueue(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))

{
	List *list = malloc(sizeof(List) *1);
	
	list -> head = NULL;
	list -> tail = NULL;
	list-> printNode = printFunction;
	list-> deleteNode = deleteFunction;
	list -> compare = compareFunction;
	
	return list; 
	
	
}

/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param Queue taht points to list pointer to the List-type dummy node

**/

void destroyQueue(Queue *l)
{

	Node *temp;

	while (l->list->head != NULL)
	{
		temp = l->list->head;
		l->list->head = temp->next;
		free(temp);
     
	}
	
	Node *temp1 = NULL;
	
	temp1 = l->list->head;
			
	if(temp1 == NULL)
	{
		//printf("list is empty\n ");
				
	}

}

/**Function to remove first node from the list and alter the pointers accordingly to not disrupt the order of the 

 *data structure by calling Remove function. 

 *@pre List must exist and have memory allocated to it

 *@post toBeDeleted will have its memory freed if it exists in the list.

 *@param Queue that points to list pointer to the dummy head of the list containing deleteFunction function pointer

 *@param toBeDeleted pointer to data that is to be removed from the list

 *@return within Remove function of returns 1 on success. Returns -1 when the node cannot be found.

 **/


void dequeue(Queue *l) //change var
{
	
	void* data = peek(l);
		
	Remove(l,data);
		

}

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 

 *data structure. 

 *@pre List must exist and have memory allocated to it

 *@post toBeDeleted will have its memory freed if it exists in the list.

 *@param Queue that points to list pointer to the dummy head of the list containing deleteFunction function pointer

 *@param toBeDeleted pointer to data that is to be removed from the list

 *@return returns 1 on success. Returns -1 when the node cannot be found.

 **/
int Remove(Queue *l, void *toBeDeleted) //change var
{
	
	Node *temp = malloc(sizeof(Node));
    temp = l->list->head;
    
    while(temp!=NULL)
    {
		if(toBeDeleted == temp->data)
		{
			if(temp->previous == NULL && temp->next != NULL)
			{
				//deletes beggining 
				Node *tempNext = temp-> next;
 
				l->list->head = tempNext;
				tempNext -> previous = NULL;
				free(temp->data);
				free(temp);
			
			}
			
			else if(temp->next == NULL && temp->previous != NULL)
			{
				//deletes last node
				Node *tempPrev = temp ->previous;
				l->list->tail = tempPrev;
				tempPrev->next = NULL;
				
				free(temp->data);
				free(temp);
				
				
			}
				
			else if(temp->next == NULL && temp->previous == NULL)
			{
				//deletes only if its only node
				temp->next = NULL;
				temp ->previous = NULL;
				free(temp->data);
				free(temp);	
			}
			
			else
			{
				//deletes middle node
				Node *tempNext = temp->next;
				Node * tempPrev = temp -> previous;
				
				tempNext->previous = tempPrev;
				tempPrev->next = tempNext;
				
				free(temp->data);
				free(temp);
			
			}
			
			return 1;
			
			
		}//end of if


		temp = temp->next;

    }// end of while
	
	if(temp == NULL)
	{
		printf("Match not found");
		return -1;	
	}

	
	 return 0 ;


}

/**Function to return the data at the front of the list.

 *@pre The list exists and has memory allocated to it

 *@param Queue that list pointer to the dummy head of the list containing the head of the list

 *@return pointer to the data located at the head of the list

 **/

void *peek(Queue *l)
{
	Node *temp = l->list->head;
	
	return temp->data;
	
	
}

/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param list pointer to the dummy head of the list

*@param toBeAdded a pointer to data that is to be added to the linked list

**/
void enqueue(Queue *l, void *toBeAdded) // passes in data 
{
   
   if(l->list->head == NULL)
   {
	   
	  Node *newNode = inatalizeNode(toBeAdded);
	   
	  l->list->tail = newNode;
	  l->list->head = newNode;
	  
	  newNode->next = NULL;
	  newNode->previous = NULL; 
	   
   }
   
   else
   {
	   
	   Node *newNode = inatalizeNode(toBeAdded);
	   
	   Node *temp = l->list->tail;
	   Node *temp2 = l->list->tail->previous;
	   l->list->tail = newNode;
	   
	   newNode->previous = temp;
	   newNode->next = NULL;
	   
	   temp->next = newNode;
	   temp->previous = temp2;
	   
	   
	   
   }
   
   

}


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

		 
void priortyEnqueue(Queue *l, void *toBeAdded, Node *new_node)
{

	Patient* patientTemp = (Patient *) toBeAdded;
		
	/* If the first element */
	if (l->list->head == NULL)
	{
		insertFront(l->list, patientTemp);
			
	}
	
	
	else
	{
		
		
		Node *current = l->list->head;
		
		while(current != NULL)
		{
			
			if(current->next != NULL)
			{
				if(patientTemp -> priorty == ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
					
					new_node->next = current->next;
					new_node->previous = current;
					new_node->next->previous = new_node;
					current->next = new_node;
				
					break;
				
				}
			 
				else if(patientTemp -> priorty < ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
					
					insertFront(l->list, patientTemp);
					
					break;
				
				}
				
				else if(patientTemp -> priorty != ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
				
					new_node->next = current->next;
					new_node->previous = current;
					new_node->next->previous = new_node;
					current->next = new_node;
				
					break;
				
				}
			
			
				current = current->next;
			
		    }
		
		    else
			{
				if(patientTemp -> priorty == ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					enqueue(l, patientTemp );
				
					break;
				
				}
				
				else if(patientTemp -> priorty > ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					enqueue(l, patientTemp );
				
					break;
				
				}
				
				
				else if(patientTemp -> priorty < ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					insertFront(l->list, patientTemp );
				
					break;
				
				}
				
				
				current = current->next;
			
			}	
	}
		
		
}
	 
	  
}  
 /**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.

 *@pre List must exist, but does not have to have elements.

 *@param Queue that points to list Pointer that points to linked list dummy head.

 **/
 
void printQueue(Queue *l)
{
	Node *temp = NULL;
	temp = l->list->head;
			
	if(temp == NULL)
	{
		printf("list is empty\n ");
				
	}
			
	while(temp!=NULL)
	{
				
		l->list->printNode(temp->data);
		
		temp = temp->next;
	}
    
}

/**Function to check if list is empty if head is pointing to NULL.

 *@pre List must exist, but does not have to have elements.

 *@param Queue that points to list Pointer that points to linked list dummy head.

 **/
void listEmpty(Queue *l)
{
	Node *temp = NULL;
	temp = l->list->head;
			
	if(temp == NULL)
	{
		printf("list is empty\n ");
				
	}

}








