
//Andrew Jacob Markland, ajm259@uakron.edu
//University of Akron >> Data structures >> Dr. En Cheng >> Project 1
/*===================================     AIM     ===============================================
Implement a city database using array and linked list. Each database record contains the name of
the city (a string of arbitrary length) and the coordinates of the city expressed as real numbers x
and y coordinates
*/

/*
Prewrite.
1) create a menu system to select validation;
     a) make a variable for choice, native to main();
     b) Use a function to alter choice_Variable;
          i) take user input;
          ii) Validate that input;
     c) use switch statement to initiate;
          i) SST Case 1) array implementation;
          ii) SST Case 2) linked list implementation;
          iii) SST Case 3) exit the program;
          iV) SST Case Default) shoot error message and redo user input;
2) write class to take data for array or linked list
[Data consist of (name{string}), (latitude{double}), and (longitude{double})];
     a) make private elements (String_Variable: name), (Double_Variable: lati), (double_Variable: lont);
     b) Make public constructor and deconstructors;
          i) Make constructors for every case, but set default lati and lont variable to 0 for missing data, and the default name variable to ERROR_NO_NAME
             for missing data: in the case of missing data throw an error in the console;
          ii) Make deconstructors;
          iii) Overload operators as needed;
     c) Make getters and setters
3) Implement data using array in a function;
     a) File I/O;
     [a.5) possibly impliment a sort function before allowing user input];
     b) second menu;
     c) make search functions
     d) make operation 
4) Implement data using Linked List Data structure
*/

#include <iostream>
#include <limits>
#include "Assmt_1.cpp"
int main()
     {
     std::cout.precision(10);
     int choice;
     do
          {
          menu(choice);
          switch (choice)
               {
               case 1:
                  scenario_one();
                  break;
               
               case 2:
                  scenario_two();
                  break;

               case 3:
                  break;
               
               default:
                  std::cout<<"\nERROR invalid selection value, please try again\n";
                  choice = 0;
                  break; 
               }

          }  
     while (choice != 3);
     exit(0);
     }
