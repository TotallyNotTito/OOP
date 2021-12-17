/*#########################################################
  TAYLOR KRAL - 05/16/2020 - PROGRAM 3: Operator Overloading
  Implementation portion of the program responsible for defining
  functing methods. big issue I've encountered is being unsuccessful
  in implementing my base class ptr to typ convert to derived object
  within data strucutre. wiihtout thouse objects existing I can't overload
  any of the current objects

  THIS SPECIFIC PORTION IS MEANT TO DEFINE MEHTODS TO OVERLOAD.
  NONE OF IT WILL WORK SINCE IVE RUN IN TO A BARRIER SAVING OBJECTS
  IN DATA STRUCTURE.
##########################################################*/

#include "design.h"





//overloaded operators returning objects
core_data & core_data::operator += (const int value)
{
    return *this;
}
core_data & core_data::operator -= (const int value)
{
    return *this;
}
core_data & core_data::operator = (const int value)//, const int n_date)
{
    //priority = value;
    return *this;
}

//boolean overloaded operators comparing data
bool core_data::operator > (const int value)
{
    if (priority > value) return true;
    else return false;
}

bool core_data::operator < (const int value)
{
    if (priority <  value) return true;
    else return false;
}

bool core_data::operator == (const int value)//char * text, const char * to_compare);	
{
   if (priority == value) return true;
   else return false;
}

bool core_data::operator != (const int value)
{
    if (priority != value) return true;
    else return false;
}


/*
bool operator == (char * text, const char * to_compare)
{
	return false;
}
bool operator != (char * text, const char * to_compare)
{
	return false;
}
bool operator += (char * text, const char * to_compare)
{
	return false;
}
bool operator >= (char * text, const char * to_compare)
{
	return false;
}
bool operator < (char * text, const char * to_compare)
{
	return false;
}
*/

/*
   core_data & operator += (enum  & value)//, const int date) //const core_data & to_compare, 
   {
//core_data.priority += to_compare;
this->priority = value.priority //to_compare.priority;
//this->date = n_date; 
return *this;
}

core_data & operator -= (enum & value)//, const int n_date) //const core_data & to_compare, 
{
this->priority = value.priority;
//this->date = n_date;
return *this;
}

bool operator == (core_data & check, const int value)
{
if (check.priority == value) return true;
else return false;
}
 */
/*
   core_data & operator != (const int to_compare)
   {
   return false;
   }
   core_data & operator += (const int to_compare)
   {
//core_data.priority += to_compare;
return *this;
}

core_data & operator -= (const int to_compare)
{
return *this;
}
core_data & operator >= (const int to_compare)
{
if (core_data.priority > to_compare) return true;
else return false;
}
core_data & operator < (const int to_compare)
{
if (core_data.priority < to_compare) return true;
else return false;
}
 */


