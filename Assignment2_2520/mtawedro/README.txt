/***************************************
Name: Martina Tawedrous
Date: OCT 22, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
Program Discription: 

Program uses a priority queue ADT to simulate the management of an emergency 
medical clinic. The application will simulate the prioritization and processing of clients as they arrive at 
the minor emergency clinic. Each simulated client will have a client number, an emergency priority 
number, and a symptom code. Application will place the client in priority order in the queue and 
process the clients through the simulation. 

Program reads in data from a data file in the format specified. In addition, patients may be added after reading the initial input from a
command prompt  having 3 menu options: 
1) Adding a new patient from the command line, 
2) Processing the full simulation
3) Exiting the program
******************************************/

ASSUMPTIONS: 
1) When wrong symptom code is read in or user enters in wrong symptom code and doesnt match the specfied symptom codes outlines, timeFinished
will be the same value from where it left off as if no patient was added until valid data is inputed 
2) When user inputs priority value greater then 5 or less than or = to 0 error message will display until user inputs valid input value again
3)When user enters in value in command prompt that doesnt match with options in menu, user will be asked to enter in their input again.
