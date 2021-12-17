#include "header.h"

/*#################################################
Purpose of this part of the program is to allow the
interface to interact with program outside of main
allower abstraction for access to pointers and protected
data members
##################################################*/

/*
//default constructor that creates list for data structure
interface::interface() : head(NULL), tail(NULL)
{
    //activities_list create;
    //create.activities_list::set_list(head, tail);
    cout << "Default interface created" << endl;
    head->set_list(head, tail);

}

//copy constructor for creating data structure
interface::interface(const interface & source) : head(NULL), tail(NULL)
{
    
    //activities_list create;
    //create.activities_list::set_list(head, tail);
}
//adding data
bool interface::add_data()
{
    //checking if head is null
    if (!head) return false;
    return head->add(); 
}



//destructor for interface
interface::~interface()
{
    remove_all(this->head);    
}

bool interface::remove_all(activities_list * & head)
{
    if (!head) return true;
    else remove_all(head->go_next());
        delete head;
	head = NULL;
}



//CODE GRAVEYARD
/*
    if (head)
    {
	//of type activities_list
	delete head;
	head = NULL;
    }
        //making tail NULL
	tail = NULL;
    */

































/*###########################################*/
//constructor for interface class
/*
interface::interface() : head(NULL), tail(NULL), ptr(NULL)
{
    cout << "default INTERFACE constructor being called." << endl;
}
//copy constructor for interface class
interface::interface(const interface & source) : head(NULL), tail(NULL), ptr(NULL)
{
    cout << "Copy constructor being called." << endl;    
}
//Main program interface
//were in the scope of interface so initially tail and 
//head are set to NULL and then we create new objects with 
// temp set_next & previous
int interface::run()
{
    //garden_node to_plant;
    //exercise to_run;
    //projects to_complete;

    //implementing garden object    
    cout << "Here we have the testing platform of the program." << endl;
    
    if (!head)
    {
	//previous and next are ste to NULL
        ptr = new garden_node;
	head = ptr;
	tail = head;
    }
    //NEED TO THINK ABOUT THE LOGIC HERE
    //temp->next is set to previous
    //temp->previous is set to NULL
    //want to set temp-.previous to this->tail
    //ptr = new garden_node;
    //temp->set_previous(this->tail);
    //tail = temp;

    return 0;
       
}
//need to implement interface
interface::~interface()
{
    //need to implement remove all function
    if (head) head->remove_all();
}

###########################################
*/


