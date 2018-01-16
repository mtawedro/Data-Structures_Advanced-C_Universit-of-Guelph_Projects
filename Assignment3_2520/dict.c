#include <stdio.h>

#include <stdlib.h>

//#include "linkedList.c"

#include "HashTableAPI.h"//take out

#include <string.h>

#include <ctype.h>

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

int compareDupl(char **array, int length)
{
	int flag = 0;
	
	for(int x = 0; x< length; x++)
	{
		for(int i = x + 1; i<length; i++)
		{
			if(strcmp(array[x], array[i]) == 0)
			{
				flag = 1;
				return 1;
			
			}
		}
	}
	
	if(flag != 1)
	{
		return 0;
	}
	
	return 0;

}


int main(int argc, char*argv[]) {
	
	/*calls OpenFile function to acess and open file*/
	FILE* inFile = OpenFile(argv[1]);
	
	size_t size = 4;
	
	HTable *table1 = createTable(size, &hashNode, &destroyNodeData, &printNodeData);
	
	char tempWord[100];
	char tempOrig[100];
	int i = 0;
	char line[100];
	char userChoice[50];
	int input = 0;
	char **secondArray; 
	int check;
	
	
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
	

	 while(fgets(line,100, inFile) != NULL) 
    {
		    sscanf(line,"%s", tempWord);
		    
		    firstArray = realloc(firstArray, sizeof(char*) *  (i +1));
		    //--> stored in anotehr temp 2-d array to check for dupliacted strings
		    tempArray = realloc( tempArray, sizeof(char*) *  (i +1));
		
			//each world will be placed on a new row in the 2d array 
			firstArray[i] = malloc(sizeof(char) * (strlen(tempWord) +1 )); 
			tempArray[i] = malloc(sizeof(char) * (strlen(tempWord) +1 )); 
			 
			strncpy(firstArray[i], tempWord, (strlen(tempWord) +1));
			strncpy(tempArray[i], toLower(tempWord), (strlen(toLower(tempWord)) +1));
			
			check = compareDupl(tempArray, i + 1);
			
			if(check == 0)
			{
				
				insertDataInMap(table1, firstArray[i]);
			}	
			
			
		    i++;
		    
		    
	
	}
	fclose(inFile);
	 
	
	printf("(1) Add a new word to the dictionary\n");
	printf("(2) Remove a word from dictionary\n");
	printf("(3) Spell Check a file\n");
	printf("(4) Show dictionary words\n");
    printf("(5) Quit\n");
   
   
   
	printf("Enter Choice:");
	scanf("%d", &input);
	getchar();
   
	while(input!= 5)
	{ 
		switch(input)
		{
			case 1:
			{
				i = 0;
				printf("Enter a word:\n"); // NEED TO COMPARE
				fgets(userChoice, 50 , stdin);
				
				//gets rid of hard return
				if(userChoice[strlen(userChoice)-1] == '\n')
				{
					userChoice[strlen(userChoice)-1] = '\0';
				}
				
				
				 secondArray = realloc(secondArray, sizeof(char*) *  (i +1));
				 tempArray1 = realloc( tempArray1, sizeof(char*) *  (i +1));//--> to check for dupliacted strings
		
		
				//each world will be placed on a new row in the 2d array 
				 secondArray[i] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
				 tempArray1[i] = malloc(sizeof(char) * (strlen(userChoice) +1 )); 
			
  
				 strncpy(secondArray[i], userChoice, (strlen(userChoice) +1));
				 strncpy(tempArray1[i], toLower(userChoice), (strlen(toLower(userChoice)) +1));
			
				 Node *temp = lookupData(table1, tempArray1[i]); //doesnt find word in dictionay, ok to pass in
		         
		         if(temp == NULL)
		         {
					
					insertDataInMap(table1, secondArray[i]);
				 }	
				
				
				 i++;
				
				 break;
			}
			case 2:
			{
				 int x =0;
				 printf("Enter word you want to delete:\n");
		  
				 fgets(userChoice, 50 , stdin);
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
		            
		           Node *temp = lookupData(table1, fourArray[x]);
		           if(temp != NULL)
		            {
						int index = hashNode(table1->size, fourArray[x]);
					
						if(table1->table[index]!= NULL || table1->table[index]->list->head != NULL)
						{
							removeData(table1, fourArray[x]);
						}	
						
						printf("Succesfully Deleted\n");
				    }
				    else
				    {
						printf("<%s> was not found in the dictionary\n", tempOrig);
						
					}
		  
		          
				   x++;
				   break;
				
			}
			
				
			case 3:
			{
				char File[20];
				int countCorrect = 0;
		        int countIncorrect = 0;
		        int x = 0;
		
				 printf("Please enter in a file to spell check\n");
             
				fgets(File, 200, stdin);
      
				//gets rid of hard return
				if(File[strlen(File)-1] == '\n')
				{
					File[strlen(File)-1] = '\0';
				}
              
				 FILE* spell = OpenFile(File);
				
				printf("File processed by Spell Check <%s>:\n", File);
				
				while(fgets(line,100, spell) != NULL) 
				{
					sscanf(line,"%s", tempWord);
					sscanf(line,"%s", tempOrig);
		   
					thirdArray = realloc(thirdArray, sizeof(char*) *  (x +1));
		
					//each world will be placed on a new row in the 2d array 
					thirdArray[x] = malloc(sizeof(char) * (strlen(tempWord) +1 )); 
					
					strncpy(thirdArray[x],toLower(tempWord), (strlen(toLower(tempWord)) +1));

					
					Node *temp2 = malloc(sizeof(Node)* 1);
					temp2 = lookupData(table1, thirdArray[x]);
					
				    if(temp2 != NULL)
				    {
						countCorrect++;
						
					}
					
					//if a word is spelled wrong = doesnt exsit in dictonary
			    	else
					{
						countIncorrect++;
						printf("<%s> was not found in the dictionary\n", tempOrig);
					}
				
					x++;
		    
				}
				
				printf("Summary:\n");
				printf("Correctly spelt words:<%d>\n", countCorrect);
				printf("InCorrectly spelt words:<%d>\n", countIncorrect);
			
				fclose(spell);
			
				
				break;
			}
			
			case 4:
			{
				display(table1);
				break;
				
				
				
			}
			default:
			{
				printf("Sorry, Incorrect Input\n");
			}
			
		}
	
	
		printf("Enter Choice:");
		scanf("%d", &input);
		getchar();
		
		
	}
	
		
	return 0;
	
}
