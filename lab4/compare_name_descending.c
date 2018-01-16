#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/*compares the order of the names in desending order(backwards) and returns it from least to greatest (un-alpha order) by using strcmp
and comparing the fisrt word and seeing if its less then the next word in terms of asci values */

int	compare_name_descending	( const	void	*a,	const	void *b)
{
	
	
	return (strcmp(((struct element*)a)-> last_name, ((struct element*)b)->last_name)<0);
	
	
	
	
}
