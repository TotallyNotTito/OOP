/*###########################################
HAD COMPLIATION ERRORS BASED ON HOW FILES
WERE BEING INCLUDED SO MOVED ALL THIS CONTENT
IN TO TEACHER.H!!!!!!!!


THIS HEADER FILE DEVELOPS THE CLASS HIERARCHY
THAT CREATES THE CONTENT FOR THE LMS SYSTEM
NAMELY THE ABILITY TO SEND NOTES TO THE TEACHER
THE ABILITY TO REVIEW LECTURE, AND ABILITY TO
REVIEW HW ASSIGNEMENTS. 
############################################*/

//#include "teacher.h"

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
        
	bool add(char * text);
        //member functions
	//bool go_next();
	//bool set_next();
    protected:
        //protected data members
        message_mgr * next;//initialized to NULL
	//protected member functions
	message_mgr *& go_next();
        void  set_next(message_mgr * next);
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

