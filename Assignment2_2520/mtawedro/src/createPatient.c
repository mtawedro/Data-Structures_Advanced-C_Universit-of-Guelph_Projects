#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "patient.h"
#include "LinkedListAPI.h"


/**
 * [createBook description]
 * @param  title static string of title
 * @param  price double
 * @return  a dynamically created Book.
 */
 
Patient* createPatient( char patientTempID [], int priortyTemp, char symptomTemp [])
{
    	 
    Patient* tempPatient = malloc(sizeof(Patient));
    
    strncpy(tempPatient->patientID, patientTempID, (strlen(patientTempID) +1));
    
    strncpy(tempPatient->symptom, symptomTemp, (strlen(symptomTemp) +1));
   
    tempPatient->priorty = priortyTemp;
    
   // printf("HERE %s %s %d\n ", tempPatient->patientID, tempPatient->symptom,  tempPatient->priorty );
    
    
    

    return  tempPatient;
}


/**
 * Get price of book
 * @param  b Book
 * @return Double price
 */
int getPriorty( Patient * p ) 
{ 
    return p->priorty;
}



/**
 * Return a books name
 * @param  b Book
 * @return  char* string of name
 */
char* getSymptom( Patient *p )
{
	return p->symptom;
}

char* getPatientID( Patient *p )
{
	return p->patientID;
}


/**
 * Display a book's name and price.
 * @param v [Book]
 */
void printPatient( void * v )
{
    Patient* p = (Patient *) v;
   
    printf("%s %s %d\n ", getPatientID(p), getSymptom(p), getPriorty(p) );
}

