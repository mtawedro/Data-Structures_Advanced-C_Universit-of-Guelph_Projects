#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedListAPI.h"
#include "QueueAPI.h"
#include "patient.h"
#include "createPatient.c" //take this out after
#include "linkedList.c"//take this out after
#include "Queue.c"//remove after

//global var
int flag = 0;

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



 /*Similation starts at beggining of Queue and ilaterates through until = NULL, it calcualtes timeFinished, 
  * as every first Node gets deletes and will go to the next one by using peek() function*/
 void Similation(Queue *l, Queue *l2)
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

	Node *current = l->list->head;
	
	Node *temp = l2->list->head;
		
		while(current != NULL)
		{
			
			if(strcmp(((Patient*)(current->data)) -> symptom, "CV") == 0)
			{
				
				finishTime = finishTime +  Cardio + 1;
			 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "HN") == 0)
			{
		
				finishTime = finishTime + nosePlus + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "EV") == 0)
			{
		 
				finishTime = finishTime + enviro + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "GI") == 0)
			{
		 
				finishTime = finishTime + gastro + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "MH") == 0)
			{
				finishTime = finishTime + mentalHealth + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "NC") == 0)
			{
		 
				finishTime = finishTime + neuro + 1;
			
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "EC") == 0)
			{
				finishTime = finishTime + ophtha + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "RC") == 0)
			{
				finishTime = finishTime + respir + 1;
				
		 
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "SK") == 0)
			{
				finishTime = finishTime + skin + 1;
				
			}
	
			else if(strcmp(((Patient*)(current->data)) -> symptom, "SA") == 0)
			{
		 
				finishTime = finishTime + substAbuse + 1;
				
			}
			else if(strcmp(((Patient*)(current->data)) -> symptom, "TR") == 0)
			{
		 
				finishTime = finishTime + trauma + 1;
				
			}
	
			else
			{
				
				printf("Invalid Symptom");
				
			}
			
			Node *new = l2->list->head;
			
			new = l2->list->head;
				
			while(new!=NULL)
			{
				if(strcmp(((Patient*)(new->data)) -> patientID,((Patient*)(current->data)) -> patientID) == 0 )
				{
					
					((Patient*)(new->data)) -> finishTime = finishTime;
				}	
					
				new = new->next;
			}		
			
			current = current->next;
			
			temp = temp->next;
}

	
			if(flag !=1)
			{
				//prints Queue list
				Node *temp1 = l2->list->head;

				while(temp1!=NULL)
				{
						
					printf("%s			%d			 %s			  %d\n",((Patient*)(temp1->data)) -> patientID, ((Patient*)(temp1->data)) -> priorty, ((Patient*)(temp1->data)) -> symptom, ((Patient*)(temp1->data)) -> finishTime );
			
					temp1 = temp1->next;
				
				}
			}

	 
 }
 
 
int main(int argc, char*argv[]) {
	
	/*calls OpenFile function to acess and open file*/
	FILE* inFile = OpenFile(argv[1]);
   
    //declares and initializes variables
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
   
	List * list1 = createQueue(&printNode, &deleteFunction, &compare);
	List * listOrig = createQueue(&printNode, &deleteFunction, &compare);
	Queue *l = malloc(sizeof(Queue) * 1);
	Queue *l2 = malloc(sizeof(Queue) * 1);
   
	l->list = list1;
  
	l2->list = listOrig;
   
   
   //reads in data and uses priotryEnqeue(insertSorted) to sort list as its read in
    while(fgets(line,100, inFile) != NULL) 
    {
		    sscanf(line,"%s %d %s", patientIDTemp, &tempPrio, tempSymptom);
			
			//creates newData
			patientTemp = createPatient(patientIDTemp, tempPrio, tempSymptom);
			
			//inserts to the back of the original list
			enqueue(l2, patientTemp); 
			
			//creates new node for data
			Node *new_node = inatalizeNode(patientTemp);
	      
			//sorts the node in list
			priortyEnqueue(l, patientTemp,new_node ); 
					
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
		  
				//error checks
				while( prioChoice > 5 || prioChoice <= 0 )
				{
					printf("Invalid Input\n");
					printf("Enter Priorty:");
		 
					scanf("%d", &prioChoice);
					getchar();
				}
				
				//creates new data
				patientTemp = createPatient(patientChoice, prioChoice, symChoice);
		  
				//inserts to the back of the original list
				enqueue(l2, patientTemp);
	      
				//creates new node for data
				Node *new_node = inatalizeNode(patientTemp);
			
				//sorts the node in list
				priortyEnqueue(l, patientTemp, new_node); 
			
				//sets flag to 1 so woudnt print output of similation until user enters in 2 
				flag = 1;
			
				Similation(l, l2);
	     
				break;
	     
	 }
	 
	 case 2:
	 {
			//flag set to 0 again so woud print similation
			flag = 0;
			printf("\n");
			printf("Patient ID           Priority               Symptom Code	      Time Finished\n");
			Similation(l, l2);
		 
			break;
	 }
	 
	 default:
	 {
			printf("Invalid Input\n");
			printf("Enter Choice:");
			scanf("%d", &input);
			getchar();
		 
	 }
	 
	 
 }
 	
	
   printf("\n");
   printf("Enter Choice:");
   scanf("%d", &input);
   getchar();


}		
			
   fclose(inFile);
   
   return 0;
   
}
