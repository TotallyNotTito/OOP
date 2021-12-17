/*#########################################################
  TAYLOR KRAL - 05/16/2020 - PROGRAM 3: Operator Overloading
  Implementation portion of the program responsible for defining
  functing methods. big issue I've encountered is being unsuccessful
  in implementing my base class ptr to typ convert to derived object
  within data strucutre. wiihtout thouse objects existing I can't overload
  any of the current objects
##########################################################*/

#include "design.h"

//default BST constructor
BST::BST() : root(NULL)
{
	//how will I handle input stream?
}
//BST copy constructor
BST::BST(const BST & source) : root(NULL)
{
	//how will I handle input stream?
}
//BST Destructor
BST::~BST()
{
	//post order traversal
	remove_all(this->root);
	/*
	if(root)
	{
		delete root;//will suspending destructor of Node 
		//and call destructor of derived type
		root = NULL;
	}
	*/
}

void BST::remove_all(node *& root)
{
    if (!root) return;
    remove_all(root->go_left());
    remove_all(root->go_right());
        if (root)
	{
	    delete root;
	    root = NULL;
	}
}

//insert function for BST
//need to make sure this calls overloaded constructor
//root = new node(*root);
//return true;
bool BST::insert()
{
	//creating objects to insert
	cout << "insert objects. 1 - News, 2 - Work, 3 - Hobby" << endl;
	int choice = 0;
	//enum choice {"news", "work", "hobby"};
	//tried to use enum data type
	cin >>  choice;
	cin.ignore(BUFFER, '\n');
	//calling default constructor
	//node to_add;
	// need to deallocate memory for to_add objects
	if (choice == 1)
	{
		//creating object of type to add
	        news to_add;

		if (insert_news(root, to_add)) 
		{
			cout << "News inserted" << endl;
			return true;
		}
		else 
		{
			cout << "News not inserted" << endl;
				return false;
		}
	}

	else if (choice == 2)
	{
		//creating object of type to add
		work to_add;

		if (insert_work(root, to_add)) 
		{
			cout << "Work inserted" << endl;
			return true;
		}
		else 
		{
			cout << "Work not inserted" << endl;
			return false;
		}
	}

	else 
	{

		//creating object of type to add
		hobby to_add;

		if (insert_hobby(root, to_add)) 
		{
		    cout << "Hobby inserted" << endl;
		    return true;
		}
		else 
		{    
		    cout << "Hobby not inserted" << endl;
		    return false;
		}
	}


	//if (to_add.title) delete [] to_add.title;
	//if (to_add.description) delete [] to_add.description;

}
//recursive implementations of insert function
bool BST::insert_news(node * & root, news & to_add)
{
	if (!root) 
	{  
                root = new news(to_add);
		return true;
		/*
		news * n_ptr  = dynamic_cast <news *> (ptr);
		if (n_ptr) 
		{
			root = new news(*n_ptr);	
			return true;
		}

		return false;
		*/
	}
	//traversal
	if (root->get_priority() <  to_add.get_priority()) return insert_news(root->go_right(), to_add);//root->get_priority() <  to_add.get_priority()
	else return insert_news(root->go_left(), to_add);

	//return insert_news(root->go_right(), ptr);
}
//creates new work data type and traverses structure
bool BST::insert_work(node * & root, work & to_add)
{
	if (!root)
	{
		root = new work(to_add);
		return true;
		/*
		work * w_ptr = dynamic_cast <work *> (ptr);
		if (w_ptr) 
		{
			root = new work(*w_ptr);
			return true;
		}
		*/

	}

	if (root->get_priority() <  to_add.get_priority()) return insert_work(root->go_right(), to_add);
	else return insert_work(root->go_left(), to_add);

}
//inserts hobby data type and traverses structure
bool BST::insert_hobby(node * & root, hobby & to_add)
{
	if (!root)
	{
	        root = new hobby(to_add);
		return true;
		/*
		hobby * h_ptr = dynamic_cast <hobby *> (ptr);
		if (h_ptr) 
		{
			root = new hobby(*h_ptr);
			return true;
		}
		*/

		//return false;
	}

	if (root->get_priority() <  to_add.get_priority()) return insert_hobby(root->go_right(), to_add);
	else return insert_hobby(root->go_left(), to_add);


}

bool BST::insert(core_data & to_add)
{
	//root = new work;
	//root = new hobby;
	//root = new news;

	return true;     
} 
//THESE FUNCTIONS CAN NOT BE IMPLEMENTED SINCE OBJECTS
//ARE NOT BEING CREATED WITHIN DATA STRUCTURE
bool BST::remove()
{
	return false;
}

bool BST::retrieve(node * & source)
{
	return false;
}

bool BST::display()const
{
    //post order traversal
    display(this->root);
    return true;
}
//display function
void BST::display(node * root) const
{
    if (!root->go_left())
    {
	//supposed to suspend execution to 
	//access title of correct derived obj3ct
	//instead is segfaulitng
        root->get_title();
        root->get_description();
        int value = root->get_priority();
	cout << value << " is the priority" << endl;
        value = root->get_date();
	cout << value << " is the date" << endl;
	return;
    }

    display(root->go_left());

    if (!root->go_right())
    {
	//supposed to suspend execution to 
	//access title of correct derived obj3ct
	//instead is segfaulitng
        root->get_title();
        root->get_description();
        int value = root->get_priority();
	cout << value << " is the priority" << endl;
        value = root->get_date();
	cout << value << " is the date" << endl;
	return;
    }

    display(root->go_right());

}


//this block of code is calling virtual member
//functions of core data to get info back from 
//most indirect base class to keep pointer for segfaulting

int node::get_priority()
{
    return core_data::get_priority();
}

int node::get_date()
{
    return core_data::get_date();
}

void node::get_title()
{
    core_data::get_title();
}

void node::get_description()
{
    core_data::get_description();
}

int news::get_priority()
{
    return node::get_priority();
}

int hobby::get_priority()
{
    return node::get_priority();
}

int work::get_priority()
{
    return node::get_priority();
}

int news::get_date()
{
    return node::get_date();
}

int hobby::get_date()
{
    return node::get_date();
}

int work::get_date()
{
    return node::get_date();
}

void news::get_title()
{
    node::get_title();
}

void work::get_title()
{
    node::get_title();
}

void hobby::get_title()
{
    node::get_title();
}

void news::get_description()
{
    node::get_description();
}

void hobby::get_description()
{
    node::get_description();
}

void work::get_description()
{
    node::get_description();
}
//###############################################
/*
   bool BST::insert_news(node * & ptr, core_data & to_add)
   {
//need to traverse first
if (!this->root)
{
news * n_ptr  = dynamic_cast <news *> (ptr);
if (n_ptr) 
{
root = new news(*n_ptr);	
return true;
}

return false; 
}

if (insert_news(this->root, to_add)) return true;
else return false;

}
 */
//function that returns priority
int core_data::get_priority()
{
	return priority;
}
//function that gets date
int core_data::get_date()
{
	return date;
}



/*###################################################*/

//default constructor
core_data::core_data() : title(NULL), description(NULL), date(0), priority(0)
{
	char temp_title[BUFFER];
	cout << "Enter title" << endl;
	cin.get(temp_title, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');

	char temp_desc[BUFFER];
	cout << "Enter description" << endl;
	cin.get(temp_desc, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');

	cout << "Enter date as an integer" << endl;
	cin >> date;
	cin.ignore(BUFFER, '\n');

	cout << "Enter priority" << endl;
	cin >> priority;
	cin.ignore(BUFFER, '\n');

}

//copy constructor overloading
core_data::core_data(const core_data & source) : title(NULL), description(NULL), date(0)
{
	if (source.title && source.description)
	{
		title = new char[strlen(source.title) + 1];
		strcpy(title, source.title);

		description = new char[strlen(source.description) + 1];
		strcpy(description, source.description);
	}
	//primitive
	date = source.date;
}

//core_data(cosnt node *& source)

//unary operator
//core data = obj1; core_data = obj2; obj1 = obj2;
//overloaded function
core_data & core_data::operator= (const core_data & source)
{
	//checking for self assignment
	if (this == &source) return *this;
	//deep copy
	if (title) delete [] title;
	if (description) delete [] description;
	title = new char[strlen(source.title) + 1];
	strcpy(title, source.title);

	description = new char[strlen(source.description) + 1];
	strcpy(description, source.description);
	//primitive
	date = source.date;

	return *this;

}

void core_data::get_title()
{
    cout << title << endl;
    return;
}

void core_data::get_description()
{
    cout << description << endl;
    return;
}

core_data::~core_data()
{
	if (title) delete [] title;
	if (description) delete [] description;
}

//default constructor for node
node::node() : right(NULL), left(NULL)
{

}
//node copy constructor
node::node(const node & source) : core_data(source), right(NULL), left(NULL)
{

}
//node overloaded
node & node::operator=(const node & source)
{
	if (this == &source) return *this;

	return *this;
}

//node traversal right and left
node *& node::go_right()
{
	return right;
}

//node traversal right and left
node *& node::go_left()
{
	return left;
}

node *& node::set_left(node *& left)
{
	left = this->left;
	return left;
}

node *& node::set_right(node *& right)
{
	right = this->right;
	return right;
}
//node destructor
node::~node()
{
	if (right) right = NULL;
	if (left) left = NULL;
}
//news constructor
news::news() : good_news(false)
{
	good_news = true;
}

news::news(const news & source) : node(source), good_news(false)
{
	good_news = true;
}

news::~news()
{

}
//hobby constructor
hobby::hobby() : duration(0)
{
	duration = 10;
}

hobby::hobby(const hobby & source) : node(source), duration(0)
{

}

hobby::~hobby()
{

}
//work constructor
work::work() : due_date(0)
{
	//cout << "default constructor being called" << endl;
	due_date = 5;
}

work::work(const work & source) : node(source), due_date(0)
{
	//cout << "copy constructor being called" << endl;
}

work::~work()
{

}






//default constructor of my_string
/*
   my_string::my_string() : title(NULL), description(NULL), date(0), id_num(0), priority(0)
   {

   }

//for copying whole objects
my_string::my_string(const my_string & source) : title(NULL), description(NULL), date(0), id_num(0), priority(0)
{
//deep copy of dynamic memory
if (source.title)
{
title = new char[strlen(source.title) + 1];
strcpy(title, source.title);
}
//deep copy operators
if (source.description)
{
description = new char[strlen(source.description) + 1];
strcpy(description,source.description);
}
//primitives
date = source.date;
id_num = source.id_num;
priority = source.priority;

}
//deallocating dynamic memory
my_string::~my_string()
{
if (title) delete [] title;
if(description) delete [] description;
}
 */
