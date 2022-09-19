#include <iostream>
using std::string;

//constant variables
const double R = 3963.191;
const double PI = 3.14159265359;


class c_data
//class for city data: c = city, in this case;
{
private:
     std::string name;
     //city name
     double lati;
     //city latitude
     double lont;
     //city longitude
     c_data* node;
     //node to be used for linked list application

public:
//to remove confusion, in the case of the constructors: (alpha = name), (beta = lati), and (gamma = lont)
     //constructors
     c_data();
     c_data(std::string& alpha, double& beta, double& gamma);
     c_data(std::string alpha, double beta);
     c_data(double beta, double gamma);
     c_data(std::string alpha);
     c_data(double beta);
     
     //class functions
     void new_node();
     //this function is to set nodes for linked lists
     void link_node(c_data* next);
     //this function links nodes together to form the liked list
     void set_node_null();
     //sets node to null ptr
     void set_value(string& in_name, double& in_lati, double& in_lont);
     //this is a setter to i nput data from the std::ifstream object.
     void set_empty();
     //makes the value of the elements in the object empty, in essence deleting them.
     void print_data();
     //this function is just to print all of the elements in the given array in a neat order, similar to what is native to the data file.
     c_data* get_node();
     //returns node 
     string get_name();
     //returns the name of the city
     double get_lati();
     //returns the latitude of the city
     double get_lont();
     //returns the longitude of the city
     void copy_object(c_data*);
     //copies element from one c_data object onto another c_data object using pointers
     void copy_object_literal(c_data&);
     //copies elements from one c_data object onto another c_data object, but with the literal variable instead of a pointer.
};


// General function declarations___________________________________________________________________________________________________________________
void menu(int& choice);
//this function produces the menu selection and validation for the user's choice;
void submenu(int& choice);
//this function produces the sub menu to allow the user to input actions in scenario A and B;
bool calculate_distance(c_data*, c_data, double*);
//this function checks to see if a city is in a given radius of another city by the user
//__________________________________________________________________________________________________________________________________________________


//Scenario_1 functions: Array implementation________________________________________________________________________________________________________
//for convenience sake, any function labeled "alpha" is strictly associated with Scenario one: array implementation, and its methods of function;
void scenario_one();
//this function impliments the data sorting with an array as outlined;
void get_data_alpha(c_data*);
//this function loads and initilized data to an array using ifstream object;
void insert_record_alpha(c_data*);
//insertaion function for array application of data
void print_all_c_data_alpha(c_data*);
//this function prints every element containing data in the c_data array
void search_by_name_alpha(c_data*);
//this function allows the user to search for an element by name;
bool search_by_name_and_return_alpha(c_data*, c_data*, string*);
//this function is for conveniece and allows a search and return function without bloating the the Print_in_distance() function
void search_by_coord_alpha(c_data*);
//this function allows the user to search for an element by coordinates;
void delete_by_name_alpha(c_data*);
//this function allows the user to delete an element in the array by city name;
void delete_by_coord_alpha(c_data*);
//this function allows the user to delete an element of the array by coordinates;
void print_in_distance_alpha(c_data*);
//__________________________________________________________________________________________________________________________________________________


////Scenario 2 functions: Linked list Implementation ________________________________________________________________________________________________
void scenario_two();
//this function impliments the data sorting with a linked list as outlined;
void get_data_delta(c_data*);
//this function generates the linked list
void print_all_c_data_delta(c_data*);
//prints every element in the linked list
void insert_record_delta(c_data*);
//inserts a record at the end of the linked list
void search_by_name_delta(c_data*&, c_data*&, c_data*&);
//allows the user to search and find a city by name;
void search_by_coord_delta(c_data*&, c_data*&, c_data*&);
//deletes an element via searching by city name
void delete_element(c_data*&, c_data*&, c_data*&);
//uses pointers to delete an element in the linked list
void print_in_distance_delta(c_data*&, c_data*&, c_data*&);
//this function allows the user to print all cities within a given distance;
//__________________________________________________________________________________________________________________________________________________