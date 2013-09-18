//FileName : TestClient.cpp
//Project : LLQueue
//Author : Derek Gordon
//Date : April 2, 2012
//Purpose : This file is designed to test
//	all the methods of the queueclass to 
//	find any imperfections or errors within the class.
//
//Assumptions:
//	The class has been coded correctly
//	ItemType is a struct for integer storage.
//
//Error Handling:
//	None


#include "queue.h"
#include <iostream>

const int DEF_MAX_ENTRIES = 50; //test 50 entries

void main()
{
	QueueClass que;//default constructed stack
	ItemType insert;//used for EnQing items
	ItemType retrieve;//used for retrieving items before DeQ

	//test EnQ methods
	cout << "Insert 50 of items" << endl << endl;
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
	{
		insert.num = rand() % 500;
		cout << insert.num << " Inserted" << endl;
		que.EnQ(insert);
	}//end for

	cout << endl << "Print Queue" << endl << endl;
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
	{
		retrieve = que.Retrieve();//get top item
		cout << retrieve.num << endl;//print top item
		que.DeQ();//remove bottom item off stack
	}//end for

	//test repeated retrieves on empty
	cout << endl << "Retrieve on Empty(50)" << endl << endl;
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
		retrieve = que.Retrieve();//throws exception
	
	//test repeated DeQ on empty
	cout << endl << "DeQ on Empty(50)" << endl << endl;
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
		que.DeQ();//throws exception
	

	//Test Clear on Empty multiple times
	cout << endl << "Clear on Empty" << endl;
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
		que.Clear();//throws exception
	cout << "Does Nothing" << endl << endl;

	//random insert numbers
	insert.num = 5;
	que.EnQ(insert);
	cout << insert.num << " inserted" << endl;
	insert.num = -15;
	que.EnQ(insert);
	cout << insert.num << " inserted" << endl;

	insert.num = 46;
	que.EnQ(insert);
	cout << insert.num << " inserted" << endl;

	//Test operator=
	cout << endl << "Test operator=" << endl << endl;
	//new queue gets old stack
	QueueClass operQ = que;


	//print new stack to make sure the same
	while(!operQ.IsEmpty())
	{
		retrieve = operQ.Retrieve();
		cout << retrieve.num << endl;
		operQ.DeQ();
	}//end while


	cout << endl << "Clear new Stack" << endl << endl;
	operQ.Clear();

	//Check to make sure clear works
	cout << endl << "Try to print cleared stack" << endl << endl;
	if(operQ.IsEmpty())
		cout << "Didn't Print" << endl;
	else
		cout << "Could Have Printed" << endl;

	que.Clear();


	//Test Operator+
	cout << endl << "Test operator +" << endl;
	insert.num = 1;
	que.EnQ(insert);
	insert.num = 2;
	que.EnQ(insert);
	insert.num = 3;
	que.EnQ(insert);
	insert.num = 4;
	operQ.EnQ(insert);
	insert.num = 5;
	operQ.EnQ(insert);
	insert.num = 6;
	operQ.EnQ(insert);
	operQ = que + operQ;
	
	//test operator+ multiple times
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
		operQ = operQ + que;
	//123456 + 123, 123456123 + 123...

	cout << "Operator+ ran 50 times" << endl;
	while(!operQ.IsEmpty())
	{
		retrieve = operQ.Retrieve();
		cout << retrieve.num << endl;
		operQ.DeQ();
	}//end while


	//test operator= multiple times
	for(int i = 0; i < DEF_MAX_ENTRIES; i++)
		operQ = que;
	//123456 = 123, 123 = 123, 123 = 123...

	cout << "Operator= ran 50 times" << endl;
	while(!operQ.IsEmpty())
	{
		retrieve = operQ.Retrieve();
		cout << retrieve.num << endl;
		operQ.DeQ();
	}//end while

}//end main