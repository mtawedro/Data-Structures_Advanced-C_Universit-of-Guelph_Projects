#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/*compares the id numbers in desending order and returns the id numbers from greatest to least*/

int	compare_id_descending ( const	void	*a,	const	void  *b)
{


	

	return(((struct element*)a)->id_number < ((struct element*)b)->id_number);
	
	
	
	
}
