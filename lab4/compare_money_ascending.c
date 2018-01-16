#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareElements.h"
 
/*compares the order of money in asending order and returns it from least to greatest*/

int	compare_money_ascending	( const	void	*a,	const	void *b)
{
	
	
	

	return(((struct element*)a)->salary > ((struct element*)b)->salary);
	
	
}
