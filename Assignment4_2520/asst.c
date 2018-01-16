#include <stdio.h>

#include <stdlib.h>

#include "BinSearchTreeAPI.h"

#include <string.h>

#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

#include "BinSearchTree.c"


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


int compareDupl(char **array, char wordtoCompare [], int length)
{
	int flag = 0;
	
	if(length != 1)
	{
		for(int x = 0; x< length; x++)
		{
			for(int i = x + 1; i<length; i++)
			{
				if(strcmp(array[x], wordtoCompare) == 0)
				{
					flag = 1;
					return 1;
			
				}
			}
		}
	
	}
	
	if(flag != 1)
	{
		return 0;
	}
	
	return 0;

}


int main(int argc, char*argv[])
{
	/*calls OpenFile function to acess and open file*/
	FILE* inFile = OpenFile(argv[1]);
	
	Tree *tree1 = createBinTree(&compare, &deleteFunction);
	
	char tempSen[200] = " ";
	char tempKey[200];
	char tempOrig[200];
	int i = 0;
	char line[200];
	char userChoice[200];
	char userSentence[200];
	int input = 0;
	char **secondArray; 
	int check;
	double range = 0.0;
	
	
	secondArray = malloc(sizeof(char*) *1);
	
	char **firstArray; 
	
	firstArray = malloc(sizeof(char*) *1);
	
	char **thirdArray; 
	
	thirdArray = malloc(sizeof(char*) *1);
	
	char **fourArray; 
	
	fourArray = malloc(sizeof(char*) *1);
	
	char **tempArray; 
	
	tempArray = malloc(sizeof(char*) *1);
	
	char **tempArray1; 
	
	tempArray1 = malloc(sizeof(char*) *1);
	

	 while(fgets(line,200, inFile) != NULL) 
    {
		    sscanf(line,"%s", tempKey);
		    
		    firstArray = realloc(firstArray, sizeof(char*) *  (i +1));
		    //--> stored in anotehr temp 2-d array to check for dupliacted strings
		    tempArray = realloc( tempArray, sizeof(char*) *  (i +1));
		
			//each world will be placed on a new row in the 2d array 
			firstArray[i] = malloc(sizeof(char) * (strlen(tempKey) +1 )); 
			tempArray[i] = malloc(sizeof(char) * (strlen(tempKey) +1 )); 
			 
			strncpy(firstArray[i], tempKey, (strlen(tempKey) +1));
			strncpy(tempArray[i], toLower(tempKey), (strlen(toLower(tempKey)) +1));
			
			//reads in sentence
			if(fgets(line,200, inFile) == NULL)
			{
				strncpy(line, tempSen, strlen(tempSen) + 1 );
			}
			
			check = compareDupl(tempArray, tempArray[i], i + 1);
					
			if(check == 0)
			{
				Storage* tempStorage = createStorage(firstArray[i], line, 0.5, 0.5, 0);
				addToTree(tree1,tempStorage);
			}	
		
		    i++;
		   	    		    
	}
	fclose(inFile);
	
	printf("(1) Add a new rule\n");
	printf("(2) Remove a rule\n");
	printf("(3) Display rules\n");
	printf("(4) Modify rule rating\n");
    printf("(5) Discuss\n");
    printf("(9) Quit\n");
   
   
   
	printf("Enter Choice:");
	scanf("%d", &input);
	getchar();
   
	while(input!= 9)
	{ 
		switch(input)
		{
			case 1:
			{
	            i = 0;
	            printf("Enter a Keyword:\n");
	            fgets(userChoice, 200, stdin);
	           
	            printf("Enter a Sentence:\n");
	            fgets(userSentence, 200, stdin);
	          
	            printf("Enter the percieved importance of this rule (user rating) (in range 0.0 - 1.0)\n");
	            scanf("%lf", &range);
				getchar();
	            
	            while(range < 0.0 || range > 1.0)   
				{
					printf("Invalid Input\n");
					printf("Enter new user rating (0.0 - 1.0):\n") ;
					scanf("%lf", &range);
					getchar();
				    
			    }
	                
	            //gets rid of hard return
				if(userChoice[strlen(userChoice)-1] == '\n')
				{
					userChoice[strlen(userChoice)-1] = '\0';
				}
				
				//gets rid of hard return
				if(userSentence[strlen(userSentence)-1] == '\n')
				{
					userSentence[strlen(userSentence)-1] = '\0';
				}
					
				secondArray = realloc(secondArray, sizeof(char*) *  (i +1));
				tempArray1 = realloc( tempArray1, sizeof(char*) *  (i +1));//--> to check for dupliacted strings
		
		
				//each world will be placed on a new row in the 2d array 
				secondArray[i] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
				tempArray1[i] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
			
  
				strncpy(secondArray[i], userChoice, (strlen(userChoice) +1));
				strncpy(tempArray1[i], toLower(userChoice), (strlen(toLower(userChoice)) +1));
			
				Storage* tempCheck = createStorage(tempArray1[i], userSentence, 0.0, 0.0, 0);
				 
				TreeNode *temp = findInTree(tree1, tempCheck); //doesnt find word, ok to pass in
		         
		        if(temp == NULL)
		        {
					tempCheck = createStorage(secondArray[i], userSentence, range, 0.5, 0);
					addToTree(tree1,tempCheck);
					
				}	
				  
				i++;
				
			    break;
			}
		
		    case 2:
		    {
				
				 int x =0;
				 printf("Enter keyword you want to delete:\n");
		  
				 fgets(userChoice, 200 , stdin);
				 strcpy(tempOrig, userChoice);
				
				//gets rid of hard return
				 if(userChoice[strlen(userChoice)-1] == '\n')
				 {
					userChoice[strlen(userChoice)-1] = '\0';
				 }
			
				 //gets rid of hard return
				 if(tempOrig[strlen(tempOrig)-1] == '\n')
				 {
					tempOrig[strlen(tempOrig)-1] = '\0';
				 }
		  
		  
				 fourArray = realloc(fourArray, sizeof(char*) *  (x +1));
		
				 //each world will be placed on a new row in the 2d array 
				 fourArray[x] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
  
				 strncpy(fourArray[x], toLower(userChoice), (strlen(toLower(userChoice)) +1));

		         printf("Searching....\n");
		            
		         Storage* tempCheck = createStorage(fourArray[x], userSentence, 0.0, 0.0, 0);
				  
		         TreeNode *temp = findInTree(tree1, tempCheck);
		           
		         if(temp != NULL)
		         {
					removeFromTree(tree1, temp->data); 
							
					printf("Succesfully Deleted\n");
				 }
				 else
				 {
					printf("<%s> was not found\n", tempOrig);
						
				 }
		  
				 x++;
				   
				 break;
				
			}
		
		
		     case 3:   
		     {
				 printInOrder(tree1, printFunction);
				 break;
			 }
		     
		     case 4:
		     {
				int x =0;
				printf("Enter keyword to modify rule rating:\n");
		  
				fgets(userChoice, 200 , stdin);
				strcpy(tempOrig, userChoice);
				
				//gets rid of hard return
				if(userChoice[strlen(userChoice)-1] == '\n')
				{
					userChoice[strlen(userChoice)-1] = '\0';
				}
			
				//gets rid of hard return
				if(tempOrig[strlen(tempOrig)-1] == '\n')
				{
					tempOrig[strlen(tempOrig)-1] = '\0';
				}
		  
		  
				fourArray = realloc(fourArray, sizeof(char*) *  (x +1));
		
				//each world will be placed on a new row in the 2d array 
				fourArray[x] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
  
				strncpy(fourArray[x], toLower(userChoice), (strlen(toLower(userChoice)) +1));

		        printf("Searching....\n");
		            
		        Storage* tempCheck = createStorage(fourArray[x], userSentence, 0.0, 0.0, 0);
				  
		        TreeNode *temp = findInTree(tree1, tempCheck);
		           
		        if(temp != NULL)
		        {
					print(temp->data);
					printf("Enter new user rating (0.0 - 1.0):\n") ;
					scanf("%lf", &range);
				    getchar();
				       
				    while(range < 0.0 || range > 1.0)   
				    {
						printf("Invalid Input\n");
						printf("Enter new user rating (0.0 - 1.0):\n") ;
						scanf("%lf", &range);
						getchar();
				    
					}
				       
				    ((Storage*)(temp->data)) -> userRating = range;
				       	
					printf("Succesfully Updated\n");
				}
				else
				{
					printf("<%s> was not found\n", tempOrig);
						
				}
		  
			    x++;
				   
				break;
			 }
		     
		     case 5:
		     {  
				 int x = 0;
				 int count = 0;
				 char message[200];
				 double ratings[50]; //change to x+1
				 int flag = 0;
				 char feedback;
				 TreeNode *temp;
				 
				 printf("User: ");
				 fgets(message,200,stdin);
				 
				 if(message[0] != '\n')
				 {
				   //gets rid of hard return
				   if(message[strlen(message)-1] == '\n')
				   {
					  message[strlen(message)-1] = '\0';
				   }
				
				   thirdArray = realloc(thirdArray, sizeof(char*) *  (x +1));
		
				   char* tok;
				   char delim [20] = " ,.-;:!?";
				   tok = strtok(message, delim );

	                //each world will be placed on a new row in the 2d array 
				    thirdArray[x] = malloc(sizeof(char) * (strlen(tok) +1 )); 
					
					strncpy(thirdArray[x],toLower(tok), (strlen(toLower(tok)) +1));
				   
				    x++;
				   
				    while ((tok = strtok(NULL, delim )) != NULL)
				    {

						thirdArray = realloc(thirdArray, sizeof(char*) *  (x +1));
		
						//each world will be placed on a new row in the 2d array 
						thirdArray[x] = malloc(sizeof(char) * (strlen(tok) +1 )); 
					
						strncpy(thirdArray[x], toLower(tok), (strlen(toLower(tok)) +1));
					   
						x++;
				    }
				  
				   for(int i = 0; i< x; i++)
				   {
					   Storage* tempCheck = createStorage(thirdArray[i], tempSen, 0.0, 0.0, 0);
				 
				       temp = findInTree(tree1, tempCheck);
		           
		               if(temp != NULL)
		               {  
		                  
		                    if(x !=0)
		                    {
								ratings[count] = ((Storage*)(temp->data)) -> userRating + ((Storage*)(temp->data)) -> systemRating;	
							    count++;
							}
		               
				        }
			       }
		     
		         
		           double largest = ratings[0];
		           for(int i = 0; i< count; i++)
		           {
					  if(largest < ratings[i])
					  {
						 largest = ratings[i];
							   
					  }   
				   }
		     
					for(int i = 0; i< x; i++)
					{
					   Storage* tempCheck = createStorage(thirdArray[i], tempSen, 0.0, 0.0, 0);
				  
		               temp = findInTree(tree1, tempCheck);
		           
		               if(temp != NULL)
		               {
						    flag = 1;
					        if(largest == ((Storage*)(temp->data)) -> userRating + ((Storage*)(temp->data)) -> systemRating)
					        {
								printf("Personal Assistant: %s\n", ((Storage*)(temp->data)) -> sen);
								
								break;
								
							}          
				        }
					}
		    
			}	
					
					
					if(flag != 1)
					{
						printf("I'm sorry I'm currently unable to help with that but I'm learning\n");
			   
					}
		  	   
					else
					{    //add learning rate 0.05
						((Storage*)(temp->data)) ->occur ++;
				
						printf("Was this Feedback helpful? (y or n)\n");
						scanf("%c", &feedback);
						getchar();
	            
						if(feedback == 'y' || feedback == 'Y' )
						{
							((Storage*)(temp->data)) ->systemRating = ((Storage*)(temp->data)) ->systemRating + (((Storage*)(temp->data)) ->systemRating * ((Storage*)(temp->data)) ->learnRating / ((Storage*)(temp->data)) ->occur);
				 
						}
			 
						else if (feedback == 'n' || feedback == 'N')
						{
							((Storage*)(temp->data)) ->systemRating = ((Storage*)(temp->data)) ->systemRating - (((Storage*)(temp->data)) ->systemRating * ((Storage*)(temp->data)) ->learnRating / ((Storage*)(temp->data)) ->occur);
				 
						}  
		  	  
		  			}   
		  	   		  	   
					break; 
		}
		
	}
	
		printf("Enter Choice:");
		scanf("%d", &input);
		getchar();
	
	}
	


return 0;
   
 }
