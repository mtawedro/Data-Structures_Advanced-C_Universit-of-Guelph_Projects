#include <stdio.h>

#include <stdlib.h>

#include "BinSearchAPI.h"

#include <string.h>

#include <ctype.h>


char* toLower(char* string)
{
   int length = strlen(string);
	
	for(int x = 0; x< length; x++)
	{
	   string[x] =  tolower((unsigned char) string[x]);
	  
	}

  return string;

}

/**

 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.

 * @param data - the data to be stored within the Node. 

 * @return Newly created TreeNode

 *

 */
TreeNode* createTreeNode(void* data)
{
	 TreeNode *newTreeNode;
   
    newTreeNode = malloc(sizeof(TreeNode));
    newTreeNode -> data = data;
    newTreeNode -> right = NULL;
    newTreeNode -> left = NULL; 
	
	return newTreeNode; 

	
	
}

/**

 * createBinTree allocates memory for Tree and assigned function pointers

 * @param  compare [Function pointer to Compare data in tree nodes]

 * @param  del     [Function pointer to delete data from node]

 * @return Newly created Tree

 */

Tree * createBinTree(CompareFunc compare, DeleteFunc del)
{
	Tree *tree = malloc(sizeof(Tree) * 1);
	tree->root = NULL;
	tree->compareFunc = compare;
	tree->deleteFunc = del;
	
	return tree;
	
	
}


/**

 * destroyBinTree - remove all items and free memory

 * @param  toDestroy - the tree

 * @return

 */

void  destroyBinTree(Tree * toDestroy)
{
	destroyTree(toDestroy -> root);
	
	free(toDestroy);
	toDestroy -> root = NULL;
	
}      
void destroyTree(TreeNode * root)
{
   if (root !=NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
	
}	


/**

 * Add data to a tree

 * @param theTree 

 * @param data    

 */

void addToTree(Tree * theTree, void* data)
{
	
	theTree->root = insertFunction(theTree->root, data);
	
}

TreeNode * insertFunction(TreeNode * root, void* data)
{
	 Storage* storage = (Storage *) data;
		
	if(root == NULL)
	{
		//creates a new node
		root = createTreeNode(data);
		
		//return newTreeNode;	
	}
	
	
	else if(strcmp(storage->key ,(((Storage*)(root->data)) -> key)) > 0 )
	{
		root->right = insertFunction(root->right, data);	
	}
	
	else if(strcmp(storage->key ,(((Storage*)(root->data)) -> key)) < 0)
	{	
		root->left = insertFunction(root->left, data);	
	}
	
	return root;
	
}


/**

 * This function searches the tree for the target data

 * @param  theTree 

 * @param  data    

 * @return         NULL if fail, otherwise return data

 */


TreeNode* findInTree( Tree* theTree, void* data )
{
	 TreeNode *temp;	
     temp = Search(theTree->root, data);

     return temp;
}


TreeNode* Search(TreeNode * root, void* data)
{
	 Storage* storage = (Storage *) data;
	
	char temp[200];
	
	if(root != NULL)
	{
		strncpy(temp, (char*)((Storage*)(root->data)) -> key,(strlen((char*)((Storage*)(root->data)) -> key) +1 ) );
		toLower(temp);
    }			       
				
	if(root == NULL)
	{
		return NULL;
		
	}
	
	
	if(strcmp(storage->key ,( temp/*((Storage*)(root->data)) -> key*/)) > 0)
	{
		
		return Search(root->right, data);
		
	}
	
	else if( strcmp(storage->key ,( temp/*((Storage*)(root->data)) -> key*/)) < 0)
	{
		
		return Search(root->left, data);
		
	}
	
	else
	{
		return root;
	}
	
	
}

/**

 * [printInOrder This function prints the tree using an inOrder traversal (wrapper)

 * @param theTree   [description]

 * @param printData [description]

 */

void printInOrder(Tree *theTree, PrintFunc printData)
{
	if(theTree->root == NULL)
	{
		//printf("List is empty");
		return;
		
	}	
	else
	{
		printNodeInOrder(theTree->root);
		
	}



}
/**

 * [printPreOrder This function prints the tree using an preOrder traversal wrapper

 * @param theTree   [description]

 * @param printData [description]

 */
void printPreOrder(Tree *theTree, PrintFunc printData)
{
	if(theTree->root == NULL)
	{
		return;
		
	}	
	else
	{
		printNodePreOrder(theTree->root);
		
	}



}

/**

 * [printPostOrder This function prints the tree using an postOrder traversal (wrapper)

 * @param theTree   [description]

 * @param printData [description]

 */
void printPostOrder(Tree *theTree, PrintFunc printData)
{
	if(theTree->root == NULL)
	{
		return;
		
	}	
	else
	{
		printNodePostOrder(theTree->root);
		
	}



}

void printNodeInOrder(TreeNode * root)
{
	if( root == NULL)
	{
		return;
	}
	
	printNodeInOrder(root->left);
	print(root->data);
	printNodeInOrder(root->right);
	
}


void printNodePreOrder(TreeNode * root)
{
	if(root == NULL)
	{
		return;
		
	}
	
	print(root->data);
	printNodePreOrder(root->left);
	printNodePreOrder(root->right);
	
	
}

void printNodePostOrder(TreeNode * root)
{
	if( root == NULL)
	{
		return;
		
	}
	
	printNodePostOrder(root->left);
	printNodePostOrder(root->right);
	print(root->data);
	
}


TreeNode* Min(Tree *theTree)
{
	TreeNode *temp = FindMin(theTree->root);
	
	return temp;
	
}

TreeNode* Max(Tree *theTree)
{
	TreeNode *temp = FindMax(theTree->root);
	
	return temp;
	
}


TreeNode* FindMin(TreeNode * root)
{
	if(root == NULL)
	{
		return NULL;
	}
	
	if(root->left)
	{
		return FindMin(root->left);
	}
	else
	{
		return root;
	}
	
	
} 

TreeNode* FindMax(TreeNode * root)
{
	if(root == NULL)
	{
		return NULL;
		
	}
	
	if(root->right)
	{
		return FindMax(root->right);
	}
	
	else
	{
		return root;
	}
	
}


/****Delete node from tree and Delete tree and Print Node from tree****/


void removeFromTree(Tree * theTree, void* data)
{
	theTree->root = Delete(theTree->root, data);
	
}

TreeNode* Delete(TreeNode * root, void* data)
{
	Storage* storage = (Storage *) data;
	
	TreeNode *temp;
	if(root == NULL)
	{
		
		//printf("element not found");
		//return root;
	}
	
	else if(strcmp(storage->key ,(((Storage*)(root->data)) -> key)) < 0)
	{
		root->left = Delete(root->left, data);	
	}
	
	else if(strcmp(storage->key ,( ((Storage*)(root->data)) -> key)) > 0)
	{
		root->right = Delete(root->right, data);
	}
	
	else
	{
		if(root->right && root->left)
		{
			temp = FindMin(root->right);
			//root->data = temp->data;
			strcpy(((Storage*)(root->data)) -> key, ( (Storage*)(temp->data) ) -> key );
			root->right = Delete(root->right, temp->data);
			
		}
		
		else
		{
			temp = root;
			if(root->left == NULL)
			{
				root = root->right;
			}
			else if(root->right == NULL)
			{
				root = root->left;
			}
			
			free (temp);
		}
	}
	
	return root;
}


int isTreeEmpty(Tree* theTree)
{
	
	if(theTree->root == NULL)
	{
		return 1;
	}
	
	return 0;
}


void print( void * v )
{
    Storage* p = (Storage *) v;
   
    printf("<%s> Rating:<%.2f> System:<%.2f> Ocurrances:<%d>\n", p->key , p->userRating, p->systemRating, p->occur);
}


int isLeaf( TreeNode * treeNode)
{
	if(treeNode->left == NULL && treeNode->right == NULL)
	{
		
		return 1;
	}
	
	else
	{
		return 0;
	}
	
	
	
}



int hasTwoChildren( TreeNode *treeNode)
{
	
	if(treeNode->left != NULL && treeNode->right != NULL)
	{
		return 1;
		
	}
	
	else
	{
		return 0;
	}
	
}


int getHeight( TreeNode* treeNode )
{
	 if (treeNode == NULL)
	 {
		 return 0;
	 }
    
     return 1 + (getHeight(treeNode->left), getHeight(treeNode->right));

}

void* getRootData(Tree * theTree)
{
	if(theTree->root != NULL)
	{
		return theTree->root->data;
	}
		
    else
    {
		return theTree->root;
		
	}
}


Storage* createStorage(char keyword [], char sentence [], double Urate, double Srate, int count)
{
    //creates *Data struct
    Storage* tempStorage = malloc(sizeof(Storage) * 1);
    
    strncpy(tempStorage->key, keyword, (strlen(keyword) +1)); 
    strncpy(tempStorage-> sen, sentence, (strlen(sentence) +1));
    tempStorage->userRating = Urate;
    tempStorage->systemRating = Srate;
    tempStorage->learnRating = 0.05;
    tempStorage->occur = count;
    
    return tempStorage;
}

int compare(const void* first, const void* second)
{
	return 0;
}


void deleteFunction(void *toBeDeleted)
{
	
}

void printFunction(void *toBeDeleted)
{
	
}
