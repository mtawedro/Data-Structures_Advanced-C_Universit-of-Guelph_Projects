/***************************************
Name: Martina Tawedrous
Date: Dec 2, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
Program Discription: 
***************************************/
Program that uses a Binary Search Tree to provide answers to user provided questions. This program will be similar in concept to the 
early AI and natural language processing program called ‘Eliza’. Program will be provided with a list of keywords and canned responses to initialize 
conversations. This information will be passed into your program by a file passed in by a command line argument. The conversation file consists of
several entries each entry (termed rule) will be of the form: Keyword, Conversational text response ( a full sentence - on a single line ).
Once the conversation data is read and loaded into the Binary Search Tree the user will be presented with a menu system. The menu system supports adding/removing new rules. 
In addition, the menu system displays the contents of the Binary Search Table and modifying the importance of a rule. Each rule will have a keyword and 
conversational text that occurs on their own separate line. Each rule has associated personalized information specific to a user’s usage. 
The personalized information includes 4 pieces of information about a rule: user rating, the system’s rating, the learning rate, and a count of the total 
number of times the rule was used. Together the rule and personalized information form a personalized rule. The personalized rules will be stored and 
updated in the Binary Search Tree. 

Menu:
(1) Add a new rule
(2) Remove a rule
(3) Display rules
(4) Modify rule rating
(5) Discuss
(9) Quit


