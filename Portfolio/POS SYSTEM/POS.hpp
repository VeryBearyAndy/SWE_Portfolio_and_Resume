
//Class object functions and constructors
//|||||||||||||||||||||||||||||||||||||||
// Product Class declaration            \\
//////////////////////////////////////////______________________________________________________________________________________________________________________________

class product
{
private:
     std::string name;
     double cost;
     std::string upc_barcode;
     int stock;
     product* node;

public:
//class constructors
     product();
     product(std::string, double, std::string, int);
     product(std::string, double, std::string);
     product(std::string, double);
     product(std::string);
     product(double, std::string, int);
     product(std::string, int);
     product(int);
     product(double);
     product(double, int);
     product(std::string, std::string);
//class memeber functions
     void set_data(std::string, double, std::string, int);
     void set_name(std::string);
     void set_cost(double);
     void set_cost_zero();
     void set_cost_negative();
     void set_upc(std::string);
     void set_stock(int);
     std::string get_name();
     double get_cost();
     std::string get_upc();
     int get_stock();
     void print_data();
     void set_node(product*);
     void set_node_new();
     product* get_node();
     void set_node_null();
     void copy_product(product*);

};


//Class object functions and constructors
//|||||||||||||||||||||||||||||||||||||||
// General Functions                    \\
//////////////////////////////////////////______________________________________________________________________________________________________________________________

void get_choice(int&);
//this function is used to navigate the main menu of this POS system, it gives the user a selection and validates their input for that selection
void get_data(std::map<std::string, product>& product_list);
//This function reads from a file and inputs it into a map.
void Transaction_mode(std::map<std::string, product>& product_list);
//this function initiates transaction mode to allow for ringing goods for tender.
void add_tender(product*, product*, product*, product*);
//adds an item to a linked list which stores the ringed items to be tendered later.
void get_total(double&, product*, product*, product*);
//calculates the total of the transaction
void generate_receipt(double&, double&, double&, product*, product*, product*);
//this function generates a reciept for the transaction.
void delete_linked_list(product*, product*, product*);
//deletes the linked list used for transactions
