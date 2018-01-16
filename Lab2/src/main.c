#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "gameboard.h"
#include "storeHead.h"
#include "book.h"
#include "LinkedListAPI.h"
//List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));


	void dummnyCompare(const void *first, const void *second);
	void printFunction(void *toBePrinted);
	void deleteFuncton(void *toBeDeleted);

int main(int argc, char ** argv)
{
	






	/*calls createBook function
	*@ param book title 
	*@param book price
	* @return  a dynamically created Book.

	node *



*/

 	
Node *node ;

int *num = malloc(sizeof(int*));

int *num2 = malloc(sizeof(int*));

*num= 7;
*num2 = 10;


List *list;

List *num1;


list  = initializeList(&printFunction, &Compare, &deleteFunction);
num1 =  initializeList(&printFunctionint, &Compareint, &deleteFunctionint);



	Book *book1 = createBook(" Harry Potter And The Cursed Child", 19.99);
	
	Book *book2 = createBook("The Hunger Games", 10.50);

	Book *book3 =  createBook("Harry Potter and the Deathly Hallows", 22.90); 
	

	Node *node1 = initializeNode( book1);
	insertFront(list, node1->data);
	printFrorward(list);
	printBackwards(list);
	
	Node *node2 = initializeNode( book2);
	insertFront(list, node2->data);
	printFrorward(list);
	printBackwards(list);
	
	Node *node3 = initializeNode( book3);
	insertFront(list, node3->data);
	printFrorward(list);
	printBackwards(list);

  

   node =  initializeNode( book1);
    Book*book = (Book*)(node->data);
	printf("%s", book->name);

    Node * initializeNode( num);
    Node * initializeNode( num2);

	//print forward and bacwards





	//in dummy.c
void printFunction(void *tobePrinted)
{

   printf("<%s> \n", (Book*)(tobePrinted)->name);


}




/*

int  bookcompare(const void *first, const void *second)
{

    //assending order
	
	//Book *b1 = (Book*) first;

	//Book *b2 = (Book*) second; 

     return (strcmp(((Book*)first)->name, ((Book*)second)-> name) >0);

}
*/
//in dummy.c
int  compare(const void *first, const void *second)
{

    //assending order
	
	Book *b1 = (Book*) first;

	Book *b2 = (Book*) second; 

	if( b1->price > b2->price)
	{
		return -1;
	}

     if(b2 -> price < b1->price)
     {
     	return 1 ; 
     }
     
     else
     {
     	return 0;
     }


}


   // node =  initializeNode( book1);
   // Book*book = (Book*)(node->data);
	//printf("%s", book->name);

   // Node * initializeNode( num);
   // Node * initializeNode( num2);

	//print forward and bacwards

    //insertFront(list, book1);
   // insertFront(list, book2);
   // insertFront(list, book3);








// main, intalize list, malloc node with 2-3 ints, call printffrorward





}
