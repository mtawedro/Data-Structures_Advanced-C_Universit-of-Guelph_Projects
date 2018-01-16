
#include <stdio.h>

#include <stdlib.h>

//#include "linkedList.c"

#include "HashTableAPI.h"
#include "LinkedListAPI.h"

#include <string.h>

#include <ctype.h>


/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.

*@return pointer to the hash table

*@param size size of the hash table

*@param hashFunction function pointer to a function to hash the data

*@param destroyData function pointer to a function to delete a single piece of data from the hash table

*@param printNode function pointer to a function that prints out a data element of the table

**/

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, char* key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{

    HTable *newHTable = malloc(sizeof(HTable) *1);
	newHTable->size = size;
	newHTable->table = malloc(sizeof(HNode*) * size);
	newHTable-> destroyData = destroyData;
	newHTable-> printNode = printNode;
	newHTable -> hashFunction = hashFunction; 
	
	return newHTable; 

}

/**Function for creating a node for the hash table.

*@pre Node must be cast to void pointer before being added.

*@post Node is valid and able to be added to the hash table

*@param key integer that represents the data (eg 35->"hello")

*@param data is a generic pointer to any data type.

*@return returns a node for the hash table

**/

HNode *createNode(int key, void *data)
{
	HNode *newNode;
   
    newNode = malloc(sizeof(HNode));
    newNode -> key = key;
    newNode -> data = data;
    
     newNode->list = initializeList(&printNode, &deleteFunction, &compare); ///< pointer to the next Node if a collision is detected

	return newNode; 
		
}



/** Deletes the entire hash table and frees memory of every element.

*@pre Hash Table must exist.

*@param hashTable pointer to hash table containing elements of data

**/

void destroyTable(HTable *hashTable)
{
	
	for(int x = 0; x< hashTable->size; x++)
	{
		if(hashTable->table[x] != NULL)
		{
			deleteList(hashTable->table[x]->list);
		}
			
		
	}
	
	
	
}  



/**Inserts a Node in the hash table.

*@pre hashTable type must exist and have data allocated to it

*@param hashTable pointer to the hash table

*@param key integer that represents the data (eg 35->"hello")

*@param data pointer to generic data that is to be inserted into the list

**/

void insertData(HTable *hashTable, int key, void *data)
{
     HNode *newNode;
     
     int index = key;
      
     if( hashTable->table[index] == NULL)
     {
	
		 newNode = createNode(key, data);
		 hashTable->table[index] = newNode;
		 
		 insertBack(hashTable->table[index]->list, newNode);
		
	 }
	 
	 else if(hashTable->table[index] != NULL)
	 {
		  newNode = createNode(key, data);  
		  insertBack(hashTable->table[index]->list, newNode);
		 
	 }
     
  
 }
    
    

/** THIS FUNCTION IS NOT MANDATORY, users call this function to insert a Node in the hash table.

* It's meant as a wrapper for insertData so the users don't need to generate the key when adding.

*@pre hashTable type must exist and have data allocated to it

*@param hashTable pointer to the hash table

*@param data pointer to generic data that is to be inserted into the list

**/

void insertDataInMap(HTable *hashTable, char* data)
{
	int index = hashNode(hashTable->size, data);
	
	insertData(hashTable, index, data);
	
}



/**Function to remove a node from the hash table 

 *@pre Hash table must exist and have memory allocated to it

 *@post Node at key will be removed from the hash table if it exists.

 *@param hashTable pointer to the hash table struct

 *@param key integer that represents a piece of data in the table (eg 35->"hello")

 **/

void removeData(HTable *hashTable, char* key)
{
	int flag;
	int index = hashNode(hashTable->size, key);
	
  if(hashTable->table[index]->list->head != NULL)
  {
		
	Node *temp2 = lookupData(hashTable, key);
	
	if(temp2 != NULL)
	{
		flag = deleteNodeFromList(hashTable->table[index]->list ,temp2->data);//something like patient struct
		
	}
	
	
	if(flag == 2)
	{
	 //Test
	
	}

  }


}



/**Function to return the data from the key given.

 *@pre The hash table exists and has memory allocated to it

 *@param hashTable pointer to the hash table containing data nodes

 *@param key integer that represents a piece of data in the table (eg 35->"hello")

 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.

 **/

void *lookupData(HTable *hashTable, char* key)
{
  
    int index = hashNode(hashTable->size, key);
    
	HNode *temp = hashTable-> table[index];
		 
		 
		 if(temp != NULL) //soemthing in first HNode
		 {
			 
			   Node *temp2 = hashTable-> table[index]->list->head;
			  
			   if(temp2 != NULL) //something in linked list
			   {
				   
					while(temp2!=NULL)
					{
				         char temp[150];
				         strncpy(temp,(char*)((HNode*)(temp2->data)) -> data,(strlen((char*)((HNode*)(temp2->data)) -> data) +1 ) );
				         toLower(temp);
				       
				        if(strcmp(temp, key) == 0) 
						{	
							return temp2;
							//toReturn = temp2;

						}
						
						temp2 = temp2->next;
			        }
				
				
				}
				
		    
		  }// if temp != Null
		 
	
	return NULL;
	
}


int hashNode(size_t tableSize, char* key)
{
	
	char string[100];
	strcpy(string, key);
	int value = 0;
	
	
	int length = strlen(string);
	
	for(int x = 0; x< length; x++)
	{
	   string[x] =  tolower((unsigned char) string[x]);
	  
	}
	
	for(int x = 0; x< length; x++)
	{
		value = value + (int)string[x];
	}
	
	
	
	value = value % tableSize;
	
	return value;
	
}



void destroyNodeData(void *data)
{
	
	
}



void printNodeData(void *toBePrinted)
{
	Node *p = malloc(sizeof(Node));
	p = (Node*)(toBePrinted);
	print(p);
	
}

void print( void * v )
{
    HNode* p = (HNode *) v;
   
    printf("[Key: %d Data: %s]\n ", p->key , (char*)p->data);
}

void display(HTable *hashTable)
{
	for(int x = 0; x< hashTable->size; x++)
	{
		
		if(hashTable->table[x] != NULL)
		{
			Node *temp = hashTable->table[x]->list->head;
				
			if(temp!= NULL)
			{	
				while(temp != NULL)
				{
					printf("<%d>:<%d>:<%s>\n", x,((HNode*)(temp->data)) -> key, (char*)((HNode*)(temp->data)) -> data);	
				    temp = temp ->next;
			    }
		     }
		}
		
	}
	
}

char* toLower(char* string)
{
   int length = strlen(string);
	
	for(int x = 0; x< length; x++)
	{
	   string[x] =  tolower((unsigned char) string[x]);
	  
	}

  return string;

}

