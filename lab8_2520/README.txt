/***************************************
Name: Martina Tawedrous
Date: Nov 04, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
**************************************/
Program Discription: 

implements 2 sorting algorithms: I used  bubble sort, and selection sort. In addition to 
implementing the algorithms, there is a small command line interface that allows users to select 
the input values, sorting algorithm, and sorting method. This consists of creating a command line interface for a user to insert N values. 
The program prompts the user for the value of N and then read N values into an integer array.
3 sorting options: increasing
	           decreasing
	           sorts even before odd (increasing)

***How I implemented my "sorting even before odd" functions***
Search throught the whole array and find all even numbers put that in a seperate array consisting of only even ints,
find all odd put that in a seprate array consiting of only odd ints
sort the even array
sort odd array
once both arrays are sorted put sorted even numebrs and sorted odd numbers back in a single array 
Print 