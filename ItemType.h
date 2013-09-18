//Filename: ItemType.h
//Project: LLQueue
//Author: Derek Gordon
//Date: November 14, 2011
//Modified: March 28, 2012
//Purpose: Declares a struct that will store
//	one or many datatypes inside it.
//
//	For This Project it will be only storing one
//	datatype which in this case is an integer.
//	The client is expected to abide by the rules of
//	the class and with this itemtype only use
//	integers for storage in the Queue.

#ifndef item_h
#define item_h



#include <string>
using namespace std;

struct ItemType		
{					
	int num; //number to be stored
};


#endif
