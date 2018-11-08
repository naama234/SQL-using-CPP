// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of main *
****************************************/
#include "QueryParser.h"
#include <iostream>


int main()
{
	//new parser
	QueryParser parser;	
	list<DataBaseOperation*> operations;
	try
	{
		operations = parser.parse(std::cin);
	}
	catch( Exception &exp )
	{
		cout<<exp.toString();
	}
	//new date base
	DataBase db;
	for(list<DataBaseOperation*>::iterator op = operations.begin(); 
	op != operations.end(); op++)
	{
		try
		{
			//update data base
			(*op)->apply(db);
		}
		catch( Exception &exp )
		{
			cout<<exp.toString();
		}
	}
	//delete from the data base
	for(list<DataBaseOperation*>::iterator op = operations.begin(); 
	op != operations.end(); op++)
	{
		delete (*op);
	}
	cout<<endl;
	return 0;
}
