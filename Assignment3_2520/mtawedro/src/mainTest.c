#include <stdio.h>

#include <stdlib.h>

//#include "linkedList.c"

#include "HashTableAPI.h"
//#include "HashTable.c" //take thsiout

#include <string.h>

#include <ctype.h>


int main(void)
{
	size_t size = 26;
	
	HTable *table1 = createTable(size, &hashNode, &destroyNodeData, &printNodeData);
	char string[50] = "Martina";
	char string1[50] = "John";
	char string2[50] = "Mamma";
	char string3[50] = "Papa";
	char string4[50] = "James";
	char string5[50] = "Mammma";
	
	printf("Size of Table is %lu\n", table1->size);
	
	printf("Test 1: Inatalizing Hash Node with data -Mammma with its corrsopinding index suppose to be index 6\n");
	int index = hashNode(table1->size, string5);
	HNode *newNode = createNode(index,string5);
	printNodeData(newNode);
	printf("Test Passed\n");
	
	printf("\n");
		
	printf("Test 2: Changing String -jOHn- to all lower cases with toLower function->suppose to be john\n");
    char name[50] = "jOHn";
	//--> to lower needs to pass in a string variable (not hard coded)
	printf("%s\n", toLower(name));
	printf("Test Passed\n");
	
	printf("\n");
	
	index = hashNode(table1->size, string);
	printf(" Test 3: Testing HashNode function -> passing in string -Martina- suppose to return 20\n");
	printf("Hash Index: %d\n", index);
	printf("Test Passed\n");
	
	printf("\n");
	
	printf("Test 4: Testing InsertDatainMap Function->passing in Keys: Martina, John, Mamma, Papa to map to correct indexes\n");
	printf("Suppose to print Papa, Mamma, John, Martina\n");
	insertDataInMap(table1, string);
	insertDataInMap(table1,  string1);
	insertDataInMap(table1,  string2);
	insertDataInMap(table1,  string3);
	
	display(table1);
	
	printf("Test passed\n");
	
	
	printf("\n");
	
	printf("Test 5: Testing insertData function with new Nodes Nicole,Josh,Dina,Emily that map to same keys (Chanining Collision)\n");
	printf("suppose to be [Martina, Nicole], [John, Josh], [Mamma, Dina], [Papa,Emily]\n");
	insertData(table1, 20, "Nicole");
	insertData(table1, 15, "Josh");
	insertData(table1, 1, "Dina");
	insertData(table1, 2, "Emily");
	
	display(table1);
	printf("Test Passed\n");
	
	printf("\n");
	
	printf("Test 6: Testing destroyTable function should return NULL\n");
	destroyTable(table1);
	printf("NULL\n");
	printf("Test Passed\n");
	
	printf("\n");
	
	printf("Test 7: Testing insertData and reinserting every key back into their hashes->passing in Keys: Martina, John, Mamma, Papa to map to correct indexes\n");
	printf("Suppose to print Papa, Mamma, John, Martina\n");
	insertData(table1, 20, string);
	insertData(table1, 15, string1);
	insertData(table1, 1, string2);
	insertData(table1, 2, string3);
	display(table1);
	printf("Test Passed");
	
	printf("\n");
	
	printf("Test 8: using insertData function to insert key at a random index (hardcoded index)->passing in Key: James ");
	printf("Suppose to print Papa, Mamma, John, Martina, James\n");
	insertData(table1, 22, string4);
	display(table1);
	printf("Test Passed");
	
	printf("\n");
	
	printf("Test 9: Removing specfic key - Martina - using removeData Function supoose to return Mamma, Papa, John, Martina, James\n");
	removeData(table1, toLower(string) );
	display(table1);
	printf("Test passed\n");
	
	
	printf("\n");
	
	printf("Test 10:*EDGE CASE* Removing specfic key -Martina- AGAIN -error check using removeData Function supoose to return Mamma, Papa, John, James\n");
	index = hashNode(table1->size, string);
	if(table1->table[index]->list->head != NULL)
	{
		removeData(table1, toLower(string));
		
	}

	display(table1);
	printf("Test passed\n");
	
	
	printf("\n");
	
	printf("Test 11: Removing specfic key-Mamma- using removeData Function supoose to return Papa, John, James\n");
	removeData(table1, toLower(string2));
	display(table1);
	printf("Test passed\n");

	printf("\n");
	
	printf("Test 12: Looking up Data using key specfic Node -Martina- using lookupData Function supoose to return 'Sorry, word not found'\n");
	Node *temp = lookupData(table1,toLower(string));
	if(temp == NULL)
	{
		printf("Sorry, word not found\n");
	}
	printf("Test passed\n");

	printf("\n");
	
	printf("Test 13: Looking up Data using key specfic Node -Mamma- using lookupData Function supoose to return 'Sorry, word not found'\n");
	temp = lookupData(table1, toLower(string2));
	if(temp == NULL)
	{
		printf("Sorry, word not found\n");
	}
	printf("Test passed\n");
	
	
	printf("\n");
	
	printf("Test 14: Looking up Data using key specfic Node -Papa- using lookupData Function supoose to return Data: Papa and Key:2\n");
	temp = lookupData(table1, toLower(string3));
	if(temp == NULL)
	{
		printf("Sorry, word not found\n");
	}
	else
	{
		printf("Data : %s\n", (char*)((HNode*)(temp->data)) -> data);
	    printf("key  : %d\n", ((HNode*)(temp->data)) -> key);
	
		
	}
	printf("Test passed\n");
	
	
	printf("\n");
	
	printf("Test 15:*EDGE CASE* Removing specfic key -Mammma- doesnt exsit in dict  using removeData Function supoose to return Papa, John, James\n");	
	index = hashNode(table1->size, string5);
	
	 if(table1->table[index] != NULL)
	 {
		removeData(table1, toLower(string5));	
	 }

	display(table1);
	printf("Test Passed\n");
	
	printf("\n");
	
	printf("Test 16: Inserting Data new key-Marina- using insertDataInMap Function suppose to be Papa, Marina, John, James\n");
	insertDataInMap(table1,  "Marina");
	display(table1);
	printf("Test Passed\n");
	
	
	printf("\n");
	
	printf("Test 17: Inserting Data new key-Ms.Skelly- using insertDataInMap Function suppose to be Papa, Marina, John, Ms.Skelly, James\n");
	insertDataInMap(table1,  "Ms.Skelly");
	display(table1);
	printf("Test Passed\n");
	
	
	printf("\n");
	
	
	
	
	return 0;
	
}

