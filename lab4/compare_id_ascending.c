#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/* compares the id numbers and sorts them in ascending order and returns in the form of greatest to least */

int	compare_id_ascending ( const	void	*a,	const	void *b)
{
	

	return(((struct element*)a)->id_number > ((struct element*)b)->id_number);
	
	
}
