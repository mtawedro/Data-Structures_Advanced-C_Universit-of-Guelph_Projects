#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"
#include "LinkedListAPI.h"


/**
 * [createBook description]
 * @param  title static string of title
 * @param  price double
 * @return  a dynamically created Book.
 */
 
Car* createCar(  char coordin, char dir, double seconds)
{
    	 
    Car* tempCar = malloc(sizeof(Car));
    
    tempCar->direction  = dir;
    tempCar->sec = seconds;
    tempCar->coord = coordin;
    

    return tempCar;
}


/**
 * Get price of book
 * @param  b Book
 * @return Double price
 */
double getSec( Car * c ) 
{ 
    return c->sec;
}



/**
 * Return a books name
 * @param  b Book
 * @return  char* string of name
 */
char getDirection( Car *c )
{
	return c->direction;
}

char getCoor( Car *c )
{
	return c->coord;
}


/**
 * Display a book's name and price.
 * @param v [Book]
 */
void printCar( void * v )
{
    Car* c = (Car *) v;
    printf("%c %c %.2f\n ", getCoor(c), getDirection(c), getSec(c) );
}

