#ifndef CAR_H
#define CAR_H

 /**
 * declares struct book with elements price and ptr name 
 *
 */

typedef struct Car{

    char direction;
    double sec;
    char coord;  
	double secBefore;
    

}Car;



 /**
 * declares function createBook
 * @param  char title 
 * @param  double price
 * @return dynamatically created book with filled in data
 */
Car* createCar( char coordin, char dir, double seconds );

/**
 * Get price of book
 * @param  b Book
 * @return Double price b
 */
char getDirection( Car * c );

/**
 * Return a books name
 * @param  b Book
 * @return  char* string of name
 */
double getSec( Car *c );

char getCoor( Car * c );


/**
 * Display a book's name and price.
 * @param v [Book]
 */
void printCar( void * v );





#endif
