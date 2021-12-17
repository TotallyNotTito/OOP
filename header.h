/*###############################################
Taylor Kral - Program 2: FUN WITH DYNAMIC BINDING - April 23, 2020
Purpose of this program is to experience the wonderful
world of dynamic binding with a small bit of RTTI Practice.
The header file and subsequent files are aimed to create
a DLL of base_arrays that sort data by their priority for activities
to be done once the stay home stay safe order has been lifted
The way I'm planning on tackling this is take the things
I'm interested in doing by prioritiy and create a list that
prioritizes those activities glued together by an
abstract base class.
################################################*/
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int BUFFER = 1000;
const int INDEX = 5;

//ABSTRACT BASE CLASS, ACTIVITIES
//This most indirect base class is meant to add data for inherited objects
//leaving them out of virtual activities since you can not insnatiate
//objects and ultimately deep copy data



//Abstract base class 
class activities 
{
    public:
        //constructor and destructor
        activities();
	activities(const activities & source);
	//dynamic destructor
	virtual ~activities();
        //pure virtual functions
	virtual bool add() = 0;//adds and fills information for function
	virtual bool remove() = 0;
	virtual bool retrieve() = 0; //retrieve object
	virtual bool display() = 0;
	virtual bool remove_all() = 0; //destorys data structure

        activities * b_ptr;

    protected: 
    
        //dymamic memory to invoke dynamic binding
        //activities * ptr; 
        //activities * next;
	//activities * previous;
        //head pointer to objects
	//tail pointer to objects
	//activities * next;
	//activities * previous;
    
};
//node data structure for managing data structure

class list_manager
{
    public:
        list_manager();
	list_manager(const list_manager & source);
	~list_manager();

        bool add();
	bool remove();
	bool retrieve(); //retrieve object
	bool display();
	bool remove_all(); //destorys data structure



    protected:

        class activities_node * head;
	class activities_node * tail;
};

class activities_node  //: public activities
{
    public:
        //constructors and destructors
        activities_node();
	activities_node(const activities_node & source);
	~activities_node();

	//void set_list();
        
	//virtual function implementation that 
	//is called from interface class
	        //function for when setting list is called
        void set_list(activities_node * & head, activities_node * & tail);

	activities_node * & go_next();
	activities_node * & go_previous();

	int get_priority();

    protected:

        //protected data members
	
        activities_node * next;//base class next pointer for DLL
	activities_node * previous;//previous pointer for DLL
        activities ** to_do; // to_do [index] = new derived;
	int priority;
        //class base_array ** to_do;//BASE CLASS pointer to a pointer for index

        //base class data types

	//int index; //for size of index
	//int priority_length; //number of nodes in list

	//pretected member functions
	//traversal back and forth
        //setting next and prevoius
	activities_node * & set_next(activities_node * & next);
	activities_node * & set_previous(activities_node * & previous);
	//helper functions
        //void set_list(activities_node * & head, activities_node * & tail);
        bool set_list(activities_node *& head, activities_node *& tail, int & count);
	bool set_base_array(activities ** to_do, int & position);

        bool add(const int choice, const int level);//adds and fills information for function
	bool remove_ptr(class base_array ** & to_do, int & count);

};

//base_array objects filled with base class pointers
class base_array
{
    public:
        base_array();
	base_array(const base_array & source);
	~base_array();

	//bool remove_ptr(const int count);

    protected:
        activities * base_ptr;
};
//manages all the derived objects data
class core_data : public activities
{
    public:
        core_data();
	core_data(const core_data & source);
	~core_data();

    protected:
        
	//protected data members
	
        //attribute members
        char * description;
	int date;
	int duration;
	int priority; //between 1 - 5
	bool with_friend;

	//base class pointer to be used for RTTI / Dynamic binding

};



/*####################################################*/
//class for gardening derived from ABC
class garden : public core_data
{
    public:
        //constructor / destructor
    	garden();
	garden(const garden & source);
	~garden();
	//member functions
	bool add();
	bool remove();
	bool retrieve();
	bool display();
	bool remove_all();

	//for potential RTTI
	bool purchase();

    protected:

        //dynnamic data members
        //protected data members for managing class
	//bool set_next(garden * & next, garden * & previous);

};



//exercise class derived from ABC
class exercise : public core_data
{
    public:
        //constructor / destructor
        exercise();
	exercise(const exercise & source);
	~exercise();
	//member functions
	bool add();
	bool remove();
	bool retrieve();
	bool display();
	bool remove_all();

	//for RTTI
	bool add_exercise();

    protected:
        //dynamic memory data memebrs
        //protected member functions
};



//node class for exercise object
/*
class exercise_node : public core_data
{
    public:
        //constructors and destructors
        exercise_node();
	exercise_node(const exercise_node & source);
	~exercise_node();

        bool set_next(exercise_node * & next);
	bool set_previous(exercise_node * & previous);
	//for getting next or previous
        exercise_node *& get_next();
	exercise_node *& get_previous();


    protected:
        //dynamic pointers to link up nodes
        exercise_node * next;
	exercise_node * previous;
	//setting and getting
};
*/

//projects to fill my time
class projects : public activities
{
    public:
        //constructor / destructor
	projects();
	projects(const projects & source);
	~projects();
	//member functions
	bool add();
	bool remove();
	bool retrieve();
	bool display();
	bool remove_all();

        //for RTTI
	bool create_project();

    protected:
        //dynmaic memory data memebrs
	//protected member functions

};


//LAND OF GARBAGE CODE. BEWARE!!!!!!!

//derived class to manage nodes
/*
class garden_node : public garden
{
    public:
        //constructors / destructor
        garden_node();
	garden_node(const garden_node & source);
	~garden_node();

        garden_node *& set_next(activities * & next);
	garden_node *&  set_previous(activities * & previous);

        //garden_node *& set_next(garden_node * & next);
	//garden_node *&  set_previous(garden_node * & previous);

	garden_node *& go_next();
	garden_node *& go_previous();

    protected:

        //dynamic next and previous pointers
        //garden_node * next;
	//garden_node * previous;
        //protected members for getting and setting next
	
};
*/
/*
	activities * next;
	activities * previous;

        activities * & set_next();
	activities * go_next();
	activities * go_back();
*/

//interface class that contains head aand tail pointer
/*
class interface
{
    public:
        interface();
	interface(const interface & source);
	~interface();
        //public member function to enable program to run
	int run();
        //adding data to list	
	bool add_data();

    protected:
        //base pointer pointing to derived object
        class activities_node * head;
	class activities_node * tail;
	//class activities_node * ptr;
        //creating a list from the program interface
	bool set_list(activities_node *& head, activities_node *& tail);
	//recursive function adding data to list
	//bool add_data(activities_node * head, const int priority);
	bool remove_all(class activities_node *& head);
};
*/
