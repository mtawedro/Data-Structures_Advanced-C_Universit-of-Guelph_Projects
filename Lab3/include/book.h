#ifndef BOOK_H
#define BOOK_H

 /**
 * declares struct book with elements price and ptr name 
 *
 */

typedef struct book {
    
    
    double price;
    
    
    char *name;



} Book;



 /**
 * declares function createBook
 * @param  char title 
 * @param  double price
 * @return dynamatically created book with filled in data
 */
Book* createBook( char * title, double price );

/**
 * Get price of book
 * @param  b Book
 * @return Double price b
 */
double getPrice( Book * b );

/**
 * Return a books name
 * @param  b Book
 * @return  char* string of name
 */
char* getName( Book *b );


/**
 * Display a book's name and price.
 * @param v [Book]
 */
void printBook( void * v );





#endif
