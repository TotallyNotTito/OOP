/*###########################################
  THIS IMPLEMENTATION FILE FOCUSES ON WHAT OBJECTS
  INTERACT WITH THE CONTENT CLASS HIERARCHY. NAMELY
  TEACHER AND STUDENTS. A TEACHER HAS MANY STUDENTS
  AND A STUDENT'S ABILITY TO INTERACT WTIH THE CLASS
  IS "READ ONLY" EXCEPT FOR COMMUNICATING WITH A 
  TEACHER.
###########################################*/

#include "teacher.h"

//JUST HANDLES MANAGING NAME
//default constructor
name::name() : data(NULL)
{
	//intiializes dynamic memory
}
//copy constructor
name::name(const name & source) : data(NULL)
{
	//if there is an object being passed
	//copy that data in to instance of that object
	if (source.data)
	{
		data = new char[strlen(source.data)+1];
		strcpy(data, source.data);
	}
	//calls read data function if no object 
	//is being passed
	else cout << "No information to copy" << endl;//read_data(source.data);
}
//constructor taking in a char *
//predominant constructor use for derived classes
name::name(char * info) : data(NULL)
{
	//constructor that takes a character array
	//as its argument
	if (!info) return;
	cout << "What is the date for this information? " << endl;
	cin >> date;
	cin.ignore(BUFFER, '\n');
	data = new char[strlen(info) + 1];
	strcpy(data, info);
}
//destructor
name::~name()
{
	//deletes info
	if (data) delete [] data;
}
//wrapper function for reding data
//don't really need it
/*
   bool name::read_data(char * info)
   {
   if (!data) 
   {
//creating data
//deep copy
cout << "We are reading in data from info"<<endl;
data = new char[strlen(info) + 1];
strcpy(data, info);
delete [] info;//make sure to deallocate dynamic memory created in this block
return true;
}
else return false;
}

class message_n * m_head;
class lecture_n * l_head;
class hw_n * hw_head;



 */
//************END MANAGING NAME**************

//HANDLES TEACHER OBJECT AND CALLING ROUTINES FOR OBJECT
//default constructor
teacher::teacher() : counter(0),num_students(0), head(NULL), msg_head(NULL), lec_head(NULL), hw_head(NULL)
{


}

//COPY CONSTRUCTOR
//ensure right constructor gets called
//HAVE QUESTIONS HERE ON ORDER OF SUPPLYING DATA
//This constructor is created if we are not copying from an external file
teacher::teacher(char * text) : name(text), counter(0), num_students(0), msg_head(NULL), lec_head(NULL), hw_head(NULL) //gets teachers name
{
	if (!text) return;
	cout << "How many students are in your class?" << '\n';
	cout << "Make it a small class..." << endl;
	cin >> num_students;
	cin.ignore(BUFFER, '\n');
	//initializing size of class
	head = new student * [num_students]; 
	int full = 0;	
	if (create_list(head, full)) cout << "List is all set!" << endl;
	else cout << "Hm, something went wrong" << endl;
	//setting student pointers to NULL
	/*
	   for (int i = 0; i < num_students; ++i)
	   {
	//making an object of the student instance
	//cout << "What is your student's name" << endl;
	head[i] = NULL;//setting pointer to student objects NULL
	//head[i] = new student;//default constructor being called
	}   
	 */
}

bool teacher::create_list(student ** head, int & full)
{
	if (full == num_students) return false;
	head[full] = NULL;
	create_list(head, ++full);
	return true;
}

//copy constructor invoked when teacher is created with an object,
//passed in from some external data
teacher::teacher(const teacher & source) : name(source), head(NULL), msg_head(NULL), lec_head(NULL), hw_head(NULL)//kickstarts name copy constructor  //name(source.data)
{
	cout << "Teacher Copy constructor" << endl; 
	//reading in number of students in class
	//cout << "How many students are in your class?" << endl;
	num_students = source.num_students;
	//cin.ignore(BUFFER, '\n');
	//initializing size of class
	head = new student * [num_students]; 
	//setting student pointers to NULL
	for (int i = 0; i < num_students; ++i)
	{
		//making an object of the student instance
		//cout << "What is your student's name" << endl;
		head[i] = new student(*source.head[i]);//calls the copy constructor for student
	}


}
//displaying teacher
bool teacher::display_teacher()
{
	if (!data) return false;
	else cout << this->data << " is teacher's name" << endl;
	return true;
}

//displaying whole class
bool teacher::display_all()
{
	if (!head) return false;
	teacher::display_teacher();
	//need to make this recursive
	for (int i = 0; i < num_students; ++i)
	{
		if (head[i]) head[i]->get_name(); 
	}
	return true;
}
//wrapper add student function for teacher
bool teacher::add_student()
{
	int count = 0;
	cout << num_students << " is size of class" << endl;
	bool added = add_student(head, count);
	return added;
}
//recursive function for adding students
bool teacher::add_student(student ** & head, int & count)
{
	if (count == num_students) return false;
	if (!head[count]) 
	{
		char info[BUFFER];
		cout << "What is the name of your student?" << endl;
		cin.get(info, BUFFER, '\n');
		cin.ignore(BUFFER, '\n');
		this->head[count] = new student(info);
		++this->counter;
		add_student(head, ++count);
		return true;
	}
	add_student(head, ++count);
}
//wrapper function for searching a student
bool teacher::search_student()
{
	cout << "Which student are you searching for?" << endl;
	char search_for[BUFFER];
	cin.get(search_for, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');
	int size = 0;

	bool check = search_student(head, search_for, size);
	return check;
}

//searching for a student function
bool teacher::search_student(student ** head, const char * search, int & size)
{
	if (size == num_students) return false;
	if(head[size])
	{
		if (head[size]->search_name(search))
		{
			head[size]->get_name();
			return true;
		}
	}
	search_student(head, search, ++size);
}

//function for removing a student
bool teacher::remove_student()
{
	char search[BUFFER];
	cout << "What student do you need to remove?" << endl;
	cin.get(search, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');

	int count = 0;
	bool remove = remove_student(head, search, count);
	if (remove) --this->counter;
	return remove;
}
//recursive function for removing student
bool teacher::remove_student(student ** & head, const char * search, int & count)
{
	if (count == num_students) return false;
	if (head[count]->search_name(search)) 
	{
		delete head[count]; 
		head[count] = NULL;
		return true;
	}
	remove_student(head, search, ++count);
}
//adds a message by passing in a text arg
//that kickstarts the constructors with marching args
//up the hiearchy
bool teacher::add_message()
{
	cout << "What message would you like to add?" << endl;
	char text[BUFFER];
	cin.get(text, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');
	//if no list exists
	if (!msg_head)
	{
		msg_head = new message_mgr(text);
		return true;
	}
	//if a list exists, kickstart the node class
	//and instantiate the dynamic memory up the chain
	message_mgr * temp = new message_mgr(text);
	//connect the nodes
	temp->set_next(this->msg_head);
	//reset the head pointer
	this->msg_head = temp;
	return true;
}
//remove message wrapper function
bool teacher::remove_message()
{
	if (!this->msg_head) return false;

	cout << "What message are you trying to remove?" << endl;
	char text[BUFFER];
	cin.get(text, BUFFER, '\n');
	cin.ignore(BUFFER, '\n');
	
	return  remove_message(this->msg_head,text);

}
//calling a function to pass a protected data member to message_manager
bool teacher::remove_message(message_mgr * & head, char * text)
{
	if (!head) return false;
	if (head->compare(text))
	{
	    message_mgr * temp = head->go_next();
	    delete head;
	    head = temp;
	    return true;
	}
	return remove_message(head->go_next(), text);
	//return msg_head->remove(head, text);
}

//helper function for removing 
bool message_mgr::compare(char * text)
{
    if (strcmp(text, this->data) == 0) return true;
    else return false;
}
//for displaying messages
bool teacher::display_message()
{
	if (!msg_head) return false;
	return  display_message(msg_head);
}

bool teacher::display_message(message_mgr * head)
{
	return this->msg_head->display(head);
}
//destructor for teacher deallocating pointers to student objects
teacher::~teacher()
{
	/*
	   for (int i = 0; i < num_students; ++i)
	   {
	   if (head[i])
	   {
	   delete head[i];
	   head[i] = NULL;
	   }
	   }
	 */

	int count = 0;     
	//deletes array of student pointers
	if (head) remove_students(head, count);
        delete head;
	head = NULL;
	//removes LLL of messages
	if (this->msg_head) remove_messages(this->msg_head);
	//removes LLL of hws
	//removes LLL of lectures
}

void teacher::remove_students(student ** & head, int & count)
{
	if (count == num_students) return;
	if (head[count]) 
	{
		delete head[count];
		head[count] = NULL;
	}
	remove_students(head, ++count);
}

void teacher::remove_messages(message_mgr * & head)
{
	if (!head) return;
	remove_messages(head->go_next());
	delete head;
	head = NULL;
}

//************************END MANAGING TEACHER**********

//STUDENT
//default constructor
student::student() : msg_head(NULL), lec_head(NULL), hw_head(NULL) //initialization list
{

}
//copy constructor for student.
student::student(const student & source) : name(source.data), msg_head(NULL), lec_head(NULL), hw_head(NULL)
{

}
//constructor for student
student::student(char * info) : name(info), msg_head(NULL), lec_head(NULL), hw_head(NULL)
{

}
//student destructor
student::~student()
{
	//if (student) delete student;
	/*
	   if (l_head) 
	   {
	   delete l_head;
	   l_head = NULL;
	   }
	   if (m_head) delete m_head;
	   {
	   delete m_head;
	   m_head = NULL;
	   }
	   if (hw_head) delete hw_head;
	   {
	   delete hw_head;
	   hw_head = NULL;
	   }
	 */
}
//helper function for displaying name
bool student::get_name()
{
	if (this->data) cout << this->data << endl;
	return true;
}
//helper function for searching name
bool student::search_name(const char * search)
{
	if (strcmp(search, data) == 0) return true;
	else return false;
}

//**************************GARBAGE CODE******************
//BEWARE YE WHO ENTER THIS DIGITal WASTELAND!!!!!!!!!!!!!
//function to read in data
//wrapper and unnecessara 
/*
   bool name::read_data(char * text)
   {
   if(!text)
   {
   cout << "What is the name?" << endl;
   cin.get(text, BUFFER, '\n');
   cin.ignore(BUFFER, '\n');

   data = new char[strlen(text) + 1];
   strcpy(data, text);
   delete [] text;
   return true;
   }

   return false;
   }

   name::read_data();
//need to implement where this is getting created
return false;
//passing in a pointer to be used to track changes
	//to message manager data structure
	   if (strcmp(this->msg_head->data,text) == 0)
	   {
	   message_mgr * temp = this->msg_head->go_next();
	   delete [] msg_head->data;
	   delete msg_head;
	   msg_head = temp;
	   }
	   
	  
*/


