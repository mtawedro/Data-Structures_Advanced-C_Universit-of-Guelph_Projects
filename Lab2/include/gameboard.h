#ifndef GAMEBOARD_H
#define GAMEBOARD_H

    
	//defines struct boardgame with elements name, price, and brandname 

	typedef struct boardgame
    	{
		
		char *name;
		double price;
		char *brandName;
		
	} boardGame;

	

/**
 * [createBoardGame description]
 * @param  title static string of title
 * @param char brand
 * @param  price double
 * @return  a dynamically created BoardGame.
 */
boardGame* createBoard( char * title, double price, char * brandName );

/**
 * Get price of boardGame
 * @param  bo Boardgame
 * @return  Double price
 */	
double getPrice1(  boardGame * bo ) ;

/**
 * Return a boardgame name
 * @param  bo Boardgame
 * @return  char* string of name
 */

char* getName1( boardGame *bo );

/**
 * Return a boardgame brand  name
 * @param  bo Boardgame
 * @return  char* string of name
 */
char* getBrandName1( boardGame *bo );


/**
 * Display a boards's name and price and brand.
 * @param v [Boardgame]
 */
void printBoardGame1( void * v );

	
	
	
#endif
