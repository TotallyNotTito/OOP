/*#####################################################
  The following code is for the implementation of the different
  objects as they are stored in a DLL of base_arrays. 
######################################################*/

#include "header.h"

/*########################################
  MOST INDIRECT BASE CLASS Manages object dynamic memory
########################################*/

//default constructor for ABC
activities::activities()
{
	//cout << "Activities default constructor called" << endl; 
}
//copy constructor for indirect ABC
activities::activities(const activities & source)
{
	//no dynamic memory
	//no instance of class object
}
//virtual destructor for activities
activities::~activities()
{

}

//############### List Manager implementation ################
list_manager::list_manager() : head(NULL), tail(NULL)
{

}

list_manager::~list_manager()
{
    
}

//############### Activities LIST implementation ################

//default constructor
activities_node::activities_node() : next(NULL), previous(NULL), to_do(NULL), priority(0)
{
	//cout << "Activities node  default constructor called" << endl;
}

//this will only return NULL if we are creating the data structure the first time
activities_node *& activities_node::go_next()
{
	return next; 
}

activities_node *& activities_node::go_previous()
{
	return previous;
}
//takes in an activities pointer which allows us to utilize base clas spointer 
//to fill base_array of objects of derived classes
int activities_node::get_priority()
{
	return priority;
}

//copy constructor
activities_node::activities_node(const activities_node & source) : next(NULL), previous(NULL), to_do(NULL)
{

}



activities_node::~activities_node()
{
	next = NULL;
	previous = NULL;
	//to_do = NULL;

}






/* #####################FIRST ITERATION OF CODE THAT IS NOT STRUCTURED AS IT SHOULD
########################HAD TO RESTART FROM SCRATCH#############################
//default constructor
core_data::core_data() : description(NULL), date(0), duration(0), priority(0), with_friend(false)
{
cout << "default core_data constructor called" << endl; 

//initializing temp data
char temp_data [BUFFER];
date = 0;
duration = 0;
priority = 0;
with_friend = false;
//getting data
cout << "Need to input information. Please take care to enter data correctly." << endl;
cout << "What is the activity?" << endl;
cin.get(temp_data, BUFFER, '\n');
cin.ignore(BUFFER, '\n');
//perform deep copy
description = new char[strlen(temp_data) + 1];
strcpy(description, temp_data);

cout << "What is the due date? Please input date as an integer." << endl;
cin >> date;
cin.ignore(BUFFER, '\n');

cout << "How long will this activity take? Please enter time as an integer" << endl;
cin >> duration;
cin.ignore(BUFFER, '\n');

cout << "Is this a high or low priority? Please enter value between 1 - 5 with 5 being largest priority." << endl;
cin >> priority;
cin.ignore(BUFFER, '\n');

char temp_friend;
cout << "Do you plan on doing this activity with a friend? type Y if you are." << endl;
cin >> temp_friend;
cin.ignore(BUFFER, '\n');
temp_friend = tolower(temp_friend);

if (temp_friend = 'y') with_friend = true;
}
//copy constructor
//sets all core data for derived objects
core_data::core_data(const core_data & source) 
{
//initializing temp data
char temp_data [BUFFER];
date = 0;
duration = 0;
priority = 0;
with_friend = false;
//getting data
cout << "Need to input information. Please take care to enter data correctly." << endl;
cout << "What is the activity?" << endl;
cin.get(temp_data, BUFFER, '\n');
cin.ignore(BUFFER, '\n');
//perform deep copy
description = new char[strlen(temp_data) + 1];
strcpy(description, temp_data);

cout << "What is the due date? Please input date as an integer." << endl;
cin >> date;
cin.ignore(BUFFER, '\n');

cout << "How long will this activity take? Please enter time as an integer" << endl;
cin >> duration;
cin.ignore(BUFFER, '\n');

cout << "Is this a high or low priority? Please enter value between 1 - 5 with 5 being largest priority." << endl;
cin >> priority;
cin.ignore(BUFFER, '\n');

char temp_friend;
cout << "Do you plan on doing this activity with a friend? type Y if you are." << endl;
cin >> temp_friend;
cin.ignore(BUFFER, '\n');
temp_friend = tolower(temp_friend);

if (temp_friend = 'y') with_friend = true;

}
//Destructor for core_data
core_data::~core_data()
{
	if (description) delete [] description;
}
*/

/*######################################################
  ABSTRACT BASE Class that contains virtual pointers / functions
######################################################*/
//Virtual Abstract Base Class, Default constructor
/*
   activities::activities() 
   {
   cout << "default activities constructor called" << endl;
   }

//copy constructor
activities::activities(const activities & source) : core_data(source)
{
cout << "Activities copy constructor being called " << endl;
}

//virtual destructor for activities 
activities::~activities()
{

}
 */

/*#####################################
  GARRDEN DERIVED CLASS THAT HANDLES Garden Activities
  Calls copy constructor for activities
#####################################*/


/*

//default constructor 
garden::garden()
{
cout << "default garden constructor called" << endl;

}

//copy constructor calls copy constructor of ABC
garden::garden(const garden & source) : activities(source)
{
cout << "garden copy constructor being called" << endl;
}
//garden destructor
garden::~garden()
{

}
//add function for garden class
bool garden::add() 
{
return false; 
}
//removes item of garden class
bool garden::remove() 
{ 
return false; 
}
//Retrieves objects
bool garden::retrieve() 
{
return false; 
}
//displays garden object
bool garden::display() 
{
return false; 
}
//removes all garden objects 
bool garden::remove_all() 
{

return false; 
}

//for potential RTTI
bool garden::purchase() 
{ 
return false; 
}

 */

/*#############################
  Functions managing garden nodes
#####################################*/

/*
//default constructor
garden_node::garden_node()  //: next(NULL), previous(NULL)
{
cout << "Default garden node constructor called." << endl;
}

//copy constructor 
garden_node::garden_node(const garden_node & source) : garden(source) // , next(NULL), previous(NULL)
{
cout << "Copy constructor for garden_node being called" << endl;
}

 */
//destructor
/*
   garden_node::~garden_node()
   {
//remove all function        

if (next)
{
delete next;
next = NULL;
}

if (previous)
{
delete previous;
previous = NULL;
}

}

//passes in objects next pointer to get the next pointer
garden_node * & garden_node::set_next(activities * & to_connect)
{
//need to think this one through 
//next = to_connect;
//return next;
}

//passes in objects previous pointer to set new previous
garden_node * & garden_node::set_previous(activities * & to_connect)
{
//need to think about this one
//previous = to_connect;
//return previous;

}

//for traversal
garden_node *& garden_node::go_next()
{
//return next;
}

//for traversal
garden_node *& garden_node::go_previous()
{
//return previous;
}
 */
/*
   if (next)
   {
   activities_node * temp = go_next();
   delete next;
   if (previous)
   {
   delete previous;
   previous = NULL;
   }

   next = temp;
   }
 */
//FUNCTION NOT USEd
/*
   bool activities_node::set_base_array(activities ** to_do, int & position)
   {
   if (position == INDEX) return true;
   to_do[position] = NULL;
   set_base_array(to_do, ++position);
   }
 */
//destructor for activities list
/*
   bool activities_node::remove_ptr(base_array ** & to_do, int & count)
   {
   if (count == INDEX) return true; 
   if (to_do)
   {
   to_do->remove_ptr(count);
   }

   remove_ptr(to_do, ++count);

   }


   bool base_array::remove_ptr(const int count)
   {
   if (base_ptr)
   {
   if(base_ptr[count])
   {
   delete base_ptr[count];
   base_ptr[count] = NULL;
   }
   }
   }
 */
/*
   for (int i = 0; i < INDEX; ++i)
   {
   if (base_ptr[i])
   {
   delete base_ptr[i];
   base_ptr[i] = NULL;
   }
   }
 */

/*
   if (to_do)
   {
   delete to_do;
   to_do = NULL;
   }
 */
//if (remove_all()) cout << "List removed" << endl;
/* 
   if (to_do)
   {
   for (int i = 0; i < INDEX; ++i)
   {
   if (to_do[i].base_ptr)
   {
   delete to_do[i].base_ptr;
   to_do[i].base_ptr;
   }
   }
//int count = 0;
//remove_ptr(to_do, count);
}


if (next)
{
delete next;
next = NULL;

if (previous)
{
delete previous;
previous = NULL;
}
}
 */ 
/*
	cout << "Are you wanting to add a 1 - Garden Task, an 2 - Exercise, or 3 - Project?" << endl;
	int choice = 0;
	cin >> choice;
	cin.ignore(BUFFER, '\n');
	cout << "What is the priority level, between 1 - 5, of the item you are looking to add?" << endl;
	int temp_priority = 0;
	cin >> temp_priority;
	cin.ignore(BUFFER, '\n');

	//activities_node * head = this->activities_node;

	return add(choice, temp_priority); 
	*/

//creates a new activities_node node and updates tail
	/*
	head = new activities_node;
	//setting priority
	head->priority = count + 1;

	tail = head;
        */
	//this next line of code seg faults
	//to_do [count] = NULL;
	//position that is meant to passed in for creating base_array size

	//if (set_base_array(to_do, position)) cout << "Empty list is set" << endl;//this->to_do is a base class pointer of type activities
	//else cout << "List was not set somehow" << endl;

	//base case for creating lenght of priority list
	//base case
/*
//#############################################
bool activities_node::add()
{

        
}

bool activities_node::add(const int choice, const int temp_priority)
{
	return true;

}


bool activities_node::remove()
{

}


bool activities_node::retrieve()
{

}


bool activities_node::display()
{

}


bool activities_node::remove_all()
{

}

*/
/*
void activities_node::set_list(activities_node *& head, activities_node *& tail)
{
	//wrapper function for creating priority list 
	int count = 0; 
	if (set_list(head, tail, count)) cout << "All set" << endl;
	else cout << "Hm something went wrong" << endl;

}
*/
/*
bool activities_node::set_list(activities_node *& head, activities_node *& tail, int & count)
{

	
	if (INDEX == count) return false;
	set_list(head->go_next(),tail, ++count);
	//cout << "Unwinding stack" << endl;
	//setting previous pointer to current head as stack unwinds
	if (head->go_next()) 
	{
		//does not appear that we are connecting list
		//cout << "Next is connected and connecting previous" << endl;
		//cout << head->priority << " Is priority" << endl;
		head->go_next()->go_previous() = head;
		return true;
	}

}
base_array::base_array() : base_ptr(NULL)
{
	//cout << "Array being creatied setting base ptr to NULL" << endl;
}

base_array::base_array(const base_array & source) : base_ptr(NULL)
{
	//cout << "Array copy constructor called" << endl;
}

base_array::~base_array()
{

}
*/
/*################################################
  Exercise OBject and Nodes 
################################################*/


/*#############################
  Functions managing exercise nodes
#####################################*/
