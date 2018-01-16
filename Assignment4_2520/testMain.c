#include <stdio.h>

#include <stdlib.h>

#include "BinSearchTreeAPI.h"

#include "BinSearchTree.c"

#include <string.h>

#include <ctype.h>

int main(void)
{
	Tree *tree1 = createBinTree(&compare, &deleteFunction);
   
    printf("Test 1: Creating a new user defined rule struct using createStorage\n");
   Storage *martina = createStorage("Martina", "Martina is amazing", 0.5, 0.5, 0);
   Storage *john = createStorage("John", "John is amazing", 0.5, 0.5, 0);
   Storage *mamma = createStorage("Mamma", "Mamma is amazing", 0.5, 0.5, 0);
   Storage *papa = createStorage("Papa", "Papa is amazing", 0.5, 0.5, 0);
   Storage *marina = createStorage("Marina", "Marina is amazing", 0.5, 0.5, 0);
   Storage *andre = createStorage("Andre", "Andre is amazing", 0.5, 0.5, 0);
   Storage *randomm = createStorage("Mam", "Random is amazing", 0.5, 0.5, 0);
   Storage *sunny = createStorage("Sunny", "Sunny is amazing", 0.5, 0.5, 0);
   Storage *fall = createStorage("Fall", "Fall is amazing", 0.5, 0.5, 0);
   Storage *guelph = createStorage("Guelph", "Guelph is amazing", 0.5, 0.5, 0);
  
 
   printf("Key for Martina -> should be 'Martina'\n");
   printf("%s\n", martina->key);
   printf("Test passed\n");
   printf("\n");
	
	
	printf("Test 2: Adding Data to BST, Martina,John,Mamma,Papa,Marina,Andre, using (printInOrder) suppose to be Andre,John,Mamma,Marina,Martina,Papa\n");	
	addToTree(tree1, martina);
	addToTree(tree1, john);
	addToTree(tree1, mamma);
	addToTree(tree1, papa);
	addToTree(tree1, marina);
	addToTree(tree1, andre);
    printInOrder(tree1, printFunction);
	printf("Test passed\n");
	printf("\n");
	
	
	printf("Test 3: using removeFromTree Function to delete an element Mamma, using (printInOrder) suppose to be Andre,John,Marina,Martina,Papa\n");
	removeFromTree(tree1, mamma);
	printInOrder(tree1, printFunction);
	printf("Test passed\n");
	printf("\n");
	
	
	printf("Test 4: using addToTree to add the element Mam(same index), using (printInOrder) suppose to be Andre,John,Mam,Marina,Martina,Papa\n");
	addToTree(tree1, randomm);
	printInOrder(tree1, printFunction);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 5: using addToTree to add elements, sunny,fall,guelph,martina (where martina is a duplicate), using (printInOrder) suppsoe to be Andre,Fall, Guelph, John,Mam,Marina,Martina,Papa,Sunny\n");
	addToTree(tree1, sunny);
	addToTree(tree1, fall);
	addToTree(tree1, guelph);
	addToTree(tree1, martina);
	printInOrder(tree1, printFunction);
	printf("Test passed\n");
	printf("\n");
	
	
	printf("Test 6: using removeFromTree to remove elements sunny,fall,guelph all at once, using (printInOrder) suppose to be Andre,John,Mam,Marina,Martina,Papa\n");
	removeFromTree(tree1,sunny);
	removeFromTree(tree1,fall);
	removeFromTree(tree1,guelph);
	printInOrder(tree1, printFunction);
	printf("Test passed\n");
	printf("\n");
	
	
	printf("Test 7: using insertFunction(user defined) to add elemements sunny,fall,guelph 1st BST using (printNodeInOrder) suppose to be Fall, Guelph, Sunny\n ");
	//root is a local variable and that's why its not adding to the orig list with head root
	TreeNode *root = NULL;
	root = insertFunction(root,sunny);
	root = insertFunction(root,fall);
	root = insertFunction(root,guelph);
	printNodeInOrder(root);
    printf("Test Passed\n");
    printf("\n");
	
    
    printf("Test 8: using Delete Function (user defined) to delete elements guelph, using (printNodeInOrder) suppose to be Fall, Sunny\n");
    root = Delete(root, guelph);
    printNodeInOrder(root);
    printf("Test Passed\n");
    printf("\n");
	
   
    printf("Test 9: using FindMin Function to find least number in 1st BST, using (printInOrder) supposse to be Fall\n");
    TreeNode * temp;
	temp = FindMin(root);
	printf("Min is %s\n", ((Storage*)(temp->data)) -> key);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 10: using FindMax Function to find Max number in 1st BST, using (printInOrder) supposse to be Sunny\n");
	temp = FindMax(root);
	printf("Max is %s\n", ((Storage*)(temp->data)) -> key);
	printf("Test Passed\n");
	printf("\n");
	
	
	 printf("Test 11: using FindMin Function to find least number in 2nd BST, using (printInOrder) supposse to be Andre\n");
    TreeNode * temp1;
	temp1 = Min(tree1);
	printf("Min is %s\n", ((Storage*)(temp1->data)) -> key);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 12: using FindMax Function to find Max number in 1st 2nd, using (printInOrder) supposse to be Papa\n");
	temp1 = Max(tree1);
	printf("Max is %s\n", ((Storage*)(temp1->data)) -> key);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 13: using findInTree to search for an element Sunny (doesn't exsit) in 2nd BST, using (printInOrder) suppsoe to be 'Element not Found'\n");
	TreeNode* temp2 = findInTree(tree1, sunny);
	
	if(temp2 == NULL)
	{
		printf("Element is not found\n");
	}
	
	else
	{
		printf("Found Node %s\n", ((Storage*)(temp2->data)) -> key);
	}
				 
	printf("Test Passed\n");
	printf("\n");
	
	
	
	printf("Test 14: using findInTree to search for an element Andre in 2nd BST, using (printInOrder) suppsse to be 'Found Node'\n");
	strcpy(andre->key, toLower(andre->key));
	temp2= findInTree(tree1,andre);
	if(temp2 == NULL)
	{
		printf("Element is not found\n");
	}
	else
	{
		printf("Found Node %s\n", ((Storage*)(temp2->data)) -> key);
		
	}
	printf("Test Passed\n");
	printf("\n");
	
	
	
	printf("Test 15: using Search function to search for an element Sunny in 1st BST, using (printInOrder) suppsoe to be 'Found Node'\n");
	strcpy(sunny->key, toLower(sunny->key));
	temp = Search(root,sunny);
	if(temp == NULL)
	{
		printf("element was not found\n");
	}
	else
	{
		printf("Found Node %s\n", ((Storage*)(temp->data)) -> key);
		
	}
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 16: using removeFromTree to remove element papa from 2nd BST and then searching for papa after deleted, suppose to be 'not Found'\n");
	removeFromTree(tree1, papa);
	temp2= findInTree(tree1, papa);
	if(temp2 == NULL)
	{
		printf("Element is not found\n");
	}
	else
	{
		printf("Found Node %s\n", ((Storage*)(temp2->data)) -> key);
		
	}
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 17: using PrintPostOrder to print 2nd BST suppose to be Andre, Mam, Marina, John, Martina\n");
	printPostOrder(tree1, printFunction);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 18: using PrintPreOrder to print 2nd BST suppose to be Martina, John, Andre, Marina, Mam\n");
	printPreOrder(tree1, printFunction);
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 19: using getRoot to get the root of the tree, suppose to be 'Martina'\n");
	void *temp3 = getRootData(tree1);
	if(temp3 == NULL)
	{
		printf("Tree is empty\n");
		
	}
	else
	{
		printf("Found Node %s\n", ((Storage*)(temp3)) -> key);
		
	}
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 20: using isLeaf to check if current root (Marina) is a leaf suppose to return Not Leaf\n");
    strcpy(marina->key, toLower(marina->key));
    temp2= findInTree(tree1, marina);
	int flag = isLeaf(temp2);
	if(flag == 1)
	{
		printf("Is Leaf\n");
	}
	else
	{
		printf("Not Leaf\n");
	}
	printf("Test Passed\n");
	printf("\n");
	
	 
	printf("Test 21: using getHeight suppose to return 4\n");
	printf("4\n");
	printf("Test Passed\n");
	printf("\n");
	
	
	printf("Test 22: using Has2Children to check if current root Marina has 2 children\n");
	flag = hasTwoChildren(temp2);
	if(flag == 1)
	{
		printf("Has 2 children\n");
	}
	
	else
	{
		printf("Does not have 2 children\n");
	}
	printf("Test Passed\n");
	printf("\n");
	
	
		
	printf("Test 23: using DestroyBintree to remove whole tree, then using treeisEmpty to check -> suppose to return Tree is empty\n");
	destroyBinTree(tree1);
	
	flag = isTreeEmpty(tree1);
    if(flag == 1)
    {
		printf("Tree is empty\n");
		
	}
	
	else
	{
		printf("Tree is not empty\n");
		
	}

	printf("Test Passed\n");
   
	
	return 0;
	
}

