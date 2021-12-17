/*#########################################################
  TAYLOR KRAL - 05/16/2020 - PROGRAM 3: Operator Overloading
##########################################################*/

#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const int BUFFER = 1000;
//Abstract string class
//What are my string abstractions and operations?

//data structure manager class
class BST
{
	public:
		//constructors and destructors
		BST();
		BST(const BST & source);
		~BST();
		//member functions
		bool insert();
		bool insert(class core_data & to_add);
		//bool insert(class core_data & to_add);
		bool remove();
		bool retrieve(class node * & source);
		bool display() const;

		//overloaded operators

		//protected members functions
	protected:
		//private data members for string
		class node * root;
		//managing exetrnal data file
		//istream input; //does not compile as protected withint context of object
		//ostream output; //does not compile as protected withint context of object
		//protected member functions
		bool insert(node * & root);

		bool insert_work(node * & root, class work & to_add);
		//bool insert_work(node *& root, node *& ptr, core_data & to_add);

		bool insert_hobby(node * & root, class hobby & to_add);

		bool insert_news(node * & root, class news & to_add);
		//bool insert_news(node *& root, node *& ptr);

		bool remove(node * & root);
		void remove_all(node *& root);
		//takes a node to traverse and data to collect
		bool retrieve(node * root); //maybe pass a core_data object?
		void display(node * root) const;

};

//##################most indirect base class ##################
//Object Hierarchy
//for setting data in nodes
class core_data
{
	public:
		//constructors and destructors
		core_data();
		core_data(const core_data & source);
		//core_data(const class node *& source);

		core_data & operator=(const core_data & source);
		~core_data();
		//self-similar interface
		//wrapper functions for root accessing my_string data

		//returns *this object
		//core_data & operator += (enum & value);//, const int date);
		//core_data & operator -= (enum & value);//, const int date);
		//binary operators
		//bool operator == (core_data & check, const int to_compare);	
		/*
		   core_data & operator > (const int to_compare);
		   core_data & operator < (const int to_compare);
		   core_data & operator != (const int to_compare);	
		 */ 

                //overloaded operators
		core_data & operator += (const int value);
		core_data & operator -= (const int value);
		core_data & operator = (const int value);// const int n_date);

		bool operator == (const int value);//char * text, const char * to_compare);	
		bool operator != (const int value);	
		bool operator > (const int value);
		bool operator < (const int value);

		virtual int get_priority();
		virtual int get_date();
		
		virtual void get_title();
		virtual void get_description();

		//bool compare_data(); 
		//protected members functions
	protected:
		//protected data members
		//my_string data;
		char * title;
		char * description;
		int date;
		int priority;

		enum type {Work, News, Hobby};

		//int priority;
		//int id_num;
		//protected member functions to access info

		//bool compare_data(const my_string & to_get);
};
//node for traversing data structure
class node : public core_data
{   
	public:
		//constructors and destructors     
		node();
		node(const node & source);
		node & operator=(const node & source);
		//making node virtual since dynamic binding is used 
		//from BST that uses base pointer to invoke 
		//derived objects / self-similar interface
		virtual ~node();

		//non OO setters and getters
		node * & go_right();
		node * & go_left();

		node * & set_right();
		node * & set_left();
                //suspending execution of virtual type
		int get_priority();
		int get_date();
		
		void get_title();
		void get_description();

		/* 
		   bool operator == (const char * to_compare);	
		   bool operator != (const char * to_compare);	
		   bool operator += (const char * to_compare);
		   bool operator >= (const char * to_compare);
		   bool operator < (const char * to_compare);
		 */


		//protected members functions
	protected:
		//protected data members
		node * right;
		node * left;
		//protecte member functions
		node * & go_right(node * & right);
		node * & go_left(node * & left);

		node * & set_right(node * & right);
		node * & set_left(node * & left);

		enum type {news, work, hobby};
};


/*######### Derived Class Objects ##############*/

//WHAT ARE MY UNIQUE OPERATIONS? HOW ARE THEY SELF-SIMILAR?


//derived type
class news : public node
{
	public:
		//constructors and destructors
		news();
		news(const news & source);
		news & operator=(const news & source);
		~news();
		
		int get_priority();
		int get_date();
		
		void get_title();
		void get_description();
		//protected members functions
	protected:
		bool good_news;
};

//derived type
class work : public node
{
	public:
		//constructors and destructors
		work();
		work(const work & source);
		work & operator=(const work & source);
		~work();
 
		int get_priority();
		int get_date();
		
		void get_title();
		void get_description();
		//protected members functions
	protected:
		int due_date;
		//int priority;
};

//derived type
class hobby : public node
{
	public:
		//constructors and destructors
		hobby();
		hobby(const hobby & source);
		hobby & operator=(const hobby & source);
		~hobby();

		int get_priority();
		int get_date();
		
		void get_title();
		void get_description();

		//protected members functions
	protected:
		int duration;
};

/*
   class my_string
   {
   public:
//Constructors and destructors
my_string();
my_string(const my_string & source);
//special constructors based on what's being done
~my_string();

//protected members functions
protected:
//private data members for string
//populate with data to overload
char * title;
char * description;
int date;
int id_num;
int priority;

};
 */
