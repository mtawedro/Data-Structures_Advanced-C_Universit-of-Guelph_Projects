#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/*compares the order of money in desending order and returns it from greatest to least*/

int	compare_money_descending ( const	void	*a,	const void	*b)
{
	
	

	return(((struct element*)a)->salary < ((struct element*)b)->salary);
	
	
	
	
}
