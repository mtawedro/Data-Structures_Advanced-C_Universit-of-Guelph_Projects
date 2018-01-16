/***************************************
Name: Martina Tawedrous
Date: OCT 10, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
Program Discription: 

**DID NOT DO INSERTSORTED FUNCTION
Create a Doubly Linked List ADT in C and use it in a simulation of traffic coming through an 
interaction with a traffic light. The traffic light is broken and will only show a green light in 
one direction all other directions having a red light. 

The data file will be delimited and consists of three data elements in each row. The first element 
represents the direction the car is traveling prior to getting to the intersection.  The second element of each row represents the direction that the 
car will proceed through the intersection. The third element is the time, in seconds, that the vehicle reaches the intersection. A sample set of data is 
shown below.
******************************************/

ASSUMPTIONS: Calculating the car's crossing time is determiend from their arrival time or the car infront of them , waitimg for 
the car infront of them to make their turn at the intersection depenedent if they are going forward, However if say for example there are 5 cars in a list and 2 of them coudnt make it and 2 cars
are left over after the cycle when it returns back to the 2 cars.. the waiting time is not calculated becasue for example in real life 
logically when a car infront of u and leaves your the first one in the line again untul u wait until the other cars go, it doesnt make sense for ur to 
consider the waiting time when ur the first car in the line with no other cars infront of you to compare too in terms of when they finsih their turn 
