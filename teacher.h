/*###################################################
TAYLOR KRAL - PROGRAM 1: LMS SOFTWARE - APRIL 13 2020
The purpose of this program is to develop a simple LMS
software that enables a teacher to create a classroom 
of students managed by an ALL, create content for hw and 
for lectures, and post / respond to questions posed by students
students are able to remove themself from classes, pose questions
and review hw and lectures, but not change its data. I have 
seperated the implementations of these files based on what 
a teacher and student can do, and the actions of the content
in seperate files. wish me luck lol. 
####################################################*/

//external libraries
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>

//namespace collection
using namespace std;

//most indirect base class
//purpose is to allow every class to inherit character data
//minimizing pointers and deallocation of dynamic memory
const int BUFFER = 1000;
//SUPERCLASS
class name
{
    public:
        //constructors
        name();
	name(const name & source);
	name(char * data);
	//destructor
	~name();
        //wrapper function for reading data
	bool read_data();


    protected:
        //dynamic memory
    	char * data;
	int date;
	//protected member functions
	bool read_data(char * text);
};

//PART OF PROGRAM RESPONSIBLE FOR MANAGING PRIMARY DATA
class teacher : public name
{
    public:
        //constructor
        teacher();
	teacher(char * text);
	teacher(const teacher & source);
	//destructor
	~teacher();
	//public member functions
	bool add_teacher();
	bool add_student();

	bool display_teacher();
	bool display_all();
        //working with students	
	bool search_student();
	bool remove_student();
	bool remove_message();
        //working with LMS hiearchy
	bool add_message();
	bool display_message();



    protected:
        int num_students; //integer for size of class
	int counter;
        class student ** head; //initialize array of head pointers
			       //of student object
	//protected members to work with hierarchy
        class message_mgr * msg_head;
	class lecture_mgr * lec_head;
	class hw_mgr * hw_head;

	//protected member functions
	bool add_student(class student ** &  head, int & count);
	bool search_student(class student ** head, const char * search, int & size);
	bool remove_student(class student ** & head, const char * search, int & count);
	bool create_list(class student ** head, int & full);
	bool add_message(message_mgr * & msg_head);
	bool remove_message(message_mgr *& head, char * text);
	bool display_message(message_mgr * head);
	void remove_messages(message_mgr * & head);
	void remove_students(student ** & head, int & count);
	
};

class student : public name
{
    public:
        //constructors
        student();
	student(const student & source);
	student(char * data);
	//destructor
	~student();

	//public member functions
	bool get_name();	
        bool search_name(const char * search);
    protected:
        //protected data members working with hierarchy
        class message_mgr* msg_head;
	class lecture_mgr * lec_head;
	class hw_mgr * hw_head;

};

class room : public name
{
    public:
        room();
	room(const room & source);
	room(char * text);
	~room();
        //public member functions
	//meant to share in the hiearchy
        bool add();
	bool remove();
	bool search();
	bool display_all();

    protected:
        //protected member functions
	bool add(char * text);
	bool remove(char * search);
	bool search(char * search);
};

//message class to send messages to teacher
//message and manager handle the data structures 
//for students to send messages to teachers
class message : public room
{
    public:
        //constructors
        message();
	message(const message & source);
	message(char * text);
	~message();
        //public member functions
        bool add();
	bool remove();
        bool search();
	bool display_all();

    protected:
        //protected member functions 
        bool add(char * text);
	bool remove(char * search);
	bool search(char * search);
	
	
	//bool add_message();
	//bool remove_message();
	//bool view_messages();

};
//node class of message
class message_mgr : public message
{
    public:
        //constructors
        message_mgr();
	message_mgr(const message_mgr & source);
	message_mgr(char * text);
	~message_mgr();
        //public member functions 
        message_mgr * & go_next();
        void  set_next(message_mgr * next);
	bool add(char * text);
	bool remove(char * text);
	bool remove(message_mgr * & head, char * text);
	bool display(message_mgr * head);
	bool compare(char * text);
        //member functions
	//bool go_next();
	//bool set_next();
    protected:
        //protected data members
        message_mgr * next;//initialized to NULL
	//protected member functions
	//message_mgr *& go_next();
        //void  set_next(message_mgr * next); 
	//bool remove(message_mgr * & head, char * text);
};

/*
class hw : public room
{
    public:
    protected:
};

class hw_mgr : public hw
{
    public:
    protected:
};


class lectures : public room
{
    public:
    protected:
};


class lecture_mgr : public lectures
{
    public:
    protected;
};
*/


