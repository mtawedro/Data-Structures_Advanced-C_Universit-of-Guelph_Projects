#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "storeHead.h"

/**Store function to initlize data of ptr book and boardGame
 * @param item
 * @param  data -> game or book
 * @returns dynamatically store intalized with data
 */
Store* createStore(void*item, void(*fptr)(void*))

	{
		Store *s = malloc(sizeof(Store));
		
		s->fptr = fptr;
		s->item = item;
		
		
		return s;
	
	}

	
	
	
	void displayStore(Store *s)
	{
		
		//intalizes whats stored in data(game/book) to function ptr
		void(*fptr)(void*);
		fptr = s->fptr;
		
		//intalizes whats stored in item to ptr var
		void *ptr;
		ptr = s->item;
		
		
		//passes function ptr
		fptr(ptr);
		
	
	
	}
