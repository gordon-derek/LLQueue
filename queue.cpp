//Implementation FILE : QueueClass.cpp
//Author: Derek Gordon
//Date: 3/29/2012
//Purpose: To implement the methods of the
//	que class. These methods are declared in the header
//	file and gives the list the ability to
//	be used as a QueClass for Last in First Out data
//	Insertion/Deletion.
//
//Assumptions:
//	The ItemType passed in by the client will
//	be populated with an intended and valid
//	number.
//
//
//Error Handling:
//	DeQ on Empty
//	Retrieve on Empty

#include "queue.h"

struct node
{
	ItemType data;	//Itemtype for data to be stored in
	node* next;		//pointer to next node
};

QueueClass::QueueClass()								///Default Constructor
{
	tail = NULL;
}//end default constructor

/*****************************************************************************************/

QueueClass::~QueueClass()							//Destructor
{
	Clear();	//return all memory to system
}//end deconstructor

/*****************************************************************************************/

QueueClass::QueueClass(const QueueClass& orig)			//Copy Constructor
{
	tail = NULL;
	operator=(orig);	//makes a deep copy of orig
}//end copy constructor

/*****************************************************************************************/

bool QueueClass::IsEmpty() const
{
	return (tail == NULL);
}//end IsEmpty

/*****************************************************************************************/

bool QueueClass::IsFull() const
{
	return false;
}//end IsFull

/*****************************************************************************************/

void QueueClass::EnQ(ItemType newItem)	//item to be inserted
{
	node* insertion = Allocate();	//get new node for insertion
	insertion -> data = newItem;	//set the data for the new node

	//case 1, queue is empty
	if(IsEmpty())
	{
		//insertion becomes tail and points to itself
		//	to maintain circular properties
		insertion -> next = insertion;
		tail = insertion;
	}//end if

	//case 2, queue has nodes
	else
	{
		//insertion's next pointer points to top of queue
		insertion -> next = tail -> next;
		//tail's next pointer points to insertion(new tail)
		tail -> next = insertion;
		tail = insertion;
	}//end else
}//end EnQ

/*****************************************************************************************/

void QueueClass::DeQ()
{
	try
	{
		//case 1, no nodes in queue(empty)
		if(IsEmpty())
			throw (ExceptionClass(DEQ_ON_EMPTY));

		//case 2, one node in queue
		if(tail -> next == tail)
		{
			//make list definable as empty
			delete tail;
			tail = NULL;
		}//end if

		//case 3, multiple nodes in queue
		else
		{
			node* temp = tail -> next;
			//set tail's next pointer to skip over item getting deleted
			tail -> next = temp -> next;
			delete temp;	//remove node at tail->next(top of list)
		}//end else
	}//end try
	catch(ExceptionClass)
	{}
}//end DeQ

/*****************************************************************************************/

ItemType QueueClass::Retrieve() const
{
	try
	{
		if(IsEmpty())
			throw (ExceptionClass(RET_ON_EMPTY));

		//return data section of the node at top of list
		return tail -> next -> data;
	}//end try
	catch(ExceptionClass)
	{}
}//end Retrieve

/*****************************************************************************************/

void QueueClass::Clear()
{
	while(!IsEmpty())
		DeQ();

	tail = nullptr;
}//end Clear

/*****************************************************************************************/

void QueueClass::operator =(const QueueClass& orig)
{
	Clear();	//list getting orig needs to be empty

	//if the list is empty there is nothing to copy
	if(!orig.IsEmpty())
	{
		node* temp;

		//cycle through orig copying all items
		for(node* otemp = orig.tail -> next;
			otemp != orig.tail; otemp = otemp -> next)
		{
			//case 1, list is empty
			if(tail == nullptr)
			{
				tail = Allocate();	//tail gets a new node
				//copy data from orig to tail
				tail -> data = otemp -> data;
				//only item in list so points to itself to remain circular
				tail -> next = tail;
				temp = tail;
			}//end if

			//case 2, list has items
			else
			{
				temp = Allocate();	//tail gets a new node
				//temp's next field points to top of list
				temp -> next = tail -> next;
				//get data from orig
				temp -> data = otemp -> data;
				//set bottom of lists' next pointer to temp(new bottom of list)
				tail -> next = temp;
				tail = temp;
			}//end else

		}//end for
		//copy the tail of orig to a new node in applying object

		temp = Allocate();	//tail gets a new node
		//temp's next field points to top of list
		temp -> next = tail -> next;
		//get data from orig
		temp -> data = orig.tail -> data;
		//set bottom of lists' next pointer to temp(new bottom of list)
		tail -> next = temp;
		tail = temp;

	}//end if
	
}//end operator=

/*****************************************************************************************/

QueueClass QueueClass::operator +(const QueueClass& rtOp)
{
	
	QueueClass plus;	//queue to contain merger of applying object and rtOp

	//nothing to copy if the list is empty
	if(!IsEmpty())
	{
		//cycle through list inputting from top to bottom
		for(node* temp = tail -> next; temp != tail; temp = temp -> next)
		{
			plus.EnQ(temp -> data);
		}//end for
		//input bottom item in list
		plus.EnQ(tail -> data);
	}//end if

	//nothing to copy if the list is empty
	if(!rtOp.IsEmpty())
	{
		//cycle through list inputting from top to bottom
		for(node* temp = rtOp.tail -> next; temp != rtOp.tail; temp = temp -> next)
		{
			plus.EnQ(temp -> data);
		}//end for
		//input bottom item in list
		plus.EnQ(rtOp.tail -> data);
	}//end if
	return plus;
	
}//end operator+

/*****************************************************************************************/

node* QueueClass::Allocate()
{
	try
	{
		//if there is not enough memory for new node will throw exception
		node* newNode = new node;
		newNode -> next = nullptr;

		return newNode;
	}//end try
	catch(bad_alloc)
	{
		throw(ExceptionClass(OUT_OF_MEMORY));
	}//end catch
}//end allocate