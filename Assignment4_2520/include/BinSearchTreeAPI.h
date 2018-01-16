#ifndef BST_GUARD

#define BST_GUARD

/**************************************

Interface for a Binary Tree ADT

Author:  Judi McCuaig

October, 2012

Modfied: James Fraser (Nov 2017)

**************************************/

/**

 * Function pointer tyepdefs

 */

typedef int (*CompareFunc)(const void* a, const void* b);

typedef void (*DeleteFunc)(void* data);

typedef void (*PrintFunc)(void* data);


/**

 * Typedef the void* to make the API cleaner and more readable.

 */

typedef void* TreeDataPtr;


typedef struct Storage
{
	char key[200];
	char sen[200];
	double userRating;
	double systemRating;
	double learnRating;
	int occur;
	
}Storage;


/**

 * A Single Binary Tree Node.

 * Left and Right branches

 * void* data

 */

typedef struct binTreeNode TreeNode;

struct binTreeNode{

	void* data;

	TreeNode * left;

	TreeNode * right;

	//TreeNode * parent; Optional but useful

    //Tree* parentTree;  Optional but gets you access to function pointers.

};



/**

 * This is the definition of the Binary Tree.

 *

 */

typedef struct binTree

{

	TreeNode *root;

	CompareFunc compareFunc;

	DeleteFunc deleteFunc;



	// Additions must work with abstract data types.

	// Additional function pointers to generalize tree.

	// Additional properties can be added such as count.

} Tree;




/**

 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.

 * @param data - the data to be stored within the Node. 

 * @return Newly created TreeNode

 *

 */

TreeNode* createTreeNode(void* data);



/**

 * createBinTree allocates memory for Tree and assigned function pointers

 * @param  compare [Function pointer to Compare data in tree nodes]

 * @param  del     [Function pointer to delete data from node]

 * @return Newly created Tree

 */

Tree * createBinTree(CompareFunc compare, DeleteFunc del);



/**

 * destroyBinTree - (wrapper)

 * @param  toDestroy - the tree

 * @return

 */

void  destroyBinTree(Tree * toDestroy);

/**

 * destroyBinTree - remove all items and free memory

 * @param  toDestroy - the tree

 * @return

 */

void destroyTree(TreeNode * root);

/**

 * Add data to a tree

 * @param theTree 

 * @param data    
 
 * @return TreeNode
 
 */

TreeNode * insertFunction(TreeNode * root, void* data);

/**

 * (wrapper)

 * @param theTree 

 * @param data    

 */

void addToTree(Tree * theTree, void* data);
/**

 * (wrapper)

 * @param theTree 

 * @param data    

 */

void removeFromTree(Tree * theTree, void* data);


/**

 * Remove data from the tree

 * @param theTree 

 * @param data    
    
 * @return TreeNode
 
 */

TreeNode* Delete(TreeNode * root, void* data);


/**

 * (wrapper)

 * @param  theTree 

 * @param  data    

 * @return         NULL if fail, otherwise return data

 */


TreeNode* findInTree( Tree* theTree, void* data );

/**

 * This function searches the tree for the target data

 * @param  theTree 

 * @param  data    

 * @return         NULL if fail, otherwise return data

 */

TreeNode* Search(TreeNode * root, void* data);


/**

 * Get data from the root of the Tree if it exists.

 * @param  theTree 

 * @return NULL if tree is empty, otherwise return root

 */

TreeDataPtr getRootData(Tree * theTree);


/**

 * [printInOrder This function prints the tree using an inOrder traversal (wrapper)

 * @param theTree   [description]

 * @param printData [description]

 */
void printInOrder(Tree *theTree, PrintFunc printData);

/**

 * [printInOrder This function prints the tree using an inOrder traversal

 * @param theTree   [description]

 * @param printData [description]

 */

void printNodeInOrder(TreeNode * root);


/**

 * [printPreOrder This function prints the tree using an preOrder traversal wrapper

 * @param theTree   [description]

 * @param printData [description]

 */

void printPreOrder(Tree *theTree, PrintFunc printData);

/**

 * [printPreOrder This function prints the tree using an preOrder traversal

 * @param theTree   [description]

 * @param printData [description]

 */
void printNodePreOrder(TreeNode * root);


/**

 * [printPostOrder This function prints the tree using an postOrder traversal (wrapper)

 * @param theTree   [description]

 * @param printData [description]

 */
void printPostOrder(Tree *theTree, PrintFunc printData);

/**

 * [printPostOrder This function prints the tree using an postOrder traversal (wrapper)

 * @param theTree   [description]

 * @param printData [description]

 */

void printNodePostOrder(TreeNode * root);

/**

 * Checks if a tree is empty

 * @param  theTee [description]

 * @return        0 if false, 1 otherwise

 */

int isTreeEmpty(Tree* theTree);

/**

 * Helper function for checking if a single node is a leaf (no children)

 * @param  treeNode [description]

 * @return          0 if false, 1 otherwise

 */

int isLeaf( TreeNode * treeNode);

/**

 * Helper funciton for checking if a single node has two children.

 * @param  treeNode [description]

 * @return         0 if false, 1 otherwise

 */


int hasTwoChildren( TreeNode *treeNode);

/**

 * Helper funciton Get the height of a particulat Node in the tree. 

 * @param  treeNode [description]

 * @return    (1-Based) heigh for the tree. 

 */


int getHeight( TreeNode* treeNode );


/**

 * You may add additional API functions below this comment if you want to extend the funcitonality.

 */


int compare(const void* a, const void* b);

void deleteFunction(void *data);

void print( void * v );

TreeNode* Min(Tree *theTree);

TreeNode* Max(Tree *theTree);

TreeNode* FindMin(TreeNode * root);

TreeNode* FindMax(TreeNode * root);

void printFunction(void *toBeDeleted);

char* toLower(char* string);

Storage* createStorage(char keyword [], char sentence [], double Urate, double Srate, int count);

#endif
