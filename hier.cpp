/*##################################
  This file contains the imlementation 
  of the LMS hiearchy and the objects
  being interacted with via LLLs managing
  the data that can be reviewed by students
  and changed / updated by teacher.
###################################*/ 

#include "teacher.h"
/*##################################
  ROOM DOES NOT HAVE ANY FUNCTIONALITY
  OTHER THAN KEEPING FUNCTIONS HELD TOGETHER
  LIKE A HUB. THAT IS WHY THERE ARE NO IMPLEMENTATIONS
##################################*/
//most indirect base class function implementations
room::room() 
{

}
// no dynamic memory
room::room(const room & source) : name(source)
{
	//no dynamic memory being implemented
}
//primary constructor used to set the name of message
room::room(char * text) : name(text)
{

}
//add implementation of data
//to be used through hiearchy
bool room::add()
{

}
//remove implementation of data
//to be used through hiearchy
bool room::remove()
{

}
//search implementation of data
//to be used through hiearchy
bool room::search()
{

}

//destructor, no dynamic memory
room::~room()
{

}
//*****************END OF ROOM IMPLEMENTATION*********************
//ROOM REALLY DOESN"T DO ANYTHING FYI

message::message()
{

}

message::message(const message & source) : room(source)
{
	//no dynamic memorybeing managed, not implemented
}

message::message(char * text) : room(text)
{
	//this is the constructor that gets called, what needs to be implemented?
}
//to be used through hiearchy
bool message::add(char * text)
{
	//new message(text);
	//return true;
}

//remove implementation of data
//to be used through hiearchy
bool message::remove()
{

}
//search implementation of data
//to be used through hiearchy
bool message::search()
{

}

message::~message()
{
    //delete message;
}

//********************END OF MESSAGE CLASS IMPLEMENTTION***********
//default constructor, does not get called
message_mgr::message_mgr() : next(NULL)
{

}
//copy constructor passing an object up to message pararent
message_mgr::message_mgr(const message_mgr & source) : message(source), next(NULL)
{

}
//Constructor with arguments that calls message constructor with 
//character argument, predominant constructor used
message_mgr::message_mgr(char * text) : message(text), next(NULL)
{

}
//add helper function to create object of type message
bool message_mgr::add(char * text)
{
	new message_mgr(text);
	return true;
}

/*
bool message_mgr::remove(message_mgr * & head, char * text)
{
    if (!head) return false;
    if (strcmp(head->data, text) == 0)
    {
        	
        message_mgr * temp = head->go_next();
	delete [] head->data;
	delete head;
	head = temp;
	return true;
    }
    return remove(head->go_next(), text);

    //return true;
}
*/

bool message_mgr::display(message_mgr * head)
{
    if (!head) return false;
    cout << head->data << endl;
    display(head->go_next());
    return true;
}

//getter
message_mgr *& message_mgr::go_next()
{
	return next;
}
//setter
void message_mgr::set_next(message_mgr * next)
{
	//return this->next;
	this->next = next;
}
//destructor to deallocate dynamic memory
message_mgr::~message_mgr()
{
    
//does not need to implement
//handled in teacher class

}

//******************END OF MESSAGE MANAGER "NODE" IMPLEMENTATION************
//wrapper function for removing recursively
/*
bool message_mgr::remove(char * text)
{
    message_mgr * head = &message_mgr;
    
    bool find = remove(head,text);
    return find;

}

bool message_mgr::remove(message_mgr * & head, char * text)
{
	if (!head) return false;  
	if (strcmp(head->data,text) == 0);
	{
            message_mgr * temp = head->go_next();
	    delete [] head->data;
	    delete head;
	    head = temp;
	    return true;
	}
	remove(head->go_next(),text);
}
    if (next) 
    {
        message_mgr * temp = go_next();
	delete next;
	next = temp;
    }
    */

