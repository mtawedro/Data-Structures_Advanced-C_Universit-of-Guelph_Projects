/***************************************
Name: Martina Tawedrous
Date: Nov 25, 2017
Student Num: 0977473
Email: mtawedro@uoguelph.ca
Program Discription: 
***************************************/
Program performs spell checking on a user file and  application will be provided a dictionary of correctly spelt words via a 
file passed in by a command line argument. Once the data from your dictionary file is read and loaded into the Hash Table the user will be presented with a 
menu system. The menu system must support adding/removing a new word to the dictionary, processing a user provided file for incorrectly spelt words, showing 
the words inside the Hash Table, and quitting the program. The application uses a Hash Table with an appropriate hash function and collisions strategy(chaining method).

**WARNING**: Please do not delete a word that is the FIRST INDEX of the HashTable AND press option 3 RIGHT afterwards *****or else it will seg fault 
(didnt have time to fix this part)- What I mean is that: Example -> press 4 to display table:

HashTable:
<0>:<0>:<guarded> **** EX.1 DO NOT DELETE WORD THEN PRESS 3 IN MENUE RIGHT AWAY
<0>:<0>:<unit>
<0>:<0>:<pest>         OR
<0>:<0>:<wren>
<0>:<0>:<Martina>
<1>:<1>:<tip>     ***** EX.2 DO NOT DELETE WORD THEN PRESS 3 IN MENUE RIGHT AWAY
<1>:<1>:<ban>
<1>:<1>:<wriggle>
....

*Other than that, removing and deleting is working**

Collosion Method (chaining) stragity, Selections, and HashFunction: Method Calculating Hash is determiend by the asci values of each character and adds up each asci value and 
% tablesize which will give it a range between 0 and the tablesize determined in this case and will return an index (MY INDEX IS MY KEY), example if im passing in key "Martina" hashes to 
20 and will go to index 20 to hash. **For collision method Ex. say key "Ms.Skelly" which also Maps to index 20 therefore in order for to the collision method
to occur my HashNode has type *List list which points to the head of the list defined in HNode. Thus, when a collison occurs I make a condition if the Hnode at
the specfic index is NULL, if its NULL I Create a new HNode and intalize Key: and Data and add it the specfied index in that HNode has the list that it will be pointing too. However if its not 
NULL(which means a HNode is already intalized at the index) then i call my insertBack Function and it will insert at the back of the linked list thats specfied
at the index), By this method each index will point to a linked list. When I want to search for the key "Martina" I call my hashFunction and return the index, 
it will go to the specfied index and i access the list at that specfied index using a temp pointer of type Node (not HNode) and i itereate through the linked list 
using a while loop and I comapre the strings(since they are unique) and if they match then i return the Node pointer, else return NULL. When user wishes to delete
a a specfic Node I call my removeData function, it will generate a index and will pass that to my searchFunction if the searchFunction returns NULL it does not delete
anything, else it will call my deleteNodefromList Function and if there is nothing left in linked list, will return 2 and if == 2 then the HNode at the specfied index
is freed.


 