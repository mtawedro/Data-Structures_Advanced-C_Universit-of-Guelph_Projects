/***************************************
Name: Martina Tawedrous
Date: September 30, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
Program Discription: integrates a static library into a makefile by using  external C libraries within a project.
Utilizes an Abstract Data Type (ADT) interface with multiple data types and develops preliminary testing for an ADT.
***************************************/
Questions:

1.What are the benefits of testing with multiple data types?
2.If we wanted to test the print functions how might we change the signature to do that?
3.Does the getFromFront() remove the first element?


A 1. The benfits of testing with multiple data types is that as each new part of the system is
  completed, it is tested to make sure that it works properly - otherwise other parts of the
  system that will rely on it could fail

A 2. To test the print Functions one case is when printing an empty list after a list got deleted,
Some problems that occured is when the printforward function was used, a seg fault occured, However
when the printBackwards function was used , the printFunction printed "List is Empty" . Another Case, is 
instead of passing an Int to the printFunction, NULL can be passed in and the print statement should
print NULL

A 3. No, the getFromFront only gets the first element and prints it out.