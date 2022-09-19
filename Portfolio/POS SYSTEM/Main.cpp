/*
     All Properties rights for this program are reserved by Andrew J Markland, and the University of Akron.
It is with express intent of the author, I, Andrew J Markland, for this program to be used to demonstrate the skill and style of work of the said parties, 
and these works are permissible to use freely if and only if, third parties expound upon their additions within the source code, and the original parties are given due 
accredation in their submission of reuse in their own works. Reuse of this work without either of those conditions being met may result in a cease and 
disist or further legal action on either the part of myself, or on the part of the Univeristy of Akron, as its submission makes it a public access resource via the 
University of Akron. The University of Akron nor myself condone plagerism in any form. Thank you.
~ Andy
you may reach me either via email or phone at:
ajm259@uakron.edu
(330) - 612 - 7821
*/


#include <iostream>
#include <map>
#include "POS.cpp"


int main()
    {
    std::map<std::string, product> product_bank;
    int choice = 0;
    get_data(product_bank);
    do
    {
        get_choice(choice);
        switch (choice)
            {
            case 1:
               Transaction_mode(product_bank);
               break;

            case 2:
               break;

            case 3:
               break;

            case 4:
               break;

            default:
               std::cout<< "ERROR, INVALID SELECTION VALUE, PLEASE TRY AGAIN.\n\n";
               break;

            }
    }  
    while (choice != 4);


}