#include <iostream>
#include <limits>
#include <map>
#include <fstream> 
#include "POS.hpp"

//Class object functions and constructors
//|||||||||||||||||||||||||||||||||||||||
//    Product constructors              \\
//////////////////////////////////////////______________________________________________________________________________________________________________________________
//for the sake of brevity, I shall refer to each member of the product object with a psuedonym in the constructors and class functions when necessary
// (name == alpha), (cost == beta), (upc_barcode == delta), and (stock == sigma)
product::product()
	{
	name = "ERROR, NO VALID DATA AVAILABLE";
	cost = 0.0;
	upc_barcode = "-1";
	stock = -1;
	}

product::product(std::string alpha, double beta, std::string delta, int sigma)
	{
	name = alpha;
	cost = beta;
	upc_barcode = delta;
	stock = sigma;
	}

product::product(std::string alpha, double beta, std::string delta)
	{
	name = alpha;
	cost = beta;
	upc_barcode = delta;
	stock = -1;
	}

product::product(std::string alpha, double beta)
	{
	name = alpha;
	cost = beta;
	upc_barcode = "-1";
	stock = -1;
	}

product::product(std::string alpha)
	{
	name = alpha;
	cost = 0.0;
	upc_barcode = "-1"; 
	stock = -1;
	}

product::product(double beta, std::string delta, int sigma)
	{
	name = "ERROR, NO VALID DATA AVAILABLE";
	cost = beta;
	upc_barcode = delta;
	stock = sigma;
	}

product::product(std::string alpha, int sigma)
	{
	name = alpha;
	cost = 0.0;
	upc_barcode = "-1";
	stock = sigma;
	}

product::product(int sigma)
     {
     name = "ERROR, NO VALID DATA AVAILABLE";
     cost = 0.0;
     upc_barcode = "-1";
     stock = sigma;
     }

product::product(double beta)
     {
     name = "ERROR, NO VALID DATA AVAILABLE";
     cost = beta;
     upc_barcode = "-1";
     stock = -1;
     }

product::product(double beta, int sigma)
     {
     name = "ERROR, NO VALID DATA AVAILABLE";
     cost = beta;
     upc_barcode = "-1";
     stock = sigma;
     }

product::product(std::string alpha, std::string delta)
     {
     name = alpha;
     cost = 0.0;
     upc_barcode = delta;
     stock = -1;
     }


//Class object functions and constructors
//|||||||||||||||||||||||||||||||||||||||
// Product Class Functions              \\
//////////////////////////////////////////______________________________________________________________________________________________________________________________
void product::set_data(std::string alpha, double beta, std::string delta, int sigma)
	{
	name = alpha;
	cost = beta;
	upc_barcode = delta;
	stock = sigma;
	}

void product::set_name(std::string alpha)
	{
	name = alpha;
	}

void product::set_cost(double beta)
	{
	cost = beta;
	}

void product::set_cost_zero()
	{
	cost = 0;
	}

void product::set_cost_negative()
	{
	cost *= (-1);
	}

void product::set_upc(std::string delta)
	{
	upc_barcode = delta;
	}

void product::set_stock(int sigma)
	{
	stock = sigma;
	}

std::string product::get_name()
	{
	return (name);
	}

double product::get_cost()
	{
	return (cost);
	}

std::string product::get_upc()
	{
	return (upc_barcode);
	}

int product::get_stock()
	{
	return (stock);
	}

void product::print_data()
	{
	std::cout<< "Name: "<< name << ", \n"<<
			  "Price: "<< cost << ", \n"<<
			  "UPC: "<< upc_barcode << ", \n"<<
			  "QTY in stock "<< stock << ", \n"<<
			  "_________________________________\n\n";
	}

void product::set_node(product* next_node)
	{
	node = next_node; 
	}

void product::set_node_new()
	{
	node = new product;
	}

product* product::get_node()
	{
	return(node);
	}

void product::set_node_null()
     {
	node = nullptr;
     }

void product::copy_product(product* conjugate)
	{
	name = conjugate->get_name();
	cost = conjugate->get_cost();
	upc_barcode = conjugate->get_upc();
	stock = conjugate->get_stock();
	}



//Class object functions and constructors
//|||||||||||||||||||||||||||||||||||||||
// General Functions                    \\
//////////////////////////////////////////______________________________________________________________________________________________________________________________
void get_choice(int& choice)
    {
    std::cout<< "Please select what operation you would like to do.\n"<<
			 "1) Transaction Mode,\n"<<
			 "2) Inventory Management Mode,\n"<<
			 "3) Product look-up mode, \n"<<
			 "4) End operation.\n";
	std::cin>> choice;

	if ((std::cin.fail()) || (choice < 1) || (choice > 4))
		{
		do
		     {
		     std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		      std::cout<< "error, Invalid selection, please select a number between 1 and 4\n"<<
				        "1) Transaction Mode,\n"<<
			             "2) Inventory Management Mode,\n"<<
			             "3) Product look-up mode, \n"<<
			             "4) End operation.\n";
			std::cin>> choice;
		} while (std::cin.fail() || (choice < 1) || (choice > 4));
		}
	
    }

void get_data(std::map<std::string, product>& product_list)
// preconditions->) A map is passed to the function
// postconditions ->) This function reads a file, generates product objects from the file, then inputs them into the inserted map via (UPC, Product object)->(key, return). 
	{
	product* entry = new product;
	std::string* input_name = new std::string;
	std::string* holder = new std::string;
	double* input_cost = new double;
	std::string* input_UPC = new std::string;
	int* input_stock = new int;
	std::string* char_dump = new std::string;

     std::ifstream infile;
	infile.open("UPC_list.txt");
	while (!infile.eof())
		{
		std::getline(infile, *input_name, ',');
		std::getline(infile, *holder, ',');
		*input_cost = std::stod(*holder);
		std::getline(infile, *char_dump, ' ');
		std::getline(infile, *input_UPC, ',');
		std::getline(infile, *holder, '\n');
		*input_stock = std::stoi(*holder);
		entry->set_data(*input_name, *input_cost, *input_UPC, *input_stock);
		product_list.insert(std::pair<std::string, product>(entry->get_upc(), *entry));
		}

	infile.close();
	delete entry;
	entry = nullptr;
	delete input_name;
	input_name = nullptr;
	delete holder;
	holder = nullptr;
	delete input_cost;
	input_cost = nullptr;
	delete input_UPC;
	input_UPC = nullptr;
	delete input_stock;
	input_stock = nullptr;
	delete char_dump;
	char_dump = nullptr;
	}

void Transaction_mode(std::map<std::string, product>& product_list)
	{
	product* temp_product = new product;
	product* head = new product;
	product* holder = head;
	product* before_holder;
	std::string* input = new std::string;
	double* tax = new double;
	double* total = new double;
	double* payment = new double;
	double* change = new double;

	std::cout<< "please enter the tax percentage in decimal form.\n\n";
	std::cin>> *tax;
	*tax = 1 + *tax;
     std::cout<< "Please scan an Item.\n"<<
	          "input /t to recieve the subtotal\n"<<
			  "input /r to remove an item then scan the UPC you'd like to remove,\n"<<
			  "input /e to end the transaction without payment,\n"<<
			  "input /p to promo the last item scanned.\n";
	do
		{
		std::cin>> *input;
		if ( (*input != "/t") && (*input != "/e") && (*input != "/T") && (*input != "/E") )
		//this if statement is a safeguard from trying to add the input commands to tender which will generate an error
			{
			if( ( (*input == "/p") || (*input == "/P") ) && (temp_product->get_upc() != "-1") )
			//this if statement contols the promo feature of this function
				{
				temp_product->set_cost_zero();
				add_tender(temp_product, head, holder, before_holder);
				}

			if((*input == "/r") || (*input == "/R"))
			//this if statement has nested validation and controls the remove item feature of this function
				{
				std::cout<< "Please scan the item you would like to remove.\n\n";
				do
					{
					std::cin>> *input;
					if(product_list.count(*input) == 0)
						{
						std::cout<< "ERROR, UPC does not exist, please try again\n\n";
						}
					} 
				while (product_list.count(*input) == 0);
				*temp_product = product_list[*input];
				temp_product->set_cost_negative();
				add_tender(temp_product, head, holder, before_holder);
				*input = "/r";
				}
			
			//these two nested if-statements below serve as validation that the input for the map is indeed a key.
			if((product_list.count(*input) != 0) && (*input != "/r") && (*input != "/R"))
				{
				*temp_product = product_list[*input];
				add_tender(temp_product, head, holder, before_holder);
				}

			if( (product_list.count(*input) == 0) && (*input != "/p") && (*input != "/r") && (*input != "/P") && (*input != "/R") )
				{
				std::cout<< "ERROR, UPC does not exist, please try again\n\n";
				}
			}
		} 
	while ( (*input != "/t") && (*input != "/e") && (*input != "/T") && (*input != "/E") );
	
	if( (*input == "/e") || (*input == "/E") )
	//this if statment cleans up the variables and linked list that may have been generated to cancel the transaction.
		{
		std::cout<< "Transaction Cancelled\n\n";
		delete_linked_list(head, holder, before_holder);
		delete temp_product;
		temp_product = nullptr;
		delete head;
		head = nullptr;
		delete holder;
		holder = nullptr;
		delete before_holder;
		before_holder = nullptr;
		delete input;
		input = nullptr;
		delete tax;
		tax = nullptr;
		delete total;
		total = nullptr;
		delete payment;
		payment = nullptr;
		delete change;
		change = nullptr;
		return;
		}
	
	get_total(*total, head, holder, before_holder);
	*total = (*total) * (*tax);
	std::cout<< *total<<"\n";
	}

void add_tender(product* temp_product, product* head, product* holder, product* before_holder)
// preconditions->) 4 pointers are passed, temp_product being an element to add to a linked list. the other 3 being the core elements for both naviagating and
//interacting with the linked list
// postconditions ->) temp_product is added to the end of the linked list.
	{
	holder = head;
	if (head->get_upc() == "-1")
		{
		head->copy_product(temp_product);
		head->set_node_null();
		}
	else
		{
		while (holder->get_node() != nullptr)
			{
			before_holder = holder;
			holder = before_holder->get_node();
			}
		holder->set_node_new();
		before_holder = holder;
		holder = before_holder->get_node();
		holder->copy_product(temp_product);
		holder->set_node_null();
		}
	}

void get_total(double& total, product* head, product* holder, product* before_holder)
	{
	total = 0;
	holder = head;
	do
		{
		total = total + holder->get_cost();
		before_holder = holder;
		holder = before_holder->get_node();
		} 
	while (holder != nullptr);
	}

void generate_receipt(double& total, double& payment, double& change,  product* head, product* holder, product* before_holder)
	{
	
	}

void delete_linked_list(product* head, product* holder, product* before_holder)
	{
	holder = head;
	do
		{
		before_holder = holder;
		holder = before_holder->get_node();
		delete before_holder;
		} 
	while (holder != nullptr);
	}

// preconditions->)
// postconditions ->)