#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorting.h"

void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)
{
	
	  printf("%s\n", menuSelection);
	  sorter(array, length, compare);
}


//decreasing
int CompareFunctionDecreasing(void* a, void* b) 
{
    int* A = (int*) a;
    int* B = (int*) b;
    if (*A  < *B) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

//increasing
int CompareFunctionIncreasing(void* a, void* b) 
{
    int* A = (int*) a;
    int* B = (int*) b;
    if (*A  > *B) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

//compares if each number in array and indentfies if even or odd 
int CompareFunctionEven(void* a, void* b) 
{
    int* A = (int*) a;
    int* B = (int*) b;
    
    if (*A % *B == 0) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}




void bubbleSort(int* container, int length, CompareFunc cf) 
{
    for (int i = 0; i < length-1; i++) 
    {
        for (int j = 0; j < (length - i) -1; j++) 
        {
            
            if ((cf(&container[j], &container[j + 1])) == 1) 
            {               
                int temp = container[j];
                container[j] = container[j+1];
                container[j+1] = temp;
            }
        }
    }
}

/*The smallest element is selected from the unsorted array and swapped with the 
  leftmost element, and that element becomes a part of the sorted array. This process
  continues moving unsorted array boundary by one element to the right.
 **/
void selectionSort(int* container, int length, CompareFunc cf) 
{
	int position,swap;
   
    for(int c = 0; c<(length-1); c++)
	{
	
		position = c;
	
		for(int d = c+1; d<length; d++)
		{
			if((cf(&container[position], &container[d])) == 1)
			{
				position = d;	
			}
		}
	
		if(position !=c)
		{
			swap = container[c];
			container[c] = container[position];
			container[position] = swap;	
		}
	
	}

}


//function that finds even numbers puts them in sepearte array, then odd numbers put them in a different array 
void EvenOddCheck(int* container, int* evenCont, int* oddCont, int n,  CompareFunc cf, int* together, int flag)
{
	int b = 2;
	int count = 0;
	int countO = 0;
	char menuOption[100];
     
   //finds even numbers puts them in array, find odd numbers put them in a different array 
    for (int j = 0; j < n ; j++) 
    {
        //if container[j] %2 == 0 **calls 3rd comapare function to check for even/odd numbers
         if ((cf(&container[j], &b)) == 1) 
		 {
            evenCont[count] = container[j];
            count++;
		 }
		
		 //if odd
		 else 
		 {
			oddCont[countO] = container[j];
            countO++;
			 
		 }

	}
	
	if(flag == 0)
	{
	  strcpy(menuOption, "Selection Sort(increasing order – evens numbers before odd numbers)");
	 
	  //sorts even array (array containg only even numbers)
	  sort(menuOption, selectionSort,  evenCont, count, CompareFunctionIncreasing);
	 
	  //sorts odd array (array containg only odd numbers)
	  sort("", selectionSort,  oddCont, countO, CompareFunctionIncreasing);
	 
	  //once both arrays are sorted, puts sorted even and odd numbers from both arrays into one sigle array, then prints
	  togetherAdd(count, countO, evenCont, oddCont, together);
	 
  }
  
  else if(flag == 1)
  {
	  strcpy(menuOption, "Bubble Sort(increasing order – evens numbers before odd numbers)");
	 
	  sort(menuOption, bubbleSort,  evenCont, count, CompareFunctionIncreasing);
	 
	  sort("", bubbleSort,  oddCont, countO, CompareFunctionIncreasing);
	 
	  togetherAdd(count, countO, evenCont, oddCont, together);
  }
	
}


//puts sorted even num amd sorted odd num in same array
void togetherAdd(int count, int countO, int* evenCont, int* oddCont, int *together)
 {
	 int add = 0;
 
	// places sorted even numbers in array
	for(int c = 0; c<count; c++)
	{
		together[add] = evenCont[c];
		add++;
	}
 
    //places odd sorted numbers in same array 
    for(int c = 0; c<countO; c++)
	{
		together[add] = oddCont[c];
		add++;
	}
  
	printArray( together, add );
   
 
} 


void printArray( int* arr, int length )
{
	printf("Result Array:");
	for(int i =0 ; i < length; i++ ) 
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");

}

void printArrayTemp( int* arr, int length )
{
	for(int i =0 ; i < length; i++ ) 
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");

}


int main(void)
{

int array[100], evenArray[100], oddArray[100], together[100], tempArray[100],n,c;
   
  
   int choice;
   char menuOption[200];
   int flag;

printf("enter number of elements\n");
scanf("%d", &n);
  
printf("Enter %d integers\n", n);

for(c=0; c<n; c++)
{
	scanf("%d", &array[c]);
	tempArray[c] = array[c];
	
}

printf(" Sorting Menu System\n");
printf("1. Bubble Sort (increasing order)\n");
printf("2. Bubble Sort (decreasing order)\n");
printf("3. Bubble Sort (increasing order – evens numbers before odd numbers)\n");
printf("4. Selection Sort (increasing order)\n");
printf("5. Selection Sort (decreasing order)\n" );
printf("6. Selection Sort (increasing order – evens numbers before odd numbers)\n");
printf("7. Quit\n");

printf("Enter Choice:");
scanf("%d", &choice);
getchar();

while(choice !=7)
{						
   printf("Initial Array:");
   printArrayTemp(tempArray, n);
   printf("\n");
    
  
   switch(choice)
   {
    case 1:
	{
		
		strcpy(menuOption, "Bubble Sort(increasing order)");
		sort(menuOption, bubbleSort, array, n, CompareFunctionIncreasing);
		printf("\n");
		printArray(array, n);
		break;
	 
	}
	case 2:
	{
		
		strcpy(menuOption, "Bubble Sort(decreasing order)");
		sort(menuOption, bubbleSort, array, n, CompareFunctionDecreasing);
		printf("\n");
		printArray(array, n);
		break;
	}
	case 3:
	{
		
		flag = 1;
		EvenOddCheck(array, evenArray, oddArray, n, CompareFunctionEven, together, flag );
		break;	
	  
	}
	case 4:
	{
		
		strcpy(menuOption, "Selection Sort(increasing order)");
		sort(menuOption, selectionSort, array, n, CompareFunctionIncreasing);
		printf("\n");
		printArray(array, n);
		break;
	}
	case 5:
	{
		
		strcpy(menuOption, "Selection Sort(decreasing order)");
		sort(menuOption, selectionSort, array, n, CompareFunctionDecreasing);
		printf("\n");
		printArray(array, n);
		break;
	}
	case 6:
	{
		
		flag = 0;
		EvenOddCheck(array, evenArray, oddArray, n, CompareFunctionEven, together, flag );
		break;
	 
	
	}
	default:
	{
		printf("Invalid Choice:");
		
	}
	
    
    
  }
    printf("\n");
    printf("Enter Choice:");
	scanf("%d", &choice);
	getchar();
  }



return 0;

}






