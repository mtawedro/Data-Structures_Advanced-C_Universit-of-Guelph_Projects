#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "book.h"

#include "gameboard.h"

//#include "storeHead.h"




/**
 * [createBoardGame description]
 * @param  title static string of title
 * @param char brand
 * @param  price double
 * @return  a dynamically created BoardGame.
 */
boardGame* createBoard( char * title, double price, char * brand )
{
    boardGame* bo = malloc(sizeof(boardGame));
    
    bo-> price = price;
    bo-> name = title;
	bo-> brandName = brand; 
   
    return bo;
}

/**
 * Get price of boardGame
 * @param  bo Boardgame
 * @return  Double price
 */

double getPrice1(  boardGame * bo ) 
{ 
    return bo->price;
}


/**
 * Return a boardgame name
 * @param  bo Boardgame
 * @return  char* string of name
 */
char* getName1(  boardGame *bo )
{
	return bo->name;
}


/**
 * Return a boardgame brand  name
 * @param  bo Boardgame
 * @return  char* string of name
 */

char* getBrandName1(  boardGame *bo )
{
	return bo->brandName;
}


/**
 * Display a boards's name and price and brand.
 * @param v [Boardgame]
 */
void printBoardGame1( void * v )
{
     boardGame * bo = ( boardGame *) v;
   
    printf("<%s>    <%.2f>    <%s>\n", getName1(bo), getPrice1(bo), getBrandName1(bo) );
}



