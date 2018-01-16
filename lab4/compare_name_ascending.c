#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/*compares the order of the names in asending order(alpha order) and returns it from greatest to least (alpha order) by using strcmp
and comparing the fisrt word and seeing if its greater then the next word in terms of asci values */

int	compare_name_ascending	( const	void	*a,	const	void *b)
{
	
	return (strcmp(((struct element*)a)->last_name, ((struct element*)b)-> last_name) >0);
	
	
	
	
	
}
