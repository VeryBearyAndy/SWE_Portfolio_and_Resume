#include "Assmt_1.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath> 

//=======================================================================================================================================================================
//class constructors and Functions
//class constructors
c_data::c_data()
     {
     name = "empty";
     lati = 0.0;
     lont = 0.0;
     node = nullptr;
     }

c_data::c_data(std::string& alpha, double& beta, double& gamma)
     {
     name = alpha;
     lati = beta;
     lont = gamma;
     }

c_data::c_data(std::string alpha, double beta)
     {
     std::cout <<"\nERROR Incomplete data\n";
     name = alpha;
     lati = beta;
     lont = 0.0;
     }

c_data::c_data(double beta, double gamma)
     {
     std::cout <<"\nERROR Incomplete data\n";
     name = "ER_no_name";
     lati = beta;
     lont = gamma;
     }

c_data::c_data(std::string alpha)
     {
     std::cout <<"\nERROR Incomplete data\n";
     name = alpha;
     lati = 0.0;
     lont = 0.0;
     }

c_data::c_data(double beta)
     {
     std::cout <<"\nERROR Incomplete data\n";
     name = "ER_no_name";
     lati = beta;
     lont = 0.0;
     }

//___________________________________________________________________________________
//class functions
void c_data::new_node()
//precondition)-> a c_data pointer is passed
//postcondition)-> the node variable is assinged to the c_data pointer 
     {
     node = new c_data;
     }

void c_data::link_node(c_data* next)
     {
     node = next;
     }

void c_data::set_node_null()
     {
     node = nullptr;
     }

void c_data::set_value(string& in_name, double& in_lati, double& in_lont)
//precondition)-> A string value, and two double values are passed by reference
//postcondition)-> the string value is assinged to name, one doube is assinged to lati, and the other double is assinged to lont
     {
     name = in_name;
     lati = in_lati;
     lont = in_lont;
     }

void c_data::print_data()
     {
     std::cout<< name << ", " << lati << ", " << lont << "\n"; 
     }

string c_data::get_name()
     {
     return (name);
     }

double c_data::get_lati()
     {
     return(lati);
     }

double c_data::get_lont()
     {
     return(lont);
     }

c_data* c_data::get_node()
     {
     return (node);
     }

void c_data::set_empty()
     {
     name = "empty";
     lati = 0;
     lont = 0;
     }

void c_data::copy_object(c_data* holder)
//precondition)-> A c_data object pointer is passed
//postcondition)-> the parameter c_object pointer is rewritten with a copy of the c_data object calling the function
    {
    holder->name = name;
    holder->lati = lati;
    holder->lont = lont;
    }

void c_data::copy_object_literal(c_data& holder)
//precondition)-> a c_data object is passed by reference
//postcondition)-> contents of the c_data object calling the function are copied onto the holder c_data object
     {
     holder.name = name;
     holder.lati = lati;
     holder.lont = lont;
     }
//=======================================================================================================================================================================
//general functions
void menu(int& choice)
//this function is a menu system function that allows the reuse of the program without exiting and allows the user to select which scenario they'd like to test;
//precondition)-> int_Variable: choice is passed by reference;
//postcondition)-> nothing is returned, but int_Variable: choice is changed and validated before returning to main()_function;
     {
     std::cout<< "Please select a number between 1 and 3 to launch an application or exit!\n\n"<<
                 "1) Scenatio one: Array Implementation\n"<<
                 "2) Scenario two: Linked List Implimentation\n"<<
                 "3) Exit the Program\n\n";
     std::cin>> choice;
     do
     //This "do-while" loop serves as validation for the int_Variable: Choice, to ensure the input is either: 1, 2, or 3;
           {
           if (((choice != 1) && (choice != 3) && (choice != 2)) || (std::cin.fail()))
                {
                std::cout<< "\n\nERROR: Invalid Entry, Please select a valid entry,\na number between 1 and 3. \n\n"<<
                            "1) Scenatio one: Array Implementation\n"<<
                            "2) Scenario two: Linked List Implimentation\n"<<
                            "3) Exit the Program\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin>>choice;
                }
           
           } 
     while (((choice != 1) && (choice != 3) && (choice != 2)) || (std::cin.fail()));
     }

void submenu(int& choice)
//This function opens the sub-menu in scenario A or scenario B to allow the user to perform operations on the data set;
//precondition)-> int_Variable: choice is passed by reference;
//postcondition)-> nothing is returned, but int_Variable: choice is changed and validated before returning to scenario_one():function or scenario_two():function;
     {
     std::cout<< "Please select what operation you would like to perform on the data set with its designated number.\n\n"<<
                 "1) Insert City record,\n"<<
                 "2) Search for record by name,\n"<<
                 "3) Search for record by coordinates,\n"<<
                 "4) Delete Record by name,\n"<<
                 "5) Delete record by coordinates,\n"<<
                 "6) Print Records within a Specified Distance,\n"<<
                 "7) Print all Records,\n"<<
                 "8) Exit.\n\n";
     std::cin>> choice;
     if (((choice < 1) && (choice >8)) || (std::cin.fail()))
          {
          do
               {
               std::cout<<"ERROR: Invalid Entry, Please select a valid entry,\na number between 1 and 8.\n\n"<<
                          "1) Insert City record,\n"<<
                          "2) Search for record by name,\n"<<
                          "3) Search for record by coordinates,\n"<<
                          "4) Delete Record by name,\n"<<
                          "5) Delete record by coordinates,\n"<<
                          "6) Print Records within a Specified Distance,\n"<<
                          "7) Print all Records,\n"<<
                          "8) Exit.\n\n";
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cin>>choice;
               } 
          while (((choice < 1) && (choice >8)) || (std::cin.fail()));
          
          }
     }

bool calculate_distance(c_data* c_get, c_data c_list, double* distance)
     {
     double* lati_1 = new double;
     double* lont_1 = new double;
     double* lati_2 = new double;
     double* lont_2 = new double;
     double* calc_1 = new double;
     double* calc_2 = new double;

     *lati_1 = ((c_get->get_lati()) * PI) / 180;
     *lont_1 = ((c_get->get_lont()) * PI) / 180;
     *lati_2 = ((c_list.get_lati()) * PI) / 180;
     *lont_2 = ((c_list.get_lont()) * PI) / 180;

     *calc_1 = (sin(*lati_1)) * (sin(*lati_2));
     *calc_2 = (cos(*lati_1)) * (cos(*lati_2)) * (cos((*lont_2) - (*lont_1)));
     *calc_1 = R * (acos((*calc_1) + (*calc_2))); 
     
     if(*calc_1 <= *distance)
          {
          delete lati_1;
          lati_1 = nullptr;
          delete lont_1;
          lont_1 = nullptr;
          delete lati_2;
          lati_2 = nullptr;
          delete lont_2;
          lont_2 = nullptr;
          delete calc_1;
          calc_1 = nullptr;
          delete calc_2;
          calc_2 = nullptr;

          return (true);
          }
     else
          {
          delete lati_1;
          lati_1 = nullptr;
          delete lont_1;
          lont_1 = nullptr;
          delete lati_2;
          lati_2 = nullptr;
          delete lont_2;
          lont_2 = nullptr;
          delete calc_1;
          calc_1 = nullptr;
          delete calc_2;
          calc_2 = nullptr;

          return (false);   
          }
     }
//___________________________________________________________________________________
//Scenario one: Array Implementation functions, for convenience sake, functions only for the implementation for Scenario one are marked with "alpha"

void scenario_one()
//This is the main application function of Scenario A: using an Array to manage data 
//precondition)-> Nothing is passed,
//postcondition)-> Data is liable to be manipulated
     {
     int choice_alpha = 0;
     c_data* c_list = new c_data[50];
     get_data_alpha(c_list);
     do
          {
          std::cout<< "________________________________________________\n"<<
                      "| Scenario One: Data application with an Array |\n"<<
                      "________________________________________________\n";
          submenu(choice_alpha);
          switch(choice_alpha)
               {
               case 1:
                  insert_record_alpha(c_list);
                  break;

               case 2:
                  search_by_name_alpha(c_list);
                  break;

               case 3:
                  search_by_coord_alpha(c_list);
                  break;

               case 4:
                  delete_by_name_alpha(c_list);
                  break;

               case 5:
                  delete_by_coord_alpha(c_list);
                  break;

               case 6:
                  print_in_distance_alpha(c_list);
                  break;

               case 7:
                  print_all_c_data_alpha(c_list);
                  break;

               case 8:
                  break;

               default:
                  std::cout<< "ERROR: Invalid selection value please try again.\n\n";
                  break;
               }
          } 
     while (choice_alpha != 8);
     
     }

void get_data_alpha(c_data* c_list)
//precondition)-> a pointer that generated an array is passed
//postcondition)-> data from a file is inputted into the array
     {
     std::ifstream infile;
     infile.open("data.txt");
     int* counter = new int;
     //this counter is used to manage the array's inputted data in ascending order
     std::string* char_dump = new string;
     //this string variable only exists to suck up the new line character.
     std::string* holder = new std::string;
     std::string* in_name = new std::string;
     double* in_lati = new double;
     double* in_lont = new double;
     *counter = 0;
     while(!infile.eof())
          {
          std::getline(infile, *in_name, ':');
          std::getline(infile, *holder, ',');
          *in_lati = std::stod(*holder);
          std::getline(infile, *holder, '\n');
          *in_lont = std::stod(*holder);
          std::getline(infile, *char_dump);
          if(!infile.eof())
               {
               c_list[*counter].set_value(*in_name, *in_lati, *in_lont);
               }
          
          *counter += 1;
          }
     delete in_name;
     in_name = nullptr;
     delete in_lati;
     in_lati = nullptr;
     delete in_lont;
     in_lont = nullptr;
     delete counter;
     counter = nullptr;
     delete char_dump;
     char_dump = nullptr;
     }

void insert_record_alpha(c_data* c_list)
//precondition)-> A c_data object pointer is passed
//postcondition)-> An empty element is changed to reflect the inputted data, if no element is empty, it throws an error and returns to the menu.
     {
     std::string* temp_name = new std::string;
     double* temp_lati = new double;
     double* temp_lont = new double;
     std::cout<< "Please type the name of the city you would like to enter into the city record.\n";
     std::cin>> *temp_name;
     std::cout<< "Now please enter the latitude of the city.\n";
     std::cin>> *temp_lati;
     std::cout<< "Please enter the longitude of the city\n";
     std::cin>> *temp_lont;
     
     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     for(auto counter = 0; counter < 50; counter += 1)
          {
          if(c_list[counter].get_name() == "empty")
               {
               c_list[counter].set_value(*temp_name, *temp_lati, *temp_lont);
               delete temp_name;
               temp_name = nullptr;
               delete temp_lati;
               temp_lati = nullptr;
               delete temp_lont;
               temp_lont = nullptr;

               end = std::chrono::system_clock::now();
               std::chrono::duration<double> elapsed_seconds = end - start;
               std::time_t end_time = std::chrono::system_clock::to_time_t(end);
               std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

               return;
               }
          }
     std::cout<< "ERROR: insufficient space, please clear space for the inputted data!\n\n";
     delete temp_name;
     temp_name = nullptr;
     delete temp_lati;
     temp_lati = nullptr;
     delete temp_lont;
     temp_lont = nullptr;

     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return;
     } 

void print_all_c_data_alpha(c_data* c_list)
//precondition)-> A c-data object pointer is passed
//postcondition)-> Every element associated with the c-data object is printed up until either, the end of the array is hit, or an empty data slot is found.
    {
     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     for (int counter = 0; counter < 50; counter += 1)
          {
          if(c_list[counter].get_name() == "empty")
               {
               end = std::chrono::system_clock::now();
               std::chrono::duration<double> elapsed_seconds = end - start;
               std::time_t end_time = std::chrono::system_clock::to_time_t(end);
               std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

               return;
               }
          c_list[counter].print_data();
          }
    }

void search_by_name_alpha(c_data* c_list)
//precondition)-> A c-data object pointer is passed
//postcondition)-> Every C_data class object is cycled through and compared with an inputted value, and if theres a math, that object's data is printed.
     {
     std::string* input = new string;
     std::string* temp_name = new string;
     std::cout<< "Please enter the name of the city you would like to search.\n";
     std::cin>> *input;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     for (auto counter = 0; counter < 50; counter +=1)
          {
          *temp_name = c_list[counter].get_name();
          if(*input == *temp_name)
               {
               std::cout<< "VALUE HIT: Data found.\n";
               c_list[counter].print_data();
               delete input;
               input = nullptr;
               delete temp_name;
               temp_name = nullptr;

               end = std::chrono::system_clock::now();
               std::chrono::duration<double> elapsed_seconds = end - start;
               std::time_t end_time = std::chrono::system_clock::to_time_t(end);
               std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

               return;
               }
          }
     std::cout<<"VALUE MISS: No data matches a city named '"<< *input <<",' please try again.\n";
     delete input;
     input = nullptr;
     delete temp_name;
     temp_name = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return;
     }

bool search_by_name_and_return_alpha(c_data* c_list, c_data* c_get, string* input)
//precondition)-> c_data object array pointer, c_data object pointer, and a string pointer input variable are all passed;
//postcondition)-> The array is searched for the string input, if found, its contents are copied onto "c_get" object and returns with a true boolean value, if
//not an error message is thrown and the boolean value returns false.
     {
     std::string* temp_name = new string;
     for (auto counter = 0; counter < 50; counter +=1)
          {
          *temp_name = c_list[counter].get_name();
          if(*input == *temp_name)
               {
               std::cout<< "VALUE HIT: Data found.\n";
               c_list[counter].copy_object(c_get);
               delete temp_name;
               temp_name = nullptr;
               return (true);
               }
          }
     std::cout<<"VALUE MISS: No data matches a city named '"<< *input <<",' please try again.\n";
     delete temp_name;
     temp_name = nullptr;
     return(false);
     }

void search_by_coord_alpha(c_data* c_list)
//precondition)-> A c_data object pointer is passed
//postcondition)-> Every c_class object in the array is compared with 2 inputted values, and if they match an object, that object is printed
     {
     double* temp_lati = new double;
     double* temp_lont =new double;
     std::cout<< "Please enter the Latitude coordinate of the city you would like to search.\n";
     std::cin>> *temp_lati;
     std::cout<< "Now, please input the Longitude coordinate of the city you would to search.\n";
     std::cin>> *temp_lont;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     for(auto counter = 0; counter < 50; counter += 1)
          {
          if((c_list[counter].get_lati() == *temp_lati) && (c_list[counter].get_lont() == *temp_lont))
               {
               std::cout<< "VALUE HIT: Data found.\n";
               c_list[counter].print_data();
               delete temp_lati;
               temp_lati = nullptr;
               delete temp_lont;
               temp_lont = nullptr;

               end = std::chrono::system_clock::now();
               std::chrono::duration<double> elapsed_seconds = end - start;
               std::time_t end_time = std::chrono::system_clock::to_time_t(end);
               std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

               return;
               }
          }
     std::cout<< "VALUE MISS: no data matches a city with (x/y)," << *temp_lati << ", " << *temp_lont <<", please try again.\n";
     delete temp_lati;
     temp_lati = nullptr;
     delete temp_lont;
     temp_lont = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return;
     }

void delete_by_name_alpha(c_data* c_list)
//precondition)-> A c_list object pointer to a c_list array is passed
//postcondition)-> every elemtn of the C_list object array is compared with the user input and is either deleted and resorted, or the user is throw an error because
//the input was not found
     {
     int* counter = new int;
     std::string* input = new string;
     std::string* temp_name = new string;
     std::cout<< "Please enter the name of the city you would like to search.\n";
     std::cin>> *input;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     for ((*counter) = 0; (*counter) < 49; *counter +=1)
     //this for loop searches the array for a matching name value to the input
          {
          *temp_name = c_list[*counter].get_name();
          if(*input == *temp_name)
               {
               std::cout<< "VALUE HIT: Data found.\n";
               break;
               }
          }
     if((*counter == 49) && (*temp_name != *input))
     //this if statement controls whether or not the program ends based on if the input was found or not
          {
          std::cout<< "VALUE MISS: no data matches a city named '"<< *input <<",' please try again\n";
          delete counter;
          counter = nullptr;
          delete input;
          input = nullptr;
          delete temp_name;
          temp_name = nullptr;

          end = std::chrono::system_clock::now();
          std::chrono::duration<double> elapsed_seconds = end - start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";    

          return;
          }
     c_list[*counter].set_empty();
      //The chunk of code below is responsible for moving the delete c_data object to the back of the array 
     c_data* holder = new c_data;
     for (*counter; *counter < 49; *counter += 1)
          {
          if( *counter != 49 )
               {
               *temp_name = c_list[((*counter) + 1)].get_name();
               if (*temp_name == "empty")
                    {
                    delete holder;
                    holder = nullptr;
                    delete counter;
                    counter = nullptr;
                    delete input;
                    input = nullptr;
                    delete temp_name;
                    temp_name = nullptr;

                    end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

                    return;
                    }
               }
          c_list[((*counter) + 1)].copy_object(holder);
          c_list[*counter].copy_object_literal(c_list[(*counter) +1 ]);
          holder->copy_object_literal(c_list[*counter]);
          }
     
     }

void delete_by_coord_alpha(c_data* c_list)
//precondition)-> A c_data object is passed by reference
//postcondition)-> The entire array is searched by coordinate data points and an element with matching data coordinates are deleted, or an error message is displayed
     {
     int* counter = new int;
     double* input_lati = new double;
     double* input_lont = new double;
     double* temp_lati = new double;
     double* temp_lont = new double;
     std::cout<< "Please enter the Latitude coordinate of the city you would like to delete.\n";
     std::cin>> *input_lati;
     std::cout<< "Now, please input the Longitude coordinate of the city you would to delete.\n";
     std::cin>> *input_lont;
     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();
     for (*counter = 0; *counter < 49; *counter += 1)
          {
          *temp_lati = c_list[*counter].get_lati();
          *temp_lont = c_list[*counter].get_lont();
          if ((*input_lati == *temp_lati) && (*input_lont == *temp_lont))
               {
               std::cout<< "VALUE HIT: Data found.\n";
               break;
               }
          }
     
     if((*counter == 49) && (*temp_lati == 0) && (*temp_lont == 0))
          {
          std::cout<< "VALUE MISS: No data matches a city with (x/y) '"<< *input_lati << ", " << *input_lont << ",' please try again.\n";
          delete counter;
          counter = nullptr;
          delete input_lati;
          input_lati = nullptr;
          delete input_lont;
          input_lont = nullptr;
          delete temp_lati;
          temp_lati = nullptr;
          delete temp_lont;
          temp_lont = nullptr;

          end = std::chrono::system_clock::now();
          std::chrono::duration<double> elapsed_seconds = end - start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

          return;
          }
     c_list[*counter].set_empty();
     c_data* holder = new c_data;
     for (*counter; *counter < 49; *counter += 1)
          {
          if(*counter != 49)
               {
               *temp_lati = c_list[(*counter) + 1].get_lati();
               *temp_lont = c_list[(*counter) + 1].get_lont();
               if ((*temp_lati == 0) && (*temp_lont == 0))
                    {
                    delete counter;
                    counter = nullptr;
                    delete input_lati;
                    input_lati = nullptr;
                    delete input_lont;
                    input_lont = nullptr;
                    delete temp_lati;
                    temp_lati = nullptr;
                    delete temp_lont;
                    temp_lont = nullptr;

                    end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

                    return;
                    }
               }
          c_list[((*counter) + 1)].copy_object(holder);
          c_list[*counter].copy_object_literal(c_list[(*counter) +1 ]);
          holder->copy_object_literal(c_list[*counter]);
          }
     }

void print_in_distance_alpha(c_data* c_list)
     {
     std::string* input_name = new string;
     double* input_distance = new double;
     c_data* c_get = new c_data;
     int* count = new int;
     std::cout<< "Please enter the city you would like to survey the radius of\n";
     std::cin>> *input_name;
     std::cout<< "please enter the radius around the city you would like to search.\n";
     std::cin>> *input_distance;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     bool value_found = search_by_name_and_return_alpha(c_list, c_get, input_name);
     bool is_in_distance = 0;
     if (value_found == true)
          {
          std::cout<< "VALUE HIT: Data found, presenting all cities within the given radius of the given city\n\n";
          for(*count = 0; *count < 49; *count += 1)
               {
               if (c_list[*count].get_name() == "empty")
                    {
                    break;
                    }
               is_in_distance = calculate_distance(c_get, c_list[*count], input_distance);
               if (is_in_distance == true)
                    {
                    c_list[*count].print_data();
                    }
               }
          }
     else
          {
          std::cout<< "VALUE MISS: No data matches a city named '"<< *input_name <<",' please try again.\n";
          }
     delete input_name;
     input_name = nullptr;
     delete input_distance;
     input_distance = nullptr;
     delete c_get;
     c_get = nullptr;
     delete count;
     count = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
     }
//___________________________________________________________________________________
//Scenario two: Linked List Implementation functions, for convenience sake, functions only for the implementation for scenario two are marked with "delta"
void scenario_two()
     {
     int choice_alpha = 0;
     c_data* head = new c_data;
     c_data* location;
     c_data* pre_location;
     get_data_delta(head);
     do
          {
          std::cout<< "__________________________________________________\n"<<
                      "|Scenario Two: Data application with Linked Lists|\n"<<
                      "__________________________________________________\n";
          submenu(choice_alpha);
          switch(choice_alpha)
               {
               case 1:
                  insert_record_delta(head);
                  break;

               case 2:
                  search_by_name_delta(head, location, pre_location);
                  if(location != nullptr)
                       {
                       location->print_data();
                       }
                  break;

               case 3:
                  search_by_coord_delta(head, location, pre_location);
                  if(location != nullptr)
                       {
                       location->print_data();
                       }
                  break;

               case 4:
                  search_by_name_delta(head, location, pre_location);
                  delete_element(head, location, pre_location);
                  break;

               case 5:
                  search_by_coord_delta(head, location, pre_location);
                  delete_element(head, location, pre_location);
                  break;

               case 6:
                  print_in_distance_delta(head, location, pre_location);
                  break;

               case 7:
                  print_all_c_data_delta(head);
                  break;

               case 8:
                  break;

               default:
                  std::cout<< "ERROR: Invalid selection value please try again.\n\n";
                  break;
               }
          } 
     while (choice_alpha != 8);
     }

void get_data_delta(c_data* head)
//precondition)-> C_data object pointer is passed
//postcondition)-> Data is loaded from a file and uses a temporary pointer to assign the data from infile into a linked list
     {
     std::ifstream infile;
     infile.open("data.txt");
     std::string* char_dump = new string;
     //this string variable only exists to suck up the new line character.
     std::string* holder = new std::string;
     std::string* in_name = new std::string;
     double* in_lati = new double;
     double* in_lont = new double;
     c_data* place = head;
     c_data* temp;
     while(!infile.eof())
          {
          std::getline(infile, *in_name, ':');
          std::getline(infile, *holder, ',');
          *in_lati = std::stod(*holder);
          std::getline(infile, *holder, '\n');
          *in_lont = std::stod(*holder);
          std::getline(infile, *char_dump);
          if(!infile.eof())
               {
               place->set_value(*in_name, *in_lati, *in_lont);
               temp = place;
               place = new c_data;
               temp->link_node(place);
               }
          if (infile.eof())
               {
               temp->set_node_null();
               }
          }
     delete in_name;
     in_name = nullptr;
     delete in_lati;
     in_lati = nullptr;
     delete in_lont;
     in_lont = nullptr;
     delete char_dump;
     char_dump = nullptr;
     place = nullptr; 
     }

void print_all_c_data_delta(c_data* head)     
//precondition)-> head pointer is passed 
//postcondition)-> linked list is cycled thorugh and the contents of every object are read with a class function;
     {
     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     c_data* point = head;
     c_data* temp = head;
     do
          {
          point->print_data();
          temp = point;
          point = temp->get_node();
          } 
     while (point != nullptr);
     point = nullptr;
     temp = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
     }

void insert_record_delta(c_data* head)
//precondition)-> head pointer is passed 
//postcondition)-> linked list is cycled thorugh the contents until it finds nullptr, and then a new object is dynamically created and written over with the new
//object
     {
     std::string* name_input = new std::string;
     double* lati_input = new double;
     double* lont_input = new double;
     c_data* point = head;
     c_data* temp;
     std::cout<< "Please enter the name of the city you would like to enter.\n";
     std::cin>> *name_input;
     std::cout<< "please enter the latitude of the city you would like to enter.\n";
     std::cin>> *lati_input;
     std::cout<< "please enter the longitude of the city you would like to enter.\n";
     std::cin>> *lont_input;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

          do
          {
          temp = point;
          point = temp->get_node();
          }
     while (temp->get_node() != nullptr);
     temp->new_node();
     point = temp->get_node();
     point->set_value(*name_input, *lati_input, *lont_input);
     point->set_node_null();

     delete name_input;
     name_input = nullptr;
     delete lati_input;
     lati_input = nullptr;
     delete lont_input;
     lont_input = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
     }

void search_by_name_delta(c_data*& head, c_data*& location, c_data*& pre_location)
//precondition)-> head pointer is passed, location pointer is passed, and pre_location pointer is passed
//postcondition)-> linked list is cycled thorugh and the contents of every object are compared with the inputted name and the address of the object with a matching name
//is written to location, and the adress immediately behind it is written to pre_location
     {
     std::string* input = new string;
     std::cout<< "Please enter the name of the city you would like to search.\n";
     std::cin>> *input;

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     location = head;
     pre_location = head;
     do
          {
          if (location->get_name() == *input)
               {
               std::cout<< "VALUE HIT: Data found.\n";
               break;
               }
          
          pre_location = location;
          location = pre_location->get_node();
          } 
     while (pre_location->get_node() != nullptr);
     if (location == nullptr)
          {
          std::cout<< "VALUE MISS: No data matches a city named '"<< *input <<",' Please try again.\n";
          }
     delete input;
     input = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return;
     }

void search_by_coord_delta(c_data*& head, c_data*& location, c_data*& pre_location)
//precondition)-> head pointer is passed, location pointer is passed, and pre_location pointer is passed
//postcondition)-> linked list is cycled thorugh and the contents of every object are compared with the inputted coordinates to find a match
//and the address of the object with matching coordinates is written to location, and the address immediately behind it is written to pre_location
     {
     double* input_lati = new double;
     double* input_lont = new double;
     std::cout<< "Please enter the latitude of the city you wish to look up.\n";
     std::cin>> *input_lati;
     std::cout<< "Please enter the Longitude of the city you wish to look up.\n";

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();
     
     std::cin>> *input_lont;
     location = head;
     pre_location = head;
     do
          {
          if (((location->get_lati()) == *input_lati) && ((location->get_lont()) == *input_lont))
               {
               std::cout<< "VALUE HIT: Data found.\n";
               break;
               }
          
          pre_location = location;
          location = pre_location->get_node();
          } 
     while (pre_location->get_node() != nullptr);
     if (location == nullptr)
          {
          std::cout<< "VALUE MISS: No data matches a city with (x/y) '"<< *input_lati <<", "<< *input_lont <<",' coordinates.\n";
          }
     delete input_lati;
     input_lati = nullptr;
     delete input_lont;
     input_lont = nullptr;

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return;
     }

void delete_element(c_data*& head, c_data*& location, c_data*& pre_location)
//precondition)-> head pointer is passed, location pointer is passed, and pre_location pointer is passed, the search function is used in conjunction with this function
//so the location pointer contains the element to be deleted, and pre_location is used to re link the linked list.
//postcondition)-> a c_data object is deleted and the list is re-linked in vary ways depending on the location of the element to be deleted.
     {
     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     if(location == nullptr)
          {
          return;
          }
     if((location != head) && (location != nullptr))
          {
          pre_location->link_node((location->get_node()));
          delete (location);
          return;
          }
     if(location == head)
          {
          head = location->get_node();
          delete location;
          return;
          }
     if(location->get_node() == nullptr)
          {
          delete location;
          pre_location->set_node_null();
          return;
          }

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
     }

void print_in_distance_delta(c_data*& head, c_data*& location, c_data*& pre_location)
//precondition)-> head pointer, location pointer, and prelocation, c_data pointers are passed by reference.
//postcondition)-> an element is search via the search function of the linked list and each of the elements distances are calculated and if they are found to be 
//in the inputted radius they are printed.
     {
     c_data* chosen_city;
     double* radius = new double;
     bool is_in_distance = 0;

     std::cout<< "please enter the city you wish to use as the center of your radius by name.\n";
     search_by_name_delta(head, location, pre_location);

     std::chrono::time_point<std::chrono::system_clock> start, end;
     start = std::chrono::system_clock::now();

     if (location == nullptr)
     {
          std::cout<< "ERROR: VALUE MISS: no city data exists for the chosen name, please try again.\n";
          return;
     }
     
     chosen_city = location;
     location = head;
     pre_location = head;
     std::cout<< "Please select the radius you wish to search around the city.\n";
     std::cin>> *radius;
     std::cout<< "Cities aroud "<< chosen_city->get_name() <<" in a radius of "<< *radius <<":\n\n";
    
     while (location != nullptr)
          {
          if (location == nullptr)
               {
               break;
               }
          is_in_distance = calculate_distance(chosen_city, *location, radius);
          if (is_in_distance == true)
               {
               location->print_data();
               }
          pre_location = location;
          location = pre_location->get_node();
          }

     end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
     }



//precondition)-> 
//postcondition)-> 

/*
std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();


end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end - start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
*/