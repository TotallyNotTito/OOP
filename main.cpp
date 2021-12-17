/*#########################################################
TAYLOR KRAL - 05/16/2020 - PROGRAM 3: Operator Overloading
main implementation is meant to serve as a testing ground
for program. Problem with this program is I have been unsuccessful
in type converting base class pointer to create and save objects
within the data structure.
##########################################################*/

#include "design.h"

int main()
{
    //menu   
    //core_data object;
    //ostream out;
    //istream in;
    int count = 0;
    BST to_manage;

    do
    {
    	if(to_manage.insert()) cout << "Object Inserted" << endl;
	else cout << "Object not inserted" << endl;
    	++count;

    } while (count < 3);

    //displaying seg faults
    to_manage.display();
    
    return 0;
}
