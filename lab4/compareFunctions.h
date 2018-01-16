#ifndef COMPAREFUNCTIONS_H_INCLUDED
#define COMPAREFUNCTIONS_H_INCLUDED



/*
 *  Functions to do comparison for qsort 
 */

int compare_id_ascending ( const void *a, const void *b );
int compare_id_descending ( const void *a, const void *b );

int compare_name_ascending ( const void *a, const void * b);
int compare_name_descending ( const void *a, const void * b);

int compare_money_ascending ( const void *a, const void * b);
int compare_money_descending ( const void *a, const void * b);




#endif
