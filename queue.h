//SPECIFICATION FILE : QueueClass.h
//Author: Derek Gordon
//Date: 3/29/2012
//Purpose: This file declares the methods used
//	in the use of a Queue Class. It allows the client
//	to use a list that maintains ItemTypes on a First
//	In Last Out basis.
//
// Assumptions:
//	ItemType.h contains a struct where the data for the node will be stored
//		as an integer datatype.
//	Client understands the basic properties of a Queue.
//
//Exception Handling:
//	DeQ on Empty
//	Retrieve on Empty
//
//**********Summary of Methods*******************************************
//																		*
// QueueClass();														*
//	- Default constructor, initializes pdm's to default values			*
//																		*
// ~QueueClass();														*
//	- Deconstructor, returns the memory to the system					*
//																		*
//	QueueClass(const QueueClass& orig);									*
//	- Copy Constructor, creates a deep copy of orig.					*
//																		*
//	bool IsEmpty() const;												*
//	- Returns whether the que has items or not.							*
//																		*
//	bool IsFull() const;												*
//	- Returns whether the que can take any more items. (never full)		*
//																		*
//	void EnQ(ItemType newItem);	//item to be inserted					*
//	-inserts newItem into the bottom of the que.						*
//																		*
//	void DeQ();															*
//	-Deletes an item from the top of the que.							*
//																		*
//	ItemType Retrieve() const;											*
//	-Returns the item at the top of the	queue, does not alter queue		*
//																		*
//	void Clear();														*
//	- deletes all nodes within the que									*
//																		*
//	virtual void operator =(const QueueClass orig);						*
//	- makes a copy of orig to the applying object						*
//																		*
//	virtual QueueClass operator +(const QueueClass& rtOp);				*
//	-merges the lists, rtOp is appended to the bottom of applying		*
//	object																*
//																		*
//	node* Allocate();													*
//	- returns a new node if enough memory is available, throws			*
//		exception if out of memory										*
//																		*
//																		*
//***********************************************************************


#include "ItemType.h"
#include "exceptions.h"

//forward declaration
struct  node;
/* Place the following definition at top of .cpp file and delete from here
struct node
{
	ItemType data;
	node* next;
};*/

class QueueClass

{
	public:
	//constructors and destructors
//Pre: list is instantiated
//Post: the pdm's are set to their default values
//Purpose: initialize the list and set pdm's to default values
		QueueClass();								///Default Constructor



	  
//Pre: list does exist
//Post: the list is deleted and memory returned to the system
//Purpose: to return the memory that was in use by the class to the system
		~QueueClass();							//Destructor


//Pre: list exists
//Post: a deep copy of the list is created
//Purpose: to create a deep copy of the list.
		QueueClass(const QueueClass& orig);			//Copy Constructor




	// ADT  operations:
//Pre: list exists
//Post: true if the lists has no items, false otherwise
//Purpose: to return whether the list has items or not

		bool IsEmpty() const;



//Pre: list exists
//Post: true if the list is full, false otherwise
//Purpose: to return whether the list is full or not

		bool IsFull() const;



//Pre: list exists and is not full
//Post: a new item is inserted at the bottom of the list, back is incremented
//Purpose: to insert a new item at the bottom of the list

		void EnQ(ItemType newItem);	//item to be inserted


//Pre: list exists
//Post: the top item in the list is removed from the list, tail is modified
//Purpose: to remove the top item in the list

		void DeQ();



//Pre:the list has been created and is not empty
//Post: the top item in the list is returned
//Purpose: to get the top item in the list and return it
		ItemType Retrieve() const;



//Pre: the list has been created and is not empty
//Post: all items in the list are deleted, pdm's are returned to default values
//Purpose: to remove all items in the list, reset the list back to defaults

		void Clear();


//Pre: two lists exist
//Post: all the elements of orig are copied into the applying class object
//Purpose:  Copies elements of orig SnQ class into applying class object.
		virtual void operator =(const QueueClass& orig);
			

//Pre: two lists exist
//Post: all the elements of rtop are copied into the applying class object,
//	duplicates are deleted
//Purpose: merges the rtOp with the applying class object
		virtual QueueClass operator +(const QueueClass& rtOp);

protected:

		node* Allocate();	//returns a new node with next pointer set to null.
							//throws bad_alloc exception
		
//private data members
	private:       
		node* tail;

};  // end SnQClass