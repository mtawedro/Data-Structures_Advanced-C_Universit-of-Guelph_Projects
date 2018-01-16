#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**

 * Create a typedef for a  Compare Function 

 */

typedef int (*CompareFunc)(void* a, void* b); // do we have to use this ??



/**

 * Create a typedef for a Sort Algorithm of an array

 */
//containor is array??
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

/***

 * NOTE: You will implement this function, it will be used to call all sorting algorithms. 

 *      It will also output the all the information required by the output section of the lab.

 *       

 * menuSelection is the text for the menu option that was selected.

 * sorter -> is the sorting function

 * array -> is the input array given by the user

 * length-> is the length of the array

 * compare -> is a comparison function pointer.

 */
		    //text					//function that sorts
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare);


 void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)
{
  
  SortAlgorithm(array, length,  compare)
  
}


int main(void)
{
   int array[100], evenArray[100], oddArray[100], together[100],n,c,d,position,swap;
   
   int count = 0;
   int countO = 0;
   int t = 0;
   int add = 0;

printf("enter number of elements\n");
scanf("%d", &n);
  
printf("Enter %d integers\n", n);

for(c=0; c<n; c++)
{
	scanf("%d", &array[c]);
	
}

printf(" Sorting Menu System");
printf("1)	Bubble Sort ( increasing order)\n");
printf("2)	Bubble Sort ( decreasing order\n");
printf("3)	Bubble Sort ( increasing order – evens numbers before odd numbers\n ");
printf("4)	Selection Sort ( increasing order\n");
printf("5)	Selection Sort ( decreasing order\n" );
printf("6)	Selection Sort ( increasing order – evens numbers before odd numbers\n ");
printf("7)	Quit\n");



 char menuSelection[50];
 char compare[50];
*SortAlgorithm sorter;

enter in number printf("Enter Choice:")
				  scanf("%d", &choice)
						
while(choice != 7)
	 switch(choice)
	 {
				  case 1:
				  {
				     sorter = &bubbleSort();
				     strcpy(menuSelection, "increasing");
				     strcpy(compare, "increasing");
				     sort(menuSelection, sorter, array, compare);
				     
				   }
				  case 2:
				   {
				     sorter = &bubbleSort();
				     strcpy(menuSelection, "decreasing");
				     strcpy(compare, "decreasing");
				     sort(menuSelection, sorter, array, n, compare);
				     
				   }
				   case 3:
				   {
				     SortAlgorthim sorter = &bubbleSort();
				     strcpy(menuSelection, "even");
				     strcpy(compare, "even");
				     sort(menuSelection, sorter, array, n, compare);
				     
				   }
				   case 4:
				   {
				     SortAlgorthim sorter = &selectionSort();
				     strcpy(menuSelection, "increasing");
				      strcpy(compare, "increasing");
				     sort(menuSelection, sorter, array, n, compare);
				     
				   }
				   case 5:
				   {
				      SortAlgorthim sorter = &selectionSort();
				     strcpy(menuSelection, "decreasing");
				     strcpy(compare, "decreasing");
				     sort(menuSelection, sorter, array, n, compare);
				     
				   }
				   case 6:
				   {
				      SortAlgorthim sorter = &selectionSort();
				     strcpy(menuSelection, "even");
				     strcpy(compare, "even");
				     sort(menuSelection, sorter, array, n, compare);
				     
				   }
				  			  
				  
				  
				  }
				  				  
				  


//get coorsponding sorting name
//does if conditions if sorting name == bubble || selection
//equals the sortAlgorthim pointer == &sorting function
//calls sort function 
//inside sort function call SortAlgorthiem function 










//finds even numbers puts them in array, find odd numbers put them in a different array (make into function)
    for (int j = 0; j < n ; j++) {
          
       // printf("(array[j] %d\n", array[j]);
       
         if (array[j]%2 == 0) 
		 {
            evenArray[count] = array[j];
         //  printf("Even %d\n", evenArray[count]);
            count++;
		 }
		
		 else 
		 {
			oddArray[countO] = array[j];
           // printf("Odd %d\n", oddArray[countO]);
            countO++;
			 
		 }
	
	
	
	}
// sorts even   
for(c = 0; c<(count-1); c++)
{
	
	position = c;
	
	for(d = c+1; d<count; d++)
	{
		if(evenArray[position] > evenArray[d])
		{
			position = d;
			
		}
		
		
	}
	
	if(position !=c)
	{
		swap = evenArray[c];
		evenArray[c] = evenArray[position];
		evenArray[position] = swap;
		
	}
	
}
  // sorts odd   
for(c = 0; c<(countO-1); c++)
{
	
	position = c;
	
	for(d = c+1; d<countO; d++)
	{
		if(oddArray[position] > oddArray[d])
		{
			position = d;
			
		}
		
		
	}
	
	if(position !=c)
	{
		swap = oddArray[c];
		oddArray[c] = oddArray[position];
		oddArray[position] = swap;
		
	}
	
}
  
 //puts sorted even num amd sorted odd num in same array
  int len = count + countO; // 2
 
  for(c = 0; c<count; c++)
  {
	
    together[add] = evenArray[c];
	add++;

  }
 
  for(c = 0; c<countO; c++)
  {
	
    together[add] = oddArray[c];
	add++;

  }
   
   
   
   printf("(Insertation Sort) Even Numbers before odd )Sorted list in increasing  order:\n");
  for(int x = 0; x<add; x++)
  {
	  printf("%d\n",  together[x]);
	  
  }
 
 add = 0;
 countO = 0;
 count = 0;
 
 
 
for(c = 0; c<(n-1); c++)
{
	
	position = c;
	
	for(d = c+1; d<n; d++)
	{
		if(array[position] > array[d])
		{
			position = d;
			
		}
		
		
	}
	
	if(position !=c)
	{
		swap = array[c];
		array[c] = array[position];
		array[position] = swap;
		
	}
	
}
  
  
  
  
  
  printf("Sorted list in ascending order:\n");
  for(c = 0; c<n; c++)
  {
	  printf("%d\n", array[c]);
	  
  }
  
  for(c = 0; c<(n-1); c++)
{
	
	position = c;
	
	for(d = c+1; d<n; d++)
	{
		if(array[position] < array[d])
		{
			position = d;
			
		}
		
		
	}
	
	if(position !=c)
	{
		swap = array[c];
		array[c] = array[position];
		array[position] = swap;
		
	}
	
}

printf("Sorted list in decreasing order:\n");
  for(c = 0; c<n; c++)
  {
	  printf("%d\n", array[c]);
	  
  }
  
  
  for (d = 0; d < (c-1) ; d++) {
      
      for ( int j = 0; j < (c-d)-1; j++) {
         
         if (array[j] > array[j + 1]) 
			{
            
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
			}
			
		}
		
	}
  
  
  printf("(Bubble Sort )Sorted list in increasing  order:\n");
  for(c = 0; c<n; c++)
  {
	  printf("%d\n", array[c]);
	  
  }
  
   for (d = 0; d < c-1 ; d++) {
      
      for ( int j = 0; j < (c-d)-1  ; j++) {
         
         if (array[j] < array[j + 1]) 
			{
            
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
			}
			
		}
		
	}
  
  printf("(Bubble Sort )Sorted list in decreasing  order:\n");
  for(c = 0; c<n; c++)
  {
	  printf("%d\n", array[c]);
	  
  }
  
 
  //finds even numbers puts them in array, find odd numbers put them in a different array 
    for (int j = 0; j < n ; j++) {
          
       // printf("(array[j] %d\n", array[j]);
       
         if (array[j]%2 == 0) 
		 {
            evenArray[count] = array[j];
         //  printf("Even %d\n", evenArray[count]);
            count++;
		 }
		
		 else 
		 {
			oddArray[countO] = array[j];
           // printf("Odd %d\n", oddArray[countO]);
            countO++;
			 
		 }
	
	
	
	}
  
  //sorts even array
  for (d = 0; d < count-1 ; d++) {
      
      for ( int j = 0; j < (count-d)-1  ; j++) {
         
         if ( evenArray[j] >  evenArray[j + 1]) 
			{
            
                int temp =  evenArray[j];
                 evenArray[j] =  evenArray[j+1];
                 evenArray[j+1] = temp;
			}
			
		}
		
	}
 
  // sorts  odd array
 
  for (d = 0; d < countO-1 ; d++) {
      
      for ( int j = 0; j < (countO-d)-1  ; j++) {
         
         if ( oddArray[j] >  oddArray[j + 1]) 
			{
            
                int temp =  oddArray[j];
                 oddArray[j] =  oddArray[j+1];
                 oddArray[j+1] = temp;
			}
			
		}
		
	}
	

  //puts sorted even num amd sorted odd num in same array
   len = count + countO; // 2
 
  for(c = 0; c<count; c++)
  {
	
    together[add] = evenArray[c];
	add++;

  }
 
  for(c = 0; c<countO; c++)
  {
	
    together[add] = oddArray[c];
	add++;

  }
   
   
   
   printf("(Bubble Sort) Even Numbers before odd )Sorted list in increasing  order:\n");
  for(int x = 0; x<add; x++)
  {
	  printf("%d\n",  together[x]);
	  
  }
 
 
 
 return 0; 
}







