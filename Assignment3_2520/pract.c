#include <stdio.h>

#include <stdlib.h>

//#include "linkedList.c"

#include "HashTableAPI.h"

#include <string.h>

#include <ctype.h>

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, char* key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{

    HTable *newHTable = malloc(sizeof(HTable) *1);
	newHTable->size = size;
	newHTable->table = malloc(sizeof(HNode*) * size);
	newHTable-> destroyNodeData = destroyData;
	newHTable-> printNodeData = printNode;
	//table -> hashNode = hashFunction;
	
	return newHTable; 

}

HNode *createNode(int key, void *data)
{
	HNode *newNode;
   
    newNode = malloc(sizeof(HNode));
    newNode -> key = key;
    newNode -> data = data;
    
     newNode->list = initializeList(&printNode, &deleteFunction, &compare); ///< pointer to the next Node if a collision is detected

	return newNode; 
		
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
     
     HNode *newNode1;
    
     Node *tempNode;
     
     int index = key;
     
     printf("INDEX IS %d\n", index);
     
      if(hashTable->table[20]!=NULL)
		 {
		    printf("Martina hashTable->table[index]->key %d\n", hashTable->table[20]->key);
		    printf("Martina hashTable->table[index]->data %s\n", hashTable->table[20]->data);
		 
		 }
		 
    
     if( hashTable->table[index] == NULL)
     {
		
		printf("BEFORE hashTable->table[index]->key %d\n", key);
		 printf("BEFORE hashTable->table[index]->data %s\n", (char*)data);
		 
		 printf("in here first\n");
		 newNode = createNode(key, data); //change later to  0 and ""
		
		
		 
		 
		 hashTable->table[index] = newNode;
		
		 printf("AFTER hashTable->table[index]->key %d\n", newNode->key);
		 printf("AFTER hashTable->table[index]->data %s\n", (char*)newNode->data);
		 
		//  printf("Martina hashTable->table[index]->key %d\n", hashTable->table[20]->key);
		//  printf("Martina hashTable->table[index]->data %s\n", hashTable->table[20]->data);
		 
		 
		// newNode = createNode(key, data); 
		 insertBack(hashTable->table[index]->list, newNode);
		 
		 
		
	 }
	 
	 else if(hashTable->table[index] != NULL)
	 {
		  printf("already occupied\n");
		  newNode = createNode(key, data);
		  insertBack(hashTable->table[index]->list, newNode);
		
		 
		 
	 }
     
    
    
     //for(int x = 0; x<hashTable->size; x++)
     //{
      //  HNode *temp1 = hashTable->table[x];
       
       
     
      // if(hashTable->table[x] == NULL)
	   //{
		 // printf("Empty List\n");
	   //}
     
     
   
		if(hashTable->table[20] !=NULL)
		{
			printf("Martina's Cell");
			HNode *temp1 = hashTable->table[20];
			
		printf("Begginig cell\n %s key %d\n", (char*)(temp1 -> data), temp1 -> key ); //check this after
		  	
			
			tempNode = hashTable->table[20]->list->head;
      
			while(tempNode!=NULL)
			{	  
				printf("in List %s key %d\n", (char*)((HNode*)(tempNode->data)) -> data, ((HNode*)(tempNode->data)) -> key ); //check this after
		  
				tempNode = tempNode->next;
			}
		}
    
	//}
    //display(hashTable);
 			 
 }
    
    
    
void display(HTable *hashTable)
{
	
	
	for(int x = 0; x< hashTable->size; x++)
	{
		if(hashTable->table[x] != NULL)
		{
			
			if(strcmp(hashTable->table[x]->data , "NULL" ) == 0) //REMOVE WHEN SOLVED
			{
				printf("HURRY");
				continue;
				
			}
			
			//HNode *temp2 = hashTable->table[x];
			
			//printf("Hash Node key: %d\n", temp2 -> key);
			//printf("Hash Node data: %s\n", (char*)(temp2->data));
			
			Node *temp = hashTable->table[x]->list->head;
			
			while(temp != NULL)
			{
			
			  //printf("%s", (char*)((HNode*)(temp->data))->data);
			
			  //	printNodeData(((HNode*)(temp->data)));
			
				printf("Found Key: %d\n", ((HNode*)(temp->data)) -> key);
				printf("Found Data: %s\n", (char*)((HNode*)(temp->data)) -> data);
				
				temp = temp ->next;
				
				
			}
			
		}
		
		
	}
	
}


int hashNode(size_t tableSize, char* key)
{
	
	//printf("in %s", key);
	//printf("TestingHI\n");
	//printf("%s", key);
	
	char string[20];
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
	
	
	
	value = value % 26;
	//printf("%d", value);
	
	return value;
	
}

void insertDataInMap(HTable *hashTable, char* data)
{
	//char* p = (char *) data;
	
	printf("In Function: InsertDataMap: %s\n", data);
	
	int index = hashNode(hashTable->size, data);
	
	printf("In Function: InsertDataMap: %d\n", index);
	
	
	   //it changes!!!!!!!!!!!!
	  if(hashTable->table[20]!=NULL)
	  {
		    printf("IN FUNCTION Martina hashTable->table[index]->key %d\n", hashTable->table[20]->key);
		    printf("IN FUNCTION Martina hashTable->table[index]->data %s\n", hashTable->table[20]->data);
		 
	  }
	  
	  if(hashTable->table[1]!=NULL)
	  {
		    printf("IN FUNCTION Mamma hashTable->table[index]->key %d\n", hashTable->table[1]->key);
		    printf("IN FUNCTION Mamma hashTable->table[index]->data %s\n", hashTable->table[1]->data);
		 
	  }
	  
	   if(hashTable->table[0]!=NULL)
	  {
		    printf("IN FUNCTION Banna hashTable->table[index]->key %d\n", hashTable->table[0]->key);
		    printf("IN FUNCTION Banna hashTable->table[index]->data %s\n", hashTable->table[0]->data);
		 
	  }
		  if(hashTable->table[15]!=NULL)
	  {
		    printf("IN FUNCTION John hashTable->table[index]->key %d\n", hashTable->table[15]->key);
		    printf("IN FUNCTION John hashTable->table[index]->data %s\n", hashTable->table[15]->data);
		 
	  }
	
	
	insertData(hashTable, index, data);
	
	
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
   
    printf("%s %d\n ", (char*)p->data, p->key );
}


void destroyNodeData(void *data)
{
	
	
}

void removeData(HTable *hashTable, char* key)
{
	int flag;
	
	int index = hashNode(hashTable->size, key);
	
	printf("index %d",index );
	// index = 15;
	 //key = "john";
	printf("SOMETHING AFTER %d\n", hashTable->table[index]-> key);
	printf("SOMETHING AFTER: %s\n", hashTable->table[index] -> data);
	
	
	Node *temp2 = lookupData(hashTable, key);
	
	if(temp2 != NULL)
	{
		 flag = deleteNodeFromList(hashTable->table[index]->list ,temp2->data); //data in node
		
	}
	
	
	printf("SOMETHING %d\n", hashTable->table[index]-> key);
	printf("SOMETHING : %s\n", hashTable->table[index] -> data);
			
	//printf("Found Key in Delete: %d\n", ((HNode*)(temp2->data)) -> key);
	//printf("Found Data in Delete: %s\n", (char*)((HNode*)(temp2->data)) -> data);
							
	//int flag = deleteNodeFromList(hashTable->table[index]->list ,temp2->data); //data in node
	
	//printf("flag %d", hashTable->table[index]->data);
	
	if(flag == 2)
	{
	 //free(hashTable->table[index]);
	  //strcpy(hashTable->table[index]-> data , "NULL");
	}
}





void *lookupData(HTable *hashTable, char* key)
{
   printf("INVESTAGATION");
  
   
    int flag = 0;
    
    int count = 0;
    
    int index = hashNode(hashTable->size, key);
    
    //index = 15; //take out after
    
    
    
     for(int x = 0; x< hashTable->size; x++)
     {
		
		
		 HNode *temp = hashTable-> table[index];
		 
		 
		 if(temp != NULL)
		 {
			if(strcmp(hashTable->table[x]->data, "NULL") == 0 ) //TAKE OUT WHEN SOLVED
			{
				continue;
				
			}  
			    
			    
			   Node *temp2 = hashTable-> table[index]->list->head;
			  
			   if(temp2 != NULL)
			   {
			   
					while(temp2!=NULL)
					{
					//	toLower(key);
				        //if stings are equal
				       printf("Data Comparasion in dict: %s\n", (char*)((HNode*)(temp2->data)) -> data);
				      //  printf("KEY to be cheked %d", key);
				    //  char string1[20];
				    //  char string2[20];
					// strcpy(string1,(char*)((HNode*)(temp2->data)) -> data);
                    // strcpy(string2,toLower(string1));
				    //  printf("STRING2 IS %s", string2);
				      
				    //  if(strcmp((char*)((HNode*)(temp2->data)) -> data, string2) == 0) //change back to normal!
						//{
							//printf("MATCH");
					//	}
				      
				       
				        if(strcmp((char*)((HNode*)(temp2->data)) -> data, key) == 0) //change back to normal!
						{
							printf("Found Key: %d\n", ((HNode*)(temp2->data)) -> key);
							printf("Found Data: %s\n", (char*)((HNode*)(temp2->data)) -> data);
							flag = 1;
							
							//count ++;
							return temp2;
						}
						
						temp2 = temp2->next;
			        }
				
				
				}
		    
		  }// if temp != Null
		 
		if(flag == 1) //-> this will never excute
		 { 
			 break;
		 }
		 
	 }
	
	    //  if(flag == 1)
		 //{ 
			// return count;
		 //}
	
	if(flag != 1)
	{
		//printf("Sorry, word not found");
		return NULL;
		
	}
	
	
	
}

char* toLower(char* string)
{
  printf("IN LOWER");
  
   int length = strlen(string);
	
	for(int x = 0; x< length; x++)
	{
	   string[x] =  tolower((unsigned char) string[x]);
	  
	}

  return string;

}




int main(void)
{
	size_t size = 26;
	
	HTable *table1 = createTable(size, &hashNode, &destroyNodeData, &printNodeData);
	
	char userChoice[20];
	char userChoice2[20];
	int input = 0;
	int i =0;
	int x = 0;
	
	//table1->table[26];
	
	//HNode *temp;
	
	//table1->table[0] = &temp;
	
	printf("%lu", table1->size);
	
	char string[20] = "Martina";
	char string1[20] = "Mamma";
	
	char string2[20] = "Baba";
	
	char string3[20] = "john";
	
	//char string[20] = "Martina";
	
	insertDataInMap(table1, string);
	
	//insertDataInMap(table1, string);
	
	insertDataInMap(table1,  "Mamma");
	
	insertDataInMap(table1,  "Baba");
	
	//insertData(table1, 15, "john");
	
	insertDataInMap(table1,  "John");
	
	
	display(table1);
	
	
	
	char **secondArray; 
	
	secondArray = malloc(sizeof(char*) *1);
	
	char **firstArray; 
	
	firstArray = malloc(sizeof(char*) *1);
	
	
//strncpy(secondArray[0], string, (strlen(string) +1));
	
//strncpy(secondArray[1], string3, (strlen(string3) +1));

	
	/*
	for(int x = 0; x<2;x++)
	{
		 char user123[20];
		 
		 if(table1->table[20]!=NULL)
		{
				printf("IN COMMAND Martina hashTable->table[index]->key %d\n", table1->table[20]->key);
				printf("IN COMMAND Martina hashTable->table[index]->data %s\n", table1->table[20]->data);
		 
		}
		
		
		
		
		printf("Enter word");
		fgets(user123, 20, stdin); 
		
		if(user123[strlen(user123)-1] == '\n')
		{
			user123[strlen(user123)-1] = '\0';
		}
		
		strncpy(secondArray[x], user123, (strlen(user123) +1));
		
		insertDataInMap(table1, secondArray[x]);
		
		
		
	}
	
	*/
	
	//insertDataInMap(table1, string);
	
	//insertDataInMap(table1, string);
	
	//insertDataInMap(table1,  string1);
	
	//insertDataInMap(table1,  string2);
	
	//insertData(table1, 15, "john");
	
	//insertDataInMap(table1,  string3);
	
	//display(table1);
	
	
	
	printf("Enter Choice:");
	scanf("%d", &input);
	getchar();
   
	while(input!= 5)
	{ 
		switch(input)
		{
		case 1:
		{
				 if(table1->table[20]!=NULL)
				{
					printf("IN COMMAND Martina hashTable->table[index]->key %d\n", table1->table[20]->key);
					printf("IN COMMAND Martina hashTable->table[index]->data %s\n", table1->table[20]->data);
		 
				}
				
				
		
				printf("Enter a word");
				fgets(userChoice, 20 , stdin);
				
				//printf("Enter a word2");
				//fgets(userChoice2, 20 , stdin);
				
				//gets rid of hard return
				if(userChoice[strlen(userChoice)-1] == '\n')
				{
					userChoice[strlen(userChoice)-1] = '\0';
				}
				
				//gets rid of hard return
			//	if(userChoice2[strlen(userChoice2)-1] == '\n')
				//{
					//userChoice2[strlen(userChoice2)-1] = '\0';
				//}
				 
				  secondArray = realloc(secondArray, sizeof(char*) *  (i +1));
		
				//each world will be placed on a new row in the 2d array 
				  secondArray[i] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
  
				  strncpy(secondArray[i], userChoice, (strlen(userChoice) +1));

		          insertDataInMap(table1, secondArray[i]);
		
				
			//	insertDataInMap(table1, userChoice2);
				
				
				//insertDataInMap(table1, string);

				printf("Enter Choice");			
				display(table1);
				
				
		i++;
		
		break;
	  }
	
	  case 2:
	  {
		  printf("Enter Word you want to delete");
		  
		  fgets(userChoice, 20 , stdin);
				
				//gets rid of hard return
				if(userChoice[strlen(userChoice)-1] == '\n')
				{
					userChoice[strlen(userChoice)-1] = '\0';
				}
		  
		  
				  firstArray = realloc(firstArray, sizeof(char*) *  (x +1));
		
				//each world will be placed on a new row in the 2d array 
				  firstArray[x] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
  
				  strncpy(firstArray[x], userChoice, (strlen(userChoice) +1));

		         // toLower("Martina");
		           removeData(table1, firstArray[x]);
		  
		          display(table1);
		  
		  
		  x++;
		  break;
	  }
	
	
	
	
	}
		i = 0;
		x = 0;
		printf("Enter Choice:");
		scanf("%d", &input);
		getchar();
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	}
    
    
    
    
    
    
    
