#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "car.h"
#include <string.h>


/**Function to point the list head to the appropriate functions. Allocates memory to the struct.

*@return pointer to the list head

*@param printFunction function pointer to print a single node of the list

*@param deleteFunction function pointer to delete a single piece of data from the list

*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order

**/

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))

{
	List *list = malloc(sizeof(List) *1);
	
	list -> head = NULL;
	list -> tail = NULL;
	list-> printNode = printFunction;
	list-> deleteNode = deleteFunction;
	list -> compare = compareFunction;
	
	return list; 
	
	
}



/**Function for creating a node for a linked list. This node contains generic data and may be connected to 

other notes in a list.

*@pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.

*data must be cast to void pointer before being added.

*@post data is valid to be added to a linked list

*@return On success returns a node that can be added to a linked list. On failure, returns NULL.

*@param data - is a generic pointer to any data type.

**/
Node* inatalizeNode(void *data)
{
    Node *newNode;
   
    newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> previous = NULL;
    newNode -> next = NULL; 
	
	return newNode; 


}

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 

 *data structure. 

 *@pre List must exist and have memory allocated to it

 *@post toBeDeleted will have its memory freed if it exists in the list.

 *@param list pointer to the dummy head of the list containing deleteFunction function pointer

 *@param toBeDeleted pointer to data that is to be removed from the list

 *@return returns EXIT_SUCCESS on success, and EXIT_FAILURE when empty. Returns -1 when the node cannot be found.

 **/
int deleteNodeFromList(List *list, void *toBeDeleted) //change var
{
	
	Node *temp = malloc(sizeof(Node));
    temp = list->head;
    
    while(temp!=NULL)
    {
		if(toBeDeleted == temp->data)
		{
			if(temp->previous == NULL && temp->next != NULL)
			{
				//deletes beggining 
				Node *tempNext = temp-> next;
 
				list->head = tempNext;
				tempNext -> previous = NULL;
				free(temp->data);
				free(temp);
			
			}
			
			else if(temp->next == NULL && temp->previous != NULL)
			{
				//deletes last node
				Node *tempPrev = temp ->previous;
				list->tail = tempPrev;
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




/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param list pointer to the List-type dummy node

**/

void deleteList(List *list)
{

	//freeing linked list first 
	Node *temp;

    while (list->head != NULL)
    {
       temp = list->head;
       list->head = temp->next;
       free(temp);
     
    }

	

	
}

/**Function to return the data at the front of the list.

 *@pre The list exists and has memory allocated to it

 *@param list pointer to the dummy head of the list containing the head of the list

 *@return pointer to the data located at the head of the list

 **/

void *getFront(List *list)
{
	Node *temp = list->head;
	
	return temp->data;
	
	
}



/**Function to print list from head to tail. This will utilize the list's printNode function pointer to print.

 *@pre List must exist, but does not have to have elements.

 *@param list Pointer to linked list dummy head.

 **/
void printForward(List *list)
{
	Node *temp = NULL;
	temp = list->head;
			
	if(temp == NULL)
	{
		printf("list is empty\n ");
				
	}
			
	while(temp!=NULL)
	{
				
		list->printNode(temp->data);
		
		temp = temp->next;
	}
    
}


/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param list pointer to the dummy head of the list

*@param toBeAdded a pointer to data that is to be added to the linked list

**/


void insertBack(List *list, void *toBeAdded) // passes in data 
{
   
   if(list->head == NULL)
   {
	   
	  Node *newNode = inatalizeNode(toBeAdded);
	   
	  list->tail = newNode;
	  list->head = newNode;
	  
	  newNode->next = NULL;
	  newNode->previous = NULL; 
	   
   }
   
   else
   {
	   
	   Node *newNode = inatalizeNode(toBeAdded);
	   
	   Node *temp = list->tail;
	   Node *temp2 = list->tail->previous;
	   list->tail = newNode;
	   
	   newNode->previous = temp;
	   newNode->next = NULL;
	   
	   temp->next = newNode;
	   temp->previous = temp2;
	   
	   
	   
   }
   
   

}


/**Inserts a Node to the front of a linked list. The list then updates accordingly to adhere to the ADT.

*@pre 'List' type must exist and be used in order to keep track of the linked list.

*@param list pointer to the dummy head of the list

*@param toBeAdded a pointer to data that is to be added to the linked list

**/

void insertFront(List *list, void *toBeAdded)
{
  
  if(list->head == NULL)
  {
	  
	  Node *node1 = inatalizeNode(toBeAdded);
	  
	  list->tail = node1;
	  list ->head = node1;
	  
	  node1->next= NULL;
	  node1->previous = NULL;
	  
	  
  }
  
  
  else
  {
	  
	  Node *newNode = inatalizeNode(toBeAdded);
	  
	  Node *temp = list->head;
	  Node *temp2= list->head->next;
	  
	  list->head = newNode;
	  
	  newNode->next = temp;
	  newNode->previous= NULL;
	  
	  temp->previous = newNode;
	  temp->next = temp2;
	  
	  
  }
  
  
  
  
  
   

}

/**Function to return the data at the back of the list.

 *@pre The list exists and has memory allocated to it

 *@param list pointer to the dummy head of the list containing the tail of the list

 *@return pointer to the data located at the tail of the list

 **/


void *getBack(List *list)
{
	
	Node * temp = list->tail;
	
	return temp->data;
	
	
}


/**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.

 *@pre List must exist, but does not have to have elements.

 *@param list Pointer to linked list dummy head.

 **/

void  printBackwards(List*list)
{
	
	Node * temp = NULL;
	temp = list->tail;
	
	while(temp!=NULL)
	{
		list->printNode(temp->data);
		temp = temp -> previous;
			
	}
	

}

//uncomment after
void deleteFunction(void *toBeDeleted)
{
	
}


//user defined functions
int compare(const void* first, const void* second)
{
	return 0;
}

void printNode(void *toBePrinted)
{
	Car *p = malloc(sizeof(Car));
	p = (Car*)(toBePrinted);
	printCar(p);

}
//uncomment after
//void deleteFunction(void *toBeDeleted)
//{
	
//}


void deleteListNode(void *toBeDeleted)
{
	printf("Does not return anything");
	
}
