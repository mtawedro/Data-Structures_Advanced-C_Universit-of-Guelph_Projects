#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "car.h"

int sim = 0;

//This function opens the file required and if file coud not be opened then user is prompt to enter file input again and returns a file pointer
FILE *OpenFile(char File[])
{
    // File pointer
    FILE *inFile = NULL; 
      
    // Open file 
    inFile = fopen(File, "r");
   
    // Error Trap, if file could not be found or user enters in wrong file name 
    while(inFile == NULL) {
        printf("Could not open file myfile.txt. Please enter in another file\n");
             
        fgets(File, 200, stdin);
      
        //gets rid of hard return
        if(File[strlen(File)-1] == '\n')
        {
             File[strlen(File)-1] = '\0';
        }
                  
        inFile = fopen(File, "r");
    
    }    
    
    
    return inFile;    

}



							/***********************STARTS SIMULATION******************************************/
void Similation(List *listN, int count)	
{



	double forward = 2;
	double right = 1;
	double left = 2.5; 
	double acrossFinish = 0.0;
	int getOut = 0;
	double lightTimer = 1.0; 
	//int print = 0;
	double array[count];
	double newArray[count];
	//int count = 0; 

	double greenTimer  = 10.0;
	
	int i = 0;




	List *list = malloc(sizeof(List));
	
	list = listN;

	Node *temp = list->head;

while(temp!=NULL)
{ 
	//searches Nlist until done;, goes through each node
	do
	{
		
		
		if(((Car*)(temp->data)) -> direction == 'F' && (lightTimer > 0.0 && lightTimer <10.0))
		{
			if((((Car*)(temp->data)) -> sec > 14) && count !=1)
			{
				
				lightTimer = 14;
				
				
			}
				//usual calculations.
				else if((((Car*)(temp->data)) -> sec > acrossFinish ))
				{
					
					if( forward < (greenTimer -lightTimer)) //-> car has enough time to cross before light turns yellow 
					{
						
						acrossFinish = (((Car*)(temp->data)) -> sec) + forward;
						sim++;
						lightTimer = lightTimer + forward; 
						if(lightTimer == 9.5)
						{						
							lightTimer = lightTimer  + 0.5;
		
						}
						
						
						 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
						 deleteNodeFromList(list,((Car*)(temp->data)) );
						
						
					}
				
					else if(forward > (greenTimer-lightTimer))// car doesnt have enough time to cross, judt add (4) + (10 - 4) to make it 10
					{
						lightTimer = lightTimer + (greenTimer-lightTimer);
						sim++;
						
					}
			
			
				}
				
			
				else      
				{
				
					if( forward < (greenTimer-lightTimer)) //-> time remaining 
					{
						
						acrossFinish = acrossFinish + forward; 
						lightTimer = lightTimer + forward; 
						sim++;
						if(lightTimer == 9.5)
						{						
							lightTimer = lightTimer  + 0.5;
		
						}
					
					
						
						 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
						deleteNodeFromList(list,((Car*)(temp->data)) );
						
					}
				
					else if(forward > (greenTimer-lightTimer))
					{
						lightTimer = lightTimer + (greenTimer-lightTimer);
						sim++;
						
					}
			
				}	
			
			
			array[i] = acrossFinish;
			i++;
		
		
		}
		
		
		
	
		else if(((Car*)(temp->data)) -> direction == 'R' && (lightTimer > 0.0 && lightTimer <10.0))
		{
			
			if((((Car*)(temp->data)) -> sec > 14) && count !=1)
			{
				
				lightTimer = 14;
				
				
			}
			
	
			else if(((Car*)(temp->data)) -> sec > acrossFinish)
			{
			
				
				if( right < (greenTimer-lightTimer)) //-> time remaining 
				{
					
					acrossFinish = (((Car*)(temp->data)) -> sec) + right; 
					lightTimer = lightTimer + right;
					sim++;
					if(lightTimer == 9.5)
					{						
						lightTimer = lightTimer  + 0.5;
		
					}
				
					 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
					deleteNodeFromList(list,((Car*)(temp->data)) );
						
				}
			
			
				else if(right > (greenTimer-lightTimer))
				{
					lightTimer = lightTimer + (greenTimer-lightTimer);
					sim++;
					
				}
			
			
			}
			
			
			else
			{
				
				if( right < (greenTimer-lightTimer)) //-> time remaining      
				{
					
						acrossFinish = acrossFinish + right; 
						lightTimer = lightTimer + right;
						sim++;
						if(lightTimer == 9.5)
						{						
							lightTimer = lightTimer  + 0.5;
		
						}
					
					
					 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
					deleteNodeFromList(list,((Car*)(temp->data)) );
						
					
				}
			
				else if(right > (greenTimer-lightTimer))
				{
					lightTimer = lightTimer + (greenTimer-lightTimer);
					sim++;
				
				}
				
			
			}
				
			array[i] = acrossFinish;
			i++;
			
		}
		
		
		else if(((Car*)(temp->data)) -> direction == 'L' && (lightTimer > 0.0 && lightTimer <10.0))
		{
			
			
			if((((Car*)(temp->data)) -> sec > 14) && count !=1)
			{
							
				lightTimer = 14;

			}
			
			
			
		
			else if(((Car*)(temp->data)) -> sec > acrossFinish )
			{
				
				
				if( left < (greenTimer-lightTimer)) //-> time remaining 
				{
				
					lightTimer = lightTimer + left;
					acrossFinish = ((Car*)(temp->data)) -> sec + left; 
					
					sim++;
					if(lightTimer == 9.5)
					{						
						lightTimer = lightTimer  + 0.5;
		
					}
				
				     
				     printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
					deleteNodeFromList(list,((Car*)(temp->data)) );
				
				
				}
				
				else if(left > (greenTimer-lightTimer))
				{
					lightTimer = lightTimer + (greenTimer-lightTimer);
					sim++;
					
				}
			
			}
		
		
			else
			{
				
				if( left < (greenTimer-lightTimer)) //-> time remaining 
				{
					lightTimer = lightTimer + left;
					acrossFinish = acrossFinish + left; 
					
					sim++;
					if(lightTimer == 9.5)
					{						
						lightTimer = lightTimer  + 0.5;
		
					}
				
					
					 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
					 deleteNodeFromList(list,((Car*)(temp->data)) );
					
				}
			
				else if(left > (greenTimer-lightTimer))
				{
					lightTimer = lightTimer + (greenTimer-lightTimer);
					sim++;
	
				}
		
			
			}
			array[i] = acrossFinish;
			i++;
			
	
		}
	
		 else if(((Car*)(temp->data)) -> direction == 'L' && (lightTimer >= 10.0 && lightTimer <10.5))
		 {
		
			if((((Car*)(temp->data)) -> sec > 14) && count !=1)
			{
				
				lightTimer = 14;
				
				
			}
			

			else if(((Car*)(temp->data)) -> sec > acrossFinish)
			{
				
				lightTimer = lightTimer + left + 0.5;
				sim++;
			
			    printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
				deleteNodeFromList(list,((Car*)(temp->data)) );
					
			
			}
			
			else
			{			
					acrossFinish = acrossFinish + left; 
					sim++;
					
				
					 printf("%c %c %.2f 				%.2f 					%.2f\n", ((Car*)(temp->data)) -> coord,((Car*)(temp->data)) -> direction,((Car*)(temp->data)) -> sec, ((Car*)(temp->data)) -> sec, acrossFinish);
					 deleteNodeFromList(list,((Car*)(temp->data)) );
							
		    }
			
			array[i] = acrossFinish;
			i++;
			
		
		}
		
		//red light
		else if(lightTimer >=13.0)
		{
			lightTimer = lightTimer + 1;
			sim++;	
			 
		}
		
		
		
		if(getOut == 1)
		{
			break;
			
		}
	
		temp = temp->next; 
		
		if(temp == NULL)
		{
			while(lightTimer<=14)
			{
				
				lightTimer ++;
				sim++;
				
			}
		
		}
		
		
	}while (lightTimer  < 14.0);


}//end of outer loop


	for( int o= 0; o<i; o++)
	{
		newArray[o] = array[o];
		
	}


	for(int m = 0; m<i; m++)
	{
		if(array[m] != newArray[m+1])
		{
		
		}
	
	}


}



int main(int argc, char*argv[]) {
	
   /*calls OpenFile function to acess and open file*/
   FILE* inFile = OpenFile(argv[1]);
   int N = 0;
   int S = 0;
   int W = 0;
   int E = 0;
   char line [1000];

   char point;
   char dir;
   double time;
   
   Car *carTempN = malloc(sizeof(Car) * 1); 
   Car *carTempS = malloc(sizeof(Car) * 1); 
   Car *carTempE = malloc(sizeof(Car) * 1); 
   Car *carTempW = malloc(sizeof(Car) * 1); 
  
   List * listE = initializeList(&printNode, &deleteFunction, &compare);
   List * listW = initializeList(&printNode, &deleteFunction, &compare);
   List * listN = initializeList(&printNode, &deleteFunction, &compare);
   List * listS = initializeList(&printNode, &deleteFunction, &compare);
			
   
    while(/*!feof(inFile)*/  fgets(line,100, inFile) != NULL) 
    {
		sscanf(line,"%c %c %lf", &point, &dir, &time);
		
		if(point == 'N')
		{
			carTempN = createCar(point, dir, time);
			
			insertBack(listN, carTempN); 
			
			
			N++;
			
			
		}	
		
		else if(point == 'S')
		{
			carTempS = createCar(point, dir, time);
			
			insertBack(listS, carTempS); 
			S++;
			
		}	
		
		else if(point == 'W')
		{
			carTempW = createCar(point, dir, time);
			
			insertBack(listW, carTempW); 
			
			W++;
			
		}	
		else if(point == 'E')
		{
			carTempE = createCar(point, dir, time);
			
			insertBack(listE, carTempE); 
			E++;
			
		}	
			
		
   
    }//end of while
    

  
    printf("Initial Vehicle Information      Intersection Arrival Time		Completed at Time\n");
	
	
	Similation(listN, N);


	Similation(listE, E);

	Similation(listS, S);	
 
	Similation(listW, W);
	Similation(listN, S);
	

	int stop = 1;	

	Similation(listN, stop);

	Similation(listE, stop);

	Similation(listS, stop);

	Similation(listW, stop);
	
	



	Similation(listN, N);

	Similation(listE, E);

	Similation(listS, S);	

	Similation(listW, W);
	Similation(listN, S);
	
	
	Similation(listN, stop);

	Similation(listE, stop);
	
	Similation(listS, stop);
	
	Similation(listW, stop);
	
	
	
	Similation(listN, N);


	Similation(listE, E);

	Similation(listS, S);	

	Similation(listW, W);
	Similation(listN, S);
	
	
	Similation(listN, stop);

	Similation(listE, stop);
	
	Similation(listS, stop);

	
	
	Similation(listW, stop);
	
	
	Similation(listN, N);


	Similation(listE, E);
  
	Similation(listS, S);	
 
	Similation(listW, W);
	Similation(listN, S);
	
	
	Similation(listN, stop);

	Similation(listE, stop);
	
	Similation(listS, stop);
	
	Similation(listW, stop);
	
	
	
	Similation(listN, N);


	Similation(listE, E);

	Similation(listS, S);	
  
	Similation(listW, W);
	Similation(listN, S);
	
	
	Similation(listN, stop);

	Similation(listE, stop);

	Similation(listS, stop);

	Similation(listW, stop);
	
	

	Similation(listE, E);

	Similation(listS, S);	

	Similation(listW, W);
	Similation(listN, S);
	

	Similation(listN, stop);

	Similation(listE, stop);

	Similation(listS, stop);

	Similation(listW, stop);
	


	//frees
	deleteList(listN);
	deleteList(listE);
	deleteList(listS);
	deleteList(listW);
	
	

	
fclose(inFile);

return 0;
}
