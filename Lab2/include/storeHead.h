#ifndef STOREHEAD_H
#define STOREHEAD_H

    //defines struct with item and function pointer
    typedef struct store
    {
		
		void *item;
		void (*fptr)(void* );
		
		
	} Store; 


/**
 *creates store's data etc game/book along with its data.
 * @param void *item -> book/game
 * @param void *fptr -> passes function ptr
 * @returns dynamatically created store filled with its data 
 */
Store* createStore(void*item,  void(*fptr)(void*));

/**
 *displays store's data etc game/book along with its data.
 * @param Store *s -> data struct and its members
 * @param void *fptr -> passes function ptr
 */
void displayStore(Store *s);
	



#endif
