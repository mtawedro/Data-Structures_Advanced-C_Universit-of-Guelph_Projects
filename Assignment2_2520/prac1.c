#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "patient.h"
#include "createPatient.c" //take this out after
#include "linkedList.c"//take this out after
//#include "libLinkedList.a"//take this out after

//void deleteFunction(void *toBeDeleted)
//{
	//return ;
//}

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


	
void insertSorted(List *list, void *toBeAdded, Node *new_node)
{

	Patient* patientTemp = (Patient *) toBeAdded;
		
	// If the first element 
	if (list->head == NULL)
	{
		insertFront(list, patientTemp);
			
	}
	
	
	else
	{
		
		
		Node *current = list->head;
		
		while(current != NULL)
		{
			
			if(current->next != NULL)
			{
					//printf("HELLO");
				if(patientTemp -> priorty == ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
					//printf("FIRST IF");
					new_node->next = current->next;
					new_node->previous = current;
					new_node->next->previous = new_node;
					current->next = new_node;
				
					break;
				
				}
			 
			 //change back to !=
				else if(patientTemp -> priorty < ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
					
					//printf("SECONF IF");
					//new_node->next = current->next;
					//new_node->previous = current;
					//new_node->next->previous = new_node;
					//current->next = new_node;
				
				insertFront(list, patientTemp);
					break;
				
				}
				
				else if(patientTemp -> priorty != ((Patient*)(current->data)) -> priorty && patientTemp -> priorty < ((Patient*)(current->next->data)) -> priorty )
				{
					
					//printf("SECONF IF");
					new_node->next = current->next;
					new_node->previous = current;
					new_node->next->previous = new_node;
					current->next = new_node;
				
					break;
				
				}
			
			
				current = current->next;
			
		    }
		
		    else
			{
				if(patientTemp -> priorty == ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					//printf("THIRD IF\n");
					insertBack(list, patientTemp );
				
					break;
				
				}
				
				else if(patientTemp -> priorty > ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					//printf("TFORTH IF\n");
					insertBack(list, patientTemp );
				
					break;
				
				}
				
				
				else if(patientTemp -> priorty < ((Patient*)(current->data)) -> priorty && current->next == NULL)
				{
					//printf("FITH\n");
					insertFront(list, patientTemp );
				
					break;
				
				}
				
				
				current = current->next;
			
			}	
	}
		
		
}
	 
	  
}  
 
 
 void Similation(List *list, List *listOrig)
 {
	int Cardio=  5;
	int nosePlus =  3;
	int enviro = 10;
	int gastro =  2;
	int mentalHealth = 5;
	int neuro = 5 ;
	int ophtha = 1 ;
	int respir = 1; 
	int skin = 2;
	int substAbuse = 7;
	int trauma = 4;
	int finishTime = 0;

	Node *current = list->head;
	Node *temp = listOrig->head;
		
		while(current != NULL)
		{
	
		
			if(strcmp(((Patient*)(current->data)) -> symptom, "CV") == 0)
			{
				
				finishTime = finishTime +  Cardio + 1;
			 
				printf("%s %s %d", ((Patient*)(current->data)) -> symptom, ((Patient*)(current->data)) -> patientID, ((Patient*)(current->data)) -> priorty );
			 
			 //   printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "HN") == 0)
			{
		
				finishTime = finishTime + nosePlus + 1;
				//  printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "EV") == 0)
			{
		 
				finishTime = finishTime + enviro + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "GI") == 0)
			{
		 
				finishTime = finishTime + gastro + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "MH") == 0)
			{
				finishTime = finishTime + mentalHealth + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "NC") == 0)
			{
		 
				finishTime = finishTime + neuro + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "EC") == 0)
			{
				finishTime = finishTime + ophtha + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "RC") == 0)
			{
				finishTime = finishTime + respir + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "SK") == 0)
			{
				finishTime = finishTime + skin + 1;
				//  printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
		 
			}
	
			else if(strcmp(((Patient*)(current->data)) -> symptom, "SA") == 0)
			{
		 
				finishTime = finishTime + substAbuse + 1;
				//  printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "TR") == 0)
			{
		 
				finishTime = finishTime + trauma + 1;
				 // printf("%s			%s			 %d			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> priorty, finishTime );
			
		 
		 
			}
	
			//Node *ptr = list->head;
			Node *new = listOrig->head;
			//while(ptr!=NULL)
			//{
				new = listOrig->head;
				
				while(new!=NULL)
				{
					if(strcmp(((Patient*)(new->data)) -> patientID,((Patient*)(current->data)) -> patientID) == 0 )
					{
					
						//printf("ID SI %s", ((Patient*)(new->data)) -> patientID);
						
						((Patient*)(new->data)) -> finishTime = finishTime;
					}	
					
					new = new->next;
				}		
				//ptr = ptr->next;
			//}
			
			
			// printf("%s			%d			 %s			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> priorty, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> finishTime );
			
		 
			
			//printf("%s			%d			 %s			  %d\n",((Patient*)(current->data)) -> patientID,  ((Patient*)(current->data)) -> priorty,((Patient*)(current->data)) -> symptom , finishTime );
				
			
			printf("%d\n", finishTime);
			current = current->next;
			temp = temp->next;
}
	 
 }
 
 
int main(int argc, char*argv[]) {
	
   /*calls OpenFile function to acess and open file*/
   FILE* inFile = OpenFile(argv[1]);
   
    char patientIDTemp [100];
	char tempSymptom [3];
	int tempPrio;
	int input = 0;
	char line [100];
	int count = 0;
	char patientChoice[100];
	char symChoice[100];
	int prioChoice = 0 ; 
   
   Patient *patientTemp = malloc(sizeof(Patient) * 1);
   
   List * list = initializeList(&printNode, &deleteFunction, &compare);
   List * listOrig = initializeList(&printNode, &deleteFunction, &compare);
   
   //reads in data and inserts back in list
    while(fgets(line,100, inFile) != NULL) 
    {
		    sscanf(line,"%s %d %s", patientIDTemp, &tempPrio, tempSymptom);
			
			patientTemp = createPatient(patientIDTemp, tempPrio, tempSymptom);//creates newNode
			
			printPatient( patientTemp);
			
			insertBack(listOrig, patientTemp); //inserts to the back of the original list
			
			Node *new_node = inatalizeNode(patientTemp);//creates new node for data
	      
			insertSorted(list, patientTemp,new_node ); //sorts the node in list
					
			count++;
			
	}
  
   
   printf("(1) Add a new patient\n");
   printf("(2) Process the full simulation\n");
   printf("(3) Exit\n");
   
   
   printf("Enter Choice:");
   scanf("%d", &input);
   getchar();
   
  while(input!= 3)
  { 
   switch(input)
   {
	   case 1:
	   {
		  printf("Enter Patient ID:");
		 
		  fgets(patientChoice,100,stdin);
		  
		//gets rid of hard return
        if(patientChoice[strlen(patientChoice)-1] == '\n')
        {
             patientChoice[strlen(patientChoice)-1] = '\0';
        }
		  
		  printf("Enter Symptom:");
		 
		  fgets(symChoice,100,stdin);
		  
		//gets rid of hard return
		if(symChoice[strlen(symChoice)-1] == '\n')
		{
			symChoice[strlen(symChoice)-1] = '\0';
		}
		  	 
		  printf("Enter Priorty:");
		 
		  scanf("%d", &prioChoice);
		  
		  getchar();
		  
		  patientTemp = createPatient(patientChoice, prioChoice, symChoice);//creates newNode
		  	          
	      printPatient( patientTemp);
	      
	      insertBack(listOrig, patientTemp);
	      
	      //insertBack(list, patientTemp);
	      
	      Node *new_node = inatalizeNode(patientTemp);
	      
	      insertSorted(list, patientTemp, new_node); //Orig?
	      
	      Similation(list, listOrig);
	     
	     break;
	     
	 }
	 
	 case 2:
	 {
		 printf("\n");
		 printf("Patient ID           Priority               Symptom Code	      Time Finished\n");
		 Similation(list, listOrig);
		 
		 break;
	 }
	 
	 default:
	 {
		 
		 printf("Invalid Input");
		 printf("Enter Choice:");
		 scanf("%d", &input);
         getchar();
		 
	 }
	 
	 
 }
 	
			
			//prints
			Node *temp = listOrig->head;

			while(temp!=NULL)
			{
						
			   printf("%s			%d			 %s			  %d\n",((Patient*)(temp->data)) -> patientID, ((Patient*)(temp->data)) -> priorty, ((Patient*)(temp->data)) -> symptom, ((Patient*)(temp->data)) -> finishTime );
			
			   temp = temp->next;
				
			}
		
			
			
		
			//prints
			Node *temp1 = list->head;

			while(temp1!=NULL)
			{
				
				printf("%s,\n %d,\n %s\n",((Patient*)(temp1->data)) -> patientID, ((Patient*)(temp1->data)) -> priorty, ((Patient*)(temp1->data)) -> symptom);
				
				temp1 = temp1->next;
				
			}
		
   printf("\n");
   printf("Enter Choice:");
   scanf("%d", &input);
   getchar();
}		
			
			
			
		
   
   
  
   fclose(inFile);
   
   return 0;
   
}



