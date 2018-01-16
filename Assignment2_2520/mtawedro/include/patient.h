#ifndef PATIENT_H
#define PATIENT_H

 /**
 * declares struct book with elements price and ptr name 
 *
 */

typedef struct Patient{

    char patientID[50];
    char symptom [50];
    int priorty;
    int finishTime;  
	
}Patient;



 /**
 * declares function createBook
 * @param  char title 
 * @param  double price
 * @return dynamatically created book with filled in data
 */
Patient* createPatient( char patientTempID [], int priortyTemp, char symptomTemp []);

/**
 * Get price of book
 * @param  b Book
 * @return Double price b
 */
char* getPatientID( Patient * p );

/**
 * Return a books name
 * @param  b Book
 * @return  char* string of name
 */
int getPriorty( Patient *p );

char* getSymptom( Patient * p );


/**
 * Display a book's name and price.
 * @param v [Book]
 */
void printPatient( void * v );





#endif
